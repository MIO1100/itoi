#ifndef LAB1
#define LAB1

#include "../core/InputImage.h"
#include "../core/DoubleImage.h"
#include "../filter/FilterUtil.h"
#include "../filter/border/IBorder.h"
#include "../filter/border/Policies.h"
#include "../filter/Kernels.h"
#include "iostream"

using namespace std;

class Lab1 {
public:
    static void work() {
        sobel("korgy", Policies::COPY_P);
        sobel("korgy", Policies::MIRROR_P);
        sobel("korgy", Policies::ZERO_P);
//        gausFilter("korgy", 0.4, Policies::MIRROR_P);
//        gausFilter("korgy", 5, Policies::COPY_P);
//        gausFilter("korgy", 2.6, Policies::ZERO_P);
        cout << "OK" << endl;
    }

    static void sobel(const QString &imageName, IBorder &border) {
        auto input = InputImage::fromResources(imageName + ".jpg");
        auto doubleInputImage = input.toDoubleImage();
        auto sobelXImage = FilterUtil::derivX(doubleInputImage);
        auto sobelYSeparableImage = FilterUtil::separable(doubleInputImage, Kernels::GetSobelSeparableY());
        auto sobelYImage = FilterUtil::derivY(doubleInputImage);
        auto result = DoubleImage(input.getWidth(), input.getHeight());
        for (int i = 0; i < result.getSize(); ++i)
            result.setPixel(i, sqrt(sobelXImage.getPixel(i) * sobelXImage.getPixel(i) +
                                    sobelYImage.getPixel(i) * sobelYImage.getPixel(i)));
//        InputImage::fromDoubleImage(sobelXImage).saveTo(
//                imageName + "_derivativeX_" + border.toString() + ".jpg");
        InputImage::fromDoubleImage(sobelYSeparableImage).saveTo(
                imageName + "_separable_derivativeY_" + border.toString() + ".jpg");
        InputImage::fromDoubleImage(sobelYImage).saveTo(
                imageName + "_derivativeY_" + border.toString() + ".jpg");
//        InputImage::fromDoubleImage(result).saveTo(
//                imageName + "_sobel_" + border.toString() + ".jpg");
    }

    static void gausFilter(const QString &imageName, double sigma, IBorder &border) {
        auto input = InputImage::fromResources(imageName + ".jpg");
        auto doubleInputImage = input.toDoubleImage();
        double sigmaTwice = sigma * sqrt(2);
        cout << imageName.toStdString() << " with sigma " << sigma << endl;
        cout << imageName.toStdString() << " with sigmaTwice " << sigmaTwice << endl;
        auto gaussA = FilterUtil::gauss(doubleInputImage, sigma, border);
        auto twiceGauss = FilterUtil::gauss(gaussA, sigma, border);
        auto gaussSum = FilterUtil::gauss(doubleInputImage, sigmaTwice, border);

        InputImage::fromDoubleImage(twiceGauss).saveTo(
                imageName + "_gauss_2sigma_" +  QString::number(sigma, 'f', 3) + '_' +
                border.toString() + ".jpg");
        InputImage::fromDoubleImage(gaussSum).saveTo(
                imageName + "_gauss_sigma" + QString::number( sigmaTwice, 'f', 3) + '_' +
                border.toString() + ".jpg");
    }
};



#endif
