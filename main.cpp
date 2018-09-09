#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "src/pagedarray/PagedArray.h"

using namespace std;

int main() {

    PagedArray *pa = new PagedArray("numeros36kb.txt");


    cout<<pa->findPos(0)<<endl;
    cout<<pa->findPos(1000)<<endl;
    cout<<pa->findPos(999)<<endl;
    cout<<pa->findPos(9000)<<endl;
//    cout<<pa->findPos(5000)<<endl;
//    cout<<pa->findPos(6000)<<endl;
//    cout<<pa->findPos(500)<<endl;

}