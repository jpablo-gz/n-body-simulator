#ifndef MATH3D_H
#define MATH3D_H

// includes:
#include <iostream>

// Clase Vector --------------------------------------------------------------------------------
struct Vec {
public:
	// parametros:
	double x, y, z, w;
	
	// constructor:
	Vec(double nx = 0, double ny = 0, double nz = 0, double nw = 0): x(nx), y(ny), z(nz), w(nw){}

	// sobrecarga de operadores
	Vec operator+(const Vec& v) const;
	Vec operator-(const Vec& v) const;
	Vec operator-() const;

	Vec operator*(const double& e) const;
	Vec operator/(const double& e) const;

	const double& operator[](int index) const;
	double& operator[](int index);

	// metodos
	const double magnitud(); // obtener magnitud del vector
	const Vec get_2D(); // obtener el vector en su version 2D 
	const Vec get_3D(); // obtener el vector en su version 3D
};

// operaciones complejas con vectores
Vec normal(const Vec& v);
double dot(const Vec& a, const Vec& b);
Vec cross(const Vec& a, const Vec& b);

#endif //MATH3D_H