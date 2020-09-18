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

Conversione di un numero da base Decimale a Binaria
attraverso il metodo della massima potenza di 2, implementato in C++.
*/

#include <iostream>  //richiama dalla libreria standard il file header iostream
#include <math.h>    //header file per la libreria che definisce la funzione pow
using namespace std; //dichiara l'uso dello spazio dei nomi della libreria standard

int main() {
    int A, pot, esp;

    //dichiarazione e inizializzazione della variabile totalizzatore N come numero reale a 32 bit
    double N = 0;

    //richiesta in input all'utilizzatore del numero da convertire
    cout << "\nInserisci un numero decimale da convertire in binario:\n";
    cin >> A;

    cout << "\nConvertendo " << A << " dalla base decimale alla base binaria..." << "\n";

    while(A != 0)   
      {
        pot = 0; esp = 0; 

        while (pot <= A)
          {
            pot = pow(2, esp);    //potenza = 2^esp(onente)
            esp++;
          }
        N = N + 1 * pow(10, esp); //viene aggiunto ordinatamente l'esponente (la cui potenza è stata sottratta dal numero) alla sequenza di numeri
        pot = pot / 2;            //viene ridefinita la potenza di 2 che più si avvicina al numero
        A = A - pot;              //viene sottratta dal numero la potenza di 2 minore o uguale
      }

    //riorganizzazione sequenza senza la notazione scientifica, ottenendo e inviando in output il risultato
    cout.precision (0); cout << fixed << N / 100 << ")₂" << " \n"; 

    return 0;
}
