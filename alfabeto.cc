// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Juan Nicolás Becerra Rogatinscaia
// Correo: alu0101743011@ull.edu.es
// Fecha: 23/09/2025
// Finalidad del código

#include <iostream>

#include "alfabeto.h"

// Devuelve si el alfabeto está vacío 
bool Alfabeto::IsEmpty() const {
  return simbolos_.empty();
}

// Imprime los símbolos de un alfabeto en un flujo de salida
void Alfabeto::Write(std::ostream& os) const {
  unsigned i = 1;
  os << "{";
  for (char c : simbolos_) {
    os << c;
    if (i != tamaño_alfabeto_) {
      os << ", ";
    }
    i++;
  }
  os << "}" << std::endl;
}

// Lee los símbolos de un alfabeto desde un flujo de entrada
void Alfabeto::Read(std::istream& is) {
  is >> cadena_alfabeto_;
  if (!IsEmpty()) {
    simbolos_.clear();
  }
  for (char c : cadena_alfabeto_) {
    simbolos_.insert(c);
  }
  tamaño_alfabeto_ = simbolos_.size();
}

// Sobrecarga del operador << para imprimir un Alfabeto
std::ostream& operator<<(std::ostream& os, const Alfabeto& alf) {
  alf.Write(os);
  return os;
}

// Sobrecarga del operador >> para leer un alfabeto
std::istream& operator>>(std::istream& is, Alfabeto& alf) {
  alf.Read(is);
  return is;
}