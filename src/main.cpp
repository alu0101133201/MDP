#define ITERACIONES 0
#define SINMEJORA 1
#define NUMBEROFITERATION 1000
#define CARDINALITY 3
#define M 3

#include <iostream>
#include "vectors.hpp"
#include "MDP.hpp"
#include "constructiveGreedy.hpp"
#include "destructiveGreedy.hpp"
#include "grasp.hpp"
#include "localSearch.hpp"
#include "branchbound.hpp"

int main(int argc, char *argv[]) {

  try {
    if (argc <= 1) {
      throw "Argumentos suministrados insuficientes\n";
    }
    std::string fileName(argv[1]);
    // std::string base_filename = fileName.substr(fileName.find_last_of("/") + 1);
    vectors prueba(fileName);
    ConstructiveGreedy constGred(prueba, M);
    DestructiveGreedy destGred(prueba, M);
    localSearch testLocal(prueba, M);
    Grasp testGrasp(prueba, M, CARDINALITY, ITERACIONES, NUMBEROFITERATION);
    branchBound bab(prueba, M);

    // std::cout << "---GREEDY CONSTRUCTIVO---\n";
    // constGred.solve();
    // constGred.write(std::cout);
    // std::cout << "---GREEDY DESTRUCTIVO---\n";
    // destGred.solve();
    // destGred.write(std::cout);
    // std::cout << "---LOCAL CON GREEDIES---\n";
    // testLocal.solve();
    // std::cout << "---GRASP---\n";
    // testGrasp.solve();
    // testGrasp.write(std::cout);
    std::cout << "---RAMIFICACIÓN Y PODA---\n";
    bab.solve();

} catch(const char* e) {
  std::cout << e;
  return(1);
}
  return (0);
}
