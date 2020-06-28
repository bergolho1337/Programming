#include "training.h"

// [CLASSIFICATION FUNCTION] --> y = mx + b
double Training_Set::classify_function (Point p)
{
    double eval = m*p.get_x() + b;
    return (p.get_y() < eval) ? 1 : -1;
}

// Default constructor
Training_Set::Training_Set ()
{
    // Create only the points over the reference domain
    for (uint32_t i = 0; i < TRAINING_SET_SIZE; i++)
    {
        Point p;
        t_set.push_back(p);
    }

    // Set the label parameter using the configured classify_function()
    classify();
}

// Specific constructor
Training_Set::Training_Set (const uint32_t n)
{
    // Create only the points over the reference domain
    for (uint32_t i = 0; i < n; i++)
    {
        Point p;
        t_set.push_back(p);
    }
    // Set the label parameter using the configured classify_function()
    classify();
}

void Training_Set::classify ()
{
    for (uint32_t i = 0; i < t_set.size(); i++)
    {
        double label = classify_function(t_set[i]);
        t_set[i].set_label(label);
    }
}

void Training_Set::print ()
{
    for (uint32_t i = 0; i < t_set.size(); i++)
    {
        t_set[i].print();
    }    
}

void Training_Set::draw ()
{
    draw_points();
    draw_line();
}

void Training_Set::draw_points ()
{
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
        values->InsertNextValue(t_set[i].get_label());
    }

    vtkSmartPointer<vtkUnstructuredGrid> unstructured_grid = vtkSmartPointer<vtkUnstructuredGrid>::New();
    unstructured_grid->SetPoints(points);
    unstructured_grid->SetCells(VTK_VERTEX,cell_array);
    unstructured_grid->GetCellData()->SetScalars(values);

    vtkSmartPointer<vtkXMLUnstructuredGridWriter> writer = vtkSmartPointer<vtkXMLUnstructuredGridWriter>::New();
    writer->SetFileName("outputs/training_set.vtu");
    writer->SetInputData(unstructured_grid);
    writer->Write();
}

void Training_Set::draw_line ()
{
    double x1 = map_function(-1,MIN_X,MAX_X,0,WIDTH);
    double y1 = map_function(-m+b,MIN_Y,MAX_Y,0,HEIGHT);
    double z1 = 0;
    
    double x2 = map_function(1,MIN_X,MAX_X,0,WIDTH);
    double y2 = map_function(m+b,MIN_Y,MAX_Y,0,HEIGHT);
    double z2 = 0;

    vtkSmartPointer<vtkPoints> points = vtkSmartPointer<vtkPoints>::New();
    points->InsertNextPoint(x1,y1,z1);
    points->InsertNextPoint(x2,y2,z2);

    vtkSmartPointer<vtkCellArray> cell_array = vtkSmartPointer<vtkCellArray>::New();    
    vtkSmartPointer<vtkLine> line = vtkSmartPointer<vtkLine>::New();
    line->GetPointIds()->SetId(0,0);
    line->GetPointIds()->SetId(1,1);

    cell_array->InsertNextCell(line);

    vtkSmartPointer<vtkUnstructuredGrid> unstructured_grid = vtkSmartPointer<vtkUnstructuredGrid>::New();
    unstructured_grid->SetPoints(points);
    unstructured_grid->SetCells(VTK_LINE,cell_array);

    vtkSmartPointer<vtkXMLUnstructuredGridWriter> writer = vtkSmartPointer<vtkXMLUnstructuredGridWriter>::New();
    writer->SetFileName("outputs/training_line.vtu");
    writer->SetInputData(unstructured_grid);
    writer->Write();
}