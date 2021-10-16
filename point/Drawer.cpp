#include "Drawer.h"


void Drawer::draw_plus(const Point &item, QImage &image) {
    int plusSize = 2;
    for (int i = -plusSize; i <= plusSize; i++) {
        if (i == 0)
            continue;
        set_point(item.get_x() + i, item.get_y(), image);
        set_point(item.get_x(), item.get_y() + i, image);
    }
}

pair<int, int> Drawer::round(int x, int y, QImage &image) {
    int resX = (x < 0) ? 0 : (x >= image.width() ? image.width() - 1 : x);
    int resY = (y < 0) ? 0 : (y >= image.height() ? image.height() - 1 : y);
    return make_pair(resX, resY);
}

void Drawer::set_point(int x, int y, QImage &image) {
    auto pair = round(x, y, image);
    image.setPixelColor(pair.first, pair.second, qRgb(255, 0, 0));
}

QImage Drawer::mark_points(const vector<Point> &points, const QImage &image) {
    QImage resultImage(image);
    for (const auto &item: points) {
        draw_plus(item, resultImage);
    }
    return resultImage;
}
