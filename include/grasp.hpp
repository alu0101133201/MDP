/*
 * Autor: Sergio Guera Arencibia
 * alu0101133201@ull.edu.es
 * Universidad de La Laguna
 * 22-04-20
 * Fichero que describe las clases que implementarán
 * el planteamiento grasp voraz del algoritmo MDP
 */

#pragma once

#include "MDP.hpp"

class Grasp : public MDP {

  public:
    Grasp(vectors myVectors, int m);
    ~Grasp();

    float solve();
};