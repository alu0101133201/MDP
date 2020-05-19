/*
 * Autor: Sergio Guera Arencibia
 * alu0101133201@ull.edu.es
 * Universidad de La Laguna
 * 22-04-20
 * Fichero que describe las clases que implementarán
 * el planteamiento constructivo voraz del algoritmo MDP
 */

#pragma once

#include "MDP.hpp"

class ConstructiveGreedy : public MDP {
  private:
    // Mëtodo para obtener el punto más lejano de otro (generalmente le centro)
    int getFarPoint(std::vector<float> center, vectors points);
    

  public:
    // Constructores y destructores
    ConstructiveGreedy(vectors myVectors, int m);
    ~ConstructiveGreedy();

    // Método de resolución principal
    float solve();
};