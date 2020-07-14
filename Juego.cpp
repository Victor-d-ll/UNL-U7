#include "Juego.h"

Juego::Juego() {
	turnoJ1 = true; //Se carga el valor true a la variable turno jugador1
	jugando = true; //Variable para el loop principal
	for (int i=0; i<9; i++){ //Carga verdadero para poder mostrar las opciones
		opciones[i] = true;
	}
}

void Juego::start() {
	bienvenida();		
	while(jugando){
		clrscr();
		mostrarTablero();	//Muestra el tablero
		mostrarOpciones();  //Muestra el menu de opciones
		mostrarJugador();   //Muestra el nombre del jugador activo
		if(setPosicion(capturarTecla())) //Captura una tecla y setea la ficha
		{			
			if(hayTateti()) {	
				clrscr();
				mostrarTablero();	//Muestra el tablero
				mostrarGanador(turnoJ1); //Muestra quien ganó la partida
				return; //Si hay ganador sale
			}
			turnoJ1 = !turnoJ1; //Cambio el turno
		}	
		verificarFin(); //Verifica si se lleno el tablero	
	}	
	clrscr();
	mostrarTablero(); //Muestra el tablero para que se vea claramente
	mensajeEmpate(); //Muestra mensaje de empate
}

//Mensaje que aparece cuando el juego finaliza sin ganadores
void Juego::mensajeEmpate(){
	textcolor(LIGHTGREEN);	
	std::cout << "Los jugadores han EMPATADO" << std::endl;
	std::cout << "Gracias por jugar" << std::endl;
	textcolor(LIGHTGRAY);
}
//verifica si el tablero esta lleno
//si está lleno pone jugando en false
void Juego::verificarFin(){
	if(tablero.estaLleno()) jugando = false;
}

//Muestra un mensaje con el ganador
void Juego::mostrarGanador(bool turnoJ1){
	textcolor(LIGHTGREEN); 
	if(turnoJ1) { //Se fija de quien es el turno activo
		std::cout << "El jugador 1 ganó la partida" << std::endl;
	}else{
		std::cout << "El jugador 2 ganó la partida" << std::endl;
	}
	std::cout << "Gracias por jugar!!!";
	textcolor(LIGHTGRAY);
}
//Chequea si hay tateti
bool Juego::hayTateti(){	
	return tablero.tateti();
}

//Pone la ficha en la posición correspondiente y marca que ya se usó
bool Juego::setPosicion(int tecla){	
	int x,y;	
	switch(tecla){ //Carga x e y y marca la opción elegida
		case 49:
			x = 0;
			y = 0;
			opciones[0] = false;
			break;
		case 50:
			x = 0;
			y = 1;
			opciones[1] = false;
			break;
		case 51:
			x = 0;
			y = 2;
			opciones[2] = false;
			break;
		case 52:
			x = 1;
			y = 0;
			opciones[3] = false;
			break;	
		case 53:
			x = 1;
			y = 1;
			opciones[4] = false;
			break;
		case 54:
			x = 1;
			y = 2;
			opciones[5] = false;
			break;
		case 55:
			x = 2;
			y = 0;
			opciones[6] = false;
			break;
		case 56:
			x = 2;
			y = 1;
			opciones[7] = false;
			break;
		case 57:
			x = 2;
			y = 2;
			opciones[8] = false;
			break;
	}
	//Si ya hay ficha retorna
	if(tablero.existeFicha(x,y)) return false;
	
	//Segun el turno escribe la ficha que corresponda	
	tablero.setFicha(x,y,getValorPorTurno());
	return true;	
	
}


//Devuelve el valor segun el turno del jugador
char Juego::getValorPorTurno(){
	if(turnoJ1) return 'X'; //Retorna el caracter según el turno
	return 'O';	
}

//Método que muestra el tablero
void Juego::mostrarTablero(){
	tablero.mostrarTablero();
}
//Un texto de bienvenida que se muestra al iniciar partida;
void Juego::bienvenida() {
	textcolor(RED);
	std::cout << "**************************" << std::endl;
	textcolor(GREEN);
	std::cout << "* Bienvenido al ta-te-ti *" << std::endl;
	textcolor(RED);
	std::cout << "**************************" << std::endl;
	textcolor(LIGHTGRAY);
	std::cout << "Presiona alguna tecla para continuar" << std::endl;
	getch();
}

//Método que muestra un texto que informa quien es el jugador activo
void Juego::mostrarJugador(){
	std::cout << std::endl;	
	if(turnoJ1){ //Dependiendo el turno muestra un mensaje u otro
		textcolor(LIGHTMAGENTA);
		std::cout << "!!! Es el turno del jugador 1 !!!" << std::endl;
	}else{
		textcolor(LIGHTGREEN);
		std::cout << "!!! Es el turno del jugador 2 !!!" << std::endl;
	}
	textcolor(LIGHTGRAY);
}

//Método que muestra las opciones del usuario en pantalla
void Juego::mostrarOpciones(){
	std::cout << std::endl;	
	int posicion = 1;
	int contador = 1;
	std::cout << "***************************" << std::endl;
	std::cout << "La ficha del jugador 1 es X" << std::endl;
	std::cout << "La ficha del jugador 2 es O" << std::endl;
	std::cout << "***************************" << std::endl;
	for(int i = 0; i < 3; i++) //Es un bucle para mostrar las opciones
	{
		char letra = 'A';		
		for (int j = 0; j < 3; j++) {
			if(opciones[contador-1]) { //Si esta marcado true muestra
			std::cout << "Presione " << contador << " para poner la ficha en " 
				<< letra << posicion << std::endl;
			}
			letra++;	
			contador++;
		}	
		posicion++;
	}	
}

//Captura una teclada que debe ser valida como opción.
int Juego::capturarTecla(){
	int tecla = 0;	
	while(tecla == 0){ //Queda en el bucle si no se ingresa lo deseado
		std::cout << "Ingrese su elección:" << std::endl;			
		tecla = getch();
		if(tecla < 49 || tecla > 57) tecla = 0;
	}
	return tecla;
}


