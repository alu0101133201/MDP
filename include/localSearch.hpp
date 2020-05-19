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
#include <chrono>

#include "constructiveGreedy.hpp"
#include "destructiveGreedy.hpp"

class localSearch : public MDP {
  protected:
    ConstructiveGreedy greedy1; // Greedy constructivo para probar la búsqueda local
    DestructiveGreedy greedy2; // Greedy destructivo para probar la búsqueda local
    
  public:
    // Constructor y destructor
    localSearch(vectors myVectors, int m);
    ~localSearch();
    
    // Método principal de resolución
    float solve();
};