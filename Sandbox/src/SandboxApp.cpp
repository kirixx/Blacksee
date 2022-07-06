#include "Blacksee.h"

class CSandbox : public Blacksee::CApplication
{
public:
    CSandbox()
    {

    }

    ~CSandbox()
    {

    }
};

Blacksee::CApplication* Blacksee::CreateApplication()
{
    return new CSandbox();
}
