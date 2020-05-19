#define ITERACIONES 0
#define SINMEJORA 1
#define NUMBEROFITERATION 10
#define CARDINALITY 3
#define M 4

#include <iostream>
#include <chrono>

#include "vectors.hpp"
#include "MDP.hpp"
#include "constructiveGreedy.hpp"
#include "destructiveGreedy.hpp"
#include "grasp.hpp"
#include "localSearch.hpp"
#include "branchbound.hpp"

int main(int argc, char *argv[]) {
  using namespace std::chrono;

  try {
    if (argc <= 4) {
      throw "Argumentos suministrados insuficientes\n";
    }
    std::string fileName(argv[1]);
    // std::string base_filename = fileName.substr(fileName.find_last_of("/") + 1);
    vectors prueba(fileName);
    ConstructiveGreedy constGred(prueba, atoi(argv[2]));
    DestructiveGreedy destGred(prueba, atoi(argv[2]));
    localSearch testLocal(prueba, atoi(argv[2]));
    Grasp testGrasp(prueba, atoi(argv[2]), atoi(argv[3]), ITERACIONES, atoi(argv[4]));
    branchBound bab(prueba, atoi(argv[2]), atoi(argv[3]), ITERACIONES, atoi(argv[4]), true);

    std::cout << "---GREEDY CONSTRUCTIVO---\n";

    constGred.solve();
    constGred.write(std::cout);
    std::cout << "---GREEDY DESTRUCTIVO---\n";
    destGred.solve();
    destGred.write(std::cout);
    std::cout << "---LOCAL CON GREEDIES---\n";

    // high_resolution_clock::time_point t1 = high_resolution_clock::now();

    testLocal.solve();
    // high_resolution_clock::time_point t2 = high_resolution_clock::now();
    // duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
    // std::cout << "It took me " << time_span.count() << " seconds.\n";

    std::cout << "---GRASP---\n";
    testGrasp.solve();
    testGrasp.write(std::cout);

    std::cout << "---RAMIFICACIÓN Y PODA---\n";
    // high_resolution_clock::time_point t1 = high_resolution_clock::now();
    bab.solve();
    bab.write(std::cout);
    // high_resolution_clock::time_point t2 = high_resolution_clock::now();
    // duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
    // std::cout << "It took me " << time_span.count() << " seconds.\n";

} catch(const char* e) {
  std::cout << e;
  return(1);
}
  return (0);
}
