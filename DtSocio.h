/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtSocio.h
 * Author: mcurbelo
 *
 * Created on March 19, 2018, 3:15 PM
 */

#ifndef DTSOCIO_H
#define DTSOCIO_H
#include <string>
using namespace std;
class DtSocio {
public:
    DtSocio();
    DtSocio(const DtSocio& orig);
    virtual ~DtSocio();
private:
    int CI;
    string nombre;
};

#endif /* DTSOCIO_H */

