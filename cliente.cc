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
// Set -> https://www.geeksforgeeks.org/cpp/different-ways-to-iterate-over-a-set-in-c/
// Getline -> https://www.geeksforgeeks.org/cpp/getline-string-c/
// Archivos -> https://www.w3schools.com/cpp/cpp_files.asp
// Librería sstream -> https://www.geeksforgeeks.org/cpp/stringstream-c-applications/
// Historial de revisiones:
// 18/09/2025 - Creación (primera versión) del código -> https://github.com/jnicolasbr5/Practica-02-Cadenas-y-lenguajes/tree/dia1
// 19/09/2025 - Segunda versión del código -> 
// 20/09/2025 - 
// 1 ./ p02_strings filein.txt fileout.txt opcode
// Compilar -> g++ alfabeto.cc cadena.cc lenguaje.cc -o p02_strings

#include <fstream>
#include <iostream>
#include <set>
#include <sstream>
#include <string>

#include "alfabeto.h"
#include "cadena.h"
#include "lenguaje.h"

// Cadena / Alfabeto (abbbab   ab) Entrada file

int main (int argc, char* argv[]) {
  if (argc == 2 && std::string(argv[1]) == "--help") {
    std::cout << "Modo de empleo: ./p02_strings filein.txt fileout.txt opcode" << std::endl;
    std::cout << "Debes escribir por línea de comandos el nombre del fichero de entrada,"
              << "el nombre del fichero de salida y un código de operación" << std::endl;
    return 0;
  } else if (argc != 4) {
    std::cout << "Modo de empleo: ./p02_strings filein.txt fileout.txt opcode" << std::endl;
    std::cout << "Pruebe './p02_strings --help' para más información." << std::endl;
    return 1;
  }
  std::string opcode = argv[3];
  std::set<std::string> codigo_operacion = {"Alfabeto", "Longitud", "Inversa", "Prefijos", "Sufijos"};
  if (codigo_operacion.find(opcode) == codigo_operacion.end()) {
    std::cout << "Estas son las opciones de código de operación: "
              << "Alfabeto, Longitud, Inversa, Prefijos, Sufijos" << std::endl;
    std::cout << "Modo de empleo: ./p02_strings filein.txt fileout.txt opcode" << std::endl;
    return 1;
  }
  std::ifstream archivo_entrada("filein.txt");
  std::ofstream archivo_salida("fileout.txt");

  if (!archivo_entrada.is_open()) {
    std::cout << "El archivo " << argv[1] << " no pudo ser abierto." << std::endl;
    std::cout << "Modo de empleo: ./p02_strings filein.txt fileout.txt opcode" << std::endl;
    return 1;
  }

  Alfabeto alfabeto;
  Cadena cadena;
  Lenguaje lenguaje;
  
  // Código de operación
  while (archivo_entrada >> cadena >> alfabeto) {
    if (opcode == "Alfabeto") {
      archivo_salida << alfabeto << std::endl;
    } else if (opcode == "Longitud") {
      archivo_salida << cadena.GetLongitud() << std::endl;
    } else if (opcode == "Inversa") {
      archivo_salida << cadena.Inversa() << std::endl; 
    } else if (opcode == "Prefijos") {
      lenguaje.Prefijos(cadena);
      std::cout << lenguaje << std::endl;
    } else if (opcode == "Sufijos") {
      lenguaje.Sufijos(cadena);
      std::cout << lenguaje << std::endl;
    }
  }

  archivo_entrada.close();
  archivo_salida.close();
  return 0;
}

