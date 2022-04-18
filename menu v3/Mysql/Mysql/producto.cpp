#include <iostream>
using namespace std;
class producto {
	//atributos
protected: string productos, descripcion, fecha_ingreso;
		 int idmarca, existencia;
		 double  precio_costo, precio_venta;
		 //constructor
protected:
	producto() {

	}
	producto(string prod, int idma, string des, double pre_c, double pre_v, int ex, string fi) {
		productos = prod;
		idmarca = idma;
		descripcion = des;
		precio_costo = pre_c;
		precio_venta = pre_v;
		existencia = ex;
		fecha_ingreso = fi;

	}