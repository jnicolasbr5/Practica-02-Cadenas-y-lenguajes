// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Juan Nicolás Becerra Rogatinscaia
// Correo: alu0101743011@ull.edu.es
// Fecha: 23/09/2025

#include <algorithm>
#include <iostream>
#include <set>
#include <string>

#include "lenguaje.h"

// Reinicio los valores del lenguaje añadiendo la cadena vacía
void Lenguaje::Reiniciar() {
  conjunto_.clear();
  conjunto_.insert(Cadena("&"));
  tamaño_lenguaje_ = 1;
}

// Añade todos los sufijos de una cadena a un lenguaje
void Lenguaje::Sufijos(const Cadena& c) {
  if (tamaño_lenguaje_ != 1) Reiniciar(); // Si el lenguaje tiene otras cadenas, lo reinicia
  tamaño_lenguaje_ += c.GetLongitud(); // Nº de cadenas que se van a añadir al lenguaje
  std::string palabra = c.GetCadena();
  std::string concatenacion;
  for (int i = c.GetLongitud() - 1; i >= 0; i--) {
    concatenacion = palabra[i] + concatenacion; // Concateno delante de la cadena
    conjunto_.insert(Cadena(concatenacion));
  }
}

// Añade todos los sufijos de una cadena a un lenguaje
void Lenguaje::Prefijos(const Cadena& c) {
  if (tamaño_lenguaje_ != 1) Reiniciar();
  tamaño_lenguaje_ += c.GetLongitud();
  std::string concatenacion;
  for (char d : c.GetCadena()) {
    concatenacion += d; // Concateno detrás de la cadena
    conjunto_.insert(Cadena(concatenacion));
  }
}

// Imprime las cadenas de un lenguaje en un flujo de salida
void Lenguaje::Write(std::ostream& os) const {
  int i = 1;
  os << "{";
  for (Cadena c : conjunto_) {
    os << c.GetCadena();
    if (i != tamaño_lenguaje_) {
      os << ", ";
    }
    i++;
  }
  os << "}" << std::endl;
}

// Sobrecarga del operador << para imprimir un Lenguaje
std::ostream& operator<<(std::ostream& os, const Lenguaje& l) {
  l.Write(os);
  return os;
}


