#pragma once

#include <string>
// cadena vacia simbolo &
class Cadena {
  private:
    std::string palabra_;
    unsigned longitud_;

  public:
    Cadena() : longitud_(0), palabra_() {}
    Cadena(std::string nombre);
    std::string Inversa();
    int GetLongitud() const {return longitud_ ;}
    std::string GetCadena() const {return palabra_;}

    // Entrada y Salida
    void Read(std::istream& is);
    void Write(std::ostream& os) const;
};

std::ostream& operator<<(std::ostream& os, const Cadena& c);
std::istream& operator>>(std::istream& is, Cadena& c);