#include "alfabeto.h"

Alfabeto::Alfabeto(const std::string& elementos) {
  for (char c : elementos) {
    alfabeto_.insert(c);
  }
}
