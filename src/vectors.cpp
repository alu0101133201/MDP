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

vectors::vectors() {
  dimension = 0;
  numberOfVectors = 0;
}

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
}

vectors::~vectors() {}

std::vector<std::vector<float>> vectors::getData() {
  return (data);
}


std::ostream& vectors::write(std::ostream& os) {
  for (int i = 0; i < data.size(); i++) {
    for (int j = 0; j < data[i].size(); j++) {
      os << data[i][j] << " ";
    }
    os << "\n";
  }
  os << "\n";
  return os;
}

int vectors::getSize() {
  return numberOfVectors;
}

int vectors::getDimension() {
  return(dimension);
}

void vectors::setDimension(int dim) {
  dimension = dim;
}

std::vector<float> vectors::getSubvector(int i) {
  return data[i];
}


void vectors::pushData(std::vector<float> newVect) {
  data.push_back(newVect);
  numberOfVectors++;
}

void vectors::popData() {
  data.pop_back();
}



void vectors::deleteData(int index) {
  std::vector<std::vector<float>>::iterator iter = data.begin();
  std::advance(iter, index);
  numberOfVectors--;
  data.erase(iter);
}

void vectors::setSubVector(std::vector<float> swapElement, int swapIndex) {
  data[swapIndex] = swapElement;
}

void vectors::clear(void) {
  for (int i = 0; i < data.size(); i++) {
    data[i].clear();
  }
  data.clear();
  numberOfVectors = 0;
}
