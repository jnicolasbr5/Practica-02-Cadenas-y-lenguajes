// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Juan Nicolás Becerra Rogatinscaia
// Correo: alu0101743011@ull.edu.es
// Fecha: 16/09/2025
// Archivo cya-P02-strings.cc: programa cliente.
// Contiene la función main del proyecto que usa las clases X e Y
// para ... (indicar brevemente el objetivo)
// Referencias:
// Enlaces de interés
// Historial de revisiones
// 16/09/2025 - Creación (primera versión) del código

// 1 ./ p02_strings filein . txt fileout . txt opcode

#include <fstream>
#include <iostream>
#include <string>

#include "alfabeto.h"
#include "cadena.h"
#include "lenguaje.h"

// Cadena / Alfabeto (abbbab   ab) Entrada file

int main (int argc, char* argv[]) {
  if (argc == 2 && argv[1] == "--help") {
    std::cout << "Modo de empleo: ./p02_strings filein.txt fileout.txt opcode" << std::endl;
    std::cout << "Debes escribir por línea de comandos el nombre del fichero de entrada,"
              << "el nombre del fichero de salida y un código de operación" << std::endl;
    return 1;
  } else if (argc != 4) {
    std::cout << "Modo de empleo: ./p02_strings filein.txt fileout.txt opcode" << std::endl;
    std::cout << "Pruebe './p02_strings --help' para más información." << std::endl;
    return 1;
  }

  std::ifstream Archivo("filein.txt");
  //getline dividing it into two lines
  
  

  return 0;
}

