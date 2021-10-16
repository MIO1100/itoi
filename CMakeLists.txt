cmake_minimum_required(VERSION 3.21)
project(itoi)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QT_VERSION 6)
set(REQUIRED_LIBS Core Gui Widgets)
set(REQUIRED_LIBS_QUALIFIED Qt6::Core Qt6::Gui Qt6::Widgets)

add_executable(${PROJECT_NAME}
        main.cpp
        common/LoadedImg.cpp common/LoadedImg.h
        common/ProcessingImg.cpp common/ProcessingImg.h
        common/Filter.cpp common/Filter.h
        common/Kernels.cpp common/Kernels.h
        common/border/IBorderPolicy.cpp common/border/IBorderPolicy.h
        common/border/MirrorPolicy.cpp common/border/MirrorPolicy.h
        common/border/ZeroPolicy.cpp common/border/ZeroPolicy.h
        common/border/SymmetryPolicy.cpp
        common/border/SymmetryPolicy.h
        common/border/CopyPolicy.cpp common/border/CopyPolicy.h
        test/Lab2.cpp test/Lab2.h
        octave/OctaveFactory.cpp octave/OctaveFactory.h
        octave/Element.cpp octave/Element.h
        octave/Octave.cpp octave/Octave.h
        point/Point.cpp point/Point.h
        point/AbstractInterestPointsAlgo.cpp point/AbstractInterestPointsAlgo.h
        point/Moravec.cpp point/Moravec.h
        point/Harris.cpp point/Harris.h
        distortions/AbstractDistortion.cpp distortions/AbstractDistortion.h
        distortions/Contrast.cpp distortions/Contrast.h
        distortions/Rotate.cpp distortions/Rotate.h
        distortions/Shift.cpp distortions/Shift.h
        test/Lab3.cpp test/Lab3.h
        descriptor/AbstractDescriptor.cpp descriptor/AbstractDescriptor.h
        descriptor/DescriptorDrawer.cpp descriptor/DescriptorDrawer.h
        descriptor/DescriptorPair.cpp descriptor/DescriptorPair.h
        test/Lab4.cpp test/Lab4.cpp
        descriptor/Histogram.cpp descriptor/Histogram.h
        descriptor/Sift.cpp descriptor/Sift.h
        descriptor/Basket.cpp descriptor/Basket.h
        descriptor/HistogramFactory.cpp descriptor/HistogramFactory.h
        test/Lab5.cpp test/Lab5.h
        descriptor/SiftFactory.cpp descriptor/SiftFactory.h common/AbstractImg.cpp common/AbstractImg.h descriptor/AbstractDescriptorFactory.cpp descriptor/AbstractDescriptorFactory.h)

set(CMAKE_PREFIX_PATH "C:\\Qt\\6.2.0\\mingw81_64\\")


if (NOT CMAKE_PREFIX_PATH)
    message(WARNING "CMAKE_PREFIX_PATH is not defined, you may need to set it ")
endif ()


find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})
