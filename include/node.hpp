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

class node {
  private:
    float partialSolutionValue;
    float upperBound;
    int depth;
    int id;

    std::vector<float> vectorAdded;

    vectors partialSolution;
    vectors partialNoInSolution;

    float getBestDistance();

  public:
    node(int depth, int id, float partialSolutionValue, vectors partialSolution, 
        vectors pns, std::vector<float> addedNode);
    ~node();

    void setDepth(int);
    void setId(int);

    int getDepth(void);
    int getId(void);
    float getPartialSolutionValue();
    float getUpperBound();
    vectors getPartialSolution();

    float diversityFromAdd(vectors, std::vector<float>, float);
    float distBetVect(std::vector<float> first, std::vector<float> second);

    void calculateUpperBound(int m);
    std::ostream& write(std::ostream&);
};