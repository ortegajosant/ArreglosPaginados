//
// Created by andrew on 09/09/18.
//

#include <cstdio>
#include "Ordenamiento.h"
#include "../pagedarray/PagedArray.h"

void Ordenamiento::insertionSort(PagedArray memory){
    if(memory.getTotalIndex() > 1){
        long size = memory.getTotalIndex();
        for(long i = 1; i < size; ++i){
            long j = i - 1;
            int key = memory.operator[](i);
            while(j >= 0 && memory.operator[](j) > key){
                memory.operator[](j+1) = memory.operator[](j);;
                --j;
            }
            memory.operator[](j+1) = key;
        }
    }
}

void Ordenamiento::PrintArray(PagedArray memory) {
    for (int i = 0; i < memory.getTotalIndex(); ++i)
        std::cout << memory.operator[](i) << " " << std::flush;
    std::cout << std::endl;
}

