/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Incripcion.cpp
 * Author: kapo_
 * 
 * Created on 16 de marzo de 2018, 04:33 PM
 */

#include "Inscripcion.h"

Socio* Inscripcion::getSocio(){
    return this->socio;
}

void Inscripcion::setSocio(Socio* socio){
    this->socio = socio;
}

Inscripcion::Inscripcion() {
}

Inscripcion::Inscripcion(const Inscripcion& orig) {
}

Inscripcion::~Inscripcion() {
}

