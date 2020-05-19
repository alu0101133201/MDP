/*
 * Autor: Sergio Guera Arencibia
 * alu0101133201@ull.edu.es
 * Universidad de La Laguna
 * 22-04-20
 * Fichero que describe las clases que implementarán
 * la clase node
 */
#include "node.hpp"

node::node(int d, int newId, float psValue,  vectors ps, vectors pns, std::vector<float> added){
  depth = d;
  id = newId;
  partialSolutionValue = psValue;
  partialSolution = ps;
  partialNoInSolution = pns;
  vectorAdded = added;
}

node::~node(){}

void node::setDepth(int newDepth) {
  depth = newDepth;
}
void node::setId(int newId) {
  depth = newId;
}
int node::getDepth(void) {
  return depth;
}
int node::getId(void) {
  return id;
}

float node::getPartialSolutionValue() {
  return partialSolutionValue;
}
float node::getUpperBound() {
  return upperBound;
}
vectors node::getPartialSolution() {
  return partialSolution;
}

std::ostream& node::write(std::ostream& os) {
  std::cout << "partialSolutionValue: " << partialSolutionValue << "\n";
  std::cout << "upperBound: " << upperBound << "\n";
  std::cout << "depth: " << depth << "\n";
  std::cout << "id: " << id << "\n";
  std::cout << "PartialSolution:\n";
  partialSolution.write(os);
  std::cout << "PartialNoInSolution:\n";
  partialNoInSolution.write(os);
  return os;
}

void node::calculateUpperBound(int m) {
  partialSolutionValue = diversityFromAdd(partialSolution, vectorAdded, partialSolutionValue);
  
  int weightsToAdd = (partialSolution.getSize() * (m - partialSolution.getSize()));
  weightsToAdd += ((m - partialSolution.getSize()) * ((m - partialSolution.getSize()) - 1)) / 2;
  float maxDist = getBestDistance();

  upperBound = (weightsToAdd * maxDist) + partialSolutionValue;
}


float node::getBestDistance() {
  float bestOut = -1;

  for (int i = 0; i < partialNoInSolution.getSize(); i++) {
    for (int j = i + 1; j < partialNoInSolution.getSize(); j++) {
      float currentDistance = distBetVect(partialNoInSolution.getSubvector(i), partialNoInSolution.getSubvector(j));
      if (currentDistance > bestOut) {
        bestOut = currentDistance;
      }
    }
  }
  for (int i = 0; i < partialSolution.getSize(); i++) {
    for (int j = 0; j < partialNoInSolution.getSize(); j++) {
      float currentDistance = distBetVect(partialSolution.getSubvector(i), partialNoInSolution.getSubvector(j));

      if (currentDistance > bestOut) {
        bestOut = currentDistance;
      }
    }
  }
  return bestOut;
}


float node::distBetVect(std::vector<float> first, std::vector<float> second) {
  float totalSum = 0;

  for (int i = 0; i < first.size(); i++) {
    totalSum += pow ((first[i] - second[i]), 2.0);
  }
  return(sqrt(totalSum));
}

float node::diversityFromAdd(vectors solution, std::vector<float> added, float oldValue) {
  float newValue = oldValue;

  for (int i = 0; i < solution.getSize(); i++) {
    if (solution.getSubvector(i) != added)
      newValue += distBetVect(solution.getSubvector(i), added);
  }
  return (newValue);
}