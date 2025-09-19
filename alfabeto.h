#pragma once

#include <iostream>
#include <set>
#include <string>

class Alfabeto {
  private: 
    std::set<char> alfabeto_;
    unsigned tamaño_ = 0;
    std::string cadena_;

  public:
    Alfabeto() : tamaño_(0) {};

    // Entrada y Salida
    void Write(std::ostream& os) const;
    void Read(std::istream& is);
};