/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtEntrenamiento.cpp
 * Author: mcurbelo
 * 
 * Created on March 19, 2018, 3:34 PM
 */

#include "DtEntrenamiento.h"

void DtEntrenamiento::setEnRambla(bool enRambla){
    this->enRambla = enRambla;
}

bool DtEntrenamiento::getEnRambla(){
    return this->enRambla;
}
DtEntrenamiento::DtEntrenamiento() {
}

DtEntrenamiento::DtEntrenamiento(const DtEntrenamiento& orig) {
}

DtEntrenamiento::~DtEntrenamiento() {
}

