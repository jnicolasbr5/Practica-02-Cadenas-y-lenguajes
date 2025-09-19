#pragma once

#include <string>
// cadena vacia simbolo &
class Cadena {
  private:
    std::string palabra_;
    unsigned longitud_;

  public:
    Cadena() : longitud_(0) {}
    std::string Inversa(const std::string& cadena);
    int GetLongitud() const {return longitud_ ;}

    // Entrada y Salida
    void Read(std::istream& is);
    void Write(std::ostream& os) const;
};