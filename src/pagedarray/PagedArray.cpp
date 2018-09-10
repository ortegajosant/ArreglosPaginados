//
// Created by ortegajosant on 03/09/18.
//

#include "PagedArray.h"
#include <iostream>

using namespace std;

int &PagedArray::operator[](int indice) {
    if (indice < totalIndex) {
        if (pagesOnMemory < 6) {
            for (int i = 0; i < pagesOnMemory; i++) {
                if (memory[i].firstPos <= indice && indice <= memory[i].lastPos) {
                    memory[i].uses++;
                    return memory[i].array[indice - ((indice / 256) * 256)];
                }
            }
            emptySlots(indice);
            return memory[pagesOnMemory - 1].array[indice - ((indice / 256) * 256)];
        } else {
            for (int i = 0; i <= pagesOnMemory; i++) {
                if (memory[i].firstPos <= indice && indice <= memory[i].lastPos) {
                    memory[i].uses++;
                    cout << memory[i].firstPos << " " << memory[i].lastPos << " Num de pagina: " << memory[i].numPag
                         << endl;
                    return memory[i].array[indice - ((indice / 256) * 256)];
                }
            }
            LRU(indice);
            return this->operator[](indice);
        }
    } else {
        cout << "Digite un indice válido" << endl;
    }
}


PagedArray::PagedArray(string nombreTxt) {
    this->iniciarBin(nombreTxt);
    fstream binario;
    binario.open("../Files/binario.bin", ios::in | ios::binary);
    binario.seekg(0, ios::end);
    this->totalIndex = binario.tellg() / 4;
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
        return true;
    } else {
        return false;
    }
}

void PagedArray::upload(int *arrayTemp, int indice) {

    bin = fopen("../Files/binario.bin", "rb");


    if (bin != NULL) {
        int numPag = indice / 256;
        int cont = 0;
        while (numPag <= this->totalIndex / 256) {
            fread(arrayTemp, sizeof(int), 256, bin);
            if (cont == numPag) {
                break;
            }
            cont++;
        }
    } else {
        cout << "No se encuentra el .bin" << endl;
    }
}

void PagedArray::emptySlots(int indice) {
    this->memory[pagesOnMemory].array = (int *) calloc(sizeof(int), 256);
    this->upload(this->memory[pagesOnMemory].array, indice);
    //
    this->memory[pagesOnMemory].firstPos = ((indice / 256) * 256);
    this->memory[pagesOnMemory].lastPos = this->memory[pagesOnMemory].firstPos + 255;
    memory[pagesOnMemory].numPag = indice / 256;
    cout << memory[pagesOnMemory].firstPos << " " << memory[pagesOnMemory].lastPos << " Num de pagina: "
         << memory[pagesOnMemory].numPag << endl;
    pagesOnMemory++;
}

void PagedArray::LRU(int indice) {
    int numberUses = memory[0].uses;
    int cont = 0;
    for (int i = 0; i < pagesOnMemory; i++) {
        if (numberUses > memory[i].uses) {
            cont = i;
            numberUses = memory[i].uses;
        }
        memory[i].uses = 0;
    }
    cout << "cont: " << cont << endl;
    //descarga
    this->upload(memory[cont].array, indice);
    memory[cont].numPag = indice / 256;
    memory[cont].firstPos = (indice / 256) * 256;
    memory[cont].lastPos = (indice / 256) * 256 + 255;
}
