/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Fecha.h
 * Author: mcurbelo
 *
 * Created on March 19, 2018, 3:33 PM
 */

#ifndef FECHA_H
#define FECHA_H

class Fecha {
public:
    Fecha();
    Fecha(const Fecha& orig);
    virtual ~Fecha();
private:
    int dia;
    int mes;
    int anio;
};

#endif /* FECHA_H */

