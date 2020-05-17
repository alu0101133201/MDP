/*
 * Autor: Sergio Guera Arencibia
 * alu0101133201@ull.edu.es
 * Universidad de La Laguna
 * 22-04-20
 * Fichero que describe la clase que implementarán
 * la clase árbol
 */
#include "tree.hpp"

tree::tree(vectors data, int myM) {
  myData = data;
  finalDepth = myM;
  currentDepth = 0;
}

tree::~tree() {}

void tree::initializeTree() {
  currentDepth++;
  for (int i = 0; i < myData.getSize() - finalDepth + 1; i++) {
    float upperBound = 1555;
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






std::ostream& tree::writeTree(std::ostream& os) {
  os << "CurrentDepth: " << currentDepth << " \n";
  os << "FinalDepth: " << finalDepth << "\n";

  os << "NODOS GENERADOS\n";
  for (int i = 0; i < generatedNodes.size(); i++)
    generatedNodes[i].write(os);
  os << "NODOS EXPANSIBLES\n";
  for (int i = 0; i < expansibleNodes.size(); i++)
    expansibleNodes[i].write(os);  
}