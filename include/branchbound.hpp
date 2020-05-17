/*
 * Autor: Sergio Guera Arencibia
 * alu0101133201@ull.edu.es
 * Universidad de La Laguna
 * 22-04-20
 * Fichero que describe las clasea que describirá
 * el algoritmo de ramificación y poda
 */

#pragma once

#include "MDP.hpp"
#include "constructiveGreedy.hpp"
#include "tree.hpp"

class branchBound : public MDP {
  private:
    tree myTree;
    ConstructiveGreedy greedy1;

    float currentBound;
    
  public:
    branchBound(vectors myVectors, int m);
    ~branchBound();

    float solve();
};