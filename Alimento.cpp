#include <string>
#include "Alimento.h"

using namespace std;
	
alimento::alimento(){
}
	
void alimento::set_Calorias(float calorias){
	this->calorias=calorias;
}
	
void alimento::set_Gorduras(float gorduras){
	this->gorduras=gorduras;
}
	
void alimento::set_GorduraT(float gorduraT){
	this->gorduraT=gorduraT;
}
	
void alimento::set_Sodio(float sodio){
	this->sodio=sodio;
}
	
void alimento::set_Potassio(float potassio){
	this->potassio=potassio;
}
	
void alimento::set_Carboidratos(float carboidratos){
	this->carboidratos=carboidratos;
}
	
void alimento::set_Fibra(float fibra){
	this->fibra=fibra;
}
	
void alimento::set_Acucar(float acucar){
	this->acucar=acucar;
}
	
void alimento::set_Proteina(float proteina){
	this->proteina=proteina;
}
	
void alimento::set_VitaminaA(float vitaminaA){
	this->vitaminaA=vitaminaA;
}

void alimento::set_VitaminaC(float vitaminaC){
	this->vitaminaC=vitaminaC;
}
	
void alimento::set_Calcio(float calcio){
	this->calcio=calcio;
}
	
void alimento::set_Ferro(float ferro){
	this->ferro=ferro;
}
	
void alimento::set_GorduraS(float gorduraS){
	this->gorduraS=gorduraS;
}
	
void alimento::set_Colesterol(float colesterol){
	this->colesterol=colesterol;
}
	
void alimento::set_Tipocomida(string tipo){
	this->tipo=tipo;
}
	
float alimento::get_Calorias(){
	return calorias;
}
	
float alimento::get_Gorduras(){
	return gorduras;
}
	
float alimento::get_GorduraT(){
	return gorduraT;
}
	
float alimento::get_Sodio(){
	return sodio;
}
	
float alimento::get_Potassio(){
	return potassio;
}
	
float alimento::get_Carboidratos(){
	return carboidratos;
}
	
float alimento::get_Fibra(){
	return fibra;
}
	
float alimento::get_Acucar(){
	return acucar;
}
	
float alimento::get_Proteina(){
	return proteina;
}
	
	
float alimento::get_VitaminaA(){
	return vitaminaA;
}

float alimento::get_VitaminaC(){
	return vitaminaC;
}
	
float alimento::get_Calcio(){
	return calcio;
}
	
float alimento::get_Ferro(){
	return ferro;
}
	
float alimento::get_GorduraS(){
	return gorduraS;
}
	
float alimento::get_Colesterol(){
	return colesterol;
}
	
string alimento::get_Tipocomida(){
	return tipo;	
};

