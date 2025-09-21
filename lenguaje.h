// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Juan Nicolás Becerra Rogatinscaia
// Correo: alu0101743011@ull.edu.es
// Fecha: 23/09/2025
// Descripción Clase Lenguaje:
// Representa un lenguaje que contiene cadenas.
// Puedes crear sufijos y prefijos de cadenas, almacenarlos y mostrarlos.
// Estructura de datos principal:
// std::set<Cadena> - almacena cadenas de manera ordenada
// Historial de modificaciones:
// Bug fix 1 - El constructor por defecto contiene una cadena vacía y tiene tamaño 1.
// Bug fix 2 - Reinicio() vacía el lenguaje al crear uno nuevo.

#pragma once

#include <set>

#include "alfabeto.h"
#include "cadena.h"

class Lenguaje {
  private:
    std::set<Cadena> conjunto_;
    int tamaño_lenguaje_;

  public:
    Lenguaje() : conjunto_{Cadena("&")}, tamaño_lenguaje_(1) {};

    // Reinicio
    void Reiniciar();

    // Salida
    void Write(std::ostream& os) const;
    
    // Cadenas
    void Sufijos(const Cadena& c);
    void Prefijos(const Cadena& c);
};

// Sobrecarga de operador
std::ostream& operator<<(std::ostream& os, const Lenguaje& l);
