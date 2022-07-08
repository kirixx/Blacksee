#pragma once
#include <atomic>
#include "Blacksee/Assertion.h"

//generation of unique constants should not be inlined
//should be exported from the only one place where type of instance is created
//for each class in hierarchy, including template instances
#define GENERATE_UNIQUE_ID()                  \
NOINLINE static const CClassId& Id() noexcept \
{                                             \
    static const CClassId id;                 \
    return id;                                \
}

//generate overloaded function to minimize code duplication
#define DERIVED_FROM(baseClass)                                                 \
typedef baseClass base;                                                         \
virtual bool IsBaseId(const CClassId& baseId) const noexcept override           \
{                                                                               \
    return baseId == Id() || base::IsBaseId(baseId);                            \
}                                                                               \
virtual const CClassId& Who() const noexcept override                           \
{                                                                               \
    return Id();                                                                \
}                                                                               

namespace Blacksee
{
    namespace
    {
        std::atomic<int32_t> gLastClassIndex;
    }

    //class for easier identification like X::id()
    //with comparison support and should be unique for each dynamic type
    class CClassId
    {
    public:
        CClassId() noexcept
            : mIndex(++gLastClassIndex)
        {}

        inline int32_t GetIndex() const noexcept { return mIndex; }

        bool operator==(const CClassId& ref) const noexcept
        {
            return mIndex == ref.GetIndex();
        }

    private:
        int32_t mIndex;
    };

    class CDynamicType
    {
    public:
        CDynamicType() noexcept {}
        virtual ~CDynamicType() noexcept {}
        
        GENERATE_UNIQUE_ID()

        virtual const CClassId& Who() const noexcept { return Id(); }

        template<class T>
        bool Is() const noexcept
        {
            return IsBaseId(T::Id()) || T::Id() == Who();
        }

        virtual bool IsBaseId(const CClassId& baseId) const noexcept
        {
            return baseId == Id();
        }

        template<typename T>
        const T& Get()
        {
            ASSERT(Is<T>());
            return static_cast<const T&>(*this);
        }

        /*template<typename T>
        T& Get()
        {
            ASSERT(Is<T>());
            return static_cast<T&>(*this);
        }*/
    };

    // Check if X derived from Y
    template <class X>
    struct IsDerived
    {
        template <class Y>
        static bool From() noexcept
        {
            return X::Id() == Y::Id() || IsDerived<class X::base>::template From<Y>();
        }
    };

    //Stop recursion if we faced the parent class
    template <>                              
    struct IsDerived<CDynamicType>
    {                                        
        template<class Y>                    
        static bool From() noexcept          
        {                                    
            return CDynamicType::Id() == Y::Id();
        }                                    
    };
}