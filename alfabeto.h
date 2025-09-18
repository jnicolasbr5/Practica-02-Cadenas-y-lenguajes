#pragma once

#include <set>
#include <string>

class Alfabeto {
  private: 
    std::set<char> alfabeto_;

  public:
    Alfabeto(const std::string& elementos);
};