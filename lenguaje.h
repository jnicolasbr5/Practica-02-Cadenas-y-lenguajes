#pragma once

#include <set>

#include "cadena.h"

class Lenguaje {
  private:
    std::set<Cadena> lenguaje_;
    int tamaño_;

  public:
    Lenguaje() : lenguaje_{Cadena("&")}, tamaño_(1) {};

    void Reiniciar();
  // Entrada y Salida
    void Write(std::ostream& os) const;
    
  // Cadenas
    void Sufijos(const Cadena& c);
    void Prefijos(const Cadena& c);
};

std::ostream& operator<<(std::ostream& os, const Lenguaje& l);
