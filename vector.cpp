#include "vector.h"
#include <stdexcept>
#include <iostream>
#include <cmath>

geom_vector::geom_vector(std::vector<double> &comps) : m_comps(comps) {};

geom_vector::geom_vector(std::initializer_list<double> comps) : m_comps(comps) {};

double& geom_vector::operator[](int index) {
    if (index < 0 || index >= m_comps.size()) {
        throw std::out_of_range("Indice non valido");
    }
    return m_comps[index];
};

double geom_vector::operator[](int index) const {
    if (index < 0 || index >= m_comps.size()) {
        throw std::out_of_range("Indice non valido");
    }
    return m_comps[index];
};

int geom_vector::size() {
    return static_cast<int>(m_comps.size());
}

geom_vector geom_vector::operator+(const geom_vector b) const {
    std::vector<double> out_vec;
    geom_vector a = *this;
    int s = a.size();

    for (int i=0; i<s; i++) {
        double t = a[i] + b[i];
        out_vec.push_back(t);
    }

    return geom_vector(out_vec);
};

void geom_vector::print() {
    std::cout << "(";
    for (int i=0; i<this->size(); i++)
        std::cout << (*this)[i] << " ";
    std::cout << ")\n";
}

geom_vector geom_vector::operator*(const double b) const {
    std::vector<double> out_vec;
    geom_vector a = *this;
    int s = a.size();

    for (int i=0; i<s; i++) {
        double t = a[i] * b;
        out_vec.push_back(t);
    }
    
    return geom_vector(out_vec);
}

double geom_vector::operator*(const geom_vector b) const {
    geom_vector a = *this;
    int s = a.size();
    double out =0;

    for (int i=0; i<s; i++) {
        out += a[i] * b[i];
    }
    
    return out;
}

geom_vector geom_vector::operator-(const geom_vector b) const {
    std::vector<double> out_vec;
    geom_vector a = *this;
    int s = a.size();

    for (int i=0; i<s; i++) {
        double t = a[i] - b[i];
        out_vec.push_back(t);
    }

    return geom_vector(out_vec);
};

geom_vector geom_vector::operator/(const double b) const {
    std::vector<double> out_vec;
    geom_vector a = *this;
    int s = a.size();

    for (int i=0; i<s; i++) {
        double t = a[i] / b;
        out_vec.push_back(t);
    }
    
    return geom_vector(out_vec);
};

double geom_vector::norm() {
    double t = 0;
    for (int i=0; i<(*this).size(); i++)
        t += pow((*this)[i], 2);
    return pow(t, 0.5);
}
