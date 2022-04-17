#pragma once
#include<iostream>
#include<string>
#include"ConexionDB2.h"

using namespace std;

class Marcas {
	//Atributos
private: string id_marcas, marca;

public:
	//Metodos
	Marcas() {

	}
	Marcas(string m) {
		marca = m;
	}

	//Metodos set y get
	//sets para actualizar la tabla marcas
	void setIdMarcas(string id_m) { id_marcas = id_m; }

	void setMarca(string m,int idm) { 
		marca = m; 
		int q_estado;
		ConexionBD2 cn = ConexionBD2();

		cn.abrir_conexion();

		if (cn.getConectar()) {
			string idm1 = to_string(idm);
			string actualizar = "UPDATE marcas SET marca = '" + marca + "' WHERE id_marca = " + idm1 + ";";
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

	//gets
	string getIdMarcas() { return id_marcas; }
	string getMarca() { return marca; }


	//Funcion para leer las marcas existentes de la tabla marcas
	void leerMarcas() {
		system("cls");
		int q_estado;
		ConexionBD2 cn = ConexionBD2();

		MYSQL_ROW fila;
		MYSQL_RES* resultado;

		cn.abrir_conexion();

		if (cn.getConectar()) {
			string leer = "select * from marcas";
			const char* c = leer.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "\t\tMarcas" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << "ID de marca: " << fila[0] << endl;
					cout << "Nombre de marca: " << fila[1] << endl;
					cout << "--------------------------------" << endl;
				}
			}
		}
		cout << "____________________________________________" << endl;
		cn.cerrar_conexion();
		system("pause");
	}

	//Funcion para agregar una marca en la tabla "marcas"
	void agregarmarca() {
		int q_estado;
		ConexionBD2 cn = ConexionBD2();
		
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string add = "INSERT INTO `db2_empresa`.`marcas`(`marca`) VALUES ('" + marca + "')";
			const char* i = add.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				system("cls");
				cout << "Ingreso exitoso" << endl;
			}
			else {
				cout << "Hubo un error al ingresar el registro" << endl;
			}
		}
		else {
			cout << "Hubo un error en la conexion" << endl;
		}
		cn.abrir_conexion();
		system("pause");
	}
	//---------------------------------------------------------------------------

	//Funcion para eliminar un registro de la tabla "marcas" atraves del ID
	void eliminarmarcas(int id_m) {
		int q_estado;
		ConexionBD2 cn = ConexionBD2();

		cn.abrir_conexion();

		if (cn.getConectar()) {
			string id_p1 = to_string(id_m);
			string eliminar = "DELETE from marcas where id_marca = " + id_p1 + "";
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
	//--------------------------------------------------------------------------

	//Funcion de multiples usos para leer solamente los id de la tabla marcas
	void leerId() {
		int q_estado;
		ConexionBD2 cn = ConexionBD2();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;

		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "SELECT id_marca FROM marcas";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "\t\tID de marcas existentes" << endl;
				cout << "ID marca: ";
				while (fila = mysql_fetch_row(resultado)) {
					cout << "|" << fila[0] << "|";
				}
				cout << endl;
			}
		}
		cn.cerrar_conexion();
	}
};