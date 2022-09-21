 Nome:  Gabriela Lopes
 TIA:   31744591

 Nome:  
 TIA:   
******************************************** */

#include "No.h"
#include "Arvore.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <locale>                                                       // std::locale, std::tolower
#include <iomanip>
#include <list>
#include <algorithm>

#include <iterator>

#define LENGTH_SPACE_NUM 5
#define LENGTH_SPACE_STR 15
#define LONGER_WORD_LENGTH 14

using namespace std;

void toCaptalize(string& words){
    locale loc;
    string prevChar = " ";

    for (string::size_type i=0; i < words.length(); ++i){
        if (prevChar == " "){
            words[i] = toupper(words[i], loc);
            prevChar = words[i];
            continue;
        }
        words[i] = tolower(words[i], loc);
        prevChar = words[i];
    }
}

string demangle( const char* name ) { return name ; }

template <class T>
string formatString(T type, const int lengthEspace){   //(string& type, const int lengthEspace)
    stringstream convertType;
    stringstream newStr;

    convertType << type;
    newStr << setw(lengthEspace);
    //newStr << setfill('-');
    //newStr.presicion(4);
    if (demangle( typeid(type).name() ) == "f"){
        newStr << right;
    }else{
        newStr << left;
    }
    newStr << convertType.str();
    return newStr.str();
}

int countColumns(string& fileName){
    ifstream file;

    string line = "";
    string word;
    //size_t columns;
    int columns;

    file.open(fileName, ios::in);

    getline(file, line);
    getline(file, line);                            //take the second line

    columns = count(line.begin(), line.end(), ';'); //delimeter: ";"

    file.close();
    return columns+1;
}

string getHeader(string &fileName, int columns){
    stringstream header;

    ifstream file;
    string line = "";
    string word;

    file.open(fileName, ios::in);

    getline(file, line);
    stringstream ss(line);

    for (int col = 0; col < columns; col++){

        getline(ss, word, ';');                      //delimeter == ';'
        header << word << " | " ;
        //cout << word << "\n"; //
    }
    header << "\n";
    file.close();
    return header.str();
}

void insertCSVDataIntoAVLTree(string &fileName, int columns, Arvore* AVLTree){//(...,int columns,...)

    ifstream file;

    string line = "";
    string word;
    string food;
    float numFloat;
    bool firstLine = true;
    bool firstColumn = true;
    //string::size_type sz;

    file.open(fileName, ios::in);
    if(!file.is_open()){
        cout << "\n" <<"File not readable or not found!" << "\n";
        cout << "\n" <<"Press 5!" << "\n";
        return;
    }

    while (!file.eof()){

        if (firstLine){
            getline(file, line);
            firstLine = false;
            continue;
        }
        float* row = new float[columns-1];               //4bytes cada float

        getline(file, line);
        if (line == "")
            break;

        stringstream s(line);
        stringstream ss;

        firstColumn = true;
        for (int col = 0; col < columns; col++){

            if (firstColumn){
                getline(s, word, ';');                  //delimeter == ';'
                food = word;
                //--> --> --> cout << food << "\n";
                firstColumn = false;
                continue;           //resolveu TUDO
            }
            getline(s, word, ';');                      //delimeter == ';'
            ss << word;

            //row[col] = stof(word, &sz);               //stof = String to Float
            ss >> numFloat;
            row[col-1] = numFloat;                      //skip the first column: row[col-1]

            ss.clear();
            ss.str();
        }
        No *no = new No(food, &row[0]);
        AVLTree->inserir(no);
    }
    file.close();
}
struct meal_t{
    string food;
    float amount;
};

void displayMealList(list<struct meal_t>& mealList, Arvore* AVLTree, int columns){
    list<struct meal_t>::iterator it;
    No *nodePointer;
    string food;
    float amount;
    float *data;
    float *total = new float[columns-1];

    for (int index = 0; index < columns-1; index++){    //fill alocated memory
        total[index] = 0.0;
    }

    for (it = mealList.begin(); it != mealList.end(); ++it){
        food = it->food;
        amount = it->amount;
        nodePointer = AVLTree->pesquisar(food);

        cout << "|" << formatString<string>(food, LENGTH_SPACE_STR);

        for (int index = 0; index < columns-1; index++){
            data = nodePointer->getInfo();
            cout << "|" << formatString<float>(data[index]*amount, LENGTH_SPACE_NUM);
            total[index] += (data[index] * amount);
        }
        cout << "|\n";
    }

    cout << "|" << formatString<string>("Total", LENGTH_SPACE_STR);
    for (int index = 0; index < columns-1; index++){
        cout << "|" << formatString<float>(total[index], LENGTH_SPACE_NUM);
    }
    cout << "|\n";

    delete[] total;
    total = NULL;
}

void InOrder(No* p, stringstream& ss, int columns){
    if (p != NULL){

        InOrder(p->getEsq(), ss, columns);

        ss << p->getChave() << ";";
        float* data = p->getInfo();
        for (int i = 0; i < columns-1; i++){
            ss << data[i] << ";";
        }
        ss << "\n";

        InOrder(p->getDir(), ss, columns);
    }
}

//adicionar funÃ§Ã£o soma valores de vetor recebe o no
//void (float amount, string food){}

int main(int argc, char *argv[]){

    string fileName = "./fileName.csv";
    const int columns = countColumns(fileName);
    const string header = getHeader(fileName, columns);
    string headerCSV = header;
    replace(headerCSV.begin(), headerCSV.end(), '|', ';');
    cout << columns << "\n";
    Arvore AVLTree;

    insertCSVDataIntoAVLTree(fileName, columns, &AVLTree);

    // list<string> dieta;

    stringstream cardapio ;
    stringstream tabelaNutricional;

    int opcao;
    string food;
    float amount;
    bool repeatedFood;

    list<struct meal_t> mealList;
    meal_t userInput;


    do{
        cout<< "\n\n";
        cout<< "----INFORMACOES NUTRICIONAIS DA SUA DIETA----\n"
            << "|                                           |\n"
            << "|   1. Adicionar um alimento a lista        |\n"
            << "|   2. Imprimir Cardapio                    |\n"
            << "|   3. Imprimir a dieta                     |\n"
            << "|   4. Remover item do Cardapio             |\n"
            << "|   5. Salvar AVLTree em backup             |\n"
            << "|   6. Altura e numero de nos               |\n"
            << "|   7. Sair do programa                     |\n"
            << "|                                           |\n"
            << "---------------------------------------------\n";

        cout<< "\n\n----Digite apenas numeros inteiros!----\n\n"
            << "OPCAO: ";
        cin >> opcao;

        cin.ignore();/* Mixing the two forms of input can cause problems:

        cin >> leaves the newline (from when the user hits <enter>)
         in the input stream and getline reads that and stops immediately.
        */

        switch(opcao) {
	 		case 1: {
          repeatedFood = false;

          //cin.ignore();
          cout << "Alimento: ";
          getline(cin, food);         //tentar: getline(cin, userInput.food)

          cout << "Quantidade(g): ";
          cin >> amount;
          cin.ignore();

          toCaptalize(food);
          cout << food << "\n";

          No* no = AVLTree.pesquisar(food);
          if (no == NULL){
              cout << "\n  --Alimento nao encontrado.--";
              cout << "\n  --Elemento desconsiderado!--";
              break;
          }
          cout << "\n  --Alimento: " << food << " encontrado.--";
          ////

          userInput.food = food;
          userInput.amount = amount;


          list<meal_t>::iterator it;
          //it = mealList.begin();

          for (it = mealList.begin(); it != mealList.end(); ++it){
              if (it->food == food){
                  it->amount = it->amount + amount;
                  repeatedFood = true;
                  break;
              }
          }

          if (!repeatedFood){
              mealList.push_back(userInput);
          }
          break;
			}
			case 2: {
          AVLTree.emOrdem();

          break;
			}
			case 3: {
			    cout << header;
			    cout << "\n\n";
			    displayMealList(mealList, &AVLTree, columns);
			    break;
			}
      case 4: {
          cout << "\nDigite um alimento a ser excluido: " ;
          getline(cin, food);
          //cin.ignore();
          //cin.ignore();
          toCaptalize(food);
          No* node = AVLTree.pesquisar(food);
          if (node == NULL){
              cout << "\nAlimento " << food << " não existe!";
              break;
          }
          AVLTree.remover(food);
          cout <<"\n"<< food << " removido!\n";
          break;
      }
			case 5: {
          ofstream fout("BackupFile.csv");
          stringstream ss;

          //cout <<"\n"<< headerCSV<< "fim"<<"\n";
          cout << "\n" << "Backup salvo!";

          InOrder(AVLTree.getRaiz(), ss, columns);
          fout << headerCSV;
          fout << ss.str();
          fout.close();
          break;
			}
			case 6: {
          int alt, qnos;
          alt = AVLTree.altura(AVLTree.getRaiz());
          cout << "Altura: " << alt << endl;
          qnos = AVLTree.qdeNos(AVLTree.getRaiz());
          cout << "Quandade de nos: " << qnos << endl;
          AVLTree.DesenhaArvore();
          break;
			}
      case 7:{
          cout << "\n Finalizando programa!";
          break;
      }
			/*case 8: {
                cout << "\n Exibindo floats do nÃ³ Apple: \n";
                No* nodePointer;
                float * floatPointer;
                nodePointer = AVLTree.pesquisar("Apple");
                cout << nodePointer->getChave() << "\n";
                floatPointer = nodePointer->getInfo();
                for (int i = 0; i < columns-1; i++)
                    cout << " | " << floatPointer[i];
			}*/
            /*
			default:
			    if (opcao != 5)
                    cout << "\n Opcao invalida! \n\n\n";
             // fim switch*/
        }
    } while(opcao != 7);


	return 0;
}
//comentario
