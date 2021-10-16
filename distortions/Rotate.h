
#ifndef IP_ROTATE_H
#define IP_ROTATE_H


#include "AbstractDistortion.h"

using namespace std;

class Rotate : public AbstractDistortion {
public:
    explicit Rotate(double degrees) : _degrees(degrees) {};

    virtual QPixmap distort(QPixmap pixmap);

    inline QString getName() override { return QStringLiteral("ROTATED_%1").arg(_degrees); }

private:
    double _degrees;
};


#endif //IP_ROTATE_H
