/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtSpinning.cpp
 * Author: mcurbelo
 * 
 * Created on March 19, 2018, 3:35 PM
 */

#include "DtSpinning.h"

void DtSpinning::setCantBicicletas(int cantBicicletas){
    this->cantBicicletas = cantBicicletas;
}

int DtSpinning::getCantBicicletas(){
    return this->cantBicicletas;
}

DtSpinning::DtSpinning() {
}

DtSpinning::DtSpinning(const DtSpinning& orig) {
}

DtSpinning::~DtSpinning() {
}

