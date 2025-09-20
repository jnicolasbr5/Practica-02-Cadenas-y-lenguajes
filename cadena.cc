// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Juan Nicolás Becerra Rogatinscaia
// Correo: alu0101743011@ull.edu.es
// Fecha: 23/09/2025

#include "cadena.h"

#include <algorithm>
#include <iostream>
#include <string>

// Construye el objeto con la cadena y su longitud
Cadena::Cadena(std::string nombre) : palabra_(nombre) {
  longitud_ = palabra_.size();
}

// Devuelve la cadena inversa
std::string Cadena::Inversa() {
  std::string cadena = palabra_;
  std::reverse(cadena.begin(), cadena.end());
  return cadena;
}

// Sobrecarga del operador < para comparar Cadenas
// Comparo las cadenas por longitud, considerando como menor la cadena más corta.
// Si ambas cadenas tienen la misma longitud, las comparo alfabéticamente
bool Cadena::operator<(const Cadena& comp) const {
  if (palabra_.size() == comp.palabra_.size()) { // Alfabéticamente
    return palabra_ < comp.palabra_;
  }
  return palabra_.size() < comp.palabra_.size(); // Por tamaño
}

// Lee la cadena desde un flujo de entrada
void Cadena::Read(std::istream& is) {
  is >> palabra_;
  longitud_ = palabra_.size();
}

// Imprime la cadena en un flujo de salida
void Cadena::Write(std::ostream& os) const {
  os << palabra_ << std::endl;
}

// Sobrecarga del operador >> para leer una Cadena
std::istream& operator>>(std::istream& is, Cadena& c) {
  c.Read(is);
  return is;
}

// Sobrecarga del operador << para imprimir una Cadena
std::ostream& operator<<(std::ostream& os, const Cadena& c) {
  c.Write(os);
  return os;
}


