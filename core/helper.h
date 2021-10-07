#ifndef HELPER
#define HELPER

#include <QColor>
#include "memory"

using namespace std;

class Helper {
public:
    static unsigned char toGrayscale(const QColor &rgbPixel);

    static unique_ptr<double[]> normalizeMinMax(const unique_ptr<double[]> &data, int size, double newDiff = 1.0);
};
#endif
