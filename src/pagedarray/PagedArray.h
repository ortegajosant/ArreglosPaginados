//
// Created by ortegajosant on 03/09/18.
//


#ifndef ARREGLOSPAGINADOS_PAGEDARRAY_H
#define ARREGLOSPAGINADOS_PAGEDARRAY_H


#include <iostream>
#include <fstream>


class PagedArray {

public:
    PagedArray(int);

    int operator[](int number);

    bool iniciarBin(FILE *file);



private:
    int page1[256];
    int page2[256];
    int page3[256];
    int page4[256];
    int page5[256];
    int page6[256];
};

#endif //ARREGLOSPAGINADOS_PAGEDARRAY_H