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
    int getFarPoint(std::vector<float> center, vectors points);
    

  public:
    ConstructiveGreedy(vectors myVectors, int m);
    ~ConstructiveGreedy();

    float solve();
};