#include "perceptron.h"

// [ACTIVATION FUNCTION]
double Perceptron::activation_function (const double value)
{
    return (value >= 0) ? 1.0 : -1.0;
}

// Default constructor (n = 3)
Perceptron::Perceptron (uint32_t n)
{
    // The last input value is the bias value, which is fixed as (BIAS = 1)
    double arr[3] = {0,0,BIAS};
    initialize(n,arr);
}

Perceptron::Perceptron (const uint32_t n, const double arr[])
{
    initialize(n,arr);
}

void Perceptron::initialize (const uint32_t n, const double arr[])
{

    for (uint32_t i = 0; i < n; i++)
    {
        // Start with an arbitrary input
        inputs.push_back(arr[i]);

        // Set random weights first
        double value = generate_random_positive_or_negative();
        weights.push_back(value);
    }
}

double Perceptron::guess ()
{
    // Calculate the weigthed sum
    double sum = 0.0;
    for (uint32_t i = 0; i < inputs.size(); i++)
        sum += inputs[i] * weights[i];
    
    double ret = activation_function(sum);

    return ret;
}

void Perceptron::train (Training_Set *training_set)
{
    char filename[200];
    std::vector<Point> t_set = training_set->get_training_set();

    for (uint32_t i = 0; i < t_set.size(); i++)
    {
        // Get the current input point coordinate
        inputs[0] = t_set[i].get_x();
        inputs[1] = t_set[i].get_y();

        // Ask the Perceptron for a guess using the current input
        double aprox = guess();

        // Get the correct answer for the current point
        double target = t_set[i].get_label();

        // Calculate its error
        double error = (target - aprox)*LEARNING_RATE;

        // Update the weights following a Gradient Descent approach
        update_weigths(error);

        // Draw current result from training
        std::cout << "Weigths: " << weights[0] << " " << weights[1] << " " << weights[2] << std::endl;

        sprintf(filename,"outputs/training-iterations/traning_iter_%u.vtu",i);
        draw(t_set,i);
    }
}

void Perceptron::update_weigths (const double error)
{
    // GRADIENT DESCENT
    // w = w + delta_w 
    // delta_w = (ref - aprox) * inputs --> Learning rate
    for (uint32_t i = 0; i < weights.size(); i++)
    {
        weights[i] += error * inputs[i];
    }
}

void Perceptron::evaluate (Training_Set *evaluate_set)
{
    char filename[200];
    std::vector<Point> e_set = evaluate_set->get_training_set();

    uint32_t counter = 0;
    for (uint32_t i = 0; i < e_set.size(); i++)
    {
        // Get the current input point coordinate
        inputs[0] = e_set[i].get_x();
        inputs[1] = e_set[i].get_y();

        // Ask the Perceptron for a guess using the current input
        double aprox = guess();

        // Get the correct answer for the current point
        double target = e_set[i].get_label();

        // Calculate its error
        double error = (target - aprox);
        if (error == 0)
            counter++;
    }

    std::cout << "\nAcuracy:> " << (double)counter/(double)e_set.size()*100.0 << " %" << std::endl;
    sprintf(filename,"outputs/evaluate-set.vtu");
    draw(e_set,500);
}

void Perceptron::draw (std::vector<Point> t_set, const uint32_t iter)
{
    draw_points(t_set,iter);
    draw_line(iter);
}

void Perceptron::draw_points (std::vector<Point> t_set, const uint32_t iter)
{
    char filename[200];
    sprintf(filename,"outputs/training-iterations/traning_iter_%u.vtu",iter);

    vtkSmartPointer<vtkPoints> points = vtkSmartPointer<vtkPoints>::New();
    for (uint32_t i = 0; i < t_set.size(); i++)
    {
        points->InsertNextPoint(t_set[i].get_map_x(),t_set[i].get_map_y(),0);
    }

    vtkSmartPointer<vtkCellArray> cell_array = vtkSmartPointer<vtkCellArray>::New();
    for (uint32_t i = 0; i < t_set.size(); i++)
    {
        vtkSmartPointer<vtkVertex> vertex = vtkSmartPointer<vtkVertex>::New();
        vertex->GetPointIds()->SetId(0,i);

        cell_array->InsertNextCell(vertex);
    }
    
    vtkSmartPointer<vtkFloatArray> values = vtkSmartPointer<vtkFloatArray>::New();
    for (uint32_t i = 0; i < t_set.size(); i++)
    {
        inputs[0] = t_set[i].get_x();
        inputs[1] = t_set[i].get_y();

        // Ask the Perceptron for a guess using the current input
        double aprox = guess();

        values->InsertNextValue(aprox);
    }

    vtkSmartPointer<vtkUnstructuredGrid> unstructured_grid = vtkSmartPointer<vtkUnstructuredGrid>::New();
    unstructured_grid->SetPoints(points);
    unstructured_grid->SetCells(VTK_VERTEX,cell_array);
    unstructured_grid->GetCellData()->SetScalars(values);

    vtkSmartPointer<vtkXMLUnstructuredGridWriter> writer = vtkSmartPointer<vtkXMLUnstructuredGridWriter>::New();
    writer->SetFileName(filename);
    writer->SetInputData(unstructured_grid);
    writer->Write();
}

void Perceptron::draw_line (const uint32_t iter)
{
    char filename[200];
    sprintf(filename,"outputs/training-iterations/traning_line_iter_%u.vtu",iter);

    double w0 = weights[0];
    double w1 = weights[1];
    double w2 = weights[2];

    double x1 = MIN_X;
    double y1 = (-w2/w1)*BIAS + (-w0/w1)*x1;

    double map_x1 = map_function(x1,MIN_X,MAX_X,0,WIDTH);
    double map_y1 = map_function(y1,MIN_Y,MAX_Y,0,HEIGHT);
    double z1 = 0;
    
    double x2 = MAX_X;
    double y2 = (-w2/w1)*BIAS + (-w0/w1)*x2;

    double map_x2 = map_function(x2,MIN_X,MAX_X,0,WIDTH);
    double map_y2 = map_function(y2,MIN_Y,MAX_Y,0,HEIGHT);
    double z2 = 0;

    vtkSmartPointer<vtkPoints> points = vtkSmartPointer<vtkPoints>::New();
    points->InsertNextPoint(map_x1,map_y1,z1);
    points->InsertNextPoint(map_x2,map_y2,z2);

    vtkSmartPointer<vtkCellArray> cell_array = vtkSmartPointer<vtkCellArray>::New();    
    vtkSmartPointer<vtkLine> line = vtkSmartPointer<vtkLine>::New();
    line->GetPointIds()->SetId(0,0);
    line->GetPointIds()->SetId(1,1);

    cell_array->InsertNextCell(line);

    vtkSmartPointer<vtkUnstructuredGrid> unstructured_grid = vtkSmartPointer<vtkUnstructuredGrid>::New();
    unstructured_grid->SetPoints(points);
    unstructured_grid->SetCells(VTK_LINE,cell_array);

    vtkSmartPointer<vtkXMLUnstructuredGridWriter> writer = vtkSmartPointer<vtkXMLUnstructuredGridWriter>::New();
    writer->SetFileName(filename);
    writer->SetInputData(unstructured_grid);
    writer->Write();
}

void Perceptron::print ()
{
    std::cout << "INPUTS" << std::endl;
    for (uint32_t i = 0; i < inputs.size(); i++)
        std::cout << inputs[i] << std::endl;

    std::cout << "WEIGTHS" << std::endl;
    for (uint32_t i = 0; i < weights.size(); i++)
        std::cout << weights[i] << std::endl;
}
