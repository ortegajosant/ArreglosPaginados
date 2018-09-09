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
using namespace std;

struct Page{
    int *array = (int*) malloc(256* sizeof(int));
    int firstPos;
    int lastPos;
    int uses;
};

class PagedArray {

public:
    PagedArray(string);

    int operator[](int number);

    bool iniciarBin(string nombreTxt);

    int* upload(int);

    void emptySlots(int indice);

    void LRU(int indice);

    int findPos(int indice);

    FILE * bin;

private:
    int pagesOnMemory = 0;
    Page * memory = (Page*) malloc(sizeof(Page) * 6);
    long totalIndex = 0;

};

#endif //ARREGLOSPAGINADOS_PAGEDARRAY_H