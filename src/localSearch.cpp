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
  greedy1.solve();
  greedy1.postProcessing();
  greedy1.write(std::cout);
  greedy2.solve();
  greedy2.postProcessing();
  greedy2.write(std::cout);
  return (greedy1.getBestSolutionValue());
}
