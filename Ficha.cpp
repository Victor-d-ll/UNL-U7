#include "Ficha.h"

//El constructor carga un valor - para mostrar en pantalla
Ficha::Ficha() {
	valor = '-';
}

//método que le carga un valor a la ficha
void Ficha::setValor(char valor) {
	this->valor = valor;
}

//método que devuelve el valor de la ficha
char Ficha::getValor(){
	return valor;
}
