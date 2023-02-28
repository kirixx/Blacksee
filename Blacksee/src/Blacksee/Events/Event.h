#pragma once
#include "Blacksee/RTTI/RTTI.h"
#include <string>

namespace Blacksee
{
    class CEvent : public CDynamicType
    {
    public:
        bool mHandled = false;

        GENERATE_UNIQUE_ID()
        DERIVED_FROM(CDynamicType)
    };
}
