#include "cadena.h"

#include <algorithm>
#include <iostream>
#include <string>


Cadena::Cadena(std::string nombre) : palabra_(nombre) {
  longitud_ = palabra_.size();
}

// Inversa
std::string Cadena::Inversa() {
  std::string cadena = palabra_;
  std::reverse(cadena.begin(), cadena.end());
  return cadena;
}

bool Cadena::operator<(const Cadena& comp) const {
  return palabra_ < comp.palabra_;
}

// Entrada y Salida
void Cadena::Read(std::istream& is) {
  is >> palabra_;
  longitud_ = palabra_.size();
}

void Cadena::Write(std::ostream& os) const {
  os << palabra_ << std::endl;
}

// Sobrecarga de operadores
std::istream& operator>>(std::istream& is, Cadena& c) {
  c.Read(is);
  return is;
}


std::ostream& operator<<(std::ostream& os, const Cadena& c) {
  c.Write(os);
  return os;
}


