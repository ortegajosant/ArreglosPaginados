//
// Created by ortegajosant on 03/09/18.
//


#ifndef ARREGLOSPAGINADOS_PAGEDARRAY_H
#define ARREGLOSPAGINADOS_PAGEDARRAY_H


#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#define NULL 0
#include "../Page/Page.h"
using namespace std;

class PagedArray {

public:
    PagedArray(string);

    int operator[](int number);

    bool iniciarBin(string nombreTxt);

    void upload(int*, int);

private:
    long totalIndex;

};

#endif //ARREGLOSPAGINADOS_PAGEDARRAY_H