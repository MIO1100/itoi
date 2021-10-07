#ifndef KERNELSHANDLER
#define KERNELSHANDLER

#include "../core/DoubleImage.h"

class Kernels {
public:
    static DoubleImage GetSobelX();

    static DoubleImage GetSobelY();

    static DoubleImage GetIncreaseSharpness();

    static DoubleImage GetGauss(double sigma);
    static vector<double> GetGaussSeparableX(double sigma);
    static DoubleImage GetGauss(double sigma, int radius, bool normalize = false);

    static pair<DoubleImage, DoubleImage> GetGaussSeparableXY(double sigma);

    static pair<DoubleImage, DoubleImage> GetSobelSeparableY();
};


#endif
