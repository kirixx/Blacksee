#include "RTTI.h"

const Blacksee::CClassId& Blacksee::CDynamicType::Id() noexcept
{
    static const Blacksee::CClassId id("CCDynamicType");
    return id;
}