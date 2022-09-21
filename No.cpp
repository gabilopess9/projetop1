#include "No.h"

No::No(string chave, float* data){
    esq = NULL;
    dir = NULL;
    this->info = data;
    this->chave = chave;
    FB = 0;
}

No::~No(){
    //dtor
}

string No::getChave(){
    return chave;
}
// funcoes getters e setters
No* No::getEsq(){
    return esq;
}

No* No::getDir(){
    return dir;
}

float* No::getInfo(){
    return info;
}

int No::getFB(){
    return FB;
}

void No::setChave(string chave){
    this->chave = chave;
}

void No::setInfo(float* data){
    this->info = data;
}

void No::setEsq(No *no){
    esq = no;
}

void No::setDir(No *no){
    dir = no;
}
//FB = R - L
void No::setFB(int FB){
    this->FB = FB;
}
