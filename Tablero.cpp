#include "Tablero.h"

Tablero::Tablero() {
	
}
//Método que imprime al tablero en pantalla
void Tablero::mostrarTablero(){
	std::cout << "Vista del tablero:" << std::endl;
	std::cout << "  " << "A" << " " << "B" << " " << "C" << std::endl;
	std::cout << " -------" << std::endl;
	int fila = 1;
	for (int i = 0; i < 3; i++){
		std::cout << fila;
		for (int j = 0; j < 3; j++){
			char ficha = fichas[i][j].getValor();	
			std::cout << "|";
			//Mostramos en colores las fichas
			if(ficha == 'X') {
				textcolor(LIGHTMAGENTA);
				std::cout << ficha;					
			}else if(ficha == 'O'){
				textcolor(LIGHTGREEN);
				std::cout << ficha;				
			}else{
				std::cout << ficha;	
			}
			textcolor(LIGHTGRAY);		
		}
		std::cout << "|" << std::endl;
		fila++;
	}	
	std::cout << " -------" << std::endl;
}

//Retorna verdadero si el tablero esta lleno
//false si esta vacío
bool Tablero::estaLleno(){
	int suma = 0;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(fichas[i][j].getValor() == 'X' || fichas[i][j].getValor() == 'O')
			{
				suma++;
			}
		}
	}
	if(suma < 9) return false;
	return true;
}

//Método que chequa las diagonales para el tateti
//devuelve true si hay coincidencia
bool Tablero::ChequeaDiagonales(){		
	//Cadena que contendrá XXX o OOO si hay tateti.
	//Para la diagonal de arriba de derecha a izquierda
	std::string cadena;
	cadena = "";
	for (int i = 0; i < 3; i++){		
		cadena += fichas[i][i].getValor();		
	}	
	//Retorna true si encontró tateti
	if(cadena == "XXX" || cadena == "OOO") return true;
	
	//Para la diagonal de abajo de derecha a izquierda
	cadena = ""; //Limpiamos la cadena
	int j = 0;
	for (int i = 2; i >= 0; i--){		
		cadena += fichas[i][j].getValor();	
		j++;
	}
	if(cadena == "XXX" || cadena == "OOO") return true;
	return false;
}

//Método que chequa las filas para el tateti
//devuelve true si hay coincidencia
bool Tablero::ChequeaFilas(){
	//Chequeamos filas	
	int x = 0;
	int o = 0;
	for (int i = 0; i < 3; i++)
	{		
		for(int j = 0; j < 3; j++) {
			if(fichas[i][j].getValor() == 'X') x++;
			if(fichas[i][j].getValor() == 'O') o++;
		}
		if(x == 3 || o == 3) return true;
		x = 0;
		o = 0;
	}
	
	return false;
}

//Método que chequa las columnas para el tateti
//devuelve true si hay coincidencia
bool Tablero::ChequeaColumnas()
{
	int x = 0;
	int o = 0;
	for (int i = 0; i < 3; i++)
	{		
		for(int j = 0; j < 3; j++) {
			if(fichas[j][i].getValor() == 'X') x++;
			if(fichas[j][i].getValor() == 'O') o++;
		}
		if(x == 3 || o== 3) return true;
		x = 0;
		o = 0;
	}
	return false;
}

//Método que chequa devuelve true si hay tateti
bool Tablero::tateti(){
	if(ChequeaColumnas() || ChequeaDiagonales() || ChequeaFilas() ) {
		return true;
	}
	return false;
	
}


//Método que devuelve true si la ficha existe en el tablero
bool Tablero::existeFicha(int x, int y){
	if(fichas[x][y].getValor() == 'X' || fichas[x][y].getValor() == 'O') {
		return true;
	}
	return false;
}

//Método que pone un caracter X o 0 a una posición [x] e [y] del arreglo
void Tablero::setFicha(int x, int y, char c){
	fichas[x][y].setValor(c);
}
