//
// Created by iqraa on 25-3-23.
//

#ifndef BPGENERATOR_RENDERBONDEDPARTICLES_H
#define BPGENERATOR_RENDERBONDEDPARTICLES_H

#include <vtkActor.h>
#include <vtkTextProperty.h>
#include <vtkTransform.h>
#include <vtkNamedColors.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkSmartPointer.h>
#include <vtkSphereSource.h>
#include <iostream>
#include <vector>

#include "Shape.h"

class RenderShape
{
public:
    static void renderSphere(std::vector<Sphere>& sphereHandler);

    static void renderSphere(double r, std::vector<double>& x,std::vector<double>& y,std::vector<double>& z);

};
#endif //BPGENERATOR_RENDERBONDEDPARTICLES_H
