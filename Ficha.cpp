#include "Ficha.h"

//El constructor carga un valor - para mostrar en pantalla
Ficha::Ficha() {
	valor = '-';
}

//m�todo que le carga un valor a la ficha
void Ficha::setValor(char valor) {
	this->valor = valor;
}

//m�todo que devuelve el valor de la ficha
char Ficha::getValor(){
	return valor;
}
