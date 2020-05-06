/*
 * Autor: Sergio Guera Arencibia
 * alu0101133201@ull.edu.es
 * Universidad de La Laguna
 * 22-04-20
 * Fichero que describe las clases que implementarán
 * el planteamiento destructivo voraz del algoritmo MDP
 */

#pragma once

#include "MDP.hpp"

class DestructiveGreedy : public MDP {
  private:
    int getNearPoint(std::vector<float> center, vectors points);
    void buildInitialSol();

  public:
    DestructiveGreedy(vectors myVectors, int m);
    ~DestructiveGreedy();

    float solve();
};