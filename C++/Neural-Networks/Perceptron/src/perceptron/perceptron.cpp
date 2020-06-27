#include "perceptron.h"

// TODO: Transform this to a function pointer
double Perceptron::activation_function (const double value)
{
    return (value >= 0) ? 1.0 : -1.0;
}

// Default constructor
Perceptron::Perceptron (uint32_t n)
{
    double arr[2] = {-1.0,0.5};
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
        inputs.push_back(arr[i]);

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
        std::cout << "Weigths: " << weights[0] << " " << weights[1] << std::endl;

        sprintf(filename,"outputs/training-iterations/traning_iter_%u.vtu",i);
        draw_guess_set(t_set,filename);
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
    draw_guess_set(e_set,filename);
}

void Perceptron::draw_guess_set (std::vector<Point> t_set, const char filename[])
{

    vtkSmartPointer<vtkPoints> points = vtkSmartPointer<vtkPoints>::New();
    for (uint32_t i = 0; i < t_set.size(); i++)
    {
        points->InsertNextPoint(t_set[i].get_x(),t_set[i].get_y(),0);
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

void Perceptron::print ()
{
    std::cout << "INPUTS" << std::endl;
    for (uint32_t i = 0; i < inputs.size(); i++)
        std::cout << inputs[i] << std::endl;

    std::cout << "WEIGTHS" << std::endl;
    for (uint32_t i = 0; i < weights.size(); i++)
        std::cout << weights[i] << std::endl;
}
