#ifndef ITOI_DRAWER_H
#define ITOI_DRAWER_H


#include <QImage>
#include "../../common/ProcessingImg.h"
#include "cmath"
#include "../../common/LoadedImg.h"
#include "Point.h"
#include <QPainter>

using namespace std;

class Drawer {
private:

    static void set_point(int x, int y, QImage &image);

    static pair<int, int> round(int x, int y, QImage &image);

    static void draw_plus(const Point &item, QImage &image);
public:
    static QImage mark_points(const vector<Point> &points, const QImage &image);
};


#endif //ITOI_DRAWER_H
