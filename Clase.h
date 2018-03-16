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
using namespace std;
class Clase {
private:
    int id;
    string nombre;
    /*Turno*/

public:
    Clase(int, string);
    Clase();
    Clase(const Clase& orig);
    virtual ~Clase();
    
    /*Setters*/
    void setId(int);
    void setNombre(string);
    
    /*Getters*/
    int getId();
    string getNombre();
    
    /*Extra functions belonging to this class*/
    virtual int cupo()=0;
};

#endif /* CLASE_H */

