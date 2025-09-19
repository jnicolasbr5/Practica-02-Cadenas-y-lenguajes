#pragma once

#include <iostream>
#include <set>
#include <string>

class Alfabeto {
  private: 
    std::set<char> alfabeto_;
    unsigned tamaño_ = 0;
    std::string elementos_;

  public:
    Alfabeto() : tamaño_(0) {};

    bool IsEmpty() const;

    // Entrada y Salida
    void Write(std::ostream& os) const;
    void Read(std::istream& is);

    // Sobrecarga de operadores 
  
};

std::istream& operator>>(std::istream& is, Alfabeto& alf);
std::ostream& operator<<(std::ostream& os, const Alfabeto& alf);