#pragma once

#ifdef BS_PLATFORM_WINDOWS

extern Blacksee::Application* Blacksee::createApplication();

int main(int argc, char** argv)
{
    Blacksee::Log::Init();
    BS_CORE_WARN("Blacksee initialized!");
    BS_INFO("Application initialized!");
    auto app = Blacksee::createApplication();
    app->run();
    delete app;
}

#endif