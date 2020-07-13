#include "Juego.h"

Juego::Juego() {
	turnoJ1 = true; //Se carga el valor true a la variable turno jugador1
}

void Juego::start() {
	bienvenida();		
	tablero.mostrarTablero();
	mostrarJugador();
	mostrarOpciones();
}

void Juego::bienvenida() {
	textcolor(RED);
	std::cout<<"**************************"<<std::endl;
	textcolor(GREEN);
	std::cout<<"* Bienvenido al ta-te-ti *"<<std::endl;
	textcolor(RED);
	std::cout<<"**************************"<<std::endl;
	textcolor(LIGHTGRAY);
}

void Juego::mostrarJugador(){
	std::cout<<std::endl;
	if(turnoJ1){
		std::cout<<"Es el turno del jugador 1"<<std::endl;
	}else{
		std::cout<<"Es el turno del jugador 2"<<std::endl;
	}
}

//Función que muestra las opciones del usuario en pantalla
void Juego::mostrarOpciones(){
	std::cout<<std::endl;	
	int posicion = 1;
	int contador = 1;
	for(int i=0; i<3; i++)
	{
		char letra = 'A';		
		for (int j=0; j<3; j++) {
			std::cout<<"Presione "<<contador<<" para poner la ficha en "<<letra<<posicion<<std::endl;
			letra++;	
			contador++;
		}	
		posicion++;
	}
	
}
