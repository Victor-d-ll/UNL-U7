#include "Juego.h"

Juego::Juego() {
	turnoJ1 = true; //Se carga el valor true a la variable turno jugador1
	jugando = true;
}

void Juego::start() {
	bienvenida();		
	while(jugando){
		mostrarTablero();	
		mostrarOpciones();
		mostrarJugador();
		capturarTecla();
		jugando=false;
	}	
}


void Juego::mostrarTablero(){
	tablero.mostrarTablero();
}
//Un texto de bienvenida que se muestra al iniciar partida;
void Juego::bienvenida() {
	textcolor(RED);
	std::cout<<"**************************"<<std::endl;
	textcolor(GREEN);
	std::cout<<"* Bienvenido al ta-te-ti *"<<std::endl;
	textcolor(RED);
	std::cout<<"**************************"<<std::endl;
	textcolor(LIGHTGRAY);
}

//Función que muestra un texto que informa quien es el jugador activo
void Juego::mostrarJugador(){
	std::cout<<std::endl;
	if(turnoJ1){
		std::cout<<"!!! Es el turno del jugador 1 !!!"<<std::endl;
	}else{
		std::cout<<"!!! Es el turno del jugador 2 !!!"<<std::endl;
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

//Captura una teclada que debe ser valida como opcion.
void Juego::capturarTecla(){
	int tecla = 0;	
	while(tecla==0){
		std::cout<<"Ingrese su elección:"<<std::endl;			
		tecla = getch();
		if(tecla<49 || tecla>57) tecla = 0;
	}
}

