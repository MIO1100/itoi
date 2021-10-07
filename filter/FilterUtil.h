#ifndef ITOI_FILTERUTIL_H
#define ITOI_FILTERUTIL_H

#include <ostream>
#include "../core/DoubleImage.h"
#include <iomanip>
#include "iostream"
#include "border/IBorder.h"
#include "border/Copy.h"
#include "Kernels.h"
using namespace std;

class FilterUtil {
public:
    constexpr static Copy DEFAULT_POLICY = Copy();
    static void print(ostream &out, DoubleImage &matrix);

    static DoubleImage crossCorel(DoubleImage &image, DoubleImage &kernel, IBorder &border);

    static DoubleImage convolution(DoubleImage &image, DoubleImage &kernel,
                                        IBorder &border = (IBorder &) DEFAULT_POLICY);

    static DoubleImage derivX(DoubleImage &image,
                                        IBorder &border = (IBorder &) DEFAULT_POLICY);

    static DoubleImage derivY(DoubleImage &image,
                              IBorder &border = (IBorder &) DEFAULT_POLICY);


    static DoubleImage gauss(DoubleImage &image, double sigma,
                                  IBorder &policy = (IBorder &) DEFAULT_POLICY, bool normalize = false);

    static DoubleImage separable(DoubleImage &image, pair<DoubleImage,DoubleImage>,
                                           IBorder &policy = (IBorder &) DEFAULT_POLICY);
};


#endif
