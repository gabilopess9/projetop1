#ifndef NO_H
#define NO_H

#include <stddef.h>
#include <string>

using namespace std;

class No{
    private:
        No *esq, *dir;
        float *info;
        string chave;
        int FB;

    public:
        No(string chave, float* data);
        ~No();
        string getChave();
        No* getEsq();
        No* getDir();
        float* getInfo();
        int getFB();
        void setChave(string chave);
        void setInfo(float* data);
        void setEsq(No *no);
        void setDir(No *no);
        void setFB(int FB);

};

#endif // NO_H
