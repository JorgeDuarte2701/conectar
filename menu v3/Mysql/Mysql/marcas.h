#pragma once
#include "producto.h"
#include <iostream>
#include <mysql.h>
#include "ConexionBD.h"
#include <string>
using namespace std;
class marcas : producto {
	//atributo
private: string marca;

	   //constructor
public:
	marcas() {
	}

	marcas(string prod, int idma, string des, double pre_c, double pre_v, int ex, string fi, string m) : producto(prod, idma, des, pre_c, pre_v, ex, fi) {
		marca = m;
	}

	//metodos
	//set (modificar)
	void setMarca(string m) { marca = m; }
	void setProductos(string prod) { productos = prod; }
	void setIdmarca(int idma) { idmarca = idma; }
	void setDescripcion(string des) { descripcion = des; }
	void setPrecio_costo(double pre_c) { precio_costo = pre_c; }
	void setPrecio_venta(double pre_v) { precio_venta = pre_v; }
	void setExistencia(int ex) { existencia = ex; }
	void setFecha_ingreso(string fi) { fecha_ingreso = fi; }
	//get (mostrar)
	string getMarca() { return marca; }
	string getProductos() { return productos; }
	int getIdmarca() { return idmarca; }
	string getDescripcion() { return descripcion; }
	double getPrecio_costo() { return precio_costo; }
	double getPrecio_venta() { return precio_venta; }
	int getExistencia() { return existencia; }
	string getFecha_ingreso() { return fecha_ingreso; }


	void Crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			//	string te = to_string(telefono);
			string insert = "INSERT INTO marcas(marca)VALUES('" + marca + "'); ";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Ingreso Exitoso...." << endl;

			}

			else {
				cout << "Error en El ingreso ..." << endl;
			}
		}
		else {
			cout << "Error en la Conexion ..." << endl;
		}
		cn.cerrar_conex();
	}
	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string consulta = "select * from marcas";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "------------------Marcas----------------" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					/ cout << fila[0] << "-" << fila[1] << endl;
					//cout << fila[0] << "-" << fila[1] << "-" << fila[2] << "-" << fila[3] << "-" << fila[4] << "-" << fila[5] << "-" << fila[6] << endl;
				}

			}

			else {
				cout << "Error en El ingreso ..." << endl;
			}
		}
		else {
			cout << "Error en la Conexion ..." << endl;
		}
		cn.cerrar_conex();
	}
};


