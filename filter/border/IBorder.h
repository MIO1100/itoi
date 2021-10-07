#ifndef IBORDER
#define IBORDER

#include "memory"
#include "../../core/DoubleImage.h"

using namespace std;

class IBorder {
protected:
    static bool isBorder(DoubleImage &image, int x, int y);
    IBorder() = default;

    virtual double getBorderedPixel(DoubleImage &image, int x, int y) = 0;
public:
    double getPixel(DoubleImage &image, int x, int y);
    virtual QString toString() = 0;
};


#endif
