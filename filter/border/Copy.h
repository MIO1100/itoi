#ifndef COPY
#define COPY


#include "IBorder.h"

class Copy : public IBorder {
protected:
    double getBorderedPixel(DoubleImage &image, int x, int y) override;
public:
    QString toString() override;
};


#endif
