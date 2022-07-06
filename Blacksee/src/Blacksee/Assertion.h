#pragma once
#include "Log.h"

#if ASSERTIONS_ENABLED
#define debugBreak() __debugbreak();
template<typename T1, typename T2, typename T3>
constexpr void ReportAssertionFailure(T1 expr, T2  file, T3  line) { return BS_CORE_ERROR("{0}, {1} : {2}", expr, file, line); }
#define ASSERT(expr) \
    if (expr) {} \
    else \
    { \
        ReportAssertionFailure(#expr, __FILE__, __LINE__);\
        debugBreak();\
    }
#else
#define ASSERT(expr)
#endif // ASSERTIONS_ENABLED