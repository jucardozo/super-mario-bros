/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   myallegro.h
 * Author: jucardozo
 *
 * Created on February 13, 2021, 9:09 AM
 */

#ifndef MYALLEGRO_H
#define MYALLEGRO_H

#ifdef __cplusplus
extern "C" {
#endif
    
 /*INCLUYO LIBRERIAS DE ALLEGRO*/
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h> // NO OLVIDAR AGREGAR EN EL LINKER DEL PROYECTO
#include <allegro5/allegro_acodec.h> // NO OLVIDAR AGREGAR EN EL LINKER DEL PROYECTO
#include"levels.h" //lo incluyo solo por los defines

/*DEFINE,PARA SU USO EN ALLEGRO*/
#define FPS    60.0
#define LARGO_DISPLAY 640      //TAMANIO DE IMAGEN
#define ANCHO_DISPLAY 544      //TAMANIO DE IMAGEN
    
#define up 100     //VER BIEN COMO INCLUIRLO DE UNA MANERA MAS PROLIJA
#define right 101
#define left 102
#define down 103
#define pausa 104
#define salir 105
    
/*PROTOTIPOS*/
int inicializacion (void);     //se inicializa todo lo que corresponde a allegro
void destroy_allegro (void);   //se destruye todo lo propio de Allegro
void * entrad_allegro(void);    /*recibe por comando el movimiento deseado por el jugador*/
void print_map_allegro(int arr [ALTURA][LARGO]);        //imprime mapa allegro


#ifdef __cplusplus
}
#endif

#endif /* MYALLEGRO_H */

