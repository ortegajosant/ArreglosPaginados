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
//        free(binario);
        return true;
    } else {
        return false;
    }
}

//bool PagedArray::iniciarBin(string nombreTxt) {
//
//    ifstream read;
//
//    char caracter;
//
//    read.open("../Files/" + nombreTxt);
//
//    int array[256];
//    int cont = 0;
//    if (!read.fail()) {
//        read.get(caracter);
//        string numero = "";
//        FILE *binario;
//
//        string pag;
//        pag = "1";
//
//        pag = "../Files/binario/binario.bin";
//
////        char pagi[] =  ;
//
//        binario = fopen(, "wb");
//        while (!read.eof()) {
//            if (caracter == ',') {
//                array[cont] = atoi(numero.c_str());
//                numero = "";
//                read.get(caracter);
//                cont++;
//            }
//            if (cont == 256) {
//                cont = 0;
//                fwrite(array, sizeof(int), 256, binario);
//            }
//            numero += caracter;
//            read.get(caracter);
//        }
//        array[cont] = atoi(numero.c_str());
//        fwrite(array, sizeof(int), 256, binario);
//
//        fclose(binario);
//        read.close();
////        free(binario);
//        return true;
//    } else {
//        return false;
//    }
//}

void PagedArray::upload(int *arrayTemp, int indice) {

    if (this->bin == NULL) {
        bin = fopen("../Files/binario.bin", "rb");
    }


//    arrayTemp = new(int);

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
        cout << "NO";
    }
//    fclose(bin);
//    free(bin);
}

void PagedArray::emptySlots(int indice) {
//    this->memory[pagesOnMemory].array = this->upload(indice);
//    Page * pag = new Page();
//    this->memory[pagesOnMemory] = pag;
//    this->(memory+pagesOnMemory).array = (int*) calloc(sizeof(int), 256);
    this->memory[pagesOnMemory].array = (int*) calloc(sizeof(int), 256);
    this->upload(this->memory[pagesOnMemory].array, indice);
    this->memory[pagesOnMemory].firstPos = ((indice / 256) * 256);
    this->memory[pagesOnMemory].lastPos = this->memory[pagesOnMemory].firstPos + 255;
    cout<<memory[pagesOnMemory].firstPos<<" "<<memory[pagesOnMemory].lastPos<<endl;
    this->memory[pagesOnMemory].uses++;
    pagesOnMemory++;
}

void PagedArray::LRU(int indice) {
    int numberUses = 0;
    Page *sustituir;
    cout << "Entré";
    for (int i = 0; i <= pagesOnMemory; i++) {
        if (numberUses >= memory[i].uses) {
            *sustituir = memory[i];
            numberUses = memory[i].uses;
        }
        memory[i].uses = 0;
    }
//    sustituir->array = this->upload(indice);
    this->upload(sustituir->array, indice);
    sustituir->firstPos = (indice / 256) * 256;
    sustituir->lastPos = (indice / 256) * 256 + 255;
    sustituir->uses++;
}

int PagedArray::findPos(int indice) {
    if (indice < totalIndex) {
        if (pagesOnMemory < 6) {
            for (int i = 0; i < pagesOnMemory; i++) {
                if (memory[i].firstPos <= indice && indice <= memory[i].lastPos) {
                    cout << pagesOnMemory << endl;
                    memory[i].uses++;
                    return memory[i].array[indice - ((indice / 256) * 256)];
                }
            }
            emptySlots(indice);
            cout << pagesOnMemory << endl;
            return memory[pagesOnMemory - 1].array[indice - ((indice / 256) * 256)];
        } else {
            for (int i = 0; i <= pagesOnMemory; i++) {
                if (memory[i].firstPos <= indice && indice <= memory[i].lastPos) {
                    memory[i].uses++;;
                    cout << pagesOnMemory << endl;
                    return memory[i].array[indice - ((indice / 256) * 256)];
                }
            }
            LRU(indice);
            return findPos(indice);
        }
    }
}