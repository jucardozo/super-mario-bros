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
void * enemigo_pez();


/*Globales*/
int nivel=1;
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
pthread_t th1,th2,th3,th4,th5;                  /*se crean thread para funciones necesarias*/
pthread_mutex_t lock1,lock2;        /*creo un candado para dos funciones que controlan el movimiento*/

int main() {

    int(*niveles[2])[ALTURA][LARGO];        // es un arreglo de 3 punteros que apuntan a una matriz  
    niveles[0]=lvl_1;
    //nivel[1]=lvl_2;
    //nivel[3]=lvl_3;
    creacionmap();          /*se genera el nivel*/
    
    printf("Bienvenido a la beta del super mario\n");
   
    printmat(*niveles[0]);  //
    int fin, boton=0 ,i;
    
    
    pthread_create(&th1,NULL,entrad,NULL);
    pthread_create(&th2,NULL,caida,NULL);
    
    
    while(vida>0){
        switch(nivel){          //habilita el control, automatico, de cada enemigo en cada nivel//
            case 1 :
                    pthread_create(&th3,NULL,enemigo_pez,NULL);i=0;fin=1; break;
            case 2 :
                    pthread_create(&th4,NULL,entrad,NULL);i=1;fin=1;break;
            case 3 :
                    pthread_create(&th5,NULL,entrad,NULL);i=2;fin=1;break;
        }
        
        while(fin){
            if(tecla !=0){       /*si el boton es igual a cero , entonces hubo problema en la entrada*/
            
                ctrl_posicion(*niveles[i],pos);    /*busca a mario en el mapa y devuelve su posicion en pos */
                boton=tecla;
                int val=reglas(*niveles[i],boton); /*val, guarda la evaluacion de reglas*/
                if(val==0){                  /*si el movimiento esta permitido , lo mueve efectivamente*/
                    
                    movimiento(*niveles[i],boton); /*realza el movimiento efectivo, solo de Mario*/
                    printmat(*niveles[i]);
                    tecla=0;
                }
                else if(val==2){             /*recogio una moneda*/
                    
                    puntaje+=10;
                    printf("PUNTAJE:%d\n",puntaje);
                    movimiento(*niveles[i],boton);
                    printmat(*niveles[i]);
                    tecla=0;
                }
                else if(val==4){    //paso de nivel
                    puntaje+=100;                               /*si es 4 es porque llego a la meta*/
                    printf("Bien jugado,pasaste de nivel\n");
                    printf("PUNTAJE: %d",puntaje);
                    tecla=0;
                    nivel+=1;
                    fin=0;
                }
                else if(val==3){
               
                    vida-=1;                                    /*si es 3 es porque mario perdio una vida*/
                    if(vida<0){
                        printf("GAME OVER\n");
                        printf("PUNTAJE: %d",puntaje);          /*si no tiene mas vidas entonces game over*/
                        fin =0;
                        tecla=0;
                        return 0;
                       
                    }
                    else
                    {
                        printf("Perdiste una vida, te quedan: %d\n",vida);
                        tecla=0;
                    }
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

void * enemigo_pez(){
    
//todas palabras peces van con Z
//THREAD DISTINTO                   HAY QUE HACERLO PARA TODOS LOS NIVELES

    /*PEZZZZ*/
    int *pezes [3];             //creo arreglo de punteros para guardar las posiciones de los peces      ESTRUCTURA Y UNION!!!
    
    pezes[0]= &lvl_1[7][3];     //estas son las posiciones iniciales de los peces en la matriz
    pezes[1]= &lvl_1[9][5];
    pezes[2]= &lvl_1[4][9];     //ESTRUCTURA Y UNION!!!
        
        
    int cant_pez = 3;     //cantidad de enemigos PEZ por nivel 
    int q=0;
    int i=0;
    int valor1 [3];		//arreglo que guardo las posiciones de los peZes
    int valor2 [3];		//arreglo que salvo las posiciones de los peZes
    
    while (1){                
        
        if (  (  ( pezes[i] - (&lvl_1[0][0]) )    % LARGO  )  == 0){         //si esta en la columna 0, entonces listo el PEZ

			//tambien se pueden volver a regenerar los PEZ con: if(pezes[i] == (&lvl_1[0][0])){

            *pezes[i]=AGUA;                                                     //que me ponga agua
            
            //++pezes;                                                         //ya el primer PEZ no existe
            while(i < cant_pez){
                pezes[i]=pezes[i+1];
                i++;
            }		//WHILE
            cant_pez -=1;                                                   //bajo la cantidad de PEZ porque van desapareciendo
            
         //   if(cant_pez==0){
          //      break;
         //    }
             
             //sleep(3);
            
        }		//IF

      else{														//SI NO ESTA EN LA PRIMER COLUMNA
			if(q<cant_pez){								//SI SE MUEVE POR PRIMERA VEZ
				 while (i < cant_pez){
		            
                                    valor1[i] = *(pezes[i]-1);               //guardo el valor para salvar lo que valia antes de que caiga el pez
		            
		            //aca ya salve el valor de lo que habia y se guarda en valor
		            
                                    *(pezes[i]-1) = PEZ;            //muevo el PEZ para la izquierda
		            
                                    * pezes[i] = AGUA;             //cuando se movio por primera vez, que me ponga agua donde arranco el PEZ

                                                                //todo es para que avance un pez, aumento i para que vaya al otro pez
                                    q++;
		            //aca va un mini sleep para que entre pez  y pez haya un poco de tiempo !!!!!!!!!!!!!!!
		            //sleep(3);
                                    pezes [i] -= 1;					//la nueva direeccion del pez es la de la izquuierda
                                    i++;
                                }		//WHILE
			}		//IF	

			else{
			    while (i < cant_pez){
				        
			        valor2[i] = *(pezes[i]-1);               //guardo el valor para salvar lo que valia antes de que caiga el pez
				        
			        //aca ya salve el valor de lo que habia y se guarda en valor
				        
			        *(pezes[i]-1) = PEZ;            //muevo el PEZ para la izquierda
				        

			        * pezes [i] = valor1[i];        //salvo lo que habia antes

			       
				        //aca va un mini sleep para que entre pez  y pez haya un poco de tiempo !!!!!!!!!!!!!!!
				        //sleep(3);
					pezes [i] -= 1;					//la nueva direeccion del pez es la de la izquuierda
					valor1 [i]= valor2[i];			//pongo en valor 1 lo que esta valor 2  asi ya se vuelve a poner otra vez
                                         i++;                            //todo es para que avance un pez, aumento i para que vaya al otro pez
			    }
            //aca va otro sleep !!!!!!!!!!!
			}
           
        }		//ELSE
        
        i=0;		//vuelvo a arrancar desde el primer pez
        
    }  //while(1)

}







/*
void * elvl_1(){
    int j=3,aux,col=9,i;
    lvl_1[7][3]=0;
    int fin=1;
    while(fin){
        
        if(j>0){
            aux=lvl_1[7][j-1];
            lvl_1[7][j-1]=PES;  
            lvl_1[7][j]=aux;
            j-=1;
            aux=lvl_1[4][col-1];
            lvl_1[4][col-1]=PES;  
            lvl_1[4][col]=aux;
            col-=1;
            
        }
       
        
        
    }
}
*/
/*NO ME BORREN ESTO POT FAVOR **/
 /* 
  * 
  *         lvl_1[9][5]=PULPO;
        lvl_1[4][9]=PES;
  * 
  * int j = 7;
  * 
    int aux;
     while(1){
        if(j>0){
            aux=matriz[7][j-1];
            matriz[7][j-1]=1;   
            printf("\n");
            
            matriz[7][j]=aux;
            printmat();
            
            j-=1;
            sleep(2);
        }
    }*/
      