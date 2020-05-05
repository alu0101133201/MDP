/*
 * Autor: Sergio Guera Arencibia
 * alu0101133201@ull.edu.es
 * Universidad de La Laguna
 * 05-05-20
 * Fichero que describe la clase vectors. Un objeto de
 * esta clase almacenará el conjunto de vectores que se usarán
 * para trabajar con el problema MDP
 */


#include <iostream>
#include <vector>
#include <fstream>
#include <string>

class vectors {
  private:
    std::vector<std::vector<float>> data;
    int numberOfVectors;
    int dimension;
  
  public:
    vectors(std::string fileName);
    ~vectors();

    std::vector<std::vector<float>> getData();
    std::ostream& write(std::ostream& os);
};