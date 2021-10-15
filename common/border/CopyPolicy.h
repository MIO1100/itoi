#ifndef ITOI_COPYPOLICY_H
#define ITOI_COPYPOLICY_H


#include "IBorderPolicy.h"

class CopyPolicy : public IBorderPolicy {
protected:
    double bordered_pixel(ProcessingImg &image, int x, int y) override;
};


#endif //ITOI_COPYPOLICY_H
