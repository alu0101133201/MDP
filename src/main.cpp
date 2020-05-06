#include <iostream>
#include "vectors.hpp"
#include "MDP.hpp"
#include "constructiveGreedy.hpp"
#include "destructiveGreedy.hpp"

int main(int argc, char *argv[]) {

  try {
    if (argc <= 1) {
      throw "Argumentos suministrados insuficientes\n";
    }
    std::string fileName(argv[1]);
    // std::string base_filename = fileName.substr(fileName.find_last_of("/") + 1);
    vectors prueba(fileName);
    ConstructiveGreedy constGred(prueba, 6);
    DestructiveGreedy destGred(prueba, 6);

    std::cout << "---GREEDY CONSTRUCTIVO---\n";
    constGred.solve();
    constGred.write(std::cout);
    std::cout << "---GREEDY DESTRUCTIVO---\n";
    destGred.solve();
    destGred.write(std::cout);

} catch(const char* e) {
  std::cout << e;
  return(1);
}
  return (0);
}
