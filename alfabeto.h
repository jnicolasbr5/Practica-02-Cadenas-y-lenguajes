// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Juan Nicolás Becerra Rogatinscaia
// Correo: alu0101743011@ull.edu.es
// Fecha: 23/09/2025

#pragma once

#include <iostream>
#include <set>
#include <string>

#include "cadena.h"

class Alfabeto {
  private: 
    std::set<char> simbolos_;
    unsigned tamaño_alfabeto_ = 0;
    std::string cadena_alfabeto_;

  public:
    Alfabeto() : tamaño_alfabeto_(0) {};
    bool IsEmpty() const;

    // Getter
    std::set<char> GetAlfabeto() const;

    // Validez Alfabeto - Cadena
    void ComprobarAlfabetoCadena(const Cadena& palabra);

    // Entrada y Salida
    void Write(std::ostream& os) const;
    void Read(std::istream& is);  
};

// Sobrecarga de operadores
std::istream& operator>>(std::istream& is, Alfabeto& alf);
std::ostream& operator<<(std::ostream& os, const Alfabeto& alf);