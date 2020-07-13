#include "Juego.h"

Juego::Juego() {
	turnoJ1 = true; //Se carga el valor true a la variable turno jugador1
}

void Juego::start() {
	bienvenida();	
	mostrarJugador();
	tablero.mostrarTablero();
}

void Juego::bienvenida() {
	textcolor(RED);
	std::cout<<"**********************"<<std::endl;
	textcolor(GREEN);
	std::cout<<"Bienvenido al te-te-ti"<<std::endl;
	textcolor(RED);
	std::cout<<"**********************"<<std::endl;
	textcolor(LIGHTGRAY);
}

void Juego::mostrarJugador(){
	if(turnoJ1){
		std::cout<<"Es el turno del jugador 1"<<std::endl;
	}else{
		std::cout<<"Es el turno del jugador 2"<<std::endl;
	}
}
