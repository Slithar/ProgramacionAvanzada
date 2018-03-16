/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: kapo_
 *
 * Created on 16 de marzo de 2018, 02:39 PM
 */

#include <cstdlib>
#include <iostream>

#include "Clase.h"
#include "Spinning.h"
#include "Entrenamiento.h"
#include "Socio.h"
#include "Incripcion.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Clase *p = new Spinning();
    p->setNombre("SpinningCami");
    p->setId(1);
    
    cout<<"Id de la clase: "+ std::to_string(p->getId()) + "\nNombre de la clase: " + p->getNombre() <<endl;
    
    return 0;
}

