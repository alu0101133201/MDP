/*
 * Autor: Sergio Guera Arencibia
 * alu0101133201@ull.edu.es
 * Universidad de La Laguna
 * 22-04-20
 * Fichero que describe la clase abstracta maxmeandp. Esta 
 * sera la clase padre de diferentes clases que implementarán
 * un algoritmo de resolución para el problema
 */

#include "MDP.hpp"

MDP::MDP(vectors myVectors, int m) {
  vectorsData = myVectors;
  bestSolution.setDimension(myVectors.getDimension());
  stopNumber = m;
}

MDP::~MDP() {}


float MDP::maxDiversity(vectors myVectors) {
  float finalResult = 0;

  for (int i = 0; i < myVectors.getSize() - 1; i++) {
    for (int j = i + 1; j < myVectors.getSize(); j++) {
      finalResult += distBetVect(myVectors.getSubvector(i), myVectors.getSubvector(j));
    }
  }
  bestSolutionValue = finalResult;
  return (finalResult);
}


std::vector<float> MDP::getCenter(vectors currentVectors) {
  std::vector<float> center;

  for (int i = 0; i < currentVectors.getDimension(); i++) {
    float currentSum = 0;
    for (int j = 0; j < currentVectors.getSize(); j++) {
      currentSum += currentVectors.getSubvector(j)[i];
    }
    currentSum /= currentVectors.getSize();
    center.push_back(currentSum);
  }
  return center;
}

float MDP::distBetVect(std::vector<float> first, std::vector<float> second) {
  float totalSum = 0;

  for (int i = 0; i < vectorsData.getDimension(); i++) {
    totalSum += pow ((first[i] - second[i]), 2.0);
  }
  return(sqrt(totalSum));
}


std::ostream& MDP::write(std::ostream& os) {
  os << "Solución al problema MDP\n";
  os << "Valor de la solución: " << bestSolutionValue << "\n";
  bestSolution.write(os);
}