/*
 * Autor: Sergio Guera Arencibia
 * alu0101133201@ull.edu.es
 * Universidad de La Laguna
 * 22-04-20
 * Fichero que describe las clases que implementarán
 * el planteamiento grasp voraz del algoritmo MDP
 */

#pragma once

#include <utility> 

#include "MDP.hpp"

class Grasp : public MDP {
  protected:
    int cardinality;
    std::vector<std::pair<std::vector<float>, float> > LRC;  // Atributo que almacena LRC

    float construct();
    void buildLRC();
    void addLRC(std::vector<float>, float);

  public:
    Grasp(vectors myVectors, int m, int card);
    ~Grasp();

    float solve();
};