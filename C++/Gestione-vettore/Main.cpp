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

#include "Funzioni/chiediconferma_chiedipos.h"
#include "Funzioni/MCD_mcm.h"
#include "Funzioni/scambianum_somma.h"
#include "Funzioni/separi_seprimo.h"
#include "Funzioni/visualizza_vettore.h"

using namespace std;

void menu_di_scelta() {
	cout << "\n- 0: Visualizza questo menu' di scelta -";

	cout << "\n\n1 - Imposta un numero in una posizione";
	cout << "\n2 - Visualizza il numero in una posizione";
	cout << "\n3 - Somma dei numeri di due posizioni";
	cout << "\n4 - Prodotto dei numeri di due posizioni";
	cout << "\n5 - M.C.D tra i numeri di due posizioni";
	cout << "\n6 - m.c.m tra i numeri di due posizioni";
	cout << "\n7 - Media dei numeri di due posizioni";

	cout << "\n\n(11-17) per eseguire le suddette operazioni";
	cout << "\nma per tutti i numeri della sequenza insieme";

	cout << "\n\n21 - Ordinamento crescente della sequenza";
	cout << "\n22 - Ordinamento decrescente della sequenza";
	cout << "\n23 - Conteggio numeri pari e dispari nella sequenza";
	cout << "\n24 - Conteggio numeri primi e composti nella sequenza";
	cout << "\n25 - Frequenza di un numero nella sequenza";

	cout << "\n\n-1 - Chiudi il programma\n";
}

int main () {
	int scelta, pos, pos2, num, d, i, j, P, R, CP, CPR, k, CK;
	//(in questo programma lavoreremo con numeri interi)

	bool conferma;

	cout << "Questo programma permette di inserire una sequenza di numeri";
	cout << "\ned eseguire varie operazioni su alcuni contenuti in posizioni";
	cout << "\nspecifiche, o su tutti i numeri insieme della sequenza.";

	do {
		cout << "\n\nDimensione (in numeri - da 2 a 50) della sequenza: "; cin >> d;
	}while(d <= 1 || d > 50);

	int vet[d];
	for(i=0; i<d; i++) { //richiesta dei numeri della sequenza
		cout << "Inserisci il numero da inserire nella posizione " << i << " della sequenza: "; cin >> vet[i];
	}

	menu_di_scelta();    //visualizza il menu' di scelta

	do{
		cout << "\nScegli quale operazione eseguire: "; cin >> scelta;

		//In base alla scelta richiedere una(1-2) o due(3-7)
		if(scelta >= 1 && scelta < 8) {
			cout << "Posizione: "; pos = chiedi_pos(d);
			if(scelta >= 3) {
				cout << "Posizione 2: "; pos2 = chiedi_pos(d);
			}
		}

		else if(scelta < -1 || (scelta > 7 && scelta < 11) || (scelta > 17 && scelta < 21) || scelta > 25)
			cout << "Scelta non valida, riprova.\n";

		switch (scelta) {
		
			case 0: //Visualizza il menu' di scelta
				menu_di_scelta();
				break;
			
			case 1: //Impostazione di un numero in una posizione
				cout << "Inserisci il numero che vuoi impostare nella posizione scelta: "; cin >> num;
				vet[pos] = num;
				break;
			
			case 2: //Visualizzazione del numero di una posizione
				cout << "La posizione " << pos << " contiene il numero " << vet[pos] << "\n";
				break;
			
			case 3: //Somma tra i numeri di due posizioni
				cout << "La somma tra " << vet[pos] << " e " << vet[pos2] << " e' " << vet[pos] + vet[pos2] << "\n";
				break;
			
			case 4: //Prodotto tra i numeri di due posizioni
				cout << "Il prodotto tra " << vet[pos] << " e " << vet[pos2] << " e' " << vet[pos] * vet[pos2] << "\n";
				break;
			
			case 5: //M.C.D tra i numeri di due posizioni
				cout << "Il M.C.D tra " << vet[pos] << " e " << vet[pos2] << " e' " << MCD(vet[pos], vet[pos2]) << "\n";
				break;
			
			case 6: //m.c.m tra i numeri di due posizioni
				cout << "Il m.c.m tra " << vet[pos] << " e " << vet[pos2] << " e' " << mcm(vet[pos], vet[pos2]) << "\n";
				break;
			
			case 7: //Media dei numeri di due posizioni
				cout << "La media tra " << vet[pos] << " e " << vet[pos2] << " e' " << (float) (vet[pos] + vet[pos2]) / 2 << "\n";
				break;
			
			case 11: //Imposta un numero per ogni posizione della sequenza
				cout << "Inserisci il numero da impostare in ogni posizione della sequenza: "; cin >> num;

				conferma = chiedi_conferma();
				if(conferma == true) {
					for(i = 0; i < d; i++) {
						cout << "\nIl numero in posizione " << i << " e' stato cambiato da " << vet[i] << " al numero " << num;
						vet[i] = num;
					}
					cout << "\n- Numeri della sequenza impostati a " << num << " -\n";
				}

				break;
			
			case 12: //Visualizza i numeri della sequenza
				visualizza_vettore(vet, d);
				break;
			
			case 13: //Somma dei numeri della sequenza
				cout << "La somma di tutti i numeri della sequenza e' " << somma(vet, d) << "\n";
				break;
			
			case 14: //Prodotto dei numeri della sequenza
				P = 1;
				for(i = 0; i < d; i++) P *= vet[i]; //moltiplicazione di ogni numero del vettore con il risultato precedente fino ad ottenere il prodotto tra tutti i numeri del vettore
				
				cout << "Il prodotto di tutti i numeri della sequenza e' " << P << "\n";
				break;
			
			case 15: //M.C.D tra i numeri della sequenza
				R = MCD(vet[0], vet[1]); 				   //il primo M.C.D (primo e secondo numero della sequenza)
				for(i = 2; i < d; i++) R = MCD(R, vet[i]); //dal secondo M.C.D in poi si trova con il M.C.D precedente e il numero attuale
				
				cout << "Il Massimo Comune Divisore tra i numeri della sequenza e' " << R << "\n";
				break;
			
			case 16: //m.c.m tra i numeri della sequenza
				R = mcm(vet[0], vet[1]); 			   	   //il primo m.c.m (primo e secondo numero della sequenza)
				for(i = 2; i < d; i++) R = mcm(R, vet[i]); //dal secondo m.c.m in poi si trova con il M.C.D precedente e il numero attuale

				cout << "Il minimo comune multiplo tra i numeri della sequenza e' " << R << "\n";
				break;
			
			case 17: //Media aritmetica dei numeri della sequenza
				cout << "Media aritmetica dei numeri che compongono la sequenza: " << (float) somma(vet, d) / d << "\n";
				break;
			
			case 21: //Ordinamento crescente della sequenza
				cout << "\n- Ordinamento crescente della sequenza -";

				conferma = chiedi_conferma();
				if(conferma == true) { //se l'utente conferma di voler eseguire l'operazione
					for(i = 0; i < d - 1; i++) {
						for(j = i; j < d; j++) if(vet[i] > vet[j]) scambia_num(&vet[i], &vet[j]);
					}
					visualizza_vettore(vet, d);
				}

				break;

			case 22: //Ordinamento decrescente della sequenza
				cout << "\n- Ordinamento decrescente della sequenza -";

				conferma = chiedi_conferma();
				if(conferma == true) { //se l'utente conferma di voler eseguire l'operazione
					for(i = 0; i < d - 1; i++) {
						for(j = i; j < d; j++) if(vet[i] < vet[j]) scambia_num(&vet[i], &vet[j]);
					}
					visualizza_vettore(vet, d);
				}

				break;
			
			case 23: //Conteggio numeri pari e dispari nella sequenza
				CP=0;
				for(i = 0; i < d; i++) if(se_pari(vet[i]) == true) CP++;
				
				cout << "Totale posizioni: " << d;
				cout << "\n     numeri pari: " << CP;
				cout << "\n  numeri dispari: " << d - CP << "\n";

				break;
			
			case 24: //Conteggio numeri primi e composti nella sequenza
				CPR=0;
				for(i = 0; i < d; i++) if(se_primo(vet[i]) == true) CPR++;
				
				cout << "Totale posizioni: " << d;
				cout << "\n    numeri primi: " << CPR;
				cout << "\n numeri composti: " << d - CPR << "\n";

				break;
			
			case 25: //Frequenza di un numero nella sequenza
				CK=0;
				cout << "\nInserisci il numero di cui verificare la frequenza nella sequenza: "; cin >> k;
				for(i = 0; i < d; i++) if(vet[i] == k) CK++;
				
				cout << k << " e' presente " << CK << " volta(e) nella sequenza\n";
				break;
			
		}
	}while(scelta != -1);
}