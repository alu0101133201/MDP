/*
 * Autor: Sergio Guera Arencibia
 * alu0101133201@ull.edu.es
 * Universidad de La Laguna
 * 22-04-20
 * Fichero que describe las clasea que implementarán
 * el algoritmo de ramificación y poda
 */

#include "branchbound.hpp"

branchBound::branchBound(vectors myVectors, int m, int cardi, int stopCriteria, int maxIterations, bool depth):
    greedy1(myVectors, m),
    greedy2(myVectors, m),
    graspAlg(myVectors, m, cardi, stopCriteria, maxIterations),
    MDP(myVectors, m),
    myTree(myVectors, m, depth) {}

branchBound::~branchBound() {}

float branchBound::solve() {
  myTree.bestUpperBound = graspAlg.solve();
  myTree.bestSolution = graspAlg.getBestSolution();
  std::cout << "cota: " << myTree.bestUpperBound << "\n";
  myTree.initializeTree();
  
  while (myTree.expansibleNodes.size() != 0) {
    node currentNode = myTree.getNextToExpand();
    myTree.expandNode(currentNode);
    myTree.prune();
  }
  bestSolutionValue = myTree.bestUpperBound ;
  myTree.writeTree(std::cout);
  return (myTree.bestUpperBound);
}