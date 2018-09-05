//
// Created by andrew on 04/09/18.
//

#include "Page.h"

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
