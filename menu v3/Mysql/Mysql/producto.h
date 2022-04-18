#pragma once
#include "ConexionBD.h"
#include <string>
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
			string consulta = "select * from productos";
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

};
