#include <iostream>

#include "alfabeto.h"

void Alfabeto::Write(std::ostream& os) const {
  unsigned i = 1;
  os << "Σ = {";
  for (char c : alfabeto_) {
    os << c;
    if (i != tamaño_) {
      os << ", ";
    }
    i++;
  }
  os << "}" << std::endl;
}

void Alfabeto::Read(std::istream& is) {
  is >> cadena_;
  for (char c : cadena_) {
    alfabeto_.insert(c);
  }
  tamaño_ = alfabeto_.size();
}

std::ostream& operator<<(std::ostream& os, const Alfabeto& alf) {
  alf.Write(os);
  return os;
}

std::istream& operator>>(std::istream& is, Alfabeto& alf) {
  alf.Read(is);
  return is;
}