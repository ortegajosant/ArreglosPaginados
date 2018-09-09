//
// Created by andrew on 04/09/18.
//

#ifndef PAGEDARRAY_PAGE_H
#define PAGEDARRAY_PAGE_H


class Page {

private:
    int array[256];
    int firstPos;
    int lastPos;
    int uses;

public:
    int getFirstPos() const;

    int getLastPos() const;

    int getValor(int pos);

    int getUses() const;

    void setUses(int uses);

    int * getArray();

};


#endif //PAGEDARRAY_PAGE_H
