#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "src/pagedarray/PagedArray.h"

using namespace std;

int main() {

    int * array = (int*) malloc(sizeof(int)*256);
    for (int i = 0; i < 256; i++) {
        array[i] = i*2;
    }

    for (int i=0; i < 256; i++) {
        cout<<array[i]<<endl;
    }

    cout<<array<<endl<<"--------------------\n"<<endl;

    PagedArray *page = new PagedArray("numeros1kb.txt");
    page->upload(array, 200);
    cout<<"\n"<<array<<endl;

}