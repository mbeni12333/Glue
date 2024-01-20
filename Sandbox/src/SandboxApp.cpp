#include <GLUE.h>
#include <iostream>


class SandboxApp : public GLUE::Application{
public:
    SandboxApp(){
        std::cout << "Application Sanbox started " << std::endl;
    }
    ~SandboxApp(){

    }
};


GLUE::Application* GLUE::CreateApplication(){
    return new SandboxApp();
}