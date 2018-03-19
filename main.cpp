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
#include "Clase.h"
#include "Spinning.h"
#include "Entrenamiento.h"
#include "Socio.h"
#include "DtSocio.h"
#include "Inscripcion.h"
#include "eTurno.h"
using namespace std;
int const MAX_SOCIOS = 10;
int CantSocios = 0;
Socio* arreglo_socios[MAX_SOCIOS];
/*
 * 
 */

void agregarSocio(int);
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
    agregarSocio(CantSocios);
    
    
    return 0;
}

void agregarSocio(int flag){
    string ci, nombre;
    cout<<"\nIngrese el número de Cédula del nuevo socio\n";
    cin>>ci;
    cout<<"\nIngrese el nombre del nuevo socio\n";
    cin>>nombre;
    Socio* s = new Socio(ci, nombre);
    try{
        arreglo_socios[flag] = s;
    }catch(const std::invalid_argument& ia){
        throw std::invalid_argument("Se ha exedido el número de socios");
    }
}