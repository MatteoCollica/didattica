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
#define max 10 //10 e' un valore massimo ragionevole per le dimensioni, in quanto considerando di volerlo scegliere sia per righe che per colonne, avremmo una matrice di 100(10*10) elementi.
using namespace std;

//Prototipo delle funzioni del programma
int chiedi_dimensione();
void carica_matrice(int r, int c, int M[max][max]);
void visualizza_matrice(int r, int c, int M[max][max]);
void visualizza_vettore(int vet[], int d);

//Funzione principale(main) del programma
int main() {
  int r, c, i, j, flag=1, diagonale=1;

  //Dimensionamento matrice
  cout << "- matrice[r][] -" << endl; r = chiedi_dimensione();
  cout << "- matrice[][c] -" << endl; c = chiedi_dimensione();

  //Dichiarazione matrice e vettori
  int matrice[max][max];
  int principale[r];
  int secondaria[r];

  //Carica matrice
  carica_matrice(r, c, matrice);

  //Visualizza matrice
  cout << "\nMatrice("<<r<<", "<<c<<"): ";
  visualizza_matrice(r, c, matrice);

  //Se la matrice e' sfruttata unicamente come vettore
  //viene definita matrice riga, matrice colonna
  //o anche entrambe se contiene un solo valore.
  if(r == 1) {
    cout << endl;
    cout << "La matrice e' riga.";
  }

  if(c == 1) {
    cout << endl;
    cout << "La matrice e' colonna.";
  }

  //Analisi matrice quadrata
  if(r == c) {
    cout << "\n\n- Analisi matrice quadrata -";

    //Diagonale principale
    j = 0;
    for(i=0; i<r; i++) {
      principale[i] = matrice[i][j];
      j++;
    }
    cout << "\nDiagonale principale: " << principale[0];
    visualizza_vettore(principale, r);

    //Diagonale secondaria
    j = c-1;
    for(i=0; i<r; i++) {
      secondaria[i] = matrice[i][j];
      j--;
    }
    cout << "Diagonale secondaria: " << secondaria[0];
    visualizza_vettore(secondaria, r);

    //Triangolare superiore
    for(i=0; i<r; i++) {
        for(j=i-1; j>=0; j--) {
            if(matrice[i][j] != 0) flag = 0;
        }
    }
    if(flag == 1) cout << "\nLa matrice e' triangolare superiore." << endl;
    else diagonale = 0; //se non e' triangolare superiore allora non puo' essere diagonale;

    //Triangolare inferiore
    flag = 1;
    for(i=0; i<r; i++) {
        for(j=i+1; j<c; j++) {
            if(matrice[i][j] != 0) flag = 0;
        }
    }
    if(flag == 1) cout << "La matrice e' triangolare inferiore." << endl;
    else diagonale = 0; //se non e' triangolare inferiore allora non puo' essere diagonale.

    //Matrice diagonale
    if(diagonale == 1) {
      cout << "La matrice e' diagonale." << endl;
    //se e' sia triangolare superiore che triangolare inferiore allora
    //corrisponde automaticamente anche alla definizione di matrice diagonale.

      //Matrice unita'
      flag = 1;
      for(i=0; i<r; i++) {
        if(principale[i] != 1) flag = 0;
      }
      if(flag == 1) cout << "  La matrice e' unita'." << endl;
    }
  }
  else cout << endl << "La matrice e' rettangolare."; //se la matrice non è quadrata allora è rettangolare.

  //Matrice nulla
  flag = 1;
  for(i=0; i<r; i++) {
    for(j=0; j<c; j++) {
        if(matrice[i][j] != 0) flag = 0;
    }
  }
  if(flag == 1) cout << "La matrice e' nulla.";

  return 0;
}

//Chiedi dimensione [richiesta in input di una dimensione(righe o colonne)]
int chiedi_dimensione() {
  int d;
  do {
    cout << "Inserisci la dimensione: "; cin >> d;
  }while(d <= 0 || d > max);
  return d;
}

//Carica matrice (richiesta in input valori per una matrice)
void carica_matrice(int r, int c, int M[max][max]) {
  for(int i=0; i<r; i++) {
    cout << "\n\nRIGA " << i+1 << " DI " << r << "\n        r  c " << endl;
    for(int j=0; j<c; j++) {
      cout << "matrice["<<i<<"]["<<j<<"] " " -> "; cin >> M[i][j];
    }
  }
}

//Visualizza matrice (visualizzazione compatta e gradevole per la lettura valori di una matrice)
void visualizza_matrice(int r, int c, int M[max][max]) {
  for(int i=0;i<r;i++){
    cout << endl;
    for(int j=0;j<c;j++) cout << M[i][j] << " ";
  }
}

//Visualizza vettore (visualizzazione compatta e gradevole per la lettura valori di un vettore)
void visualizza_vettore(int vet[], int d) {
	int i;
	for (i=1; i<d; i++) cout << ", " << vet[i];
	cout << endl;
}
