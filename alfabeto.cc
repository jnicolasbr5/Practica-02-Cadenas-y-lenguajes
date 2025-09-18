#include <iostream>

#include "alfabeto.h"

Alfabeto::Alfabeto(const std::string& elementos) {
  for (char c : elementos) {
    alfabeto_.insert(c);
  }
}

void Alfabeto::Mostrar() {
  int tamaño = alfabeto_.size(), i = 1;
  std::cout << "Σ = {";
  for (char c : alfabeto_) {
    std::cout << c;
    if (i != tamaño) {
      std::cout << ", ";
    }
    i++;
  }
  std::cout << "}" << std::endl;
}