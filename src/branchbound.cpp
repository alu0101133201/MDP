/*
 * Autor: Sergio Guera Arencibia
 * alu0101133201@ull.edu.es
 * Universidad de La Laguna
 * 22-04-20
 * Fichero que describe las clasea que implementarán
 * el algoritmo de ramificación y poda
 */

#include "branchbound.hpp"

branchBound::branchBound(vectors myVectors, int m):
    greedy1(myVectors, m),
    MDP(myVectors, m),
    myTree(myVectors, m) {}

branchBound::~branchBound() {

}

float branchBound::solve() {
  currentBound = greedy1.solve();
  
  myTree.writeTree(std::cout);
  myTree.initializeTree();
  std::cout << "\n\n";
  myTree.writeTree(std::cout);
  myTree.expandNode(myTree.expansibleNodes[0]);

  myTree.writeTree(std::cout);

}