//
// Created by andrew on 05/09/18.
//

#ifndef PAGEDARRAY_PAGEFAULTS_H
#define PAGEDARRAY_PAGEFAULTS_H

#include<bits/stdc++.h>

using namespace std;

struct Page{
    int *array = (int*) malloc(256* sizeof(int));
    int firstPos;
    int lastPos;
    int uses;
};

class PageFaults {

private:
    int pagesOnMemory = 0;
    Page * memory = (Page*) malloc(sizeof(Page) * 6);

public:
    void emptySlots(int indice);
    void upload(int * hola, int indice){};
    void LRU(int indice);
    int findPos(int indice);
};


#endif //PAGEDARRAY_PAGEFAULTS_H
