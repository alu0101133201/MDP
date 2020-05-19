/*
 * Autor: Sergio Guera Arencibia
 * alu0101133201@ull.edu.es
 * Universidad de La Laguna
 * 22-04-20
 * Fichero que implementa las clases que implementarán
 * un clase para testear la búsqueda local
 */

#include "localSearch.hpp"

localSearch::localSearch(vectors myVectors, int m):
    greedy1(myVectors, m),
    greedy2(myVectors, m),
    MDP(myVectors, m) {}

localSearch::~localSearch() {}

float localSearch::solve() {
  using namespace std::chrono;

  high_resolution_clock::time_point t1 = high_resolution_clock::now();
  greedy1.solve();
  greedy1.postProcessing();
  high_resolution_clock::time_point t2 = high_resolution_clock::now();
  duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
  std::cout << "CONSTRUCTIVO " << time_span.count() << " seconds.\n";
  greedy1.write(std::cout);
  t1 = high_resolution_clock::now();
  greedy2.solve();
  greedy2.postProcessing();
  t2 = high_resolution_clock::now();
  time_span = duration_cast<duration<double>>(t2 - t1);
  std::cout << "DESTRUCTIVO " << time_span.count() << " seconds.\n";
  greedy2.write(std::cout);
  return (greedy1.getBestSolutionValue());
}
