#include "multilayer.h"

MultilayerPerceptron::MultilayerPerceptron (const uint32_t num_inputs, const uint32_t num_hidden, const uint32_t num_outputs)
{
    this->num_inputs = num_inputs;
    this->num_hidden = num_hidden;
    this->num_outputs = num_outputs;

    this->weights_ih = new Matrix(num_hidden,num_inputs);
    this->weights_ho = new Matrix(num_outputs,num_hidden);
    this->bias_h = new Matrix(num_hidden,1);
    this->bias_o = new Matrix(num_outputs,1);

    this->weights_ih->randomize();
    this->weights_ho->randomize();
    this->bias_h->randomize();
    this->bias_o->randomize();

    this->setLearningRate();
    this->setActivationFunction();
}

MultilayerPerceptron::~MultilayerPerceptron ()
{
    if (this->weights_ih)
        delete this->weights_ih;
    if (this->weights_ho)
        delete this->weights_ho;
    if (this->bias_h)
        delete this->bias_h;
    if (this->bias_o)
        delete this->bias_o;
}

void MultilayerPerceptron::setLearningRate (double learning_rate)
{
    this->learning_rate = learning_rate;
}

void MultilayerPerceptron::setActivationFunction (Function_t f)
{
    this->activation_function = f;
}

void MultilayerPerceptron::read_training_set (std::string filename,\
                                    std::vector< std::vector<double> > &inputs,\
                                    std::vector< std::vector<double> > &answers)
{
    uint32_t n;
    FILE *file = fopen(filename.c_str(),"r");
    if (!file)
    {
        fprintf(stderr,"[-] ERROR! Cannot open file '%s'\n",filename.c_str());
        exit(EXIT_FAILURE);
    }
    fscanf(file,"%u",&n);
    inputs.assign(n,std::vector<double>());
    answers.assign(n,std::vector<double>());
    for (uint32_t i = 0; i < n; i++)
    {
        double a, b, c;
        fscanf(file,"%lf %lf %lf",&a,&b,&c);
        inputs[i].push_back(a);
        inputs[i].push_back(b);
        answers[i].push_back(c);
    }
    fclose(file);
}

std::vector<double> MultilayerPerceptron::evaluate (std::vector<double> input)
{
    // Parse the input array to a Matrix structure
    Matrix *input_l = Matrix::convert_from_array(input);
    Matrix *input_tp = Matrix::transpose(input_l);

    // Solve the hidden layer
    Matrix *hidden_l = Matrix::matrix_multiply(this->weights_ih,input_tp);
    hidden_l->add(this->bias_h);
    hidden_l->map(this->activation_function);

    // Solve the output layer
    Matrix *output_l = Matrix::matrix_multiply(this->weights_ho,hidden_l);
    output_l->add(this->bias_o);
    output_l->map(this->activation_function);
    
    // Parse the output layer Matrix to an array
    std::vector<double> output = Matrix::convert_to_array(output_l);

    delete output_l;
    delete input_l;

    return output;
}

// TODO: There is a bug here --> Check the equations again !!
void MultilayerPerceptron::train (std::string filename)
{
    std::vector< std::vector<double> > inputs;
    std::vector< std::vector<double> > answers;
    read_training_set(filename,inputs,answers);

    for (uint32_t k = 0; k < inputs.size(); k++)
    {
        // Parse the input array to a Matrix structure
        Matrix *input_l = Matrix::convert_from_array(inputs[k]);
        Matrix *answer_m = Matrix::convert_from_array(answers[k]);
        Matrix *input_tp = Matrix::transpose(input_l);

        // [FEEDFORWARD] Solve the hidden layer
        Matrix *hidden_l = Matrix::matrix_multiply(this->weights_ih,input_tp);        
        hidden_l->add(this->bias_h);
        hidden_l->map(this->activation_function);         // The activation function is applied

        // Solve the output layer
        Matrix *output_l = Matrix::matrix_multiply(this->weights_ho,hidden_l);
        output_l->add(this->bias_o);
        output_l->map(this->activation_function);         // The activation function is applied

        // Calculate the output layer error
        Matrix *output_error_m = Matrix::subtract(answer_m,output_l);

        // Compute output layer gradient
        Matrix *output_grad = Matrix::map(output_l,dsigmoid);
        output_grad->multiply(output_error_m);
        output_grad->multiply(this->learning_rate);
        
        // Calculate the weigths deltas of the output layer
        Matrix *hidden_tp = Matrix::transpose(hidden_l);
        Matrix *weights_ho_deltas = Matrix::matrix_multiply(output_grad,hidden_tp);

        // Update the weights of the of the output layer
        this->weights_ho->add(weights_ho_deltas);
        this->bias_o->add(output_grad);

        // Calculate the hidden layer error
        Matrix *weights_ho_tp = Matrix::transpose(this->weights_ho);
        Matrix *hidden_error_m = Matrix::matrix_multiply(weights_ho_tp,output_error_m);

        // Calculate hidden layer gradient
        Matrix *hidden_grad = Matrix::map(hidden_l,dsigmoid);
        hidden_grad->multiply(hidden_error_m);
        hidden_grad->multiply(this->learning_rate);
        
        // Calculate the weigths deltas of the hidden layer
        //Matrix *inputs_tp = Matrix::transpose(input_l);
        Matrix *weights_ih_deltas = Matrix::matrix_multiply(hidden_grad,input_l);

        // Update the weights of the hidden layer
        this->weights_ih->add(weights_ih_deltas);
        this->bias_h->add(hidden_grad);

        // Free memory
        delete weights_ih_deltas;
        delete weights_ho_deltas;
        delete hidden_tp;
        delete hidden_grad;
        delete output_grad;
        delete hidden_error_m;
        delete weights_ho_tp;
        delete output_error_m;
        delete output_l;
        delete hidden_l;
        delete answer_m;
        delete input_l;
    }
}   

void MultilayerPerceptron::print ()
{
    printf("%s\n",PRINT_LINE);
    printf("Number of input layers = %u\n",this->num_inputs);
    printf("Number of hidden layers = %u\n",this->num_hidden);
    printf("Number of output layers = %u\n",this->num_outputs);
    printf("Learning rate = %g\n",this->learning_rate);
    printf("Activation function = sigmoid --> f(0) = %g\n",this->activation_function(0));
    printf("%s\n",PRINT_LINE);
    printf("Inputs --> Hidden [weights]\n");
    this->weights_ih->print();
    printf("%s\n",PRINT_LINE);
    printf("Hidden --> Outputs [weights]\n");
    this->weights_ho->print();
    printf("%s\n",PRINT_LINE);
    printf("Hidden [bias]\n");
    this->bias_h->print();
    printf("%s\n",PRINT_LINE);
    printf("Outputs [bias]\n");
    this->bias_o->print();
    printf("%s\n",PRINT_LINE);
}