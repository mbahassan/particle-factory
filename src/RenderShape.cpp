//
// Created by iqraa on 25-3-23.
//
#include "RenderShape.h"

void RenderShape::renderSphere(std::vector<Sphere>& sphereHandler){
    vtkNew<vtkNamedColors> colors;
    vtkNew<vtkRenderer> renderer;
    vtkNew<vtkRenderWindow> window;
    window->AddRenderer(renderer);
    vtkNew<vtkRenderWindowInteractor> interactor;
    interactor->SetRenderWindow(window);

    vtkNew<vtkSphereSource> sphere;

    sphere->SetPhiResolution(20);
    sphere->SetThetaResolution(20);

    for (auto & sh : sphereHandler)
    {
        sphere->SetRadius(sh.getRadius());

        vtkNew<vtkPolyDataMapper> mapper;
        mapper->SetInputConnection(sphere->GetOutputPort());

        vtkNew<vtkActor> actor;
        actor->SetMapper(mapper);
        actor->SetPosition(sh.getX(), sh.getY(),sh.getZ()); // set position of each sphere

        renderer->AddActor(actor);
    }
    renderer->SetBackground(colors->GetColor3d("DarkGreen").GetData());
    window->Render();
    interactor->Start();
}

void RenderShape::renderSphere(double r, std::vector<double>& x, std::vector<double>& y, std::vector<double>& z){
    vtkNew<vtkNamedColors> colors;
    vtkNew<vtkRenderer> renderer;
    vtkNew<vtkRenderWindow> window;
    window->AddRenderer(renderer);
    vtkNew<vtkRenderWindowInteractor> interactor;
    interactor->SetRenderWindow(window);

    vtkNew<vtkSphereSource> sphere;
    sphere->SetRadius(r);
    sphere->SetPhiResolution(10);
    sphere->SetThetaResolution(10);

    for (int i = 0; i < x.size(); i++)
    {
        vtkNew<vtkPolyDataMapper> mapper;
        mapper->SetInputConnection(sphere->GetOutputPort());

        vtkNew<vtkActor> actor;
        actor->SetMapper(mapper);
        actor->SetPosition(x[i], y[i],z[i]); // set position of each sphere

        renderer->AddActor(actor);
    }
    renderer->SetBackground(colors->GetColor3d("DarkGreen").GetData());
    window->Render();
    interactor->Start();
}