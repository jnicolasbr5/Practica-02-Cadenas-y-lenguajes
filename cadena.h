// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Juan Nicolás Becerra Rogatinscaia
// Correo: alu0101743011@ull.edu.es
// Fecha: 23/09/2025
// Descripción Clase Cadena:
// Representa una cadena de símbolos.
// Calcula la inversa y la longitud.
// Historial de modificaciones:
// Bug fix 1 - El constructor por defecto es una cadena vacía con longitud 0.
// Bug fix 2 - Añado la sobrecarga < para ordenar las cadenas en un set, 
//             alfabéticamente y por tamaño.

#pragma once

#include <string>

class Cadena {
  private:
    std::string palabra_;
    int longitud_;

  public:
    Cadena() : palabra_("&"), longitud_(0) {}
    Cadena(const std::string& nombre);

    // Cadena inversa
    std::string Inversa();

    // Getters
    int GetLongitud() const {return longitud_ ;}
    std::string GetCadena() const {return palabra_;}

    // Entrada y Salida
    void Read(std::istream& is);
    void Write(std::ostream& os) const;

    // Sobrecarga para comparar cadenas
    bool operator<(const Cadena& comp) const;
};

// Sobrecarga de operadores
std::istream& operator>>(std::istream& is, Cadena& c);
std::ostream& operator<<(std::ostream& os, const Cadena& c);
