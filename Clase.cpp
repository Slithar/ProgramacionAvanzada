/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Clase.cpp
 * Author: kapo_
 * 
 * Created on 16 de marzo de 2018, 02:53 PM
 */

#include "Clase.h"
#include<string.h>
#include <stdexcept>


/*Getters*/


Inscripcion** Clase::getInscripcion() {
    return this->inscripciones;
}


Turno Clase::getTurno(){
    return this->turno;
}
int Clase::getId(){
    return this->id;
}

string Clase::getNombre(){
    return this->nombre;
}

/*Setters*/


Socio* Clase::socioEnClase(string ci) {
    for(int i=0;i<MAX_Inscripcion;i++){
        if(this->inscripciones[i]->getSocio()->getCI().compare(ci)==0){
        return this->inscripciones[i]->getSocio();
        break;}
    }
    return NULL;
    
}


void Clase::setInscripcion(Inscripcion *inscripcion) {
    int i=0;
    for(i;i<MAX_Inscripcion;i++){
        if(this->inscripciones[i]==NULL){
            break;
        }else{return throw std::invalid_argument("Maximo de inscripciones alcanzado");}
    }
    this->inscripciones[i]=inscripcion;
}

void Clase::setTurno(Turno turno){
    this->turno = turno;
}

void Clase::setId(int id){
    this->id = id;
}

void Clase::setNombre(string nombre){
    this->nombre = nombre;
}
/*Creators and destroyers*/
Clase::Clase() {
}
//Socio * Socio::socioEnClase(string ci);

Clase::Clase(int id, string nombre, Turno t){
    this->id = id;
    this->nombre = nombre;
    this->turno = t;
}

Clase::Clase(const Clase& orig) {
    this->id = orig.id;
    this->nombre = orig.nombre;
}

Clase::~Clase() {
}

