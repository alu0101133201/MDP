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
    // Método que obtiene el punto más cercano a otro (generalmente el centro)
    int getNearPoint(std::vector<float> center, vectors points);
    // Método que construye la solución inicial
    void buildInitialSol();

  public:
    // Constructor y destructor
    DestructiveGreedy(vectors myVectors, int m);
    ~DestructiveGreedy();

    // Método básico de resolución
    float solve();
};