/*
 * Autor: Sergio Guera Arencibia
 * alu0101133201@ull.edu.es
 * Universidad de La Laguna
 * 22-04-20
 * Fichero que implementa las clases que implementarán
 * el algoritmo destructivo voraz del algoritmo MDP
 */

#include "destructiveGreedy.hpp"


DestructiveGreedy::DestructiveGreedy(vectors myVectors, int m):
  MDP(myVectors, m) {}

DestructiveGreedy::~DestructiveGreedy() {}

int DestructiveGreedy::getNearPoint(std::vector<float> center, vectors points) {
  int maxIndex = -1;
  float maxValue = FLT_MAX;

  for (int i = 0; i < points.getSize(); i++) {
    float currentDistance = (distBetVect(center, points.getSubvector(i)));
    if (currentDistance < maxValue) {
      maxIndex = i;
      maxValue = currentDistance;
    }
  }
  return (maxIndex);
}

void DestructiveGreedy::buildInitialSol() {
  bestSolution = vectorsData;
  bestSolutionValue = maxDiversity(bestSolution);
}

float DestructiveGreedy::solve() {
  buildInitialSol();
  do {
    std::vector<float> currentCenter = getCenter(bestSolution);

    bestSolution.deleteData(getNearPoint(currentCenter, bestSolution));
  } while (bestSolution.getSize() < stopNumber);
  return (maxDiversity(bestSolution));

}