#include "Blacksee.h"

class Sandbox : public Blacksee::Application
{
public:
    Sandbox()
    {

    }

    ~Sandbox()
    {

    }
};

Blacksee::Application* Blacksee::createApplication()
{
    return new Sandbox();
}
