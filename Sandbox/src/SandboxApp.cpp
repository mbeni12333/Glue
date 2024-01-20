#include <GLUE.h>
#include <iostream>


class SandboxApp : public GLUE::Application{
public:
    SandboxApp(){
    }
    ~SandboxApp(){      
    }
};


GLUE::Application* GLUE::CreateApplication(){
    return new SandboxApp();
}