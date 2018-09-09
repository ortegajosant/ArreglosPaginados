#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "src/pagedarray/PagedArray.h"

using namespace std;

int main() {

    PagedArray *pa = new PagedArray("numeros36kb.txt");

//    pa.


    cout<<pa->findPos(0)<<endl; // 1
    cout<<pa->findPos(1000)<<endl; // 2
    cout<<pa->findPos(3000)<<endl; // 3
    cout<<pa->findPos(9000)<<endl; // 4
    cout<<pa->findPos(750)<<endl; // 5
    cout<<pa->findPos(8000)<<endl; // 6
    cout<<pa->findPos(9000)<<endl;
//    cout<<pa->findPos(300)<<endl;
//    cout<<pa->findPos(8000)<<endl;
    cout<<pa->findPos(3000)<<endl;
//    cout<<pa->findPos(3001)<<endl;

}