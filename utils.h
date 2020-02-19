#ifndef UTILS_H
#define UTILS_H

#include <QDebug>
#define dbg qDebug()

struct Index {
    int r;
    int c;

    Index(int row = -1, int col = -1) : r(row), c(col) {}

    bool operator==(Index other){
        return r == other.r && c == other.c;
    }

    bool operator!=(Index other){
        return !(*this == other);
    }

    bool isValid(int maxRow, int maxCol){
        return r >= 0 && r < maxRow && c >= 0 && c < maxCol;
    }

    void print(){
        qDebug() << "row:" << r << ", col:" << c;
    }
};

#endif // UTILS_H
