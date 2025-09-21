// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Juan Nicolás Becerra Rogatinscaia
// Correo: alu0101743011@ull.edu.es
// Fecha: 23/09/2025
// Archivo cya-P02-strings.cc: programa cliente.
// Función main del proyecto:
// Usa las clases Alfabeto, Cadena y Lenguaje para:
// Leer datos por un archivo de entrada, realizar las operaciones
// deseadas, y escribir los resultados en un archivo de salida.
// Referencias:
// Set -> https://www.youtube.com/watch?v=i02_JDJS3yw
// Archivos -> https://www.w3schools.com/cpp/cpp_files.asp
// Enum -> https://agrawalsuneet.github.io/blogs/enum-vs-enum-class-in-c++/
// Exit -> https://www.geeksforgeeks.org/cpp/exit-code-1-in-cpp/
// This -> https://www.geeksforgeeks.org/cpp/this-pointer-in-c/
// Historial de revisiones:
// Main -> https://github.com/jnicolasbr5/Practica-02-Cadenas-y-lenguajes
// 18/09/2025 - Creación (primera versión) del código 
// -> https://github.com/jnicolasbr5/Practica-02-Cadenas-y-lenguajes/tree/dia1
// 19/09/2025 - Segunda versión del código -> 
// https://github.com/jnicolasbr5/Practica-02-Cadenas-y-lenguajes/tree/dia2
// 20/09/2025 - Tercera versión del código -> 
// https://github.com/jnicolasbr5/Practica-02-Cadenas-y-lenguajes/tree/dia3
// ./p02_strings filein.txt fileout.txt codigo_operacion

#include <fstream>
#include <iostream>
#include <set>
#include <string>

#include "alfabeto.h"
#include "cadena.h"
#include "lenguaje.h"

// Almacena los posibles errores con los parámetros
enum class Terminal { // 
  Help,
  Argumentos,
  Archivo, 
  Opcode
};

// Muestra por pantalla los errores
void MostrarUsoError(Terminal opcion, const std::string& caso = "") {
  std::cout << "Modo de empleo: ./p02_strings "
            <<"filein.txt fileout.txt opcode\n" << std::endl;
  switch (opcion) {
    case Terminal::Argumentos: // Fallo en el número de argumentos
      break;
    case Terminal::Help: // --help
      std::cout << "El programa recibe cadenas y alfabetos desde un archivo de "
                << "entrada, realiza la operación indicada y muestra el resultado"
                << "en un archivo de salida." << std::endl;
      std::cout << "<archivo de entrada> -> formato .txt" << std::endl;
      std::cout << "<archivo de salida> -> formato .txt" << std::endl;
      std::cout << "<código de operación> -> operación que realiza." << std::endl;
      std::cout << "\nLista de códigos de operación:" << std::endl;
      std::cout << "<Alfabeto> -> Muestra el alfabeto asociado a las cadenas."
                << std::endl;
      std::cout << "<Longitud> -> Muestra la longitud de cada cadena." << std::endl;
      std::cout << "<Inversa> -> Muestra la inversa de cada cadena." << std::endl;
      std::cout << "<Prefijos> -> Muestra el conjunto de cadenas que son prefijos" 
                << " de cada cadena de entrada." << std::endl;
      std::cout << "<Sufijos> -> Muestra el conjunto de cadenas que son sufijos."
                << " de cada cadena de entrada." << std::endl;
      return;
    case Terminal::Archivo: // Fallo del archivo
      std::cerr << "El archivo " << caso << " no pudo ser abierto" << std::endl;
      break;
    case Terminal::Opcode: // Fallo del código de operación
    std::cerr << "La operación '" << caso << "' es incorrecta." << std::endl;
    std::cerr << "Códigos de operación: <Alfabeto> <Longitud> <Inversa> "
              << "<Prefijos> <Sufijos>" << std::endl;
    break;
  }
  std::cerr << "Pruebe './p02_strings --help' para más información." 
            << std::endl;
}

int main(int argc, char* argv[]) {
  if (argc == 2 && std::string(argv[1]) == "--help") {
    MostrarUsoError(Terminal::Help);
    return 0;
  }
  if (argc != 4) {
    MostrarUsoError(Terminal::Argumentos);
    return 1;
  }
  std::ifstream archivo_entrada(argv[1]);
  if (!archivo_entrada.is_open()) {
    MostrarUsoError(Terminal::Archivo, argv[1]);
    return 1;
  }
  std::ofstream archivo_salida(argv[2]);
  if (!archivo_salida.is_open()) {
    MostrarUsoError(Terminal::Archivo, argv[2]);
    return 1;
  }
  std::string codigo_operacion = argv[3];
  std::set<std::string> lista_codigos = {"Alfabeto", "Longitud", 
                                        "Inversa", "Prefijos", "Sufijos"};
  
  // Comprueba si el código de operación dado coincide 
  if (lista_codigos.find(codigo_operacion) == lista_codigos.end()) {
    MostrarUsoError(Terminal::Opcode, codigo_operacion);
    return 1;
  }
  Alfabeto simbolos;
  Cadena palabra;
  Lenguaje afijos;
  
  // Dadas las cadenas y alfabetos, ejecuta los códigos de operación
  while (archivo_entrada >> palabra >> simbolos) {
    simbolos.ComprobarAlfabetoCadena(palabra);
    if (codigo_operacion == "Alfabeto") {
      archivo_salida << simbolos;
    } else if (codigo_operacion == "Longitud") {
      archivo_salida << palabra.GetLongitud() << std::endl;
    } else if (codigo_operacion == "Inversa") {
      archivo_salida << palabra.Inversa() << std::endl; 
    } else if (codigo_operacion == "Prefijos") {
      afijos.Prefijos(palabra);
      archivo_salida << afijos;
    } else if (codigo_operacion == "Sufijos") {
      afijos.Sufijos(palabra);
      archivo_salida << afijos;
    }
  }
  return 0;
}