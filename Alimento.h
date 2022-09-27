#include <string>
using namespace std;

class alimento{

private:
	float calorias,gorduras,gorduraT,sodio,potassio,carboidratos,fibra,acucar,proteina,vitaminaA,vitaminaC,calcio,ferro,gorduraS,colesterol;
	string tipo;
public:
	alimento();
	void set_Calorias(float calorias);
	void set_Gorduras(float gorduras);
	void set_GorduraT(float gorduraT);
	void set_Sodio(float sodio);
	void set_Potassio(float potassio);
	void set_Carboidratos(float carboidratos);
	void set_Fibra(float fibra);
	void set_Acucar(float acucar);
	void set_Proteina(float proteina);
	void set_VitaminaA(float vitaminaA);
	void set_VitaminaC(float vitaminaC);
	void set_Calcio(float calcio);
	void set_Ferro(float ferro);
	void set_GorduraS(float gorduraS);
	void set_Colesterol(float colesterol);
	void set_Tipocomida(string tipo);
	float get_Calorias();
	float get_Gorduras();
	float get_GorduraT();
	float get_Sodio();
	float get_Potassio();
	float get_Carboidratos();
	float get_Fibra();
	float get_Acucar();
	float get_Proteina();
	float get_VitaminaA();
	float get_VitaminaC();
	float get_Calcio();
	float get_Ferro();
	float get_GorduraS();
	float get_Colesterol();
	string get_Tipocomida();
	
};
