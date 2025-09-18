#include "cadena.h"

#include <algorithm>

// Inversa
std::string Cadena::Inversa(const std::string& palabra) {
  std::string cadena = reverse(palabra.begin(), palabra.end());
  return cadena;
}

// Cadena vacía


// Prefijos y sufijos