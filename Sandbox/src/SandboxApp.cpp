#include <Blacksee.h>

class Sandbox : public bs::Application
{
public:
    Sandbox()
    {

    }

    ~Sandbox()
    {

    }
};

bs::Application* bs::createApplication()
{
    return new Sandbox();
}
