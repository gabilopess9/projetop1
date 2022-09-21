ORE_H
#define ARVORE_H

#include "No.h"
#include <iostream>
#include <stddef.h>
#include <string>

class Arvore{
    private:
        No *raiz;
        int testaFB;

    public:
        Arvore();
        ~Arvore();
        No* RR(No* p);   //simple right rotation;
        No* LL(No* p);   //simple left rotation;
        No* LR(No* p);   //double right rotation, LL followed RR;
        No* RL(No* p);   //double left rotation, RR followed LL;
        int chaveMenorQueRaiz(string chave, No *root);
        int chaveMaiorQueRaiz(string chave, No *root);
        void inserir(No *no);
        No* inserir(No *root, No *no);
        No* Caso1(No *p);
        No* Caso2(No *p);
        No* getRaiz();
        No* pesquisar(string k);
        No* pesquisar(No* r, string k);
        int remover(string& chave);
        No* remover(No *p, string& chave);
        No* removerNo(No* p);
        No* remocaoPorCopia(No* p, No* prevTmp, No* tmp);
        void emOrdem();
        void emOrdem(No* no);
        void DesenhaArvore();
        void DesenhaArvore(No* node, int level, int* path);
        int qdeNos(No* atual);
        int altura(No* atual);
};

#endif // ARVORE_H
