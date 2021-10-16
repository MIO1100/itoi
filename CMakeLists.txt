cmake_minimum_required(VERSION 3.19)
project(itoi)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QT_VERSION 5)
set(REQUIRED_LIBS Core Gui Widgets)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Gui Qt5::Widgets)

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
        octave/OctaveFactory.cpp octave/OctaveFactory.h
        octave/Element.cpp octave/Element.h
        octave/Octave.cpp octave/Octave.h
        point/Point.cpp point/Point.h
        point/AbstractInterestPointsAlgo.cpp point/AbstractInterestPointsAlgo.h
        point/Moravec.cpp point/Moravec.h
        point/Harris.cpp point/Harris.h
        test/Lab3.cpp test/Lab3.h
        point/Drawer.cpp point/Drawer.h
 common/AbstractImg.cpp common/AbstractImg.h)

set(CMAKE_PREFIX_PATH "C:\\Qt\\6.2.0\\mingw81_64\\")

if (NOT CMAKE_PREFIX_PATH)
    message(WARNING "CMAKE_PREFIX_PATH is not defined, you may need to set it ")
endif ()

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})
