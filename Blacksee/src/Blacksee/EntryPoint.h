#pragma once
#ifdef BS_PLATFORM_WINDOWS

extern bs::Application* bs::createApplication();

int main(int argc, char** argv)
{
    auto app = bs::createApplication();
    app->run();
    delete app;
}

#endif