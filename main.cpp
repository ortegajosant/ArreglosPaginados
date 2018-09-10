#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "src/pagedarray/PagedArray.h"
#include "src/Ordenamiento/Ordenamiento.h"

using namespace std;

int main() {

    PagedArray *pa = new PagedArray("numeros36kb.txt");

//    cout<<pa->operator[](0)<<endl;
//    cout<<pa->operator[](256)<<endl;
//    cout<<pa->operator[](512)<<endl;
//    cout<<pa->operator[](768)<<endl;
//    cout<<pa->operator[](1025)<<endl;
//    cout<<pa->operator[](2817)<<endl;//
//    cout<<pa->operator[](8960)<<endl;
//    cout<<pa->operator[](256)<<endl;

//    pa->operator[](256) = 3;
//    cout<<pa->operator[](256)<<endl;

    return 0;

}