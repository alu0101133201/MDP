/*
 * Autor: Sergio Guera Arencibia
 * alu0101133201@ull.edu.es
 * Universidad de La Laguna
 * 05-05-20
 * Fichero que implementa la clase vectors. Un objeto de
 * esta clase almacenará el conjunto de vectores que se usarán
 * para trabajar con el problema MDP
 */

#include "vectors.hpp"

vectors::vectors(std::string fileName) {
  std::ifstream vectorsFile(fileName);

  if(!vectorsFile) {
    throw "Problem opening graph file\n";
  }
  vectorsFile >> numberOfVectors;
  vectorsFile >> dimension;

   while (!vectorsFile.eof()) {
     std::vector<float> auxVector;

     for (int i = 0; i < dimension; i++) {
       float auxElement;
       vectorsFile >> auxElement;
       auxVector.push_back(auxElement);
     }
    data.push_back(auxVector);
   }

  for (int i = 0; i < data.size(); i++) {
    for (int j = 0; j < data[i].size(); j++) {
      std::cout << data[i][j] << " ";
    }
    std::cout << "\n";
  }
}

vectors::~vectors() {

}

std::vector<std::vector<float>> vectors::getData() {

}


std::ostream& vectors::write(std::ostream& os) {

}