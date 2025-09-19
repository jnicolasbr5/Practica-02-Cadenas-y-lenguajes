#include <iostream>
#include <set>

#include "lenguaje.h"


//Entrada y Salida
void Lenguaje::Read(std::istream& is) {
  is >> ;
  longitud_ = nombre_.size();
}

void Lenguaje::Write(std::ostream& os) const {
  os << "L = {";
  os << 

  os << "}";
}

// Operadores de sobrecarga
std::istream& operator>>(std::istream& is, Lenguaje& l) {
  l.Read(is);
  return is;
}

std::ostream& operator<<(std::ostream& os, const Lenguaje& l) {
  l.Write(os);
  return os;
}


