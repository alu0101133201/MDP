/*
 * Autor: Sergio Guera Arencibia
 * alu0101133201@ull.edu.es
 * Universidad de La Laguna
 * 22-04-20
 * Fichero que describe las clases que implementarán
 * la clase árbol
 */

#pragma once

#include "MDP.hpp"
#include "node.hpp"

class tree {
  private:
    std::vector<node> generatedNodes;
    std::vector<node> expansibleNodes;
    vectors myData;

    int currentDepth;
    int finalDepth;

  public:
    tree(vectors myData, int);
    ~tree();

    void initializeTree();
    void calculateUpperBound(node);
    std::ostream& writeTree(std::ostream&);
};