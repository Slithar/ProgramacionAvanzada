/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: kapo_
 *
 * Created on 16 de marzo de 2018, 02:39 PM
 */

#include <cstdlib>
#include <iostream>
#include<list>
#include <string>
#include "Clase.h"
#include "Spinning.h"
#include "Entrenamiento.h"
#include "Socio.h"
#include "DtSocio.h"
#include "Inscripcion.h"
#include "eTurno.h"
#include "DtClase.h"
#include "DtSpinning.h"
#include "DtEntrenamiento.h"
using namespace std;
int const MAX_SOCIOS = 10, MAX_CLASES = 10;
int CantSocios = 0;
int CantClases = 0;

Socio* arreglo_socios[MAX_SOCIOS];
Clase* arreglo_clases[MAX_CLASES];
/*
 * 
 */
void mostrarSocios();
void agregarSocio(int);
bool existeSocio(string);
void agregarInscripcion(string,int, Fecha);
void pedirDatosClase();
void agregarClase(DtClase&);
void mostrarClases();
bool existeClase(int);
void inscribirSocio();
int main(int argc, char** argv) {
    int opcionMenu;
    do{
        cout<<"\n1- Agregar socio\n2- Mostrar socios\n3- Agregar clase\n4- Mostrar clases\n5- Inscribir a clasen\n0- Salir\n";
        cin>>opcionMenu;
        switch(opcionMenu){
            case 1:
                agregarSocio(CantSocios);
                break;
            case 2:
                mostrarSocios();
                break;
            case 3:
                pedirDatosClase();
                break;
            case 4:
                mostrarClases();
                break;
            case 5:
                inscribirSocio();
                break;
            case 0:
                break;
            default:
                cout<<"\nOpción incorrecta. Por favor intente nuevamente.\n";
                break;
        }
    }while(opcionMenu != 0);
    
    
    return 0;
}
bool existeClase(int id){
    bool r = false;
    for(int a=0; a<CantClases;a++){
        if(arreglo_clases[a]->getId() == id)
            r = true;
    }
    return r;
}
void inscribirSocio(){
    int dia,mes,anio,codClase;
string ciS;
try{   
cout<<"Incribir Socio a clase:\n";
    cout<<"Ingrese la cedula:\n";
    cin>>ciS;
    cout<<"Ingrese el codigo de la clase:\n";
    cin>>codClase;
    if((existeSocio(ciS)!=false)&&(existeClase(codClase)!=false)){
    cout<<"Ingrese la fecha:\n";
    cout<<"Dia:\n";
    cin>>dia;
    cout<<"Mes:\n";
    cin>>mes;
    cout<<"Año:\n";
    cin>>anio;
    Fecha fecha;
    fecha.setDia(dia);
    fecha.setMes(mes);
    fecha.setAnio(anio);
    agregarInscripcion(ciS,codClase,fecha);
    }
    else {  throw std::invalid_argument("El socio o la clase no existen");
        }
    
} catch(std::invalid_argument &ia){
        cout<< ia.what() << endl;
    }
}
void agregarInscripcion(string ci, int codC, Fecha fecha){
    try{
    Socio * soc = existeSocio(ci);
    Clase* clas = existeClase(codC);
    Inscripcion * ins;
    if (clas->socioEnClase(ci)==NULL){
        ins= new Inscripcion(ci,fecha);
        clas->setInscripcion(ins);
    }
    else{throw std::invalid_argument("El socio ya esta inscripto a la clase.");}
    }
    catch(std::invalid_argument & ia){
    cout<< ia.what() <<endl;}
}

void mostrarClases(){
 for(int a=0; a<CantClases; a++){
     cout<<"\nID: "+std::to_string(arreglo_clases[a]->getId())+"\nNombre: "+arreglo_clases[a]->getNombre()+"\n";
     if(arreglo_clases[a]->getTurno() == Turno::Manana)
         cout<<"Turno: Manana\n";
     else if (arreglo_clases[a]->getTurno() == Turno::Tarde)
         cout<<"Turno: Tarde\n";
     else
         cout<<"Turno: Noche\n";
     if( Spinning* s = dynamic_cast<Spinning*>(arreglo_clases[a])){
         cout<<"Bicicletas: "+std::to_string(s->getCantBicicletas())+"\n";
     }
     else{
         Entrenamiento* e = dynamic_cast<Entrenamiento*>(arreglo_clases[a]);
         cout<<"En rambla: "+std::to_string(e->getEnRambla())+"\n";
     }
 }   
}

void pedirDatosClase(){
    try{
        int id,optT, cantBicicletas;
        string nombre;
        bool enRambla;
        DtClase clase;
        Turno t;
        cout<<"\nIngrese ID de la clase\n";
        cin>>id;
        if(existeClase(id))
            throw std::invalid_argument("El ID de la clase ya existe");
        clase.setId(id);
        cout<<"\nIngrese nombre de la clase\n";
        cin>>nombre;
        clase.setNombre(nombre);
        do{
            cout<<"\nIngrese turno de la clase:\n1- Manana\n2- Tarde\n3- Noche\n";
            cin>>optT;
            switch(optT){
                case 1:
                    t = Turno::Manana;
                    break;
                case 2:
                    t = Turno::Tarde;
                    break;
                case 3:
                    t = Turno::Noche;
                    break;
                default:
                    break;
            }
        }while(optT != 1 && optT != 2 && optT != 3);
        clase.SetTurno(t);
        agregarClase(clase);
    }
    catch(std::invalid_argument &ia){
        cout<< ia.what() << endl;
    }
}


void agregarClase(DtClase& clase){
    int optT, cantBicicletas;
    do{
        cout<<"\nQue tipo de clase desea crear?\n1- Spinning\n2- Entrenamiento\n";
        cin>>optT;
        if(optT == 1){
            cout<<"\nIngrese la cantidad de bicicletas\n";
            cin>>cantBicicletas;
            Spinning* claseSpinning  = new Spinning(clase.getId(), clase.getNombre(), clase.getTurno(), cantBicicletas);
            arreglo_clases[CantClases] = claseSpinning;
            CantClases++;
        }
        else if(optT == 2){
            cout<<"\El entrenamiento es en rambla?\n1- Si\n2- No\n";
            cin>>optT;
            if(optT == 1){
                Entrenamiento* claseEntrenamiento = new Entrenamiento(clase.getId(), clase.getNombre(), clase.getTurno(), true);
                arreglo_clases[CantClases] = claseEntrenamiento;
                CantClases++;
            }
            else{
               Entrenamiento* claseEntrenamiento = new Entrenamiento(clase.getId(), clase.getNombre(), clase.getTurno(), false);
               arreglo_clases[CantClases] = claseEntrenamiento;
               CantClases++;
            }
        }
        else{
            cout<<"\nOpción incorrecta\n";
        }
    }while(optT != 1 && optT != 2);
}


void agregarSocio(int flag){
    try{
        string ci, nombre;
        cout<<"\nIngrese el número de Cédula del nuevo socio\n";
        cin>>ci;
        if(existeSocio(ci) == true){
            throw std::invalid_argument("\nYa existe un usuario con esta cédula\n");
        }else{
            cout<<"\nIngrese el nombre del nuevo socio\n";
            cin>>nombre;
            Socio* s = new Socio(ci, nombre);
                arreglo_socios[flag] = s;
                CantSocios++;
        }
    }
    catch(std::invalid_argument& ia){
        cout<<ia.what()<<endl;
    }
}

bool existeSocio(string CI){
    bool r = false;
    for(int i=0;i < CantSocios; i++){
        if(arreglo_socios[i] != NULL && arreglo_socios[i]->getCI()   == CI){
            r = true;
        }
    }
    return r;
}

void mostrarSocios(){
    for(int a = 0; a < CantSocios; a++){
        cout<<"\nCedula: "+arreglo_socios[a]->getCI()+" Nombre: "+arreglo_socios[a]->getNombre()+"\n";
    }
}

