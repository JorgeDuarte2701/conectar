// Mysql.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "marcas.h" 
#include <mysql.h>
using namespace std;
int q_estado;
int main()
{/*

	MYSQL* conectar;
	MYSQL_ROW fila;
	MYSQL_RES* resultado;
	conectar = mysql_init(0);
	conectar = mysql_real_connect(conectar, "localhost", "root", "1234", "mantenimientos", 3306, NULL, 0);
	if (conectar) {

		string marca;
		cout << "Ingrese marca: ";
		cin >> marca;
		string insert = "insert into marcas(marca) values('" + marca + "')";
		const char* i = insert.c_str();
		q_estado = mysql_query(conectar, i);
		if (!q_estado) {
			cout << "Ingreso Exitoso...." << endl;

		}

		else {
			cout << "Error en El ingreso ..." << endl;
		}

		string consulta = "select * from marcas";
		const char* c = consulta.c_str();
		q_estado = mysql_query(conectar, c);
		if (!q_estado) {
			resultado = mysql_store_result(conectar);
			while (fila = mysql_fetch_row(resultado)) {
				cout << fila[0] << "-" << fila[1] << endl;
			}

		}

		else {
			cout << "Error en El ingreso ..." << endl;
		}
	}
	else {
		cout << "Error en la Conexion ..." << endl;
	}
	*/




	char res1;
	do {

		string marca, productos, descripcion, fecha_ingreso;
		int idmarca, existencia;
		double  precio_costo, precio_venta;


		int menu;
		system("cls");
		printf("*BIENVENIDO AL PROGRAMA DE JORGE DUARTE*\n");
		printf("*CARNET 3590-20-11844*\n");
		printf("1 - ingresar a la tabla marcas\n");
		printf("2 - Ingresar a la tabla productos\n");
		//para el menu


		printf("Seleccione una opcion: ");
		scanf("%d", &menu);

		switch (menu) {


		case 1:
			system("cls");

			system("cls");
			cout << "Ingresar marca :";
			cin >> marca;

			break;

		case 2:

			cout << "Ingresar productos :";
			cin >> productos;
			cout << "Ingresar idmarca :";
			cin >> idmarca;
			cout << "Ingresar descripcion :";
			cin >> descripcion;
			cout << "Ingresar precio costo :";
			cin >> precio_costo;
			cout << "Ingresar precio venta :";
			cin >> precio_venta;
			cout << "Ingresar Existencia :";
			cin >> existencia;
			cout << "Ingresar fecha de ingreso :";
			cin >> fecha_ingreso;
			break;

		}
		cout << "¿Desea Ingresar otro valor?..(s/n):";
		cin >> res1;
	} while (res1 == 's');




	marcas c = marcas(productos, idmarca, descripcion, precio_costo, precio_venta, existencia, fecha_ingreso, marca);
	c.Crear();
	c.leer();
	system("pause");
	return 0;
}
