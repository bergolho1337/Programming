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

std::vector<double> MultilayerPerceptron::evaluate (std::vector<double> inputs)
{
    // Parse the input array to a Matrix structure
    Matrix *input_l = Matrix::convert_from_array(inputs);

    // Solve the hidden layer
    Matrix *hidden_l = Matrix::matrix_multiply(this->weights_ih,input_l);
    hidden_l->add(this->bias_h);
    hidden_l->map(sigmoid);

    // Solve the output layer
    Matrix *output_l = Matrix::matrix_multiply(this->weights_ho,hidden_l);
    output_l->add(this->bias_o);
    output_l->map(sigmoid);
    
    // Parse the output layer Matrix to an array
    std::vector<double> output = Matrix::convert_to_array(output_l);

    delete output_l;
    delete input_l;

    return output;
}

void MultilayerPerceptron::print ()
{
    printf("%s\n",PRINT_LINE);
    printf("Number of input layers = %u\n",this->num_inputs);
    printf("Number of hidden layers = %u\n",this->num_hidden);
    printf("Number of output layers = %u\n",this->num_outputs);
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