#pragma once

#ifdef GLUE_PLATFORM_WINDOWS
// This function has to be defined in the user's application class.
extern GLUE::Application* GLUE::CreateApplication();

int main(int argc, char** argv){

    GLUE::Log::Init();
    GLUE_CORE_INFO("Started Core Logger successfully");
    GLUE_INFO("Started Client Logger successfully");

    auto app = GLUE::CreateApplication();
    app->Run();
    delete app;
}

#endif