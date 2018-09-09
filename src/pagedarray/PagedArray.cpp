//
// Created by ortegajosant on 03/09/18.
//

#include "PagedArray.h"
#include <iostream>

using namespace std;

int PagedArray::operator[](int number) {
    return 0;
}

PagedArray::PagedArray(string nombreTxt) {
    this->iniciarBin(nombreTxt);
    fstream binario;
    binario.open("../Files/binario.bin", ios::in | ios::binary);
    binario.seekg(0, ios::end);
    this->totalIndex = binario.tellg() / 4;
    cout << "por favor total: " << this->totalIndex << endl;
    binario.close();
}

bool PagedArray::iniciarBin(string nombreTxt) {

    ifstream read;

    char caracter;

    read.open("../Files/" + nombreTxt);

    int array[256];
    int cont = 0;
    if (!read.fail()) {
        read.get(caracter);
        string numero = "";
        FILE *binario;
        binario = fopen("../Files/binario.bin", "wb");
        while (!read.eof()) {
            if (caracter == ',') {
                array[cont] = atoi(numero.c_str());
                numero = "";
                read.get(caracter);
                cont++;
            }
            if (cont == 256) {
                cont = 0;
                fwrite(array, sizeof(int), 256, binario);
            }
            numero += caracter;
            read.get(caracter);
        }
        array[cont] = atoi(numero.c_str());
        fwrite(array, sizeof(int), 256, binario);

        fclose(binario);
        read.close();
        free(binario);
        return true;
    } else {
        return false;
    }
}

int* PagedArray::upload(int indice) {
    FILE *bin;

    bin = fopen("../Files/binario.bin", "rb");

    int *arrayTemp = new (int);

    if (bin != NULL) {
        int numPag = indice / 256;
        cout << "numero de página: " << numPag << endl;
        int cont = 0;
        while (numPag <= this->totalIndex/256) {
            fread(arrayTemp, sizeof(int), 256, bin);
            if (cont == numPag) {
//                for (int i = 0; i < 256; i++) {
//                    cout << arrayTemp[i] << endl;
//                }
                return arrayTemp;
            }
            cont++;
        }
    } else {
        cout << "NO";
    }
    fclose(bin);
}
