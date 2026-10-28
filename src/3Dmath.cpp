#include "3Dmath.hpp"

// Clase Vector ----------------------------------------------------------------------------

// sobrecarga de suma:
Vec Vec::operator+(const Vec& v) const {
	return Vec(this->x + v.x, this->y + v.y, this->z + v.z, this->w + v.w);
}

// sobrecarga de resta (o = origen):
Vec Vec::operator-(const Vec& v) const {
	return Vec(this->x - v.x, this->y - v.y, this->z - v.z, this->w - v.w);
}

// sobrecarga de negacion de vector:
Vec Vec::operator-() const {
	return Vec(this->x*(-1), this->y*(-1), this->z*(-1), this->w*(-1));
}

// sobrecarga de multiplicacion por escalar:
Vec Vec::operator*(const double& e) const {
	return Vec(this->x*e, this->y*e, this->z*e, this->w*e);
}

// sobrecarga de division por escalar:
Vec Vec::operator/(const double& e) const {
	if (e != 0){
		return Vec(this->x/e, this->y/e, this->z/e, this->w/e);
	} else {
		throw std::invalid_argument("division entre 0 no valida");
	}
}

// sobrecarga de iteracion (lectura):
const double& Vec::operator[](int index) const {
	switch (index) {
		case 0: return x;
		case 1: return y;
		case 2: return z;
		case 3: return w;
		default:
			throw std::out_of_range("El indice debe estar entre 0 y 3");
	}
}

// sobrecarga de iteracion (editar):
double& Vec::operator[](int index) {
	switch (index) {
		case 0: return x;
		case 1: return y;
		case 2: return z;
		case 3: return w;
		default:
			throw std::out_of_range("El indice debe estar entre 0 y 3");
	}
}

// magnitud:
const double Vec::magnitud(){
	return sqrt(x*x + y*y + z*z + w*w);
}

const Vec Vec::get_2D(){
	return Vec(x, y, 0, 0);
}

const Vec Vec::get_3D(){
	return Vec(x, y, z, 0);
}

// operaciones mas complejas con vectores --------------------------------------------------

// obtener una copia normalizada del vector original
Vec normal(const Vec& v){
	double m = sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
	return v/m;
}

// producto punto entre vectores
double dot(const Vec& a, const Vec& b){
	return (a.x*b.x)+(a.y*b.y)+(a.z*b.z);
}

// producto cruz entre vectores
Vec cross(const Vec& a, const Vec& b){
	return Vec((a.y*b.z) - (a.z*b.y), (a.z*b.x) - (a.x*b.z), (a.x*b.y) - (a.y*b.x));
}