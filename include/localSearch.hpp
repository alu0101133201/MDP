/*
 * Autor: Sergio Guera Arencibia
 * alu0101133201@ull.edu.es
 * Universidad de La Laguna
 * 22-04-20
 * Fichero que describe las clases que implementarán
 * un clase para testear la búsqueda local
 */

#pragma once

#include "MDP.hpp"
#include "constructiveGreedy.hpp"
#include "destructiveGreedy.hpp"

class localSearch : public MDP {
  protected:
    ConstructiveGreedy greedy1;
    DestructiveGreedy greedy2;
    
  public:
    localSearch(vectors myVectors, int m);
    ~localSearch();

    float solve();
};