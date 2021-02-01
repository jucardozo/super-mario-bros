/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   levels.h
 * Author: jucardozo
 *
 * Created on 28 de enero de 2021, 09:58
 */

#ifndef LEVELS_H
#define LEVELS_H

#ifdef __cplusplus
extern "C" {
#endif
    
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include "levels.h"

#define SUPERFICIE 11
#define ALTURA 16
#define LARGO 70
#define BLOQUE 4
#define ALGA 2
#define FINAL 5
#define MONEDA 3
#define PRECIPICIO 9
#define PEZ 6
#define PES 8
#define FUEGO 10
#define PULPO 7
#define MARIO 1
#define AGUA 0
#define MOV_PULPO 4


void creacionmap(void);   

#ifdef __cplusplus
}
#endif

#endif /* LEVELS_H */

