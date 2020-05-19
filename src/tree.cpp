/*
 * Autor: Sergio Guera Arencibia
 * alu0101133201@ull.edu.es
 * Universidad de La Laguna
 * 22-04-20
 * Fichero que describe la clase que implementarán
 * la clase árbol
 */
#include "tree.hpp"

tree::tree(vectors data, int myM, bool d) {
  myData = data;
  finalDepth = myM;
  currentDepth = 0;
  depth = d;
}

tree::~tree() {}

void tree::initializeTree() {
  currentDepth++;
  for (int i = 0; i < myData.getSize() - finalDepth + 1; i++) {
    std::vector<float> vectorAdded = myData.getSubvector(i);

    vectors partialSolution;
    partialSolution.pushData(myData.getSubvector(i));

    vectors partialNoInSolution = myData;
    partialNoInSolution.deleteData(i);
    node auxNode(1, i, 0, partialSolution, partialNoInSolution, vectorAdded);
    auxNode.calculateUpperBound(finalDepth);
    generatedNodes.push_back(auxNode);
    expansibleNodes.push_back(auxNode);
  }
}

void tree::expandNode(node nodo) {

  for (int i = 0; i < expansibleNodes.size(); i++) {
    if ((expansibleNodes[i].getDepth() == nodo.getDepth()) && (expansibleNodes[i].getId() == nodo.getId()) &&
        (expansibleNodes[i].getUpperBound() == nodo.getUpperBound()) &&
        (expansibleNodes[i].getPartialSolutionValue() == nodo.getPartialSolutionValue())) {
      expansibleNodes[i] = expansibleNodes[expansibleNodes.size() - 1];
      expansibleNodes.pop_back();
      break;
    }

  }
  
  int numberOfNodes = (myData.getSize() - (finalDepth - nodo.partialSolution.getSize()) - nodo.getId());
  for (int i = nodo.getId() + 1; i < nodo.getId() + 1 + numberOfNodes; i++) {
    std::vector<float> vectorAdded = myData.getSubvector(i);
    vectors partialSolution = nodo.getPartialSolution();
    partialSolution.pushData(myData.getSubvector(i));

    vectors partialNoInSolution = nodo.partialNoInSolution;
    for (int j = 0; j < partialNoInSolution.getSize(); j++) {
      if (partialNoInSolution.getSubvector(j) == myData.getSubvector(i))
        partialNoInSolution.deleteData(j);
    }

    node auxNode(nodo.getDepth() + 1, i, nodo.getPartialSolutionValue(), partialSolution, partialNoInSolution, vectorAdded);
    auxNode.calculateUpperBound(finalDepth);

    // Comprobamos si el hijo es solución final
    if ((nodo.getDepth() + 1) == finalDepth) {
      if (auxNode.getUpperBound() > bestUpperBound) {
        bestSolution = auxNode.getPartialSolution();
        bestUpperBound = auxNode.getUpperBound();
      }
    } else {
      expansibleNodes.push_back(auxNode);
    }
    generatedNodes.push_back(auxNode);
  }
}

node tree::getNextToExpand(void) {
  int minIndex;
  if (!depth) {
    float min = FLT_MAX;
    for (int i = 0; i < expansibleNodes.size(); i++) {
      if (expansibleNodes[i].getUpperBound() < min) {
        min = expansibleNodes[i].getUpperBound();
        minIndex = i;
      }
    }
  } else {
    float maxDepth = -1;
    for (int i = 0; i < expansibleNodes.size(); i++) {
      if (expansibleNodes[i].getDepth() > maxDepth) {
        maxDepth = expansibleNodes[i].getDepth();
        minIndex = i;
      }
    }
  }
  return expansibleNodes[minIndex];
}

void tree::prune(void) {
  for (int i = 0; i < expansibleNodes.size(); i++) {
    if (expansibleNodes[i].getUpperBound() < bestUpperBound) {
      expansibleNodes[i] = expansibleNodes[expansibleNodes.size() - 1];
      expansibleNodes.pop_back();
    }
  }
}


std::ostream& tree::writeTree(std::ostream& os) {
  os << "\u001b[31mTree\u001b[0m\n";
  os << "CurrentDepth: " << currentDepth << " \n";
  os << "FinalDepth: " << finalDepth << "\n";

  os << "NODOS GENERADOS: " << generatedNodes.size() << "\n";
  os << "Solución: \n";
    bestSolution.write(std::cout);
  return os;
}