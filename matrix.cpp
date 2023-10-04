#include "matrix.h"
#include <stdexcept>
#include <iostream>

matrix::matrix(int size_x, int size_y, std::initializer_list<double> comps) : m_comps(comps) {
    m_size[0] = size_x;
    m_size[1] = size_y;
}

matrix::matrix(int size_x, int size_y) {
    m_size[0] = size_x;
    m_size[1] = size_y;

    for (int i=0; i<size_x*size_y; i++)
        m_comps.push_back(0);
}

int matrix::index(int x, int y) const {
    if (x < 0 or y < 0 or x >= m_size[0] or y >= m_size[1]) {
        throw std::out_of_range("Indice non valido");
    }
    return x + y * m_size[0];
}

std::vector<int> matrix::size() const {
    std::vector<int> out = {m_size[0], m_size[1]};
    return out;
}

double& matrix::comp(int x, int y) {
    return m_comps[index(x, y)];
}

double matrix::comp(int x, int y) const {
    return m_comps[index(x, y)];
}

void matrix::print() const {
    for (int i=0; i<m_size[1]; i++) {
            for (int j=0; j<m_size[0]; j++) {
                std::cout << this->comp(j, i) << " ";
            }
            std::cout << std::endl;
        }
    std::cout << std::endl;
}

matrix matrix::operator+(const matrix b) const {
    matrix out(m_size[0], m_size[1]);

    if (this->size() != b.size())
        return out;

    else {
        for (int i=0; i<m_size[0]; i++) {
            for (int j=0; j<m_size[1]; j++) {
                out.comp(i, j) = this->comp(i, j) + b.comp(i, j);
            }
        }
    }
    return out;
}

matrix matrix::operator-(const matrix b) const {
    matrix out(m_size[0], m_size[1]);

    if (this->size() != b.size())
        return out;

    else {
        for (int i=0; i<m_size[0]; i++) {
            for (int j=0; j<m_size[1]; j++) {
                out.comp(i, j) = this->comp(i, j) - b.comp(i, j);
            }
        }
    }
    return out;
}

geom_vector matrix::row(int i) const{
    std::vector<double> out_vec;
    int s = this->size()[0];
    for (int j=0; j < s; j++)
        out_vec.push_back(this->comp(j, i));
    return geom_vector(out_vec);
}

geom_vector matrix::column(int i) const{
    std::vector<double> out_vec;
    int s = this->size()[1];
    for (int j=0; j < s; j++)
        out_vec.push_back(this->comp(i, j));
    return geom_vector(out_vec);
}

matrix matrix::operator*(const double b) const {
    matrix out(this->m_size[0], this->m_size[1]);

    for (int i=0; i<m_size[0]; i++) {
            for (int j=0; j<m_size[1]; j++) {
                out.comp(i, j) = this->comp(i, j) * b;
            }
        }
    return out;
}

matrix matrix::operator*(const matrix b) const {
    int sx = b.size()[0];
    int sy = this->size()[0];
    matrix out(sx, sy);

    for (int i=0; i<sx; i++) {
        for (int j=0; j<sy; j++) {
            out.comp(i, j) = this->row(j) * b.column(i);
        }
    }
    return out;
}

geom_vector matrix::operator*(const geom_vector b) const {
    std::vector<double> out_vec;
    for (int i=0; i<b.size(); i++)
        out_vec.push_back(this->row(i)*b);
    return geom_vector(out_vec);
}

