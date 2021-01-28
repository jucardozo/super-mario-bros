/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: El Salta, El Alito, El Micho
 *
 * Created on January 14, 2021, 4:23 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include "levels.h"         /*micho puto*/

/*define*/

/*provisorio, solo para que quede escrita la funcion reglas*/
#define up 100
#define right 101
#define left 102
#define down 103

/* prototipos*/
void printmat(int arr[ALTURA][LARGO]); /*creo que no es necesario pasarle una arreglo*/
void movimiento(int arr[ALTURA][LARGO],int boton);  /*realiza el movimiento efectivo de mario*/
void ctrl_posicion(int arr[ALTURA][LARGO],int pos[3]);  /*Funcion que busca la posicion de mario en el mapa (Matriz), se le pasa el nivel y la cantidad de movimiento del mapa*/
int reglas (int arr[ALTURA][LARGO],int boton);      /*evalua la validez del movimietno del mario*/
void * caida ();    /*caida de mario , impuesta por la gravedad */
void * entrad();    /*recibe por comando el movimiento deseado por el jugador*/


/*Globales*/
int puntaje=0;      /*se lleva el conteo del puntaje*/
int vida=3;         /*se lleva el conteo de las vidas*/
int pos[3];         /*es un arreglo que tiene en el primer elemento la fila , en el segundo la col(de la pos de mario) y en el ultimo la cantidad de movimineto del mapa*/
int tecla;          /*guarda el valor de tecla apretado*/
int lvl_1 [ALTURA][LARGO];  /*niveles vacios*/

 /*int lvl_2 [ALTURA][LARGO];  
 int lvl_3 [ALTURA][LARGO];  */
/**********************************/
/*OBSERVACIONES: el motor del juego , se podria hacer con un mutex, de esta manera , se escribiria menos codigo.
/**********************************/
/*MUTEX Y THREAD*/
pthread_t th1,th2;                  /*se crean thread para funciones necesarias*/
pthread_mutex_t lock1,lock2;        /*creo un candado para dos funciones que controlan el movimiento*/

int main() {

    
    creacionmap();          /*se genera el nivel*/
    
    printf("Bienvenido a la beta del super mario\n");
   
    printmat(lvl_1);
    int fin=1, boton=0;
    
    pthread_create(&th1,NULL,entrad,NULL);
    pthread_create(&th2,NULL,caida,NULL);
    while(fin){
        if(tecla !=0){       /*si el boton es igual a cero , entonces hubo problema en la entrada*/
            
            ctrl_posicion(lvl_1,pos);    /*busca a mario en el mapa y devuelve su posicion en pos */
            boton=tecla;
            int val=reglas(lvl_1,boton); /*val, guarda la evaluacion de reglas*/
            if(val==0){                  /*si el movimiento esta permitido , lo mueve efectivamente*/
 
                movimiento(lvl_1,boton); /*realza el movimiento efectivo, solo de Mario*/
                printmat(lvl_1);
                tecla=0;
            }
            else if(val==2){             /*recogio una moneda*/
                
                puntaje+=10;
                printf("PUNTAJE:%d\n",puntaje);
                movimiento(lvl_1,boton);
                printmat(lvl_1);
                tecla=0;
            }
            else if(val==4){
                puntaje+=100;                               /*si es 4 es porque llego a la meta*/
                printf("Bien jugado,pasaste de nivel\n");
                printf("PUNTAJE: %d",puntaje);
                tecla=0;
                return 0;
            }
            else if(val==3){
               
                vida-=1;                                    /*si es 3 es porque mario perdio una vida*/
                if(vida<0){
                    printf("GAME OVER\n");
                    printf("PUNTAJE: %d",puntaje);          /*si no tiene mas vidas entonces game over*/
                    fin =0;
                    tecla=0;
                }
                else
                {
                    printf("Perdiste una vida, te quedan: %d\n",vida);
                }
             }
         }
          
        }
      
    
    pthread_join(th1,NULL);
    pthread_join(th2,NULL);
}
    
    
    
    
    
    
   


/**************************/



/*Funciones auxiliares*/




void movimiento(int arr[ALTURA][LARGO], int boton){         /*realiza el movimiento efectivo de mario*/
    
   pthread_mutex_lock(&lock1);      /*esta funcion tiene un candado , de tal manera que no se pisen con otra llamdada*/
   int i=pos[0];                    /*es decir que trabaja solo con una llamda y luego atiende las siguientes*/
   int j=pos[1];
   switch(boton){
       case up:
           arr[i-1][j]=1;
           arr[i][j]=0;
           break;
       case down:
           arr[i+1][j]=1;
           arr[i][j]=0;
           break;
       case right:
           arr[i][j+1]=1;
           arr[i][j]=0;
           break;
       case left:
           arr[i][j-1]=1;
           arr[i][j]=0;
           break;
   }
   pthread_mutex_unlock(&lock1);
}

void ctrl_posicion(int arr[ALTURA][LARGO],int pos[3]){  /*se le pasa la matriz nivel, y un arreglo en donde se va a guarda la posicion de mario*/
    
    pthread_mutex_lock(&lock2);     /*tambien posee un candado*/
    if((16+pos[2])<LARGO){          /*en el ultimo elemento se guarda la cnatidad de movimiento del mapa*/
        for (int col=pos[2];col<(16+pos[2]);col++){     /*se centra la busqueda de mario en un cuadrado de 16 por 16 que coincide con lo mostrado por printmat*/
            for(int fil=0;fil<16;fil++){
                if(arr[fil][col]==1){
                    pos[0]=fil;
                    pos[1]=col;
                }    
            }
        }
    }
    else{
        for (int col=pos[2];col<LARGO;col++){
            for(int fil=0;fil<16;fil++){
                if(arr[fil][col]==1){
                    pos[0]=fil;
                    pos[1]=col;
                }
            }      
        }
    }
    pthread_mutex_unlock(&lock2);
}

void printmat(int arr[ALTURA][LARGO]){
    if(((16+pos[2])-pos[1])<=8){        /*se lee la columna en donde esta mario y se mueve le mapa si esta en la mitad*/
        pos[2]+=4;                      /*la cantidad de este movimineto se guarda en el tercer elemento del arreglo, se elije por default que se mueva de a 4*/
    }  
    for (int i=0;i<16;i++){
        for(int p=pos[2]; p<(16+pos[2]);p++){
            printf("%d",arr[i][p]);
        }
        printf("\n");
    }
}
/*PROVISORIO , PROBABLEMENTE TENGA QUE HACER UN REGLAS PARA ALLEGRO Y PARA LA RASPI, PORQUE DEPENDE EL COMANDO DE MOVIMINETO */
int reglas(int arr[ALTURA][LARGO],int boton){ /*se le pasa el nivel en el que se esta jugando, y el comando accionado*/
                            /*se devuelve 1 si el movimiento no esta permitido,2 si agarro una moneda,3 si murio 4 si llego al final y 0 si el movimineto esta permitido*/
    int i=pos[0];           /*copio la posicion de actual de mario*/
    int j=pos[1];           /*i es fila y j es col*/
 
    if (boton==up){
        i-=1;
    }
    else if (boton==down){
        i+=1;
    }
    else if(boton ==right){
        j+=1;
    }
    else if(boton==left){       /*CONTROLAR QUE NO SEA NEGATIVO*/
        j-=1;
    }    
    switch(arr[i][j]){
            case BLOQUE: 
            case ALGA:
            case SUPERFICIE:return 1; break;    /* si es un obstaculo, devuelvo 1*/
            case MONEDA: return 2; break;       /*si es una moneda, devuelvo 2 */
            case PULPO:
            case PEZ:
            case PES:
            case PRECIPICIO:
            case FUEGO: return 3;break;         /*si es un enemigo o maleficio para mario, devuelvo 3*/
            case FINAL: return 4;break;         /*si es la meta, devuelvo 4*/
            default: return 0;break;            /*si es otra cosa, devuelvo 0*/
    }
}
/*FUNCION THREAD*/
void*  caida ( ){
    int boton_aux=down;
    int val;
    while(1){
        sleep(3);
        ctrl_posicion(lvl_1,pos);
        val=reglas(lvl_1,boton_aux);
        if(val==0){                  /*si el movimiento esta permitido , lo mueve efectivamente*/
            movimiento(lvl_1,boton_aux); /*realza el movimiento efectivo, solo de Mario*/
            printmat(lvl_1);
        }
        else if(val==2){             /*recogio una moneda*/          
            puntaje+=10;
            printf("PUNTAJE:%d\n",puntaje);
            movimiento(lvl_1,boton_aux);
            printmat(lvl_1);
        }
        else if(val==4){     
            puntaje+=100;
            printf("Bien jugado,pasaste primer nivel\n");
            printf("PUNTAJE: %d",puntaje);          
        }
        else if(val==3){
               
            vida-=1;
            if(vida<0){
                printf("GAME OVER\n");
                printf("PUNTAJE: %d",puntaje);
            }
        }
        sleep(3);
    }
}


/*FUNCION THREAD*/
void *entrad(){
    int i=0;
    while(1){
        i=getchar();
        if(i=='W' || i=='w'){ /*up*/
            getchar();       /*libero buffer*/
            tecla= up;
            
        }
        else if(i=='D' || i=='d'){/*right*/
           getchar();
           tecla=right;
        }
        else if(i=='S' || i=='s'){/*down*/
            getchar();
            tecla =down;
        }
        else if(i=='A' || i=='a'){/*left*/
            getchar();
            tecla=left;
        }
        else{
            //printf("introdujo un movimiento no permitido\n");
            return 0;
        }
    }    
}
/*FUNCION THREAD*/

void * enemigos(){
    int i,j=3,c,f,a,l,aux;
    lvl_1[7][3]=0;
    while(1){
        if(j>0){
            aux=lvl_1[7][j-1];
            lvl_1[7][j-1]=PES;   
            j-=1;/*copia*/
            lvl_1[7][j]=aux;
        }
        
        
    }
}




      //  lvl_1[7][3]=PEZ;
     //   lvl_1[9][5]=PULPO;
     //   lvl_1[4][9]=PES;
        
      