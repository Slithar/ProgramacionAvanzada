/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtSpinning.h
 * Author: mcurbelo
 *
 * Created on March 19, 2018, 3:35 PM
 */

#ifndef DTSPINNING_H
#define DTSPINNING_H
#include "DtClase.h"
class DtSpinning : public DtClase {
public:
    DtSpinning();
    DtSpinning(const DtSpinning& orig);
    virtual ~DtSpinning();
private:
    int cantBicicletas;
};

#endif /* DTSPINNING_H */

