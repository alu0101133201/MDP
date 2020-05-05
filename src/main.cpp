#include <iostream>
#include "vectors.hpp"

int main(int argc, char *argv[]) {

  try {
    if (argc <= 1) {
      throw "Argumentos suministrados insuficientes\n";
    }
    std::string fileName(argv[1]);
    // std::string base_filename = fileName.substr(fileName.find_last_of("/") + 1);
    vectors prueba(fileName);

} catch(const char* e) {
  std::cout << e;
  return(1);
}
  return (0);
}