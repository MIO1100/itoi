#ifndef INPUT
#define INPUT

#include <cstdlib>
#include <cmath>
#include <memory>
#include <algorithm>
#include <QImage>
#include "QString"
#include "helper.h"
#include "DoubleImage.h"
#include "iostream"

using namespace std;

class InputImage {
private:

    inline static const QString INPUT_FILES = "C:\\Users\\mioner\\Documents\\itoi\\files\\input\\";
    inline static const QString OUTPUT_FILES = "C:\\Users\\mioner\\Documents\\itoi\\files\\output\\lab1\\3\\";
    QImage img;
    int width, height;
    unique_ptr<unsigned char[]> data;

    void setImage(const QImage &image);

    void setPixel(int x, int y, unsigned char value);

    void setPixel(int i, unsigned char value);

public:
    static InputImage fromResources(const QString &imageName);

    InputImage *saveTo(const QString &imageName);

    [[nodiscard]] int getWidth() const;

    [[nodiscard]] int getHeight() const;

    unsigned char getPixel(int x, int y);

    unsigned char getPixel(int i);

    DoubleImage toDoubleImage();

    static InputImage fromDoubleImage(DoubleImage &image);

    QImage getImage();

    InputImage *open(const QString &imageName = "output");
};


#endif