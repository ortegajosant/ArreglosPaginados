#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "src/pagedarray/PagedArray.h"

using namespace std;

int main() {
//    srand(time(NULL));
//
//    int num;
//
//    string dato = "";
//
//    for (int i = 0; i < 1024; i++) {
//        if (i != 1023) {
//            dato += to_string(rand() % 5000) + ",";
//        } else {
//            dato += to_string(rand() % 5000);
//        }
//    }
//
//    ofstream fs("../Files/numeros1kb.txt");
//    fs << dato << endl;
//    fs.close();
//    cout << "El archivo ha sido creado correctamente" << endl;
//    system("pause");

    // LEER NUMEROS DE TXT
    ifstream read;

    char caracter;
    FILE *binario;

    read.open("../Files/numeros1kb.txt");

    binario = fopen("../Files/binario.bin", "wb");


    int array[256];
    int cont = 0;
    if (!read.fail()) {
        read.get(caracter);
        string numero = "";
        while (!read.eof()) {
            if (caracter == ',') {
                array[cont] = atoi(numero.c_str());
                cout << numero << " " << atoi(numero.c_str()) << " " << array[cont] << endl;
                numero = "";
                read.get(caracter);
                cont++;
            }
            if (cont == 256) {
                cont = 0;
                fwrite(array, sizeof(int), sizeof(array), binario);
            }
            numero += caracter;
            read.get(caracter);
        }

    }
    fclose(binario);
    read.close();

}