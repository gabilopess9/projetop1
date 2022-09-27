#include "bstA.h"

using namespace std;

int i=1;

ArvoreBST::ArvoreBST() {
    raiz = nullptr;
}

void ArvoreBST::setRaiz(No* root){
        raiz = root;
    }

void ArvoreBST::insereElemento(string chave) {
    if (raiz == nullptr)                                  
        raiz = new No(chave);                              
    else insereAux(raiz, chave);
}

void ArvoreBST::insereAux(No *no, string chave) {
    if (chave < no->getChave()) {                           
        if (no->getEsq() == nullptr) {                      
            No *novo_no = new No(chave);
            no->setEsq(novo_no);                            
        } else {
            insereAux(no->getEsq(), chave);                 
        }
    } else if (chave > no->getChave()) {                   
        if (no->getDir() == nullptr) {                      
            No *novo_no = new No(chave);
            no->setDir(novo_no);                            
        } else {
            insereAux(no->getDir(), chave);                 
        }
    }     
}

No *ArvoreBST::getRaiz() {
    return raiz;
}

void ArvoreBST::emOrdem(No *no) {
    if (no != nullptr) 
    {
        emOrdem(no->getEsq());
        cout <<i<<"-"<<no->getChave() << "\n";
        i++;
        emOrdem(no->getDir());
    }
}


void ArvoreBST::preOrdem(No *no) {
    if (no != nullptr) {
        cout << no->getChave() << " ";
        preOrdem(no->getEsq());
        preOrdem(no->getDir());
    }
}

void ArvoreBST::posOrdem(No *no) {
    if (no != nullptr) {
        posOrdem(no->getEsq());
        posOrdem(no->getDir());
        cout << no->getChave() << " ";
    }
}

No *ArvoreBST::pesquisarRec(No *no, string chave) {
    if (no == nullptr || no->getChave() == chave) return no;                                                           
    else if (no->getChave() > chave) {                             
        return pesquisarRec(no->getEsq(), chave);            
    } 
	else {
        return pesquisarRec(no->getDir(), chave);             
    }
}

No *ArvoreBST::pesquisarIter(No *no, string chave){
	if (raiz==nullptr) return nullptr;
	No* atual= no;
	while (atual->getChave()!=chave){
		if (chave < atual->getChave()) 
			atual = atual->getEsq();
		else
			atual= atual->getDir();
		if (atual==nullptr)
			return nullptr;
			
	}
	return atual;
}

int ArvoreBST::qdeNos(No *no) {
    if (no == nullptr) return 0;                                                                    
    else return (1 + qdeNos(no->getEsq()) + qdeNos(no->getDir()));                
}


int ArvoreBST::alturaBST(No *no) {
    if (no == nullptr) return -1;                                                                 
    else {
        if (no->getEsq() == nullptr && no->getDir() == nullptr)
            return 0;                                          
        else {
            if (alturaBST(no->getEsq()) >
                alturaBST(no->getDir()))         
                return (1 + alturaBST(no->getEsq()));
            else
                return (1 + alturaBST(no->getDir()));
        }
    }
}



//recursivo
No* ArvoreBST::findMin(No* t)
    {
    if(t == NULL)
        return NULL;
    else if(t->getEsq() == NULL)
        return t;
    else
        return findMin(t->getEsq());
}

	//recursivo
No* ArvoreBST::findMax(No* t) {
    if(t == NULL)
        return NULL;
    else if(t->getDir() == NULL)
        return t;
    else
        return findMax(t->getDir());
}

int ArvoreBST::folhas(No *no) {
    if (no != nullptr){
    	if (no->getEsq() == nullptr && no->getDir() == nullptr){
    		cout<<no->getChave() << " ";
		}
		folhas(no->getEsq());
		folhas(no->getDir());
	}
    
}

bool ArvoreBST::removerFolha(string chave) {
    if (raiz == nullptr) return false;                                                      
    No *anda = raiz;
    No *ant = raiz; 
	bool temFilhoEsq = true;                                           
    while (anda->getChave() != chave) {                                       
        ant = anda;
        if (chave < anda->getChave()) {                                                
            anda = anda->getEsq();
            temFilhoEsq = true;
        } else {                                                                         
            anda = anda->getDir();
            temFilhoEsq = false;
        }                        
    }
    
 	if (anda->getEsq() == nullptr && anda->getDir() == nullptr) {
        if (anda == raiz) raiz = nullptr;
        else if (temFilhoEsq)
            ant->setEsq(nullptr);
        else
            ant->setDir(nullptr);                                                               
    }
    
    else{
    	return false;
	}
	return true;
}



No *ArvoreBST::excluir(No* t, string key){
        
        //Arvore t ? vazia
        if (t == nullptr) 
            return t;
        
        if (key < t->getChave())
            t->setEsq(excluir(t->getEsq(),key));
        else
            if (key > t->getChave())
                t->setDir(excluir(t->getDir(),key));
        
        //encontramos o n? a ser removido
        else{ 
            //Caso1: o no a ser excluido nao tem filhos
            if (t->getEsq() == nullptr and t->getDir() == nullptr){
            	delete(t);
                return nullptr; //faz o pai apontar para NULL e o n? n?o faz mais parte da BST	
			}            	
            else 
                //Caso2: tem apenas um filho, a esquerda ou a direita
                if (t->getEsq() == nullptr){
                    No* temp = t->getDir();
                    delete(t);
                    return temp; //Faz o pai apontar para o ?nico filho do n?
                }
                else 
                    if  (t->getDir() == nullptr){
                        No* temp = t->getEsq();
                        delete(t);
                        return temp; //Faz o pai apontar para o ?nico filho do n?
                    }
            
            //Caso3: o no a ser excluido tem 2 filhos. Vamos escolher o menor dos maiores
            //para substituir o no que sera removido. Sucessor = menor no na sub-arvore da direita
            
            No* temp = findMin(t->getDir()); 
            
            //Copia a chave do sucessor para o no que esta sendo removido
            t->setChave(temp->getChave());
            
            //Remove da arvore o sucessor!
            t->setDir(excluir(t->getDir(),temp->getChave()));
        }
        
        //retorna a raiz da arvore
        return t;
        
}



