#ifndef VECTOR_H
#define VECTOR_H

#include <vector>

class geom_vector {
    public:

    // constructors

    geom_vector(std::vector<double> &comps);

    geom_vector(std::initializer_list<double> comps);

    // functions

    int size();

    void print();

    double norm();

    // operators

    double& operator[](int i);

    double operator[](int i) const;

    geom_vector operator+(const geom_vector b) const;

    geom_vector operator-(const geom_vector b) const;
    
    double operator*(const geom_vector b) const;

    geom_vector operator*(const double b) const;
    
    geom_vector operator/(const double b) const;

    private:
    std::vector<double> m_comps;
};

#endif
