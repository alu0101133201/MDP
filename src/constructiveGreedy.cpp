/*
 * Autor: Sergio Guera Arencibia
 * alu0101133201@ull.edu.es
 * Universidad de La Laguna
 * 22-04-20
 * Fichero que implementa las clases que implementarán
 * el algoritmo constructivo voraz del algoritmo MDP
 */

#include "constructiveGreedy.hpp"


ConstructiveGreedy::ConstructiveGreedy(vectors myVectors, int m):
  MDP(myVectors, m) {}

ConstructiveGreedy::~ConstructiveGreedy() {}

int ConstructiveGreedy::getFarPoint(std::vector<float> center, vectors points) {
  int maxIndex = -1;
  float maxValue = FLT_MIN;

  for (int i = 0; i < points.getSize(); i++) {
    float currentDistance = (distBetVect(center, points.getSubvector(i)));
    if (currentDistance > maxValue) {
      maxIndex = i;
      maxValue = currentDistance;
    }
  }
  return (maxIndex);
}


float ConstructiveGreedy::solve() {
  vectors myAuxData = vectorsData;  
  std::vector<float> currentCenter = getCenter(myAuxData);
  // std::cout << "\nPrimer centro:\n";
  // for (int i= 0; i < currentCenter.size(); i++)
  //   std::cout << currentCenter[i] << " ";
  // std::cout << "\n";

  do {
    int indexOfFar = getFarPoint(currentCenter, myAuxData);

    bestSolution.pushData(myAuxData.getSubvector(indexOfFar));
    myAuxData.deleteData(indexOfFar);
    currentCenter = getCenter(bestSolution);
  } while (bestSolution.getSize() < stopNumber);
  return (maxDiversity(bestSolution));
}