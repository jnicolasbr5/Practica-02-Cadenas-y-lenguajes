// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Juan Nicolás Becerra Rogatinscaia
// Correo: alu0101743011@ull.edu.es
// Fecha: 23/09/2025
// Descripción Clase Alfabeto:
// Representa un alfabeto que contiene símbolos.
// Verifica si una cadena está formada por los símbolos del alfabeto
// Estructura de datos principal:
// - std::set<char> - almacena símbolos de manera ordenada
// Historial de modificaciones:
// Bug fix 1 - Corregida la llamada de funciones en sobrecargas.
// Bug fix 2 - Añado IsEmpty() para vaciar el alfabeto al añadir uno nuevo.
// Bug fix 3 - ComprobarAlfabetoCadena() verifica que los símbolos de las
//             cadenas existen en el alfabeto

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

    // Validez Alfabeto - Cadena
    void ComprobarAlfabetoCadena(const Cadena& palabra);

    // Entrada y Salida
    void Write(std::ostream& os) const;
    void Read(std::istream& is);  
};

// Sobrecarga de operadores
std::istream& operator>>(std::istream& is, Alfabeto& alf);
std::ostream& operator<<(std::ostream& os, const Alfabeto& alf);