//Copyright (C) 2020 Matteo Collica
//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.

//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.

//You should have received a copy of the GNU General Public License
//along with this program. If not, see <http://www.gnu.org/licenses/>.

//Questo programma in linguaggio C++ con l'implementazione di funzioni varie
//dara' un elenco di operazioni possibili tra cui l'operatore potra' scegliere
//cosa vuole calcolare di un elenco di numeri interi.

#include <iostream>
using namespace std;

//Prototipo
bool se_primo(int A);
bool se_pari(int A);
int CalcolaMax(int MAX, int NUM); //Funzione per confrontare ed aggiornare eventualmente il valore massimo
int CalcolaMin(int MIN, int NUM); //Funzione per confrontare ed aggiornare eventualmente il valore minimo

//Funzione principale
int main() {
  int scelta = 0, numero, S=0, Primi=0, Pari=0, N=0, Massimo, Minimo, K, CK=0;
  char elenco;

  cout << "Menu' di operazioni su un elenco di numeri";
  cout << "\nScegli cosa vuoi calcolare di un elenco di numeri:";
  cout << "\n1 - Media aritmetica;";                   //somma di cui infine divisione con la quantita' di numeri inseriti
  cout << "\n2 - Conteggio numeri primi;";             //verifica di ogni numero con la funzione se_primo
  cout << "\n3 - Conteggio pari e dispari;";           //verifica di ogni numero con la funzione se_pari
  cout << "\n4 - Valore massimo e minimo;";            //funzioni CalcolaMax e CalcolaMin
  cout << "\n5 - Numeri maggiori di una costante.";
  cout << "\nQuale e' la tua scelta? "; cin >> scelta;

  if(scelta < 1 || scelta > 5) {
    cout << "Scelta non valida, riprovare con un numero compreso tra 1 e 5!\n";
    return 1;
  }

  do {
    if(N == 0 && scelta == 5) {
        //Come primo numero va inserita la costante con cui confrontare i successivi
        cout << "Inserisci la costante K: ";
    } else cout << "Inserisci un numero: ";
    cin >> numero;

    switch(scelta) {
      case 1: //Media aritmetica
        S += numero; //sommo ai fini della media l'ultimo numero inserito

        break;
      case 2: //Conteggio numeri primi
        if((numero == 0) || (numero == 1)) {
          cout << numero << " matematicamente non puo' essere considerato ne' primo ne' composto\n";
          N--;
        } else if(se_primo(numero) == true) Primi++;

        break;
      case 3: //Conteggio pari e dispari
        if(se_pari(numero) == true) Pari++;
        break;
      case 4: //Valore massimo e minimo
        if(N == 0) {        //il primo numero inserito inizializza
          Massimo = numero; //sia il valore minimo
          Minimo = numero;  //che il valore massimo
        } else {
          Massimo = CalcolaMax(Massimo, numero);
          Minimo = CalcolaMin(Minimo, numero);
        }

        break;
      case 5: //Numeri maggiori di una costante
        if(N == 0) K = numero;
        else if(numero > K) CK++;
    }

    N++;

    //Richiesta in input di una scelta finche' essa non e' valida
    do {
        cout << "\nInserisci 's' se vuoi continuare";
        cout << "\no inserisci 'n' se vuoi terminare: ";
        cin >> elenco;

        /*
         * se l'utente sceglie di continuare verra' chiesto un altro numero in input;
         * se l'utente sceglie di non continuare verranno stampati i risultati;
         * se l'utente non effettua una scelta valida allora viene chiesta nuovamente.
         */
    }while((elenco != 'S') && (elenco !='s') && (elenco !='N') && (elenco !='n')); //finche' l'utilizzatore non effettua una scelta valida

  }while((elenco == 'S') || (elenco =='s'));

  //

  cout << "Totale numeri immessi: " << N;
  if(N > 0) {
    switch(scelta) {
      case 1:
        cout << "\nMedia aritmetica: " << (float) S/N;
        break;
      case 2:
        cout << "\nTotale numeri primi: " << Primi;
        break;
      case 3:
        cout << "\nTotale numeri pari: " << Pari;
        cout << "\nTotale numeri dispari: " << N - Pari;
        break;
      case 4:
        cout << "\n       Valore massimo: " << Massimo;
        cout << "\n       Valore minimo: " << Minimo;
        break;
      case 5:
        cout << "\nTotale numeri maggiori di K: " << CK;
    }
  }
  cout << "\n";
}

bool se_primo(int A) {
  int DIV = 2;   //DIV e' il divisore, inizia da 2 per ottimizzazione (poiche' 2 puo' essere considerato direttamente numero primo)
  bool R = true;

  while(R != false && DIV <= A/2) { //finche' il divisore e' minore o uguale alla meta' del numero
    if (A % DIV == 0) R = false;    //se la divisione non ha resto allora il numero non e' primo
    else DIV++;                     //altrimenti la verifica continua con il divisore incrementato di 1
  }

  if(R == false) return false;
  else return true;

}

bool se_pari(int A) {
  if (A % 2 == 0) return true;
  else return false;
}

int CalcolaMax(int MAX, int NUM) {
  if(MAX < NUM) return NUM;
  else return MAX;
}

int CalcolaMin(int MIN, int NUM) {
  if(MIN > NUM) return NUM;
  else return MIN;
}
