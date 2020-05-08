/*
 * Autor: Sergio Guera Arencibia
 * alu0101133201@ull.edu.es
 * Universidad de La Laguna
 * 22-04-20
 * Fichero que implementa las clases que implementarán
 * el algoritmo grasp del algoritmo MDP
 */

#include "grasp.hpp"


Grasp::Grasp(vectors myVectors, int m, int cardi, int stopCriteria, int maxIterations):
    MDP(myVectors, m),
    iterationsWithOutImprove(0) {

   // Condición de parada
  stopCriteria_ = stopCriteria;
  iterationLimit = maxIterations;

  cardinality = cardi;
  srand(time(NULL));
  }

Grasp::~Grasp() {}


void Grasp::addLRC(std::vector<float> vector, float vectorValue) {
  std::pair<std::vector<float>, float> dummy;
  dummy.first = vector;
  dummy.second = vectorValue;
  int minIndex;
  float minValue = FLT_MAX;

  if (LRC.size() < cardinality) {
    LRC.push_back(dummy);
  }
  else {
    for (int i = 0; i < LRC.size(); i++) {
      if (LRC[i].second < minValue) {
        minValue = LRC[i].second;
        minIndex = i;
      }
    }
    if (minValue < vectorValue) {
      LRC[minIndex].first = vector;
      LRC[minIndex].second = vectorValue;
   }
  }
}

void Grasp::buildLRC() {
  LRC.clear();
  std::vector<float> center;
  if (bestSolution.getSize() == 0)
    center = getCenter(noInSolution);
  else
    center = getCenter(bestSolution);

  for (int i = 0; i < noInSolution.getSize(); i++) {
    float currentValue = distBetVect(noInSolution.getSubvector(i), center);   
    addLRC(noInSolution.getSubvector(i), currentValue);
  }
}

float Grasp::construct() {
  bestSolution.clear();
  bestSolutionValue = 0;

  do {
    buildLRC();
    int randomNumber = rand() % LRC.size();
    bestSolution.pushData(LRC[randomNumber].first);
    bestSolutionValue = diversityFromAdd(bestSolution, LRC[randomNumber].first , bestSolutionValue);
 
    for (int i = 0; i < noInSolution.getSize(); i++)
    if (noInSolution.getSubvector(i) == LRC[randomNumber].first)
      noInSolution.deleteData(i);

  } while(bestSolution.getSize() != stopNumber);
  return bestSolutionValue;
}

float Grasp::solve() {
  int iterator = 0;
  vectors bestGraspSolution;
  float bestGraspValue = FLT_MIN;

  do {
    noInSolution = vectorsData;
    construct();
    localSearch(bestSolution, bestSolutionValue);
    if (bestGraspValue < bestSolutionValue) {
      bestGraspValue = bestSolutionValue;
      bestGraspSolution = bestSolution;
      iterationsWithOutImprove = 0;
    } else {
      iterationsWithOutImprove++;
    }
    
    iterator++;
  } while(!stopCriteria(iterator));
  return bestGraspValue;
}

bool Grasp::stopCriteria(int currentIterations) {
  switch(stopCriteria_) {
    case (ITERACIONES):
      if (currentIterations >= iterationLimit)
        return true;
      break;
    case (SINMEJORA):
      if (iterationsWithOutImprove >= iterationLimit)
        return true;
      break;
    default:
      throw "Caso inválido\n";
      break;
  }
  return false;
}
