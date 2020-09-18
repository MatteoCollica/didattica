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
#include "chiediconferma_chiedipos.h"
using namespace std;

bool chiedi_conferma() {
    char R;
    
    do { //esegui:
        cout << "\nSei sicuro di voler proseguire?";
        cout << "\nInserisci Y per confermare;";
        cout << "\nInserisci N per annullare: "; cin >> R;
    }while(R != 'Y' && R != 'y' && R != 'N' && R != 'n'); //finché l'utente non effettua una scelta valida

    if(R == 'Y' || R == 'y') { //se la scelta è di confermare (Y/y)
        cout << "-> Operazione confermata \n";
        return true;
    } else { //altrimenti
        cout << "-> Operazione annullata \n";
        return false;
    }
}

int chiedi_pos(int d) {
    int pos;
    
    do { //esegui:
        cin >> pos;
        if(pos < -1 || pos > d - 1) cout << "Posizione non valida, riprova: ";
    }while(pos < -1 || pos > d - 1); //finché non viene inserita una posizione esistente del vettore

    return pos;
}
