#include "cadena.h"

#include <algorithm>

// Inversa
std::string Cadena::Inversa(const std::string& palabra) {
  std::string cadena = palabra;
  std::reverse(palabra.begin(), palabra.end());
  return cadena;
}

// Cadena vacía


// Prefijos y sufijos


//Entrada y Salida
void Cadena::Read(std::istream& is) {
  is >> palabra_;
}

void Cadena::Write(std::ostream& os) const {
  os << palabra_;
}

// Sobrecarga de operadores
std::ostream& operator<<(std::ostream& os, const Cadena& c) {
  c.Write(os);
  return os;
}

std::istream& operator>>(std::istream& is, Cadena& c) {
  c.Read(is);
  return is;
}
