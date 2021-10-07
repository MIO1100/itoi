#include "FilterUtil.h"


DoubleImage FilterUtil::crossCorel(DoubleImage &image, DoubleImage &kernel, IBorder &border) {
    int kernelW = kernel.getWidth();
    int kernelH = kernel.getHeight();
    if (!(kernelW % 2) || !(kernelH % 2)) {
        cerr << "Invalid kernel size" << endl;
    }
    int kernelKW = kernelW / 2;
    int kernelKH = kernelH / 2;
    auto result  = DoubleImage(image.getWidth(), image.getHeight());
    for (int x = 0; x < image.getWidth(); x++) {
        for (int y = 0; y < image.getHeight(); y++) {
            double res = 0;
            for (int i = 0, u = -kernelKW; i < kernel.getWidth(); i++, u++) {
                for (int j = 0, v = -kernelKH; j < kernel.getHeight(); j++, v++) {
                    res += border.getPixel(image, x + u, y + v) * kernel.getPixel(i, j);
                }
            }
            result.setPixel(x, y, res);
        }
    }
    return result;
}

DoubleImage FilterUtil::convolution(DoubleImage &image, DoubleImage &kernel, IBorder &border) {
    int kernelW = kernel.getWidth();
    int kernelH = kernel.getHeight();
    if (!(kernelW % 2) || !(kernelH % 2)) {
        cerr << "Invalid kernel size. Width: " << kernelW << ", height: " << kernelH << endl;
    }
    int kernelKW = kernelW / 2;
    int kernelKH = kernelH / 2;
    auto result  = DoubleImage(image.getWidth(), image.getHeight());
    for (int x = 0; x < image.getWidth(); x++) {
        for (int y = 0; y < image.getHeight(); y++) {
            double res = 0;
            for (int i = 0, u = -kernelKW; i < kernelW; i++, u++) {
                for (int j = 0, v = -kernelKH; j < kernelH; j++, v++) {
                    res += border.getPixel(image, x - u, y - v) * kernel.getPixel(i, j);
                }
            }
            result.setPixel(x, y, res);
        }
    }
    return result;
}
void FilterUtil::print(ostream &out, DoubleImage &matrix) {
    int w = matrix.getWidth();
    int h = matrix.getHeight();
    out << "Image [" << w << "," << h << "]" << endl;
    out << std::fixed;
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            out << setprecision(3) << setw(7) << right << matrix.getPixel(x, y);
        }
        out << endl;
    }
    out.flush();
}

DoubleImage FilterUtil::derivX(DoubleImage &image, IBorder &border) {
    auto kernel = Kernels::GetSobelX();
    return convolution(image, kernel, border);
}

DoubleImage FilterUtil::derivY(DoubleImage &image, IBorder &border) {
    auto kernel = Kernels::GetSobelY();
    return convolution(image, kernel, border);
}

DoubleImage FilterUtil::gauss(DoubleImage &image, double sigma, IBorder &policy, bool normalize){
    auto gaussFilter = Kernels::GetGauss(sigma);
    auto res = FilterUtil::convolution(image, gaussFilter, policy);
    if(normalize)
        return res.normalize();
    return res;
}


DoubleImage FilterUtil::separable(DoubleImage &image, pair<DoubleImage, DoubleImage> pair, IBorder &policy) {
    auto resX = convolution(image, pair.first, policy);
    auto resY = convolution(resX, pair.second, policy);
    return resY;
}
