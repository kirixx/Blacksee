#pragma once

#ifdef BS_PLATFORM_WINDOWS

extern Blacksee::Application* Blacksee::createApplication();

int main(int argc, char** argv)
{
    Blacksee::Log::Init();
    Blacksee::Log::GetCoreLogger()->warn("Blacksee initialized!");
    Blacksee::Log::GetClientLogger()->info("Application initialized!");
    auto app = Blacksee::createApplication();
    app->run();
    delete app;
}

#endif