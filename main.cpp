#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#include "src/pagedarray/PageFaults.h"
using namespace std;



int main() {

    PageFaults pf;

    Page page1;
    Page page2;
    Page page3;
    Page page4;
    Page page5;
    Page page6;

    Page arrayPages[] = {page1, page2, page3, page4, page5, page6};

    int x = 0;

    while (x < 256) {
        page1.getArray()[x] += rand()%5000;
        x++;
    }

    int n = sizeof(page1.getArray())/ sizeof(page1.getArray()[0]);

    cout << pf.pageFaults(arrayPages, n);

    return 0;
}