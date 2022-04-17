#pragma once
#include "marcas.h"
#include<iostream>
#include "ConexionDB2.h"
#include<string>
#include<mysql.h>

using namespace std;

class Productos{
private: 
	string producto, descripcion, precio_costo, precio_venta,fecha_ingreso,id_marca;
	int existencia;

public:
	Productos() {

	}
	Productos(string product,string prec_c,string descript,string prec_v, string fn, int exst, string idm) {
		producto = product;
		descripcion = descript;
		precio_costo = prec_c;
		precio_venta = prec_v;
		fecha_ingreso = fn;
		existencia = exst;
		id_marca = idm;
	}

	//metodos get y set

	//METODOS SET PARA ACTUALIZAR CADA ATRIBUTO
	void setProducto(string prod,int idp) { 
		producto = prod;
		int q_estado;
		ConexionBD2 cn = ConexionBD2();
		
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string idp1 = to_string(idp);
			string actualizar = "UPDATE productos SET producto = '" + producto + "' WHERE id_producto = " + idp1 + ";";
			const char* i = actualizar.c_str();
			q_estado = mysql_query(cn.getConectar(), i);

			if (!q_estado) {
				system("cls");
				cout << "Actualizacion exitosa" << endl;
			}
			else {
				system("cls");
				cout << "Hubo un error en la actualizacion de los datos" << endl;
			}
		
		}
		else {
			system("cls");
			cout << "Hubo un error en la conexion con la base de datos" << endl;
		}
	cn.cerrar_conexion();
	system("pause");

	}
	void setDescripcion(string descp,int idp) { 
		descripcion = descp; 
		int q_estado;
		ConexionBD2 cn = ConexionBD2();

		cn.abrir_conexion();

		if (cn.getConectar()) {
			string idp1 = to_string(idp);
			string actualizar = "UPDATE productos SET descripcion_producto = '" + descripcion + "' WHERE id_producto = " + idp1 + ";";
			const char* i = actualizar.c_str();
			q_estado = mysql_query(cn.getConectar(), i);

			if (!q_estado) {
				system("cls");
				cout << "Actualizacion exitosa" << endl;
			}
			else {
				system("cls");
				cout << "Hubo un error en la actualizacion de los datos" << endl;
			}

		}
		else {
			system("cls");
			cout << "Hubo un error en la conexion con la base de datos" << endl;
		}
		cn.cerrar_conexion();
		system("pause");
	}

	void setPrecioC(string prec_c,int idp) { 
		precio_costo = prec_c; 
		int q_estado;
		ConexionBD2 cn = ConexionBD2();

		cn.abrir_conexion();

		if (cn.getConectar()) {
			string idp1 = to_string(idp);
			string actualizar = "UPDATE productos SET precio_costo = '" + precio_costo + "' WHERE id_producto = " + idp1 + ";";
			const char* i = actualizar.c_str();
			q_estado = mysql_query(cn.getConectar(), i);

			if (!q_estado) {
				system("cls");
				cout << "Actualizacion exitosa" << endl;
			}
			else {
				system("cls");
				cout << "Hubo un error en la actualizacion de los datos" << endl;
			}

		}
		else {
			system("cls");
			cout << "Hubo un error en la conexion con la base de datos" << endl;
		}
	cn.cerrar_conexion();
	system("pause");
}
	void setPrecioV(string prec_v,int idp) { 
		precio_venta = prec_v; 
		int q_estado;
		ConexionBD2 cn = ConexionBD2();

		cn.abrir_conexion();

		if (cn.getConectar()) {
			string idp1 = to_string(idp);
			string actualizar = "UPDATE productos SET precio_venta = '" + precio_venta + "' WHERE id_producto = " + idp1 + ";";
			const char* i = actualizar.c_str();
			q_estado = mysql_query(cn.getConectar(), i);

			if (!q_estado) {
				system("cls");
				cout << "Actualizacion exitosa" << endl;
			}
			else {
				system("cls");
				cout << "Hubo un error en la actualizacion de los datos" << endl;
			}

		}
		else {
			system("cls");
			cout << "Hubo un error en la conexion con la base de datos" << endl;
		}
		cn.cerrar_conexion();
		system("pause");
	}
	void setFechaIng(string fn,int idp) { 
		fecha_ingreso = fn; 
		int q_estado;
		ConexionBD2 cn = ConexionBD2();

		cn.abrir_conexion();

		if (cn.getConectar()) {
			string idp1 = to_string(idp);
			string actualizar = "UPDATE productos SET fecha_ingreso = '" + fecha_ingreso + "' WHERE id_producto = " + idp1 + ";";
			const char* i = actualizar.c_str();
			q_estado = mysql_query(cn.getConectar(), i);

			if (!q_estado) {
				system("cls");
				cout << "Actualizacion exitosa" << endl;
			}
			else {
				system("cls");
				cout << "Hubo un error en la actualizacion de los datos" << endl;
			}

		}
		else {
			system("cls");
			cout << "Hubo un error en la conexion con la base de datos" << endl;
		}
		cn.cerrar_conexion();
		system("pause");
	}

	void setExistencia(int ex, int idp) {
		existencia = ex; 
		int q_estado;
		ConexionBD2 cn = ConexionBD2();

		cn.abrir_conexion();

		if (cn.getConectar()) {
			string idp1 = to_string(idp);
			string existencia = to_string(ex);
			string actualizar = "UPDATE productos SET existencia = " + existencia + " WHERE id_producto = " + idp1 + ";";
			const char* i = actualizar.c_str();
			q_estado = mysql_query(cn.getConectar(), i);

			if (!q_estado) {
				system("cls");
				cout << "Actualizacion exitosa" << endl;
			}
			else {
				system("cls");
				cout << "Hubo un error en la actualizacion de los datos" << endl;
			}

		}
		else {
			system("cls");
			cout << "Hubo un error en la conexion con la base de datos" << endl;
		}
		cn.cerrar_conexion();
		system("pause");
	}

	void SetIdMarca(string id_m,int idp) { 
		id_marca = id_m; 
		int q_estado;
		ConexionBD2 cn = ConexionBD2();

		cn.abrir_conexion();

		if (cn.getConectar()) {
			string idp1 = to_string(idp);
			string actualizar = "UPDATE productos SET id_marca = '" + id_marca + "' WHERE id_producto = " + idp1 + ";";
			const char* i = actualizar.c_str();
			q_estado = mysql_query(cn.getConectar(), i);

			if (!q_estado) {
				system("cls");
				cout << "Actualizacion exitosa" << endl;
			}
			else {
				system("cls");
				cout << "Hubo un error en la actualizacion de los datos" << endl;
			}

		}
		else {
			system("cls");
			cout << "Hubo un error en la conexion con la base de datos" << endl;
		}
		cn.cerrar_conexion();
		system("pause");
	}
	//-----------------------------------------------------------------------------------------------------------------------
	
	//METODOS GET
	string getProducto() { return producto; }
	string getDescrpcion() { return descripcion; }
	string getPrecioC() { return precio_costo; }
	string getPrecioV() { return precio_venta; }
	int getExistencia() { return existencia; }
	string getFechaIng() { return fecha_ingreso; }
	//------------------------------------------------------------------------------------------


	//Funcion para leer todos los regitros de la tabla "productos"
	void leer() {
		system("cls");
		int q_estado;
		ConexionBD2 cn = ConexionBD2();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;

		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "select * from productos";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "\t\tProductos" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << "ID de producto: "<< fila[0] << endl;
					cout <<"Producto: " << fila[1] << endl;
					cout << "ID de marca: "<< fila[2] << endl;
					cout << "Descripcion de producto: "<< fila[3] << endl;
					cout << "Precio de costo: "<< fila[4] << endl;
					cout <<"Precio de venta: " << fila[5] << endl;
					cout << "Existencia: "<< fila[6] << endl;
					cout << "Fecha de ingreso: "<<fila[7] << endl;
					cout << "____________________________________________" << endl;
				}
			}
		}
		cout << "____________________________________________" << endl;
		cn.cerrar_conexion();
		system("pause");
	}
	//----------------------------------------------------------------------------------------

	//Funcion para ingresar un registro en la tabla "productos"
	void ingresar() {
		int q_estado;
		ConexionBD2 cn = ConexionBD2();

		cn.abrir_conexion();

		if (cn.getConectar()) {
			string ext = to_string(existencia);
			string insertar = "INSERT INTO `productos`(`producto`,`id_marca`,`descripcion_producto`,`precio_costo`,`precio_venta`,`existencia`,`fecha_ingreso`) VALUES('" + producto + "','" + id_marca + "','" + descripcion + "','" + precio_costo + "','" + precio_venta + "', " + ext + " , '" + fecha_ingreso + "');";
			const char* i = insertar.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (q_estado) {
				system("cls");
				cout << "Ingreso exitoso" << endl;
				system("pause");
			}
		}
		else {
			system("cls");
			cout << "Hubo un error al ingresar los datos" << endl;
			system("pause");
		}
		cn.cerrar_conexion();
		system("pause");
	}
	//--------------------------------------------------------------------------------------------------------

	//Funcion para eliminar un registro de la tabla "productos" atraves del ID
	void eliminar(int id_p) {

		int q_estado;
		ConexionBD2 cn = ConexionBD2();

		cn.abrir_conexion();

		if (cn.getConectar()) {
			string id_p1 = to_string(id_p);
			string eliminar = "DELETE from productos where id_producto = " + id_p1 + "";
			const char* i = eliminar.c_str();
			q_estado = mysql_query(cn.getConectar(), i);

			if (!q_estado) {
				system("cls");
				cout << "Eliminacion exitosa" << endl;
			}
		}
		else {
			system("cls");
			cout << "Hubo un error a la hora de eliminar el registro deseado" << endl;
			system("pause");
		}
	cn.cerrar_conexion();
	system("pause");
}
	//---------------------------------------------------------------------------------------------------------------

	//Funcion para multiples usos, la cual lee solamente los ID de los productos disponibles en la base de datos
	void leerId() {
		system("cls");
		int q_estado;
		ConexionBD2 cn = ConexionBD2();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;

		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "SELECT id_producto, producto FROM productos ";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "\t\tID de productos existentes" << endl;
				cout << "ID de producto: ";
				while (fila = mysql_fetch_row(resultado)) {
					 cout << "|" << fila[0] << "|";
					 
				}
				cout << endl;
			}
		}
		cn.cerrar_conexion();
	}
	//------------------------------------------------------------------------
	
};

