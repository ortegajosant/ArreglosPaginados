//
// Created by ortegajosant on 03/09/18.
//

#include "PagedArray.h"
#include <iostream>

using namespace std;

int &PagedArray::operator[](long indice) {
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
//                    cout << memory[i].firstPos << " " << memory[i].lastPos << " Num de pagina: " << memory[i].numPag
//                         << endl;
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
}

bool PagedArray::iniciarBin(string nombreTxt) {

    ifstream read;

    int numPag = 0;

    string nombrePagina = "../Files/binario/binario" + to_string(numPag) + ".bin";

    char caracter;

    read.open("../Files/" + nombreTxt);

    int array[256];
    int cont = 0;
    FILE *binario;

    if (!read.fail()) {
        read.get(caracter);
        string numero = "";
        while (!read.eof()) {
            if (caracter == ',') {
                array[cont] = atoi(numero.c_str());
                numero = "";
                read.get(caracter);
                cont++;
            }
            if (cont == 256) {
                cont = 0;
                binario = fopen(nombrePagina.c_str(), "wb");
                numPag++;
                nombrePagina = "../Files/binario/binario" + to_string(numPag) + ".bin";
                fwrite(array, sizeof(int), 256, binario);
                fclose(binario);
            }
            numero += caracter;
            read.get(caracter);
        }
        array[cont] = atoi(numero.c_str());
        binario = fopen(nombrePagina.c_str(), "wb");
        nombrePagina = "../Files/binario/binario" + to_string(numPag) + ".bin";
        fwrite(array, sizeof(int), 256, binario);

        fclose(binario);
        read.close();
        numPag++;
        totalIndex = numPag * 256;
        cout<<totalIndex<<endl;
        return true;
    } else {
        return false;
    }
}

void PagedArray::upload(int *arrayTemp, int indice) {
    int numPag = indice / 256;
    string paginaActual = ("../Files/binario/binario" + to_string(numPag) + ".bin");
    bin = fopen(paginaActual.c_str(), "rb");
    if (bin != NULL) {
        fread(arrayTemp, sizeof(int), 256, bin);
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
//    cout << memory[pagesOnMemory].firstPos << " " << memory[pagesOnMemory].lastPos << " Num de pagina: "
//         << memory[pagesOnMemory].numPag << endl;
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

    //descarga
    this->download(memory[cont].array, memory[cont].numPag);
    this->upload(memory[cont].array, indice);
    memory[cont].numPag = indice / 256;
    memory[cont].firstPos = (indice / 256) * 256;
    memory[cont].lastPos = (indice / 256) * 256 + 255;
}

void PagedArray::download(int * array, int numPag) {
    FILE *binarioTemp;
    string paginaActual = "../Files/binario/binario" + to_string(numPag) + ".bin";
    binarioTemp = fopen(paginaActual.c_str(), "wb");
    fwrite(array, sizeof(int), 256, binarioTemp);
    fclose(binarioTemp);
}

long PagedArray::getTotalIndex() const {
    return totalIndex;
}

void PagedArray::guardarNuevoTxt() {

    ofstream fs("../Files/ordenado.txt");
    string resultado = "";

    for (int i = 0; i < this->pagesOnMemory; i++) {
        download(memory[i].array, memory[i].numPag);
    }

    for (int i = 0; i < totalIndex; i++) {
        if(i == totalIndex - 1) {
            resultado += to_string(this->operator[](i));
        }
        else {
            resultado += to_string(this->operator[](i)) + ",";
        }
    }

    fs<<resultado<<endl;

}
