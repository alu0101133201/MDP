/*
 * Autor: Sergio Guera Arencibia
 * alu0101133201@ull.edu.es
 * Universidad de La Laguna
 * 22-04-20
 * Fichero que describe las clases que definirá
 * el planteamiento grasp voraz del algoritmo MDP
 */

#pragma once
#define ITERACIONES 0
#define SINMEJORA 1

#include <utility> 


#include "MDP.hpp"

class Grasp : public MDP {
  protected:
    int cardinality;  // Cardinalidad del LRC
    std::vector<std::pair<std::vector<float>, float> > LRC;  // Atributo que almacena LRC

    // Atributos de criterio de parada
    int iterationsWithOutImprove;
    int stopCriteria_;
    int iterationLimit;

    bool stopCriteria(int);

    // Método que construye la solución
    float construct();
    // Método que construye el LRC
    void buildLRC();
    // Método que añade un vector al LRC
    void addLRC(std::vector<float>, float);

  public:
    // Constructor y destructor
    Grasp(vectors myVectors, int m, int cardi, int stopCriteria, int maxIterations);
    ~Grasp();

    // Método principal de resolución
    float solve();
};