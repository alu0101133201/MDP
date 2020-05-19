/*
 * Autor: Sergio Guera Arencibia
 * alu0101133201@ull.edu.es
 * Universidad de La Laguna
 * 05-05-20
 * Fichero que describe la clase vectors. Un objeto de
 * esta clase almacenará el conjunto de vectores que se usarán
 * para trabajar con el problema MDP
 */

#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cfloat>
#include <iterator>

// clase que almacena la estructura de datos de un conjunto de vectores
class vectors {
  private:
    std::vector<std::vector<float>> data; // Atributo que almacena los vectores
    int numberOfVectors;  // Atributo que almacena el número de vectores
    int dimension;  // Atributo que almacena la dimensión de los vectores
  
  public:
    // Constructores y destructor básicos
    vectors();
    vectors(std::string fileName);
    ~vectors();

    // Getters básicos
    std::vector<std::vector<float>> getData();
    int getSize();
    int getDimension();
    void setDimension(int dim);

    // Métodos de manejo de los datos
    void pushData(std::vector<float>);
    void popData();
    void setSubVector(std::vector<float> swapElement, int swapIndex);
    void deleteData(int index);
    void clear(void);
    std::vector<float> getSubvector(int i);

    // Método básico de impresión
    std::ostream& write(std::ostream& os);
};