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
        core/InputImage.cpp core/InputImage.h
        core/DoubleImage.cpp core/DoubleImage.h
        core/helper.h core/helper.cpp
        filter/FilterUtil.cpp filter/FilterUtil.h
        filter/Kernels.cpp filter/Kernels.h
        filter/border/IBorder.cpp filter/border/IBorder.h
        filter/border/Mirror.cpp filter/border/Mirror.h
        filter/border/Zero.cpp filter/border/Zero.h
        filter/border/Copy.cpp filter/border/Copy.h
        lab/Lab1.cpp lab/Lab1.h filter/border/Policies.cpp filter/border/Policies.h)

set(CMAKE_PREFIX_PATH "C:\\Qt\\6.2.0\\mingw81_64\\")

if (NOT CMAKE_PREFIX_PATH)
    message(WARNING "CMAKE_PREFIX_PATH is not defined, you may need to set it ")
endif ()

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})
