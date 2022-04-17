// mysql_c++(2).cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "marcas.h"
#include <string>
#include "productos.h"

using namespace std;


//Defincion de funciones utilizadas
void CRUD_marcas();
void CRUD_productos();
void getDataProductos();
void getDataMarcas();
void D_productos();
void D_Marcas();
void Menu_Actualizar_p();
void Actualizar_marca();
void Actualizar_p();
void Actualizar_desc_p();
void Actualizar_id_marca();
void Actualizar_precio_costo_p();
void Actualizar_precio_venta_p();
void Actualizar_existencia_p();
void Actualizar_fecha_p();
//----------------------------------------
Productos p;

//Funcion principal
int main()
{
	int op;

	do {
		system("cls");
		cout << "1.CRUD de la tabla Marcas" << endl;
		cout << "2.CRUD de la tabla Productos" << endl;
		cout << "0.Salir" << endl;
		cout << "Ingrese la opcion que desea realizar: ";
		cin >> op;

		switch (op) {
		case 1: CRUD_marcas(); break;
		case 2: CRUD_productos(); break;
		case 0: break;
		default: cout << "La opcion que ingreso no existe, intentelo de nuevo" << endl; break;

		}
	} while (op != 0);
	
   system("pause");
   return 0;
}
//--------------------------------------------------------

//Menu de CRUD para marcas
void CRUD_marcas(){
	int op;
	Marcas m;
	do {
		system("cls");
		cout << "1.Agregar una marca" << endl;
		cout << "2.Leer marcas disponibles" << endl;
		cout << "3.Actualizar marca" << endl;
		cout << "4.Eliminar marca" << endl;
		cout << "0.Salir" << endl;
		cout << "Ingrese la opcion que desea realizar: ";
		cin >> op;

		switch (op) {
		case 1: getDataMarcas(); break;
		case 2: m.leerMarcas(); break;
		case 3: Actualizar_marca(); break;
		case 4: D_Marcas(); break;
		case 0: break;
		default: cout << "La opcion que ingreso no existe, intentelo de nuevo" << endl; break;

		}
	} while (op != 0);
}
//---------------------------------------------------

//Menu CRUD de productos
void CRUD_productos() {
	int op;
	Productos p;
	do {
		system("cls");
		cout << "1.Agregar un producto" << endl;
		cout << "2.Leer productos disponibles" << endl;
		cout << "3.Actualizar producto" << endl;
		cout << "4.Eliminar producto" << endl;
		cout << "0.Salir" << endl;
		cout << "Ingrese la opcion que desea realizar: ";
		cin >> op;

		switch (op) {
		case 1: getDataProductos(); break;
		case 2: p.leer(); break;
		case 3: Menu_Actualizar_p(); break;
		case 4: D_productos(); break;
		case 0: break;
		default: cout << "La opcion que ingreso no existe, intentelo de nuevo" << endl; break;

		}
	} while (op != 0);
}
//-----------------------------------------------------------------------------

//Funcion para agregar productos en la tabla productos
void getDataProductos() {
	string producto, descripcion, precio_costo, precio_venta,fecha_ingreso,id_marca;
	int existencia;

	system("cls");
	fflush(stdin);
	cout << "Ingrese el nombre del producto: ";
	cin.ignore();
	getline(cin, producto);
	cout << "Ingrese la descripcion del producto: ";
	getline(cin, descripcion);
	cout << "Ingrese el precio de costo del producto: ";
	getline(cin, precio_costo);
	cout << "Ingrese el precio de venta del producto: ";
	getline(cin, precio_venta);
	cout << "Ingrese la fecha de ingreso del producto: ";
	getline(cin, fecha_ingreso);
	cout << "Ingrese el id de la marca del producto: ";
	getline(cin, id_marca);
	cout << "Ingrese la cantidad de producto en existencia: ";
	cin >> existencia;

	Productos p = Productos(producto, precio_costo, descripcion, precio_venta, fecha_ingreso, existencia, id_marca);

	p.ingresar();
}
//----------------------------------------------------------------------------------------

//Funcion para eliminar un registro de la tabla productos a traves del ID
void D_productos() {
	Productos p;
	system("cls");
	p.leerId();

	int idp;

	cout << "Ingrese el ID del producto que desea eliminar: ";
	cin >> idp;

	p.eliminar(idp);
}
//-----------------------------------------------------------------------------

//Menu para actualizar todos los campos de la tabla productos por separado
void Menu_Actualizar_p() {
	system("cls");
	int op;

	cout << "1.Actualizar nombre del producto" << endl;
	cout << "2.Actualizar la descripcion del producto" << endl;
	cout << "3.Actualizar ID de marca del producto" << endl;
	cout << "4.Actualizar precio de costo del producto" << endl;
	cout << "5.Actualizar el precio de venta del producto" << endl;
	cout << "6.Actualizar la cantidad del producto en Stock" << endl;
	cout << "7.Actualizar la fecha en la que ingreso el producto" << endl;
	cout << "Ingrese la opcion que desea realizar: ";
	cin >> op;

	switch (op) {
	case 1: Actualizar_p(); break;
	case 2: Actualizar_desc_p(); break;
	case 3: Actualizar_id_marca(); break;
	case 4: Actualizar_precio_costo_p(); break;
	case 5: Actualizar_precio_venta_p(); break;
	case 6: Actualizar_existencia_p(); break;
	case 7: Actualizar_fecha_p(); break;
	default: cout << "La opcion que ingreso no existe" << endl; break;
	}
}
//-----------------------------------------------------------------------

//Funciones para actualizar cada campo de la tabla "produtos"
void Actualizar_p() {
	system("cls");
	string upp;
	int idp;
	Productos p;
	p.leerId();
	cout << "Ingrese el ID del producto que desea actualizar: ";
	cin >> idp;
	cout << "Ingrese el nuevo nombre del producto: ";
	cin.ignore();
	getline(cin, upp);

	p.setProducto(upp, idp);
}

void Actualizar_desc_p() {
	system("cls");
	string desc;
	int idp;
	Productos p;
	p.leerId();
	cout << "Ingrese el ID del producto que desea actualizar: ";
	cin >> idp;
	cout << "Ingrese la nueva descripcion del producto: ";
	cin.ignore();
	getline(cin, desc);

	p.setDescripcion(desc, idp);
}

void Actualizar_id_marca() {
	system("cls");
	string id_marca;
	int idp;
	Productos p;
	p.leerId();
	cout << "Ingrese el ID del producto que desea actualizar: ";
	cin >> idp;
	cout << "Ingrese el nuevo id marca del producto: ";
	cin.ignore();
	getline(cin, id_marca);

	p.SetIdMarca(id_marca, idp);
}

void Actualizar_precio_costo_p() {
	system("cls");
	string precio_costo;
	int idp;
	Productos p;
	p.leerId();
	cout << "Ingrese el ID del producto que desea actualizar: ";
	cin >> idp;
	cout << "Ingrese el precio costo del producto: ";
	cin.ignore();
	getline(cin, precio_costo);

	p.setPrecioC(precio_costo,idp);
}

void Actualizar_precio_venta_p() {
	system("cls");
	string precio_venta;
	int idp;
	Productos p;
	p.leerId();
	cout << "Ingrese el ID del producto que desea actualizar: ";
	cin >> idp;
	cout << "Ingrese el nuevo precio venta del producto: ";
	cin.ignore();
	getline(cin, precio_venta);

	p.setPrecioV(precio_venta, idp);
}

void Actualizar_existencia_p() {
	system("cls");
	int idp , existencia;
	Productos p;
	p.leerId();
	cout << "Ingrese el ID del producto que desea actualizar: ";
	cin >> idp;
	cout << "Ingrese la nueva vantidad en Stock del producto: ";
	cin >> existencia;

	p.setExistencia(existencia, idp);
}

void Actualizar_fecha_p() {
	system("cls");
	string fecha_p;
	int idp;
	Productos p;
	p.leerId();
	cout << "Ingrese el ID del producto que desea actualizar: ";
	cin >> idp;
	cout << "Ingrese la nueva fecha de ingreso del producto: ";
	cin.ignore();
	getline(cin, fecha_p);

	p.setFechaIng(fecha_p, idp);
}
//--------------------------------------------------------------------------------

//Funcion para agregar marca a la tabla "marcas" 
void getDataMarcas() {
	system("cls");
	string m2;
	cout << "Ingrese el nombre de la marca: ";
	cin.ignore();
	getline(cin, m2);

	Marcas m = Marcas(m2);
	m.agregarmarca();
}
//----------------------------------------------------

//Funcion para eliminar un registro de la tabla "marcas" atraves del ID
void D_Marcas() {
	Marcas m;
	system("cls");
	m.leerId();

	int idm;

	cout << "Ingrese el ID de la marca que desea eliminar: ";
	cin >> idm;

	m.eliminarmarcas(idm);
}
//------------------------------------------------------------------

//Funcion para actualizar la tabla marcas
void Actualizar_marca() {
	system("cls");
	Marcas m;
	string name_marca;
	int idm;

	m.leerId();

	cout << "Ingrese el ID de marca que desea actualizar: ";
	cin >> idm;
	cout << "Ingrese el nuevo nombre de la marca: ";
	cin.ignore();
	getline(cin, name_marca);

	m.setMarca(name_marca, idm);
}

//--------------------------------------------------