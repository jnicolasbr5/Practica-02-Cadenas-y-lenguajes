#pragma once

#include <set>

#include "cadena.h"

Cadena cadena_vacia;

class Lenguaje {
  private:
    std::set<Cadena> prefijos_;
    std::set<Cadena> sufijos_;

  public:
  
  // Entrada y Salida
    void Read(std::istream& is);
    void Write(std::ostream& os) const;
  
};

std::ostream& operator<<(std::ostream& os, const Cadena& c);
std::istream& operator>>(std::istream& is, Cadena& c);