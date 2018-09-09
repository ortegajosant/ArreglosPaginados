//
// Created by andrew on 05/09/18.
//

#include "PageFaults.h"

void PageFaults::emptySlots(int indice) {
    Page *page = new Page();
    this->upload(page->array, indice);
    page->firstPos = (indice / 256) * 256;
    page->lastPos = page->firstPos + 255;
    this->memory[pagesOnMemory] = *page;
    pagesOnMemory ++;
}

void PageFaults::LRU(int indice) {
    int numberUses = -1;
    Page * sustituir = new Page();
    for(int i = 0; i <= pagesOnMemory; i++){
        if(numberUses > memory[i].uses){
            *sustituir = memory[i];
            numberUses = memory[i].uses;
        }
        memory[i].uses = 0;
    }
    this->upload(sustituir->array, indice);
    sustituir->firstPos = (indice / 256) * 256;
    sustituir->lastPos = sustituir->firstPos + 255;
}

int PageFaults::findPos(int indice) {
    if(indice<totalIndex) {
        for (int i = 0; i <= pagesOnMemory; i++) {
            if (memory[i].firstPos <= i <= memory[i].lastPos) {
                return memory[i].array[indice];
            }
        }
        LRU(indice);
        findPos(indice);
    }
}

