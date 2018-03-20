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
#include <cstring>
#include "Clase.h"
#include "Spinning.h"
#include "Entrenamiento.h"
#include "Socio.h"
#include "DtSocio.h"
#include "Inscripcion.h"
#include "eTurno.h"
using namespace std;
int const MAX_SOCIOS = 1;
int CantSocios = 0;
Socio* arreglo_socios[MAX_SOCIOS];
/*
 * 
 */
void mostrarSocios();
void agregarSocio(int);
bool existeSocio(string);
int main(int argc, char** argv) {
    /*std::list<Clase*> ListaClase;
    Clase *p = new Spinning();
    ListaClase.push_front(p);
    p->setNombre("SpinningCami");
    p->setId(1);
    Turno T = Turno::Manana;
    //cout<<"Turno: "+std::to_string(T) << end;
    try{
        cout<<"Id de la clase: "+ std::to_string(p->getId()) + "\nNombre de la clase: " + p->getNombre() <<endl;    
    }
    catch(const std::invalid_argument& ia){
        cout<<"Argumento Invalido: "<<ia.what();
    }*/
    int opcionMenu;
    do{
        cout<<"\n1-Agregar socio\n2- Mostrar socios\n0- Salir\n";
        cin>>opcionMenu;
        switch(opcionMenu){
            case 1:
                agregarSocio(CantSocios);
                CantSocios++;
                break;
            case 2:
                mostrarSocios();
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

void agregarSocio(int flag){
    string ci, nombre;
    cout<<"\nIngrese el número de Cédula del nuevo socio\n";
    cin>>ci;
    if(existeSocio(ci) == true){
        cout<<"\nYa existe un usuario con esta cédula\n";
    }else{
        cout<<"\nIngrese el nombre del nuevo socio\n";
        cin>>nombre;
        Socio* s = new Socio(ci, nombre);
        try{
            arreglo_socios[flag] = s;
        }catch(const std::invalid_argument& ia){
            throw std::invalid_argument("Se ha exedido el número de socios");
        }
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