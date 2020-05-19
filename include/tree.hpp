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

// Clase que define la estructura arbórea que será gestionada por el algoritmo de
// ramificación y poda
class tree {
  private:
    std::vector<node> generatedNodes; // Vector de nodos generados
    vectors myData; // Datos del problema a resolver

    int currentDepth;
    int finalDepth; //Profundidad máxima del arbol
    bool depth; // Flag que indica si queremos seleccionar el siguiente nodo a expandir
                // por profundidad o por cota mínima
  public:
    float bestUpperBound; // Mejor cota superior actual
    vectors bestSolution; // Mejor solución encontrada
    std::vector<node> expansibleNodes;  // Vector de nodos a expandir
    
    // Constructor y destructor
    tree(vectors myData, int, bool);
    ~tree();

    // Método que expande un nodo
    void expandNode(node nodo);
    // Método que inicializa el árbol
    void initializeTree();
    // Método que calcula la cota superior de un nodo
    void calculateUpperBound(node);
    // Método que devuelve el siguiente nodo a expandir
    node getNextToExpand(void);
    // Método que poda los nodos con una cota superior inferior a la mejor cota actual
    void prune(void);

    // Mëtodo básico de impresión
    std::ostream& writeTree(std::ostream&);
};