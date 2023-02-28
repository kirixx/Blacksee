#include "Application.h"


namespace Blacksee
{

    CApplication::CApplication()
    {
        _Window = std::unique_ptr<Window>(Window::Create());
    }

    CApplication::~CApplication()
    {

    }

    void CApplication::Run()
    {
        while (_IsRunning)
        {
            _Window->OnUpdate();
        }
    }

}
