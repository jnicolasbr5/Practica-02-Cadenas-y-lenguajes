#pragma once

#include <string>

class Cadena {
  private:
    std::string palabra_;
    int longitud_;

  public:
    Cadena() : palabra_(), longitud_(0) {}
    Cadena(std::string nombre);
    std::string Inversa();
    int GetLongitud() const {return longitud_ ;}
    std::string GetCadena() const {return palabra_;}

    // Entrada y Salida
    void Read(std::istream& is);
    void Write(std::ostream& os) const;

    bool operator<(const Cadena& comp) const;
};

std::ostream& operator<<(std::ostream& os, const Cadena& c);
std::istream& operator>>(std::istream& is, Cadena& c);