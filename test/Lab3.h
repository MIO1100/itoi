#ifndef ITOI_LAB3_H
#define ITOI_LAB3_H


#include <QString>
#include "../common/LoadedImg.h"
#include "../point/Moravec.h"
#include "../point/Harris.h"
#include "../point/Drawer.h"


class Lab3 {
private:
    const QString &imageName, &ext;
    int pointsCount = 100;
    int windowSize = 4;
    double harrisThresholdCoef = 0.2;
    double moravecThresholdCoef = 0.2;
    LoadedImg loadedImg;

    Lab3(const QString &imageName, const QString &ext) : imageName(imageName), ext(ext) {
        this->loadedImg = LoadedImg::by_image_name(imageName + ext);
    }


    Lab3 *moravec() {
        cout << "test moravec processing " << imageName.toStdString() << endl;
        auto inputDouble = loadedImg.to_processing_img();
        auto moravec = new Moravec(make_shared<ProcessingImg>(inputDouble), imageName, ext);
        auto points = moravec->find_points(pointsCount, windowSize, moravecThresholdCoef);
        auto result = LoadedImg::from_processing_img(inputDouble).native_image();
        LoadedImg::save(Drawer::mark_points(points, result),
                        imageName + "_moravec_" + QString::fromStdString(to_string(pointsCount)) + ext);
        return this;
    }

    Lab3 *harris() {
        cout << "test harris processing " << imageName.toStdString() << endl;
        auto inputDouble = loadedImg.to_processing_img();
        auto harris = new Harris(make_shared<ProcessingImg>(inputDouble), imageName, ext);
        auto points = harris->find_points(pointsCount, 3, harrisThresholdCoef);
        auto result = LoadedImg::from_processing_img(inputDouble).native_image();
        LoadedImg::save(Drawer::mark_points(points, result),
                        imageName + "_harris_" + QString::fromStdString(to_string(pointsCount)) + ext);
        return this;
    }

public:
    static void test() {

        cout << "Start test for Lab3..." << endl;


        Lab3("mimimi", ".jpg").moravec()->harris();

    }
};


#endif //ITOI_LAB3_H
