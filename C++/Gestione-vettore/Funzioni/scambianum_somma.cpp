/*
Copyright (C) 2019 Matteo Collica

Permission is hereby granted, free of charge, to any person obtaining a copy of this software
to deal in the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software,
and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <iostream>
#include "scambianum_somma.h"

//l'asterisco indica che stiamo lavorando su dei puntatori a delle locazioni di memoria
void scambia_num(int *A, int *B) {
	int scambio = *A; //variabile di comodo che useremo per mantenere uno dei due numeri prima di cambiarlo con l'altro per non perderlo
	*A = *B;          //l'indirizzo di memoria contenuto dalla posizione assume quindi l'altro numero
	*B = scambio;     //mentre l'indirizzo di memoria contenuto dall'altra posizione assume il numero che avevamo salvato
}

int somma(int vet[], int d) {
  int S = 0, i;
  for(i = 0; i < d; i++) S += vet[i];
  return S;
}
