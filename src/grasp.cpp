/*
 * Autor: Sergio Guera Arencibia
 * alu0101133201@ull.edu.es
 * Universidad de La Laguna
 * 22-04-20
 * Fichero que implementa las clases que implementarán
 * el algoritmo grasp del algoritmo MDP
 */

#include "grasp.hpp"


Grasp::Grasp(vectors myVectors, int m, int card):
  MDP(myVectors, m) {
    cardinality = card;
  }

Grasp::~Grasp() {}


void Grasp::addLRC(std::vector<float> vector, float vectorValue) {
  std::pair<std::vector<float>, float> dummy;
  dummy.first = vector;
  dummy.second = vectorValue;
  int minIndex;
  float minValue = FLT_MIN;

  std::cout << "\n\nEn addLRC con LRC.size(): " << LRC.size() << "\n";
  if (LRC.size() < cardinality)
    LRC.push_back(dummy);
  else {
    for (int i = 0; i < LRC.size(); i++) {
      if (LRC[i].second < minValue) {
        minValue = LRC[i].second;
        minIndex = i;
      }
    }
    if (minValue > vectorValue) {
      LRC[minIndex].first = vector;
      LRC[minIndex].second = vectorValue;
   }
  }
}

void Grasp::buildLRC() {
  LRC.clear();
  std::cout << "LRC TAMAÑO: " << LRC.size() << "\n";
  std::vector<float> center;
  if (bestSolution.getSize() == 0)
    center = getCenter(noInSolution);
  else
    center = getCenter(bestSolution);

  std::cout << "El centro es: \n";
  for (int i = 0; i < center.size(); i++)
    std::cout << center[i] << " ";
  std::cout << "\n";

  std::cout << "Los puntos de los cuales calculo las distancias:\n";
  for (int i = 0; i < noInSolution.getSize(); i++) {
    float currentValue = distBetVect(noInSolution.getSubvector(i), center);
    std::cout << "Distancia: " << currentValue << "punto: \t";
    for (int j = 0; j < noInSolution.getSubvector(i).size(); j++)
      std::cout << noInSolution.getSubvector(i)[j] << " ";
    std::cout << "\n";
    
    addLRC(noInSolution.getSubvector(i), currentValue);
  }
}

float Grasp::construct() {
  vectors auxSol;
  float auxBestSolutionValue;
  bestSolution.clear();

  do {
    auxSol = bestSolution;
    std::cout << "Entrando a buildLRC()\n";
    buildLRC();
    std::cout << "Saliendo de buildLRC()\n";
    int randomNumber = rand() % LRC.size();
    auxBestSolutionValue = LRC[randomNumber].second;
    if (auxBestSolutionValue > bestSolutionValue) {
      bestSolutionValue = LRC[randomNumber].second;

      bestSolution.pushData(LRC[randomNumber].first);
      for (int i = 0; i < noInSolution.getSize(); i++)
        if (noInSolution.getSubvector(i) == LRC[randomNumber].first)
         noInSolution.deleteData(i);
    }
  } while(bestSolution.getSize() < stopNumber);
  return bestSolutionValue;
}

float Grasp::solve() {
  noInSolution = vectorsData;
  int iterator = 0;
  vectors bestGraspSolution;
  float bestGraspValue = FLT_MIN;

  do {
    construct();

    if (bestGraspValue > bestSolutionValue) {
      bestSolutionValue = bestGraspValue;
      bestGraspSolution = bestSolution;
    }
    iterator++;
  } while(iterator < 100);
}