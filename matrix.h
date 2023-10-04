#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include "vector.h"

class matrix {
    public:
    // constructors

    matrix(int size_x, int size_y, std::initializer_list<double> comps);

    matrix(int size_x, int size_y);

    // functions

    double& comp(int x, int y);

    double comp(int x, int y) const;

    std::vector<int> size() const;

    void print() const;

    geom_vector row(int i) const;

    geom_vector column(int i) const;

    // operators

    matrix operator+(const matrix b) const;

    matrix operator-(const matrix b) const;

    matrix operator*(const double b) const;

    matrix operator*(const matrix b) const;

    geom_vector operator*(const geom_vector b) const;

    private:

    int index(int x, int y) const;    // transforms x,y coords to vector index


    std::vector<double> m_comps;
    int m_size[2];
};

#endif