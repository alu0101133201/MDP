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
    vectors vectorsData;  // Datos del problema (vectores)
    vectors noInSolution; // Elementos no pertenecientes a la solución
    vectors bestSolution; // Solución actual del problema
    int stopNumber; // Número de iteraciones ha realizar
    float bestSolutionValue;  // Valor de la función objetivo

    // Método que obtiene le centro de un conjunto de vectores
    std::vector<float> getCenter(vectors currentVectors);
    // Método que calcula la distancia entre dos vectores
    float distBetVect(std::vector<float> first, std::vector<float> second);

    // Método que genera los vecinos a una solución
    vectors generateNeighbour(vectors, std::vector<float>, int);
    // Método que realiza la búsqueda local
    void localSearch(vectors&, float&);

  public:
    // Constructor y destructor
    MDP(vectors myVectors, int m);
    ~MDP();

    // Método que realiza el post procesamiento (búsqueda local)
    void postProcessing();
    // Método que calcula el valor de la función objetivo
    float maxDiversity(vectors myVectors);
    // Método que recalcula el valor de la función objetivo a partir de un intercambio
    float diversityFromVal(vectors, std::vector<float>, std::vector<float>, float);
    // Método que recalcula el valor de la función objetivo a partir de una adición
    float diversityFromAdd(vectors, std::vector<float>, float);

    // Getters básicos
    float getBestSolutionValue();
    vectors getBestSolution();
    // Método principal de resolución
    virtual float solve() = 0;

    // Método básico de impresión
    std::ostream& write(std::ostream& os);
};