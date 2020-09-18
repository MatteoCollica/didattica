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
#include "separi_seprimo.h"

bool se_pari(int A) {
  if (A % 2 == 0) return true;
  else return false;
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