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
#include <vtkLine.h>
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

// ----------------------------------------------------
// Domain limits
const double WIDTH = 400.0;     // Output domain
const double HEIGHT = 400.0;    // Output domain
const double MIN_X = -1;        // Reference domain
const double MAX_X = 1;         // Reference domain
const double MIN_Y = -1;        // Reference domain
const double MAX_Y = 1;         // Reference domain
// ----------------------------------------------------

double generate_random_number ();
double generate_random_number_between_interval (const double min_value, const double max_value);
double generate_random_positive_or_negative ();
double map_function (const double x, const double min_x1, const double max_x1, const double min_x2, const double max_x2);

class Point
{
private:
    double x, y;
    double label;
public:
    Point ()
    {
        x = generate_random_number_between_interval(MIN_X,MAX_X);
        y = generate_random_number_between_interval(MIN_X,MAX_X);
        label = 0;  // Do not set the label yet ...
    };

    void set_label (const double label) { this->label = label; }

    double get_map_x () { return map_function(this->x,MIN_X,MAX_X,0,WIDTH); }
    double get_map_y () { return map_function(this->y,MIN_Y,MAX_Y,0,HEIGHT); }
    double get_x () { return x; }
    double get_y () { return y; }
    double get_label () { return label; }

    void print ()
    {
        std::cout << "Point = (" << x << "," << y << ") -- Output = " << label << std::endl;
    }
};

#endif