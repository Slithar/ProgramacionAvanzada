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

Clase::Clase(int id, string nombre){
    this->id = id;
    this->nombre = nombre;
}
/*Getters*/
int Clase::getId(){
    return this->id;
}

string Clase::getNombre(){
    return this->nombre;
}
/*Setters*/
void Clase::setId(int id){
    this->id = id;
}

void Clase::setNombre(string nombre){
    this->nombre = nombre;
}
/*Creators and destroyers*/
Clase::Clase() {
}

Clase::Clase(const Clase& orig) {
    this->id = orig.id;
    this->nombre = orig.nombre;
}

Clase::~Clase() {
}

