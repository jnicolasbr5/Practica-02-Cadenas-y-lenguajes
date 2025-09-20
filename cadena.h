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

#include <string>

class Cadena {
  private:
    std::string palabra_;
    int longitud_;

  public:
    Cadena() : palabra_(), longitud_(0) {}
    Cadena(std::string nombre);

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
