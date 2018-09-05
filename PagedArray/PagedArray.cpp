//
// Created by ortegajosant on 03/09/18.
//

#include "PagedArray.h"
#include <iostream>
using namespace std;

int PagedArray::operator[](int number) {
    if (number >= 0 && number < 10) {
        cout << "Posición  "<< number << endl;
        return this->page1[number];
    }else {
        cout << "Posición incorrecta:  "<< number << endl;
        return 0;
    };
}



void PagedArray::setArray() {

}

PagedArray::PagedArray(int a) {
    this->page1[0] = 0;
    this->page1[1] = 1;
    this->page1[2] = 2;
    this->page1[3] = 3;
    this->page1[4] = 4;
    this->page1[5] = 5;
    this->page1[6] = 6;
    this->page1[7] = 7;
    this->page1[8] = 8;
    this->page1[9] = 9;

}
