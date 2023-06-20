/*
	Universidad de las Fuerzas Armadas ESPE
	-- Estructura de Datos--
	Alumno/s: Gutiérrez Miguel, Rivera Sebastián, Suquillo Martín
	Fecha de creación: 01/05/2023
	Enunciado: Proyecto 1P
	Nivel.- 3  NRC: 9671 
*/
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fstream>
#include <string>
#include <filesystem>

using namespace std;

class Archivo{
	
	private:
	/*Atributos*/
	string nombreCarpeta;
	string nombreArchivo;
	string path;
	int lenght;
	
	/*Metodos*/
	private:
	 bool is_empty(std::ifstream& pFile);
	 string getCurrentPath();
	 bool IsPathExist(const string &s);
	 bool isBlank(string line);
	 int contarLineasArchivo(string archivoName);
	 bool verificarExistencia(string nombreArchivo);
	 
	
	public:
		/*Metodos de crear*/
		bool crearCarpeta(const char*);
		bool crearArchivo(string nombreCarpeta1,string nombreArchivo);
		bool verificarArchivoVacio(string nArchivo);
		/*metodos para escribir*/
		bool escribirArchivo(string nombreArchivo,string escrito);
		bool ReEscribirArchivo(string nombreArchivo,string escrito);
		/*Metodos para leer datos del archivo*/
		void leerArchivo(string archivoName);
		string *ArchivoAObjeto(string archivoName);
		/*Metodo para eliminar Archivos*/
		bool EliminarArchivo(string archivoName);
		
		
		/*setters y getters*/
		void setNombreCarpeta(string carpeta);
		void setNombreArchivo(string archivo);
		void setPath(string path);
		void setLenght(int lenght);
		
		string getNombreCarpeta(void);
		string getNombreArchivo(void);
		string getPath(void);
		int getLenght(void);
		
		/*Constructores y destructores*/
		Archivo();
		Archivo(string dName);
		~Archivo();
};


/*constructor y destructor*/

Archivo::Archivo(){
}

Archivo::Archivo(string dName){
	this->nombreCarpeta=dName;
}

Archivo::~Archivo(){
}

/*metodos para crear*/
bool  Archivo::crearCarpeta(const char*nombreCarpeta1){
	
	bool bandera=false;
    const char* dirname;
    
    if(verificarExistencia(nombreCarpeta1)==false){
		dirname=nombreCarpeta1;
    	mkdir(dirname);
    	bandera=true;
    	setNombreCarpeta(nombreCarpeta1);
	}
	
	
	return bandera;
	
}

bool Archivo::crearArchivo(string nombreCarpeta1,string nombreArchivo){
	
	bool bandera;
	string path1;
	
	bandera=false;
	path1=nombreCarpeta1+"\\"+nombreArchivo;
	
	if(verificarExistencia(nombreCarpeta1)==true&&verificarExistencia(path1)==false){
		ofstream myfile(path1);
		myfile.close();
		bandera=true;	
	}
	
	return bandera;
	
}

/*metodo para escribir en el archivo*/
bool Archivo::escribirArchivo(string nombreArchivo,string escrito){
	
	bool bandera=false;
	if(verificarExistencia(nombreCarpeta+"\\"+nombreArchivo)!=false){
		fstream myFile;
		myFile.open(getPath()+"\\"+nombreArchivo,ios::app);
		if(myFile.is_open()){
			myFile<<escrito+"\n";
			myFile.close();
			bandera=true;
			lenght++;
		}
		
	}
	setLenght(lenght);
	return bandera;
}

/*metodo para escribir en el archivo*/
bool Archivo::ReEscribirArchivo(string nombreArchivo,string escrito){
	
	bool bandera=false;
	if(verificarExistencia(nombreCarpeta+"\\"+nombreArchivo)!=false){
		fstream myFile;
		myFile.open(getPath()+"\\"+nombreArchivo,ios::out);
		if(myFile.is_open()){
			myFile<<escrito+"\n";
			myFile.close();
			bandera=true;
			lenght++;
		}
		
	}
	setLenght(lenght);
	return bandera;
}


/*Metodos para leer datos del archivo*/
void Archivo::leerArchivo(string archivoName){
	
	if(verificarExistencia(nombreCarpeta+"\\"+archivoName)){
		fstream myFile;
		
		myFile.open(getPath()+"\\"+archivoName,ios::in);
		
		if(myFile.is_open()&&!verificarArchivoVacio(archivoName)){
			string line;
			
			while(getline(myFile,line)){
				
				if(!line.empty()&&!isBlank(line)){
					cout<<line<<endl;
				}
				
			}
			
			myFile.close();
		}
		
	}
}

string* Archivo::ArchivoAObjeto(string archivoName){
	
	string* datos=NULL;
	int i=0;
	
	if(!verificarArchivoVacio(archivoName)){
		
		datos=new string[getLenght()];
		if(verificarExistencia(nombreCarpeta+"\\"+archivoName)){
		
		fstream myFile;
		myFile.open(getPath()+"\\"+archivoName,ios::in);
		
		if(myFile.is_open()){
			
			string line;
			
			while(getline(myFile,line)){
				
				if(!line.empty()&&!isBlank(line)){
					datos[i]=line;
					i++;
				}
				
			}
			
			myFile.close();
		}
		
	}
} 
	
	
	
	return datos;
}


/*verificar archivo Vacio*/
bool Archivo::verificarArchivoVacio(string nArchivo){
	
	bool bandera=false;
	if(contarLineasArchivo(nArchivo)==0){
		bandera=true;
	}
	
	return bandera;
}

int Archivo::contarLineasArchivo(string archivoName){
	int lenght=0;
	
	bool verf=false;
	if(verificarExistencia(nombreCarpeta+"\\"+archivoName)){
		fstream myFile;
		myFile.open(getPath()+"\\"+archivoName,ios::in);
		
		if(myFile.is_open()){
			string line;
			while(getline(myFile,line)){
				if(!line.empty()&&!isBlank(line)){
					lenght++;		
				}
			}
			myFile.close();
		}
		
	}
	setLenght(lenght);

	return lenght;
}

bool Archivo::isBlank(string line){
	
	bool bandera=false;
	int count = 0;
	for (int i = 0; i <line.size(); i++){
		if (line[i]!=' '){
			count++;	
		} 	
	}
	
	if(count==0){
		bandera=true;
	}
    

  return bandera;
}

/*Eliminar Archivos*/
bool Archivo::EliminarArchivo(string archivoName){
	
	bool bandera=false;
	string path1=getPath()+"\\"+archivoName;
	const char*remover=path1.c_str();
	if(verificarExistencia(nombreCarpeta+"\\"+archivoName)){
		
		if(remove(remover)==0){
			cout<<"file "<<archivoName<<" was succesfull deleted c:"<<endl;
			bandera=true;
		}
	}else{
		cout<<"Bad Direction :C"<<endl;
	}
	
	

	return bandera;	
}



/*metodos para verificar*/


bool Archivo::IsPathExist(const string &s)
{
  struct stat buffer;
  return (stat (s.c_str(), &buffer) == 0);
}

string Archivo::getCurrentPath(){
	
	char tmp[256];
    getcwd(tmp, 256);
	
	return tmp;
}

bool Archivo::verificarExistencia(string nombreArchivo){
	
	bool bandera=false;
	string pathC=getCurrentPath();
	string pathF=pathC+"\\"+nombreArchivo;
	bandera=IsPathExist(pathF);
	
	return bandera;
}



/*setters y getters*/
void Archivo::setNombreCarpeta(string carpeta){
	this->nombreCarpeta=carpeta;
}

void Archivo::setNombreArchivo(string archivo){
	this->nombreArchivo=archivo;
}

void Archivo::setPath(string path){
	this->path=path;
}

void Archivo::setLenght(int lenght){
	this->lenght=lenght;
}


		

string Archivo::getNombreCarpeta(void){
	return nombreCarpeta;
}

string Archivo::getNombreArchivo(void){
	return nombreArchivo;	
}

string Archivo::getPath(void){
	
	return getCurrentPath()+"\\"+nombreCarpeta;
	
}

int Archivo::getLenght(void){
	return lenght;	
}


