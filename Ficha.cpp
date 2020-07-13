#include "Ficha.h"

Ficha::Ficha() {
	valor = '-';
}

void Ficha::setValor(char valor) {
	this->valor = valor;
}

char Ficha::getValor(){
	return valor;
}
