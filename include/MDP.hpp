/*
 * Autor: Sergio Guera Arencibia
 * alu0101133201@ull.edu.es
 * Universidad de La Laguna
 * 22-04-20
 * Fichero que describe la clase abstracta maxmeandp. Esta 
 * sera la clase padre de diferentes clases que implementarán
 * un algoritmo de resolución para el problema
 */

#pragma once

#include <vector>
#include <cfloat>
#include <math.h>     

#include "vectors.hpp"



class MDP {
  protected:
    vectors vectorsData;
    vectors bestSolution;
    int stopNumber;
    float bestSolutionValue;

    std::vector<float> getCenter(vectors currentVectors);
    float distBetVect(std::vector<float> first, std::vector<float> second);

  public:
    MDP(vectors myVectors, int m);
    ~MDP();

    float maxDiversity(vectors myVectors);

    // Método principal de resolución
    virtual float solve() = 0;

    // Método básico de impresión
    std::ostream& write(std::ostream& os);
};