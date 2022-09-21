#include "Arvore.h"

#define SHIFT 10

using namespace std;

Arvore::Arvore(){
    raiz = NULL;
}

Arvore::~Arvore(){
    //dtor
}

No* Arvore::RR(No* p){   //Simple Right Rotation
    No* l = p->getEsq();  //l = p's left child;

    p->setFB(0);
    l->setFB(0);  //(There are exceptions: RL, LR)

    p->setEsq(l->getDir());
    l->setDir(p);
    p = l;
    return p;
}

No* Arvore::LL(No* p){  //Simple Left Rotation
    No* r = p->getDir();  //r = p's right child;

    p->setFB(0);
    r->setFB(0);  //(There are exceptions: RL, LR)

    p->setDir(r->getEsq());
    r->setEsq(p);
    p = r;
    return p;
}

No* Arvore::LR(No* p){   //Double Right Rotation
    No* l = p->getEsq();  //r = p's left child;
    No* v = l->getDir();  //v = l's right child;

    if( v->getFB() == 1 ){  //se hÃ¡ um nÃ³ a direita de v
        l->setFB(-1);
        p->setFB(1);
    }
    else if( v->getFB() == -1 ){  //se hÃ¡ um nÃ³ a esquerda de v
        l->setFB(0);
        p->setFB(1);
    }
    else{   //( v->getFB() == 0 ) //se nÃ£o hÃ¡ nÃ³ filho em v
        l->setFB(0);
        p->setFB(0);
    }
    v->setFB(0);

    l->setDir(v->getEsq());
    p->setEsq(v->getDir());
    v->setEsq(l);
    v->setDir(p);
    p = v;
    return p;
}

No* Arvore::RL(No* p){   //Double Left Rotation
    No* r = p->getDir();  //r = p's right child;
    No* y = r->getEsq();  //y = r's left child;

    if( y->getFB() == 1 ){  //se hÃ¡ um nÃ³ a direita de y
        r->setFB(0);
        p->setFB(-1);
    }
    else if( y->getFB() == -1 ){  //se hÃ¡ um nÃ³ a esquerda de y
        r->setFB(1);
        p->setFB(0);
    }
    else{   //( y->getFB() == 0 ) //se nÃ£o hÃ¡ nÃ³ filho em y
        r->setFB(0);
        p->setFB(0);
    }
    y->setFB(0);

    r->setEsq(y->getDir());
    p->setDir(y->getEsq());
    y->setEsq(p);
    y->setDir(r);
    p = y;
    return p;
}


int Arvore::chaveMenorQueRaiz(string chave, No *root){
    int Char = 0;
    string chaveR = root->getChave();

    while (Char <= chave.size() && Char <= chaveR.size()){
        if (chave[Char] < chaveR[Char]){
            return 1;
        }else if (chave[Char] > chaveR[Char]){
            return 0;
        }else if (chave[Char] == chaveR[Char]){
            Char++;
        }
    }
}

int Arvore::chaveMaiorQueRaiz(string chave, No *root){
    int val = chaveMenorQueRaiz(chave, root);
    return ( (val==1) ? (0) : (1) );
}

void Arvore::inserir(No *no){    // (..., vector<float> * info)
    raiz = inserir(raiz, no);
}

// insere recursivamente um novo no
No * Arvore::inserir(No *root, No *no){
    string chave = no->getChave();

    if( root == NULL ){
        //seta que alterou a subarvore e eh para testar o Fator de Balanceamento
        testaFB = 1;
        return no;
    }
    // se for menor, entao insere a esquerda
    if(chaveMenorQueRaiz(chave, root)){      //if(chave < root->getChave())

        //percorre recursivamente a subarvore da esquerda
        root->setEsq(inserir(root->getEsq(), no));

        // testa o fator de  balanceamento apos a insercao na subarvore da esquerda
        if( testaFB ){
            switch( root->getFB() ){
                case 1: // se o root estava maior para direita e inseriu a esquerda
                    root->setFB(0); // seta que agora ficou balanceado
                    testaFB=0; // tudo ficou normalizado, nao precisa atualizar mais a arvore
                    break;
                case 0:// se estava balanceado e como adicionou a esquerda
                    root->setFB(-1);
                    break;
                case -1: //ja estava desbalanceado para esquerda
                    root = Caso1( root );// root=p, vamos ver qual rotacao usar
                    testaFB=0; // tudo ficou normalizado, nao precisa atualizar mais a arvore
                    break;
            }
        }
    }
    // se for maior, entao insere a direita
    else if(chaveMaiorQueRaiz(chave, root)){    //if(chave > root->getChave())

        //percorre recursivamente a subarvore da direita
        root->setDir(inserir(root->getDir(), no));
        // testa o fator de  balanceamento apos a insercao na subarvore da direita
        if( testaFB ){
            switch( root->getFB() ){
                case -1: // se o root estava maior para esquerda e inseriu a direita
                    root->setFB(0); // seta que agora ficou balanceado
                    testaFB=0; // tudo ficou normalizado, nao precisa atualizar mais a arvore
                    break;
                case 0:// se estava balanceado e como adicionou a direita
                    root->setFB(1);
                    break;
                case 1: //ja estava desbalanceado para direita
                    root = Caso2( root );// root=p, vamos ver qual rotacao usar
                    testaFB=0; // tudo ficou normalizado, nao precisa atualizar mais a arvore
                    break;
            }
        }
    }
    // caso root->chave = chave retorna o proprio root
    // nao pode existir 2 chaves iguais
    return root;
}

//  metodo trata a insercao  na subarvore a esquerda de p
No * Arvore::Caso1( No *p ){
    No *l;

    // filho a esquerda de p
    l = p->getEsq();

    // inseriu na subarvore direita de l
    // fazer uma rotacao dupla a direita
    if( l->getFB() == 1 ){
        p = LR(p);
        // ajusta o novo balanceamento de p

        cout << " => realizada uma rotacao dupla a direita \n";
    }
    // inseriu na subarvore esquerda de l
    // fazer uma rotacao simples a direita
    else{
        p = RR(p);
        // ajusta o novo balanceamento de p
        // pois ele passa ser uma T1 - T2 = 0

        cout <<" => realizada uma rotacao simples a direita \n";
    }
    return p;
}

//  metodo trata a insercao  na subarvore a direita de p
No * Arvore::Caso2( No *p ){
    No *d;

    // filho a direita de p
    d = p->getDir();

    // inseriu na subarvore direita de d
    // fazer uma rotacao dupla a esquerda
    if( d->getFB() == -1){
        p = RL(p);
        // ajusto o novo balanceamento de p

        cout << " => realizada uma rotacao dupla a esquerda \n";
    }
      // inseriu na subarvore direita de d
    // fazer uma rotacao a esquerda
    else{
        p = LL(p);
        // ajusta o novo balanceamento de p
        // pois ele passa ser uma T1 - T2 = 0

        cout << " => realizada uma rotacao simples a esquerda \n";
    }
    return p;
}

No* Arvore::getRaiz(){
    return raiz;
}

No* Arvore::pesquisar(string k){
    return pesquisar(this->raiz, k);
}

No* Arvore::pesquisar(No* r, string k){
    if (r == NULL || r->getChave() == k)
        return r;
    else if (chaveMenorQueRaiz(k, r))
        return pesquisar(r->getEsq(), k);
    else
        return pesquisar(r->getDir(), k);
}


int Arvore::remover(string& chave){
    if( pesquisar(chave) == NULL )
        return -1;

    //cout << "Cheguei";
    raiz = remover(raiz, chave);
    return 1;
}

No* Arvore::remover(No* p, string& chave){
    //cout << "Cheguei";
    if( p->getChave() == chave ){
        p = removerNo(p);
        return p;
    }

    if( chaveMenorQueRaiz(chave, p) ){
        p->setEsq(remover(p->getEsq(), chave));

        if( testaFB ){
            switch( p->getFB() ){
                case 1:
                    if( p->getDir()->getFB() == 0){
                      p = Caso2( p );
                      p->setFB(-1);
                      this->testaFB=0;
                      p->getEsq()->setFB(1);
                    }
                    else{
                      p = Caso2( p );
                    }
                    break;
                case 0:
                    p->setFB(1);
                    this->testaFB=0;
                    break;
                case -1:
                    p->setFB(0);
                    break;
            }
        }

    }
    else if( chaveMaiorQueRaiz(chave, p) ){
        p->setDir(remover(p->getDir(), chave));

        if( testaFB ){
            switch( p->getFB() ){
                case 1:
                    p->setFB(0);
                    break;
                case 0:
                    p->setFB(-1);
                    this->testaFB=0;
                    break;
                case -1:
                    if( p->getEsq()->getFB() == 0){
                      p = Caso1( p );
                      p->setFB(1);
                      this->testaFB=0;
                      p->getDir()->setFB(-1);
                    }
                    else{
                      p = Caso1( p );
                    }
                    break;
              }
        }

    }
    return p;
}

No* Arvore::removerNo(No* p){
    No* delNode = p;

    if( p->getEsq() == NULL && p->getDir() == NULL){  //No folha
        p = NULL;
        this->testaFB=1;
        delete delNode;
    }
    else if( p->getEsq() == NULL ){  //No com 1 filho a dir
        p = p->getDir();
        this->testaFB=1;
        delete delNode;
    }
    else if( p->getDir() == NULL ){  //No com 1 filho a esq
        p = p->getEsq();
        this->testaFB=1;
        delete delNode;
    }
    else{   //No com 2 filhos
        //p->setFB(0);
        p = (remocaoPorCopia(p, p, p));   //Delete By Copy Method
    }
    return p;
}

No* Arvore::remocaoPorCopia(No* p, No* prevTmp, No* tmp){
    if( p == tmp ){
        p->setEsq( remocaoPorCopia(p, p, p->getEsq()) );

        if( testaFB ){
            switch( p->getFB() ){
                case 1:
                    if( p->getDir()->getFB() == 0){
                        p = Caso2( p );
                        p->setFB(-1);
                        this->testaFB=0;
                        p->getEsq()->setFB(1);
                    }else{
                        p = Caso2( p );
                    }
                    break;
                case 0:
                    p->setFB(1);
                    this->testaFB=0;
                    break;
                case -1:
                    p->setFB(0);
                    break;
            }
        }
        return p;
    }

    if( tmp->getDir() == NULL ){
        No* tmpLeftChild = tmp->getEsq();

        p->setChave(tmp->getChave());
        p->setInfo(tmp->getInfo());

        delete tmp;
        this->testaFB = 1;
        return tmpLeftChild;
    }
    else{ //( tmp->getDir() != NULL )
        tmp->setDir( remocaoPorCopia(p, tmp, tmp->getDir()) );

        if( testaFB ){
            switch( tmp->getFB() ){
                case 1:
                    tmp->setFB(0);
                    break;
                case 0:
                    tmp->setFB(-1);
                    this->testaFB=0;
                    break;
                case -1:
                    if( tmp->getEsq()->getFB() == 0){
                        tmp = Caso1( tmp );
                        tmp->setFB(1);
                        this->testaFB=0;
                        tmp->getDir()->setFB(-1);
                    }else{
                        tmp = Caso1( tmp );
                    }
                  break;
            }
        }
        return tmp;
    }
}


// polimorfismo de sobrecarga
void Arvore::emOrdem(){
    emOrdem(raiz);
}

// polimorfismo de sobrecarga
void Arvore::emOrdem(No* no){
    if(no != NULL){

        emOrdem(no->getEsq());
        cout << "\t" << no->getChave();
        cout << "\n";
        emOrdem(no->getDir());
    }
}

void Arvore::DesenhaArvore(){
    int height = altura(this->raiz);
    int *path = new int[height];
    DesenhaArvore(raiz, 0, path);
    delete[] path;
    path = NULL;
}

void Arvore::DesenhaArvore(No* node, int level, int* path){
    if(node != NULL){
        ////
        path[level] = 1;
        DesenhaArvore(node->getDir(), level+1, path);
        ////

        if (node == this->raiz){
            cout << "â”€â”€â”€â”€â”€ ";
        }else{
            int lastDirection = path[0];
            for (int i = 1; i < level; i++){
                for (int j = 0; j < SHIFT; j++)
                    cout << " ";

                if ( (path[i] != lastDirection) ){
                    cout << "â”‚";
                }else{
                    cout << " ";
                }
                lastDirection = path[i]; //
            }

            for (int j = 0; j < SHIFT; j++)
                cout << " ";

            if (path[level-1] == 1){ //goneToRight
                cout << "â”Œâ”€â”€â”€â”€ ";
            }else if (path[level-1] == 0){
                cout << "â””â”€â”€â”€â”€ ";
            }
        }

        //=======================================================
        cout << node->getChave() << "[" << node->getFB()<< "]\n";
        //=======================================================

        if (node == this->raiz){

            for (int j = 0; j < SHIFT; j++)
                cout << " ";
            cout << "â”‚\n";
        }
        else{

            int lastDirection = path[0];
            for (int i = 1; i < level; i++){
                for (int j = 0; j < SHIFT; j++)
                    cout << " ";

                if ( (path[i] != lastDirection) ){
                    cout << "â”‚";
                }else{
                    cout << " ";
                }
                lastDirection = path[i]; //
            }
            for (int j = 0; j < SHIFT; j++)
                cout << " ";
            //--
            if (path[level-1] == 1){  //goneToRight
                cout << "â”‚";
            }else if (path[level-1] == 0){
                cout << " ";
            }
            //--
            if (node->getEsq() != NULL){
                for (int j = 0; j < SHIFT; j++)
                    cout << " ";
                cout << "â”‚";
            }
            cout << "\n";
        }
        ////
        path[level] = 0;
        DesenhaArvore(node->getEsq(), level+1, path);
        ////
    }
}
/*
void Arvore::DesenhaArvore(No* no, int espacos ){
    if(no != NULL)
    {
        DesenhaArvore(no->getDir(), espacos + 4 );

        for(int i = 0 ; i < espacos; i++ )
            cout << " ";

        cout << no->getChave() << "[" << no->getFB()<< "]\n";

        DesenhaArvore(no->getEsq(), espacos + 4 );
    }
}
*/
// para visualizar a execucao acesse
// https://pythontutor.com/cpp.html#mode=edit

int Arvore::qdeNos(No* atual){
    if(atual == NULL)
        return 0;
    else
        return ( 1 + qdeNos(atual->getEsq()) + qdeNos(atual->getDir()) );
}

int Arvore::altura(No* atual){
    if (atual == NULL)
        return -1;
    else{
        if (atual->getEsq() == NULL && atual->getDir() == NULL)
            return 0;
        else{
            if (altura(atual->getEsq()) > altura(atual->getDir()))
                return ( 1 + altura(atual->getEsq()) );
            else
                return ( 1 + altura(atual->getDir()) );
        }
    }
}
