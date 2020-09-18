/*
Copyright (C) 2019 Matteo Collica

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include <iostream>
#include "MCD_mcm.h"

long MCD(int A, int B) {
	int DIV = 1, R; //inizio a dividere a partire da 1, il quale in mancanza di altri divisori possibili sarà il M.C.D

	while(DIV <= A && DIV <= B) { 				//finché il divisore non supera uno dei due numeri
		if (A % DIV == B % DIV && B % DIV == 0) //se DIV e' un divisore comune ad entrambi
			R = DIV; 							//memorizza in R l'attuale DIVisore massimo raggiunto
		DIV++; 									//incremento il divisore
	}

	return R;
}

long mcm(int A, int B) {
	int R = A; 				  //inizializzo e assegno a una variabile che chiamo mcm uno dei due numeri
	while(R % B != 0) {
		R += A;
	}
	
	//finché il resto della divisione tra il primo numero e l'altro è diverso da 0 aggiungo il numero alla variabile mcm
	return R;
}
