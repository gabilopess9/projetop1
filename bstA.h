#include "noA.h"
#include <iostream>
#include <stddef.h>
#include <string>

using namespace std;

class ArvoreBST {

private:
    No *raiz;

public:
    ArvoreBST();

    No *getRaiz();

    void insereElemento(string chave);

    void insereAux(No *no, string chave);

    void emOrdem(No *no);

    void preOrdem(No *no);

    void posOrdem(No *no);
    
    No *pesquisarRec(No *no, string chave);
    
    No *pesquisarIter(No *no, string chave);
    
    int qdeNos(No *no);

    int alturaBST(No *no);
    
    int folhas(No *no);
    
    bool removerFolha(string chave);
    
    No *excluir(No* t, string key);
    
    No* findMax(No* t);
    
    No* findMin(No* t);
    
    void setRaiz(No* root);
    
};
