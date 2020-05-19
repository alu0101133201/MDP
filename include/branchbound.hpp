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
#include "grasp.hpp"
#include "constructiveGreedy.hpp"
#include "destructiveGreedy.hpp"

#include "tree.hpp"

class branchBound : public MDP {
  private:
    tree myTree;  // Árbol para ejecutar el algoritmo
    // Algoritmos auxiliares para obtener las cotas inicialles
    ConstructiveGreedy greedy1;
    DestructiveGreedy greedy2;
    Grasp graspAlg;
    
  public:
    // Constructor y destructor
    branchBound(vectors myVectors, int m, int cardi, int stopCriteria, int maxIterations, bool depth);
    ~branchBound();

    // Método de resolución del problema
    float solve();
};