#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include "PagedArray/PagedArray.h"
#include <stdio.h>

using namespace std;

int main() {
    // Código para generar número random
    srand(time(NULL));

    int num;

    string dato = "";

    for (int i = 0; i < 3200; i++) {
        if (i != 2999) {
            dato += to_string(rand() % 100) + ",";
        }
        dato += to_string(rand() % 100);
    }

    ofstream fs("../Files/numeros.txt");
    fs << dato << endl;
    fs.close();
    cout << "El archivo ha sido creado correctamente" << endl;
    system("pause");
}