#pragma once

#ifdef BS_PLATFORM_WINDOWS

extern Blacksee::CApplication* Blacksee::CreateApplication();

int main(int argc, char** argv)
{
    Blacksee::CLog::Init();
    BS_CORE_WARN("Blacksee initialized!");
    BS_INFO("Application initialized!");
    auto app = Blacksee::CreateApplication();
    app->Run();
    delete app;
}

#endif