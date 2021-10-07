#ifndef DOUBLEIMAGE
#define DOUBLEIMAGE

#include <memory>
#include "helper.h"

using namespace std;

class DoubleImage {
private:
    int width, height;
    unique_ptr<double[]> data;
public:
    DoubleImage(unique_ptr<double[]> byteSource, int width, int height);
    DoubleImage(vector<double> array, int width, int height);

    DoubleImage(int width, int height);

    DoubleImage(DoubleImage &&other) noexcept;

    DoubleImage &operator=(DoubleImage &&other) noexcept;

    void setPixel(int x, int y, double value);

    double getPixel(int x, int y);

    double getPixel(int i);

    void setPixel(int i, double value);

    void setPixel(int i, unsigned char value);

    void copy(DoubleImage &other);

    void applyFunc(const std::function<double(double)> &f);

    [[nodiscard]] int getHeight() const;

    [[nodiscard]] int getWidth() const;

    const unique_ptr<double[]> &getData();

    int getSize();

    DoubleImage normalize(float diff = 1.0);
};


#endif
