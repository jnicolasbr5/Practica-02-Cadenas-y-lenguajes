#include <algorithm>
#include <iostream>
#include <set>
#include <string>

#include "lenguaje.h"


void Lenguaje::Clean() {
  lenguaje_.clear();
  tamaño_ = 1;
  lenguaje_.insert(Cadena("&"));
}

bool Lenguaje::IsEmpty() const {
  return lenguaje_.empty();
}


/* 
void Lenguaje::Sufijos(const Cadena& c) {
  tamaño_ += c.GetLongitud();
  std::string palabra = c.GetCadena();
  std::string concatenacion;
  for (int i = c.GetLongitud() - 1; i >= 0; i--) {
    concatenacion = palabra[i] + concatenacion;
    lenguaje_.insert(Cadena(concatenacion));
  }
}
*/

void Lenguaje::Prefijos(const Cadena& c) {
  if (tamaño_ != 1) {
    Clean();
  }
  tamaño_ += c.GetLongitud();
  std::string concatenacion;
  for (char d : c.GetCadena()) {
    concatenacion += d;
    lenguaje_.insert(Cadena(concatenacion));
  }
}


//Entrada y Salida
void Lenguaje::Write(std::ostream& os) const {
  int i = 1;
  os << "{";
  for (Cadena c : lenguaje_) {
    os << c.GetCadena();
    if (i != tamaño_) {
      os << ", ";
    }
    i++;
  }
  os << "} == " << tamaño_ << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Lenguaje& l) {
  l.Write(os);
  return os;
}


