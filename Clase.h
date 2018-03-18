/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Clase.h
 * Author: kapo_
 *
 * Created on 16 de marzo de 2018, 02:53 PM
 */

#ifndef CLASE_H
#define CLASE_H
#include<string>
#include "eTurno.h"
#include "Inscripcion.h"
using namespace std;
class Clase {
private:
    Inscripcion *inscripciones[50];
    int id;
    string nombre;
    Turno turno;
    

public:
    Clase(int, string);
    Clase();
    Clase(const Clase& orig);
    virtual ~Clase();
    
    /*Setters*/
    void setId(int);
    void setNombre(string);
    void setTurno(Turno);
    void setInscripcion(Inscripcion*[]);
    /*Getters*/
    int getId();
    string getNombre();
    Turno getTurno();
    Inscripcion** getInscripcion();
    
    /*Extra functions belonging to this class*/
    virtual int cupo()=0;
};

#endif /* CLASE_H */

