/*
 * Autor: Sergio Guera Arencibia
 * alu0101133201@ull.edu.es
 * Universidad de La Laguna
 * 22-04-20
 * Fichero que describe las clases que implementarán
 * la clase node
 */

#pragma once

#include "MDP.hpp"

// Clase que representa un nodo de la estructura de árbol usada en
// el algoritmo de ramificación y poda
class node {
  private:
    float partialSolutionValue; // Valor de la función objetivo de la solución parcial
    float upperBound; // Cota superior del nodo
    int depth;  // Profundidad del nodo
    int id; // id del nodo

    std::vector<float> vectorAdded; // Vector que se ha añadido en la generación de este nodo

    // Método que obtiene la mejor distancia que no esté incluida en la solución
    float getBestDistance();

  public:
    vectors partialSolution;  // Solución parcial
    vectors partialNoInSolution;  // Elementos que no están en la solución parcial
    
    // Constructor y destructor
    node(int depth, int id, float partialSolutionValue, vectors partialSolution, 
        vectors pns, std::vector<float> addedNode);
    ~node();

    // Setters básicos
    void setDepth(int);
    void setId(int);

    // Getters básicos
    int getDepth(void);
    int getId(void);
    float getPartialSolutionValue();
    float getUpperBound();
    vectors getPartialSolution();

    // Funciones para recalcular el valor de la función objetivo
    float diversityFromAdd(vectors, std::vector<float>, float);
    float distBetVect(std::vector<float> first, std::vector<float> second);

    // Función para calcular la cota superior
    void calculateUpperBound(int m);
    // Mëtodo básico de impresión
    std::ostream& write(std::ostream&);
};