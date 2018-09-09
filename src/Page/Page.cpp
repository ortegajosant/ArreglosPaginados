//
// Created by andrew on 04/09/18.
//

#include "Page.h"
#include<random>


int Page::getFirstPos() const {
    return firstPos;
}

int Page::getLastPos() const {
    return lastPos;
}

int Page::getValor(int pos) {

    while(pos>256){
        pos -= 256;
    }

    return this->array[pos];
}


int * Page::getArray(){
    return this->array;
}

void Page::setUses(int uses) {
    Page::uses = uses;
}

int Page::getUses() const {
    return uses;
}
