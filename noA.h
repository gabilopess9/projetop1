#ifndef NO_H
#define NO_H

#include <string>
#include <stddef.h>

using namespace std;

class No {

private:
    No *esq, *dir;

public:
    No(string chave);
    ~No();
    string  getChave();
    No* getEsq();
    No* getDir();
    float* getinfo();
    void setEsq(No*);
    void setDir(No*);
    void setChave(string chave);
    void setInfo(float* data);

    string chave;

};
#endif
