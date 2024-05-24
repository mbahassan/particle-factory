//
// Created by iqraa on 25-3-23.
//
#include <RenderBondedParticles.h>

void RenderBondedParticles::renderSphere(double r, std::vector<double>& x){
    vtkNew<vtkNamedColors> colors;

    vtkNew<vtkTransform> transform;
    transform->Translate(0.0, 0.0, 0.0);

    vtkNew<vtkRenderer> renderer;

    vtkNew<vtkRenderWindow> window;
    window->AddRenderer(renderer);

    vtkNew<vtkRenderWindowInteractor> interactor;
    interactor->SetRenderWindow(window);

    vtkNew<vtkSphereSource> sphere;
    sphere->SetRadius(r);
    sphere->SetPhiResolution(100);
    sphere->SetThetaResolution(100);

    for (double i : x)
    {
        vtkNew<vtkPolyDataMapper> mapper;
        mapper->SetInputConnection(sphere->GetOutputPort());

        vtkNew<vtkActor> actor;
        actor->SetMapper(mapper);
        actor->SetPosition(i,0,0); // set position of each sphere

        renderer->AddActor(actor);

    }
    renderer->SetBackground(colors->GetColor3d("DarkGreen").GetData());
    window->Render();
    interactor->Start();
}

void RenderBondedParticles::renderSphere(double r, std::vector<double>& x,std::vector<double>& y){
    vtkNew<vtkNamedColors> colors;
    vtkNew<vtkRenderer> renderer;
    vtkNew<vtkRenderWindow> window;
    window->AddRenderer(renderer);
    vtkNew<vtkRenderWindowInteractor> interactor;
    interactor->SetRenderWindow(window);

    vtkNew<vtkSphereSource> sphere;
    sphere->SetRadius(r);
    sphere->SetPhiResolution(100);
    sphere->SetThetaResolution(100);

    for (int i = 0; i < x.size(); i++)
    {
        vtkNew<vtkPolyDataMapper> mapper;
        mapper->SetInputConnection(sphere->GetOutputPort());

        vtkNew<vtkActor> actor;
        actor->SetMapper(mapper);
        actor->SetPosition(x[i], y[i],0); // set position of each sphere

        renderer->AddActor(actor);
    }
    renderer->SetBackground(colors->GetColor3d("DarkGreen").GetData());
    window->Render();
    interactor->Start();
}

void RenderBondedParticles::renderSphere(double r, std::vector<double>& x,std::vector<double>& y,std::vector<double>& z){
    vtkNew<vtkNamedColors> colors;
    vtkNew<vtkRenderer> renderer;
    vtkNew<vtkRenderWindow> window;
    window->AddRenderer(renderer);
    vtkNew<vtkRenderWindowInteractor> interactor;
    interactor->SetRenderWindow(window);

    vtkNew<vtkSphereSource> sphere;
    sphere->SetRadius(r);
    sphere->SetPhiResolution(100);
    sphere->SetThetaResolution(100);

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
