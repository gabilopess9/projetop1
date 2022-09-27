#include "noA.cpp"
#include "bstA.cpp"
#include "Alimento.cpp"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <list>



using namespace std;

ArvoreBST arvorebst;
alimento alimentos[61];

void info(int n){
	
	cout<<"\n\nInformacoes gerais"<<"\n\n";
	cout<<"Calorias: "<<alimentos[n].get_Calorias()<<"\n";
	cout<<"Gorduras: "<<alimentos[n].get_Gorduras()<<"\n";
	cout<<"Gorduras Totais: "<<alimentos[n].get_GorduraT()<<"\n";
	cout<<"Sodio: "<<alimentos[n].get_Sodio()<<"\n";
	cout<<"Potassio: "<<alimentos[n].get_Potassio()<<"\n";
	cout<<"Carboidratos Totais: "<<alimentos[n].get_Carboidratos()<<"\n";
	cout<<"Fibra Alimentar: "<<alimentos[n].get_Fibra()<<"\n";
	cout<<"Acucares: "<<alimentos[n].get_Acucar()<<"\n";
	cout<<"Proteina: "<<alimentos[n].get_Proteina()<<"\n";
	cout<<"Vitamina A: "<<alimentos[n].get_VitaminaA()<<"\n";
	cout<<"Vitamina C: "<<alimentos[n].get_VitaminaC()<<"\n";
	cout<<"Calcio: "<<alimentos[n].get_Calcio()<<"\n";
	cout<<"Ferro: "<<alimentos[n].get_Ferro()<<"\n";
	cout<<"Gorduras Saturadas: "<<alimentos[n].get_GorduraS()<<"\n";
	cout<<"Colesterol: "<<alimentos[n].get_Colesterol()<<"\n";
	cout<<"Tipo de comida: "<<alimentos[n].get_Tipocomida()<<"\n";
}


void buscarInfo(){
	int numero;
	cout<<"=============TABELA NUTRICIONAL==============="<<"\n\n";
	arvorebst.emOrdem(arvorebst.getRaiz());
	cout<<"=============================================="<<"\n\n";
	cout<<"Digite um numero para obter as suas informacoes nutricionais (1-61):";
	cin>>numero;
	
	if(numero==1)
		info(39);
	if(numero==2)
		info(43);
	if(numero==3)
		info(15);
	if(numero==4)
		info(9);
	if(numero==5)
		info(29);
	if(numero==6)
		info(0);
	if(numero==7)
		info(60);
	if(numero==8)
		info(47);
	if(numero==9)
		info(19);
	if(numero==10)
		info(13);
	if(numero==11)
		info(42);
	if(numero==12)
		info(56);
	if(numero==13)
		info(2);
	if(numero==14)
		info(59);
	if(numero==15)
		info(52);
	if(numero==16)
		info(45);
	if(numero==17)
		info(12);
	if(numero==18)
		info(8);
	if(numero==19)
		info(41);
	if(numero==20)
		info(31);
	if(numero==21)
		info(11);
	if(numero==22)
		info(3);
	if(numero==23)
		info(6);
	if(numero==24)
		info(10);
	if(numero==25)
		info(22);
	if(numero==26)
		info(51);
	if(numero==27)
		info(26);
	if(numero==28)
		info(24);
	if(numero==29)
		info(23);
	if(numero==30)
		info(50);
	if(numero==31)
		info(48);
	if(numero==32)
		info(18);
	if(numero==33)
		info(33);
	if(numero==34)
		info(44);
	if(numero==35)
		info(20);
	if(numero==36)
		info(34);
	if(numero==37)
		info(16);
	if(numero==38)
		info(30);
	if(numero==39)
		info(25);
	if(numero==40)
		info(35);
	if(numero==41)
		info(49);
	if(numero==42)
		info(54);
	if(numero==43)
		info(53);
	if(numero==44)
		info(58);
	if(numero==45)
		info(46);
	if(numero==46)
		info(5);
	if(numero==47)
		info(28);
	if(numero==48)
		info(29);
	if(numero==49)
		info(1);
	if(numero==50)
		info(14);
	if(numero==51)
		info(7);
	if(numero==52)
		info(36);
	if(numero==53)
		info(37);
	if(numero==54)
		info(4);
	if(numero==55)
		info(32);
	if(numero==56)
		info(59);
	if(numero==57)
		info(17);
	if(numero==58)
		info(40);
	if(numero==59)
		info(55);
	if(numero==60)
		info(21);
	if(numero==61)
		info(38);
}

void lerDados(){
	ifstream file;

	string word;
    string food;
    string linha;
    float Cfloat;
    int quant=0;
    bool linha1=true;
    bool coluna1=true;
    
    
    
	file.open("nutricional.csv", ios::in);
	if(!file.is_open()){
		cout<<"Arquivo invalido"<<"\n";
	}
	
	while(!file.eof()){
		if(linha1){
			getline(file,linha);
			linha1=false;
			continue;
		}
	
	getline(file,linha);
	if(linha=="")
		break;
	
	stringstream s(linha);
	stringstream ss;
	
	coluna1=true;
	for (int col=0;col<16;col++){
		if(coluna1){
			getline(s,word,';');
			food=word;
			
			coluna1=false;
			continue;
		}
		
		if (col=1)
			getline(s,word,';');
			ss<<word;
			ss>>Cfloat;
			ss.clear();
            ss.str();
			alimentos[quant].set_Calorias(Cfloat);
		if (col=2)
			getline(s,word,';');
			ss<<word;
			ss>>Cfloat;
			ss.clear();
            ss.str();
			alimentos[quant].set_Gorduras(Cfloat);
		if (col=3)
			getline(s,word,';');
			ss<<word;
			ss>>Cfloat;
			ss.clear();
            ss.str();
			alimentos[quant].set_GorduraT(Cfloat);
		if (col=4)
			getline(s,word,';');
			ss<<word;
			ss>>Cfloat;
			ss.clear();
            ss.str();
			alimentos[quant].set_Sodio(Cfloat);
		if (col=5)
			getline(s,word,';');
			ss<<word;
			ss>>Cfloat;
			ss.clear();
            ss.str();
			alimentos[quant].set_Potassio(Cfloat);
		if (col=6)
			getline(s,word,';');
			ss<<word;
			ss>>Cfloat;
			ss.clear();
            ss.str();
			alimentos[quant].set_Carboidratos(Cfloat);
		if (col=7)
			getline(s,word,';');
			ss<<word;
			ss>>Cfloat;
			ss.clear();
            ss.str();
			alimentos[quant].set_Fibra(Cfloat);
		if (col=8)
			getline(s,word,';');
			ss<<word;
			ss>>Cfloat;
			ss.clear();
            ss.str();
			alimentos[quant].set_Acucar(Cfloat);
		if (col=9)
			getline(s,word,';');
			ss<<word;
			ss>>Cfloat;
			ss.clear();
            ss.str();
			alimentos[quant].set_Proteina(Cfloat);
		if (col=10)
			getline(s,word,';');
			ss<<word;
			ss>>Cfloat;
			ss.clear();
            ss.str();
			alimentos[quant].set_VitaminaA(Cfloat);
		if (col=11)
			getline(s,word,';');
			ss<<word;
			ss>>Cfloat;
			ss.clear();
            ss.str();
			alimentos[quant].set_VitaminaC(Cfloat);
		if (col=12)
			getline(s,word,';');
			ss<<word;
			ss>>Cfloat;
			ss.clear();
            ss.str();
			alimentos[quant].set_Calcio(Cfloat);
		if (col=13)
			getline(s,word,';');
			ss<<word;
			ss>>Cfloat;
			ss.clear();
            ss.str();
			alimentos[quant].set_Ferro(Cfloat);
		if (col=14)
			getline(s,word,';');
			ss<<word;
			ss>>Cfloat;
			ss.clear();
            ss.str();
			alimentos[quant].set_GorduraS(Cfloat);
		if (col=15)
			getline(s,word,';');
			ss<<word;
			ss>>Cfloat;
			ss.clear();
            ss.str();
			alimentos[quant].set_Colesterol(Cfloat);
		if (col=16)
			getline(s,word,';');
			alimentos[quant].set_Tipocomida(word);

	}
	
	arvorebst.insereElemento(food);
	quant++;
	}
	file.close();
}

void CalcularRefeicao(){
	float calorias=0,gorduras=0,gordurasT=0,sodio=0,potassio=0,carboidratoT=0,fibra=0,acucar=0,proteina=0,vitA=0,vitC=0,calcio=0,ferro=0,gorduraS=0,colesterol=0;
	string tipo;
	int x,tam;
	
	list<int>dados;
	int numero=1;
	cout<<"=============TABELA NUTRICIONAL==============="<<"\n\n";
	arvorebst.emOrdem(arvorebst.getRaiz());
	cout<<"=============================================="<<"\n\n";
	while(numero!=0){
		cout<<"Digite o numero de cada item que voce consumiu: (Para encerrar digite 0): ";
		cin>>numero;
		if(numero>0){
			if(numero==1){
				numero=39;
			}
			if(numero==2){
				numero=43;	
			}
			if(numero==3){
				numero=15;
			}
			if(numero==4){
				numero=9;
			}
			if(numero==5){
				numero=29;
			}
			if(numero==6){
				numero=0;
			}
			if(numero==7){
				numero=60;
			}
			if(numero==8){
				numero=47;
			}
			if(numero==9){
				numero=19;
			}
			if(numero==10){
				numero=13;
			}
			if(numero==11){
				numero=42;
			}
			if(numero==12){
				numero=56;
			}
			if(numero==13){
				numero=2;
			}
			if(numero==14){
				numero=59;
			}
			if(numero==15){
				numero=52;
			}
			if(numero==16){
				numero=45;
			}
			if(numero==17){
				numero=12;
			}
			if(numero==18){
				numero=8;	
			}
			if(numero==19){
				numero=41;
			}
			if(numero==20){
				numero=31;
			}
			if(numero==21){
				numero=11;	
			}
			if(numero==22){
				numero=3;
			}
			if(numero==23){
				numero=6;
			}
			if(numero==24){
				numero=10;
			}
			if(numero==25){
				numero=22;	
			}
			if(numero==26){
				numero=51;
			}
			if(numero==27){
				numero=26;
			}
			if(numero==28){
				numero=24;
			}
			if(numero==29){
				numero=23;
			}
			if(numero==30){
				numero=50;
			}
			if(numero==31){
				numero=48;
			}
			if(numero==32){
				numero=18;
			}
			if(numero==33){
				numero=33;
			}
			if(numero==34){
				numero=44;
			}
			if(numero==35){
				numero=20;
			}
			if(numero==36){
				numero=34;
			}
			if(numero==37){
				numero=16;
			}
			if(numero==38){
				numero=30;
			}
			if(numero==39){
				numero=25;
			}
			if(numero==40){
				numero=35;
			}
			if(numero==41){
				numero=49;
			}
			if(numero==42){
				numero=54;
			}
			if(numero==43){
				numero=53;
			}
			if(numero==44){
				numero=58;	
			}
			if(numero==45){
				numero=46;
			}
			if(numero==46){
				numero=5;
			}
			if(numero==47){
				numero=28;
			}
			if(numero==48){
				numero=29;
			}
			if(numero==49){
				numero=1;
			}
			if(numero==50){
				numero=14;
			}
			if(numero==51){
				numero=7;
			}
			if(numero==52){
				numero=36;
			}
			if(numero==53){
				numero=37;
			}
			if(numero==54){
				numero=4;
			}
			if(numero==55){
				numero=32;
			}
			if(numero==56){
				numero=59;
			}
			if(numero==57){
				numero=17;	
			}
			if(numero==58){
				numero=40;
			}
			if(numero==59){
				numero=55;
			}
			if(numero==60){
				numero=21;
			}
			if(numero==61){
				numero=38;
			}
			dados.push_front(numero);
		}
	}
	
	tam=dados.size();
	

	if(tam>0){
		for(int i;i<tam;i++){
			x=dados.front();
			calorias=calorias+alimentos[x].get_Calorias();
			gorduras=gorduras+alimentos[x].get_Gorduras();
			gordurasT=gordurasT+alimentos[x].get_GorduraT();
			sodio=sodio+alimentos[x].get_Sodio();
			potassio=potassio+alimentos[x].get_Potassio();
			carboidratoT=carboidratoT+alimentos[x].get_Carboidratos();
			fibra=fibra+alimentos[x].get_Fibra();
			acucar=acucar+alimentos[x].get_Acucar();
			proteina=proteina+alimentos[x].get_Proteina();
			vitA=vitA+alimentos[x].get_VitaminaA();
			vitC=vitC+alimentos[x].get_VitaminaC();
			calcio=calcio+alimentos[x].get_Calcio();
			ferro=ferro+alimentos[x].get_Ferro();
			gorduraS=gorduraS+alimentos[x].get_GorduraS();
			colesterol=colesterol+alimentos[x].get_Colesterol();
			tipo=tipo+alimentos[x].get_Tipocomida();
			
			dados.pop_front();
		}
		
	}
	
	cout<<"========Relacao nutriocional completa da refeicao=======\n\n";
	cout<<"|   CALORIAS      |"<<calorias<<"|"<<"\n";
	cout<<"|   GORDURAS      |"<<gorduras<<"|"<<"\n";
	cout<<"|GORDURAS TOTAIS  |"<<gordurasT<<"|"<<"\n";
	cout<<"|    SODIO        |"<<sodio<<"|"<<"\n";
	cout<<"|    POTASSIO     |"<<potassio<<"|"<<"\n";
	cout<<"|CARBOIDRATO TOTAL|"<<carboidratoT<<"|"<<"\n";
	cout<<"|FIBRA ALIMENTAR  |"<<fibra<<"|"<<"\n";
	cout<<"|ACUCARES         |"<<acucar<<"|"<<"\n";
	cout<<"|PROTEINA         |"<<proteina<<"|"<<"\n";
	cout<<"|VITAMINA A       |"<<vitA<<"|"<<"\n";
	cout<<"|VITAMINA C       |"<<vitC<<"|"<<"\n";
	cout<<"|CALCIO           |"<<calcio<<"|"<<"\n";
	cout<<"|FERRO            |"<<ferro<<"|"<<"\n";
	cout<<"|GORDURA SATURADA |"<<gorduraS<<"|"<<"\n";
	cout<<"|COLESTEROL       |"<<colesterol<<"|"<<"\n";
	cout<<"|TIPO DE COMIDA   |"<<tipo<<"|"<<"\n";
	
	
	
	
	
}

int main(){
	
	
	int opc;

    cout << "\n\n\n";
    cout << "\n-------------------------------------------------------------------";
    cout << "\n                      	 MENU		";
    cout << "\n (Esta menu so aceita numeros inteiros maiores ou iguais a zero)";
    cout << "\n-------------------------------------------------------------------";
	
	do 	{
        cout << "\n\n________________________   MENU   _____________________________\n";
        cout << "\n0 - Sair";
        cout << "\n1 - Ler dados";
        cout << "\n2 - Informacao de todos alimentos";
        cout << "\n3 - Calcular Refeicao";
        cout << "\n\n_______________________________________________________________\n";
        cout << "\n\nInforme sua opcao: ";
        cin >> opc;
	
	
	switch (opc) {


            case 0: {
                cout << "\n\n ~~~~ Fim da execucao! ~~~~\n\n";
                break;
            }


            case 1: {
            	lerDados();
            	cout<<"Dados foram lidos com sucesso!\n\n";
                break;
            }


            case 2: {
            	buscarInfo();
                break;
            }


            case 3: {
                CalcularRefeicao();
            }
            
            default: {
                cout << "\n Opcao invalida!";
                break;
       	    }
   		}
    }while (opc != 0);

}	



	


