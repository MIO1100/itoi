#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include "common/Filter.h"
#include "test/Lab2.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Lab2::test();
    return 0;
}
