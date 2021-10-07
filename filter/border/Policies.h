#ifndef POLICIES
#define POLICIES


#include "IBorder.h"
#include "Copy.h"
#include "Mirror.h"
#include "Zero.h"

class Policies {
public:
    inline static Copy COPY_P = Copy();
    inline static Zero ZERO_P = Zero();
    inline static Mirror MIRROR_P = Mirror();
};


#endif//
