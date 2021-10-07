#ifndef MIRROR
#define MIRROR

#include "IBorder.h"

class Mirror : public IBorder{
protected:
    double getBorderedPixel(DoubleImage &image, int x, int y) override;

public:
    QString toString() override;
};


#endif
