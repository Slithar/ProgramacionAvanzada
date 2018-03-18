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



void Clase::setInscripcion(Inscripcion* inscripcion[]) {
    int aux=0;
    while(this->inscripciones[aux] != NULL){
        aux++;
    }
    int a=0;
    while(inscripcion[a] != NULL){
        a++;
    }
    for(int i=0; i<a;i++){
        this->inscripciones[aux] = inscripcion[i];
    }
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

Clase::Clase(int id, string nombre){
    this->id = id;
    this->nombre = nombre;
}

Clase::Clase(const Clase& orig) {
    this->id = orig.id;
    this->nombre = orig.nombre;
}

Clase::~Clase() {
}

