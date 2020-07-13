#include "Tablero.h"

Tablero::Tablero() {
	
}

void Tablero::cargarTablero(){
	
}

void Tablero::mostrarTablero(){
	std::cout<<"Vista del tablero:"<<std::endl;
	std::cout<<"  "<<"A"<<" "<<"B"<<" "<<"C"<<std::endl;
	std::cout<<" -------"<<std::endl;
	int fila = 1;
	for (int i=0; i<3; i++){
		std::cout<<fila;
		for (int j=0; j<3; j++){
			std::cout<<"|"<<fichas[i][j].getValor();
		}
		std::cout<<"|"<<std::endl;
		fila++;
	}	
	std::cout<<" -------"<<std::endl;
}


