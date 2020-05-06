/*
 * Autor: Sergio Guera Arencibia
 * alu0101133201@ull.edu.es
 * Universidad de La Laguna
 * 22-04-20
 * Fichero que implementa las clases que implementarán
 * el algoritmo grasp del algoritmo MDP
 */

#include "grasp.hpp"


Grasp::Grasp(vectors myVectors, int m):
  MDP(myVectors, m) {}

Grasp::~Grasp() {}



float Grasp::solve() {
  noInSolution = vectorsData;
  bestSolution.pushData(vectorsData.getSubvector(0));
  noInSolution.deleteData(0);
  bestSolution.pushData(vectorsData.getSubvector(1));
  noInSolution.deleteData(0);
  float a = maxDiversity(bestSolution);
  std::cout << "Solución con " << a << "\n";
  bestSolution.write(std::cout);

  localSearch(bestSolution, a);

  std::cout << "Solución con " << a << "\n";
  bestSolution.write(std::cout);

}