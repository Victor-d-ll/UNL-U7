#ifndef FICHA_H
#define FICHA_H

class Ficha {
public:
	Ficha();
	
	char getValor();
	void setValor(char valor);	
	
private:
	char valor;
};

#endif

