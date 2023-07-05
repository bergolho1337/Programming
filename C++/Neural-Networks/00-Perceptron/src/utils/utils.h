#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstdbool>
#include <cstdint>

#include <vtkRegularPolygonSource.h>
#include <vtkXMLPolyDataWriter.h>
#include <vtkFloatArray.h>
#include <vtkUnstructuredGrid.h>
#include <vtkXMLUnstructuredGridWriter.h>
#include <vtkVertex.h>
#include <vtkPoints.h>
#include <vtkPolyData.h>
#include <vtkSmartPointer.h>
#include <vtkDoubleArray.h>
#include <vtkAppendPolyData.h>
#include <vtkMath.h>
#include <vtkXMLUnstructuredGridReader.h>
#include <vtkDataSetMapper.h>
#include <vtkFloatArray.h>
#include <vtkCellData.h>

#define WIDTH 400
#define HEIGHT 400

double generate_random_number ();
double generate_random_positive_or_negative ();

class Point
{
private:
    double x, y;
    double label;
public:
    Point ()
    {
        x = generate_random_number()*WIDTH;
        y = generate_random_number()*HEIGHT;

        label = (x > y) ? 1.0 : -1.0;
    };

    double get_x () { return x; }
    double get_y () { return y; }
    double get_label () { return label; }

    void print ()
    {
        std::cout << "Point = (" << x << "," << y << ") -- Output = " << label << std::endl;
    }
};

#endif