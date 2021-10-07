#ifndef ZERO
#define ZERO


#include "IBorder.h"

class Zero: public IBorder {
protected:
    double getBorderedPixel(DoubleImage &image, int x, int y) override;

public:
    QString toString() override;
};


#endif
