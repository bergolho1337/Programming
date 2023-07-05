#include "training.h"

Training_Set::Training_Set ()
{
    for (uint32_t i = 0; i < TRAINING_SET_SIZE; i++)
    {
        Point p;
        t_set.push_back(p);
    }
}

Training_Set::Training_Set (const uint32_t n)
{
    for (uint32_t i = 0; i < n; i++)
    {
        Point p;
        t_set.push_back(p);
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
