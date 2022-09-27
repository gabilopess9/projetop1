#include "noA.h"

No::No(string chave) {
    this->chave = chave;
    esq = nullptr;
    dir = nullptr;
}

No::~No(){
}

string No::getChave() {
    return chave;
}

No* No::getEsq() {
    return esq;
}

No* No::getDir() {
    return dir;
}


void No::setEsq(No *no) {
    esq = no;
}

void No::setDir(No *no) {
    dir = no;
}   

void No::setChave(string chave) {
    this->chave=chave; 
};

