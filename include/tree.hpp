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
    vectors myData;

    int currentDepth;
    int finalDepth;

  public:
    std::vector<node> expansibleNodes;
    
    tree(vectors myData, int);
    ~tree();

    void expandNode(node nodo);
    void initializeTree();
    void calculateUpperBound(node);
    std::ostream& writeTree(std::ostream&);
};