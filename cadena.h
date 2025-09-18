#pragma once

#include <string>
// cadena vacia simbolo &
class Cadena {
  private:
    std::string palabra_;
    int longitud_;

  public:
    Cadena(const std::string& palabra) : palabra_(palabra), longitud_(palabra.size()) {}
    std::string Inversa(const std::string& cadena);
    int GetLongitud() const {return longitud_ ;}

};