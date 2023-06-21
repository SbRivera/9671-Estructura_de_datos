#include<iostream>
#include <string>
#include <cstring> 
#include "Archivo.cpp"
#include "Persona.h"
#include "ListaCircularDoble.cpp"
#include "Validaciones.cpp"

class operacionesArchivo{
	
	private:
		Persona empleado;
		Archivo archivo;
		ListaDoble listaPersonas;
		
	private:
	string* splitString(string str,string deli);
	Persona CargarPersona(int);
	Persona menuBusqueda();
	bool ActualizarRegistroPersonas();
	char* mystoi(int num);	
	
	public:
	/*Funciones Listas*/
	bool verificarRegistroVacio();
	void crearRegistro(void);
	bool registrarPersona(Persona emp);
	bool CargarListaPersonas();
	void LeerDatos();
	bool buscarPersona(Persona);
	void mostrarCdoc();
	void EliminarPersonas(Persona emp);
	/*Funciones que faltan*/
	
	void actualizarPersonas(Persona emp, Persona actualizar);
	string leerArchivo();
	
	operacionesArchivo();
	~operacionesArchivo();	
	
};

operacionesArchivo::operacionesArchivo(){
	this->empleado=Persona();
	this->archivo=Archivo();
	this->archivo.setNombreCarpeta("Registro");
}

operacionesArchivo::~operacionesArchivo(){
	
}

void operacionesArchivo::crearRegistro(){
	
	bool band1=archivo.crearCarpeta("Registro");
	if(band1){
		archivo.setNombreCarpeta("Registro");
		
		if(band1){
			bool band1=archivo.crearArchivo("Registro","Registro.txt");
			if(band1){
				cout<<"Registro creado"<<endl;
			}
		}	
	}
}

bool operacionesArchivo::registrarPersona(Persona emp){
	
	bool bnd1=false;
	
	const char* cad2="Registro.txt";
	
	if(listaPersonas.verificarVacio()){
		string guardar=emp.getNombre()+","+emp.getApellido()+","+emp.getCedula()+","+emp.getCargo()+","+to_string(emp.getSalario());
		if(archivo.verificarArchivoVacio(cad2)){
			bnd1=archivo.ReEscribirArchivo(cad2,guardar);
		}else{
			bnd1=archivo.escribirArchivo(cad2,guardar);
		}
		
		if(bnd1){
			listaPersonas.insertarPorCabeza(emp);
			cout<<"\n ||Registro Exitoso|| "<<endl;	
		}
		
	}else if(!listaPersonas.verificarDobles(emp)){
		
		string guardar=emp.getNombre()+","+emp.getApellido()+","+emp.getCedula()+","+emp.getCargo()+","+to_string(emp.getSalario());
		bnd1=archivo.escribirArchivo(cad2,guardar);
		if(bnd1){
			listaPersonas.insertarPorCabeza(emp);
			cout<<"\n||Registro Exitoso|| "<<endl;	
		}
		
	}else{
		cout<<"\n||El registro ya existe|| "<<endl;
	}
	

	emp.~Persona();
	return bnd1;
}

Persona operacionesArchivo::CargarPersona(int i){
	
	string* datos;
	string* datosEm;
	char* ced;
	Persona emp1;
	bool bandera=false;

	
	datos=archivo.ArchivoAObjeto("Registro.txt");
	
	if(datos!=NULL){
		
		datosEm=splitString(datos[i],",");
		ced=strdup(datosEm[2].c_str());
		double salario=stod(datosEm[4]);
	
		emp1.setNombre(datosEm[0]);
		emp1.setApellido(datosEm[1]);
		emp1.setCedula(ced);
		emp1.setCargo(datosEm[3]);
		emp1.setSalario(salario);
	}
	
	return emp1;
}

bool operacionesArchivo::CargarListaPersonas(){
	
	bool bandera=false;
	Persona empaux=Persona();
	
	if(!archivo.verificarArchivoVacio("Registro.txt")){

		if(listaPersonas.verificarVacio()){
			
			for(int i=0;i<archivo.getLenght();i++){
				
				empaux=CargarPersona(i);
				if(empaux.getNombre()!=""){
					listaPersonas.insertarPorCabeza(empaux);	
				}
			}
		}
			
	}
	
	if(!listaPersonas.verificarVacio()){
		bandera=true;
//		cout<<"Existen datos guardados"<<endl;
	}else{
		listaPersonas=ListaDoble();
	}
	
	empaux.~Persona();
	return bandera;
}

bool operacionesArchivo::buscarPersona(Persona emp){
	Persona empFinded;
	bool bandera=false;
	if(!listaPersonas.verificarVacio()){
		int a=listaPersonas.buscar(emp);
		
		empFinded=listaPersonas.getPersona(a);
		
		if(empFinded.getNombre()!="n"){
			cout<<"\n\n  ||Registro Encontrado|| "<<endl;
			cout<<"Nombre: "<<empFinded.getNombre()<<endl;
			cout<<"Apellido: "<<empFinded.getApellido()<<endl;
			cout<<"C\202dula: "<<empFinded.getCedula()<<endl;
			bandera=true;
		}else{
			cout<<"\nRegistro no encontrado";
			bandera=false;
		}
		
		
	}else{
		cout<<"\nLista vac\241a"<<endl;
	}

	emp.~Persona();
	return bandera;
}


void operacionesArchivo::LeerDatos(){
	
	if(!listaPersonas.verificarVacio()){
		listaPersonas.mostrar();
	}else{
		cout<<"\nLista vac\241a"<<endl;
	}
	
}

void operacionesArchivo::EliminarPersonas(Persona emp){
	
	int borrar=0;
	int b;
	bool bandera=false;
	
	if(!listaPersonas.verificarVacio()){
		if(emp.getCedula()!=NULL){
			int a=listaPersonas.buscar(emp);
			if(a!=0){
				bandera=listaPersonas.borrarPorPosicion(a);
			}
			
		}else if(!emp.getApellido().empty()){
			
			do{
				b=listaPersonas.buscarPorApellido(emp);
				if(b!=0){
					bandera=listaPersonas.borrarPorPosicion(b);
				}
			}while(b!=0);
		}
		
		if(bandera){
			cout<<"\n Usuario Eliminado exitosamente "<<endl;
			ActualizarRegistroPersonas();
		}
		
	}else{
		cout<<"\nLista vac\241a"<<endl;
		listaPersonas=ListaDoble();
	}
	
	emp.~Persona();
	
}

void operacionesArchivo::actualizarPersonas(Persona emp, Persona actualizar){
	
	int borrar=0;
	int b;
	bool bandera=false;
	bool bandera2=false;
	
	if(!listaPersonas.verificarVacio()){
		if(emp.getCedula()!=NULL){
			bandera=listaPersonas.actualizarDato(emp,actualizar);
			if(bandera){
				bandera2=ActualizarRegistroPersonas();
				if(bandera2){
					cout<<"\n Registro actualizado"<<endl;	
				}
			}
		}
	}else{
		cout<<"\n Lista vac\241a"<<endl;
	}
	emp.~Persona();
	
}

bool operacionesArchivo::ActualizarRegistroPersonas(){
	int lenght=0;
	Persona empAux;
	string cad2;
	bool bandera;
	
	cad2="Registro.txt";
	if(!listaPersonas.verificarVacio()){
		
		lenght=listaPersonas.getLenght();
		cout<<"lenght: "<<lenght<<endl;
		for(int i=1;i<=lenght;i++){
			empAux=listaPersonas.getPersona(i);
			string guardar=empAux.getNombre()+","+empAux.getApellido()+","+empAux.getCedula()+","+empAux.getCargo()+","+to_string(empAux.getSalario());

			if(i==1){
				archivo.ReEscribirArchivo(cad2,guardar);
			}else{
				bandera=archivo.escribirArchivo(cad2,guardar);
			}
		}
		
	}else{
		archivo.ReEscribirArchivo(cad2,"");
		cout<<"\nLista vac\241a"<<endl;
		listaPersonas=ListaDoble();
	}
	
	empAux.~Persona();
	return bandera;	
} 

string* operacionesArchivo::splitString(string str,string deli){
	
	int start = 0,cont=0;
    int end = str.find(deli);
    string* datos=new string[5];
    
    while (end != -1) {
        datos[cont]=str.substr(start, end - start);
        start = end + deli.size();
        end = str.find(deli, start);
        cont++;
    }
    
	datos[4]=str.substr(start, end - start);
    
    return datos;
}

bool operacionesArchivo::verificarRegistroVacio(){
	return listaPersonas.verificarVacio();
}


char* operacionesArchivo::mystoi(int num){
	char* numr;
	string cero="0";
	if(num<10){
		string numreturn=to_string(num);
		string num1=cero+numreturn;
		numr=strdup(num1.c_str());	
	}else{
		string num1=to_string(num);
		numr=strdup(num1.c_str());	
	}	
	return numr;
}

string operacionesArchivo::leerArchivo(){
	string texto;
        string lectura;
        string cad2;
		cad2="Personas.txt";
        ifstream archivo;
        archivo.open("RegistroPersonas"+cad2,ios::in);
        if (archivo.fail())
        {
            cout << "\n No se pudo abrir el archivo";
            exit(1);
        }
        while (!archivo.eof())
        {
            getline(archivo, texto, ',');
            lectura += texto + ",";
        }
        archivo.close();
        return lectura;
}

