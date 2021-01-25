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
/*define*/
#define SUPERFICIE 7
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
#define PULPO 11
#define MARIO 1
/*provisorio, solo para que quede escrita la funcion reglas*/
#define up 100
#define right 101
#define left 102
#define down 103

/* prototipos*/
void creacionmap(void);
void printmat(int arr[ALTURA][LARGO]); /*creo que no es necesario pasarle una arreglo*/
void movimiento(int arr[ALTURA][LARGO],int boton);
void ctrl_posicion(int arr[ALTURA][LARGO],int pos[3]);  /*Funcion que busca la posicion de mario en el mapa (Matriz), se le pasa el nivel y la cantidad de movimiento del mapa*/
int reglas (int arr[ALTURA][LARGO],int boton);
int entrada(void);
void * caida (int arr[ALTURA][LARGO]);
void * entrad(void);


/*Globales*/
int puntaje=0;
int vida=3;
int pos[3];         /*es un arreglo que tiene en el primer elemento la fila , en el segundo la col(de la pos de mario) y en el ultimo la cantidad de movimineto del mapa*/
int tecla;
int lvl_1 [ALTURA][LARGO];  /*niveles vacios*/

 /*int lvl_2 [ALTURA][LARGO];  
 int lvl_3 [ALTURA][LARGO];  */
/**********************************/
/*OBSERVACIONES: el motor del juego , se podria hacer con un mutex, de esta manera , se escribiria menos codigo.
/**********************************/

int main() {

    pthread_t th1,th2;
    creacionmap();          /*se genera el nivel*/
    
    printf("Bienvenido a la beta del super mario\n");
   
    printmat(lvl_1);
    int fin=1,boton=0;
    
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
                puntaje+=100;
                printf("Bien jugado,pasaste primer nivel\n");
                printf("PUNTAJE: %d",puntaje);
                tecla=0;
                return 0;
            }
            else if(val==3){
               
                vida-=1;
                if(vida<0){
                    printf("GAME OVER\n");
                    printf("PUNTAJE: %d",puntaje);
                    fin =0;
                    tecla=0;
                }
            }
          
        }
            
    }
}
    
    
    
    
    
    
   


/**************************/



/*Funciones auxiliares*/


void creacionmap(void){ /*creacion de los mapas */
        
        lvl_1[7][0]=MARIO;
        lvl_1[7][3]=PEZ;
	for(int i=0;i<(LARGO-5);i++)
	{
		lvl_1[0][i]=SUPERFICIE;
		lvl_1[1][i]=SUPERFICIE;
	}

	for(int i=(LARGO-5);i<LARGO;i++)
	{
		lvl_1[0][i]=BLOQUE;
		lvl_1[1][i]=BLOQUE;
	}	

	for(int i=0;i<(LARGO/2);i++)
	{
		lvl_1[14][i]=BLOQUE;
		lvl_1[15][i]=BLOQUE;
	}

	for(int j= ((LARGO/2)+5) ;j<LARGO;j++)
	{
		lvl_1[14][j]=BLOQUE;
		lvl_1[15][j]=BLOQUE;
	}

	for(int k=9;k<14;k++)
	{
		lvl_1[k][13]=ALGA;
	}

	lvl_1[13][15]=MONEDA;
	lvl_1[13][16]=MONEDA;

	for(int k=17;k<20;k++)
	{
		lvl_1[8][k]=BLOQUE;
	}
	
	lvl_1[7][18]=MONEDA;
	
	for(int k=21;k<26;k++)
	{
		lvl_1[10][k]=BLOQUE;
		lvl_1[13][k]=MONEDA;
	}

	for(int k=5;k<10;k++)
		{
			lvl_1[k][21]=ALGA;
		}

		lvl_1[9][23]=MONEDA;
		lvl_1[8][23]=MONEDA;
		lvl_1[7][23]=MONEDA;

		for(int k=5;k<10;k++)
		{
			lvl_1[k][25]=ALGA;
		}

		lvl_1[13][31]=BLOQUE;

		for(int k=12;k<14;k++)
		{
			lvl_1[k][32]=BLOQUE;
		}

		for(int k=11;k<14;k++)
		{
			lvl_1[k][33]=BLOQUE;
		}
			
		for(int k=10;k<14;k++)
		{
			lvl_1[k][34]=BLOQUE;
		}

		for(int k=34;k<41;k++)
		{
			lvl_1[4][k]=BLOQUE;
		}		

		for(int k=5;k<7;k++)
		{
			lvl_1[k][34]=BLOQUE;
		}

		for(int k=5;k<7;k++)
		{
			lvl_1[k][40]=BLOQUE;
		}

		lvl_1[5][37]=MONEDA;
		lvl_1[6][37]=MONEDA;

		for(int k=36;k<39;k++)
		{
			lvl_1[12][k]=MONEDA;
		}

		for(int k=35;k<40;k++)
		{
			lvl_1[15][k]=PRECIPICIO;
		}		
		
		for(int k=10;k<14;k++)
		{
			lvl_1[k][40]=BLOQUE;
		}

		for(int k=11;k<14;k++)
		{
			lvl_1[k][41]=BLOQUE;
		}

		for(int k=12;k<14;k++)
		{
			lvl_1[k][42]=BLOQUE;
		}

		lvl_1[13][43]=BLOQUE;

		lvl_1[13][45]=MONEDA;

		for(int k=47;k<54;k++)
		{
			lvl_1[9][k]=BLOQUE;
		}

		for(int k=5;k<9;k++)
		{
			lvl_1[k][53]=ALGA;
		}
		
		for(int k=50;k<53;k++)
		{
			lvl_1[8][k]=MONEDA;
		}

		lvl_1[7][52]=MONEDA;

		for(int k=6;k<14;k++)
		{
			lvl_1[k][57]=ALGA;
		}

		for(int i=(LARGO-5);i<LARGO;i++)
		{
			for(int k=2;k<10;k++)
			{
				lvl_1[k][i]=BLOQUE;
				lvl_1[k][i]=BLOQUE;
			}
		}

		for(int k=10;k<14;k++)
		{
			lvl_1[k][LARGO-1]=BLOQUE;
		}

		for(int k=60;k<(LARGO-1);k++)
		{
			lvl_1[13][k]=BLOQUE;
		}

		lvl_1[12][61]=MONEDA;
		lvl_1[12][62]=MONEDA;

		lvl_1[11][LARGO-2]=FINAL;
		lvl_1[12][LARGO-2]=FINAL;

}

void movimiento(int arr[ALTURA][LARGO], int boton){         /*necesito pasarle de alguna forma la posicion de mario*/

   int i=pos[0];
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
}

void ctrl_posicion(int arr[ALTURA][LARGO],int pos[3]){  /*se le pasa la matriz nivel, y un arreglo en donde se va a guarda la posicion de mario*/
                                   
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
            case SUPERFICIE:return 1; break;
            case MONEDA: return 2; break;
            case PULPO:
            case PEZ:
            case PES:
            case PRECIPICIO:
            case FUEGO: return 3;break; /*suponiendo que el fuego mate a mario*/
            case FINAL: return 4;break;
            default: return 0;break;
    }
}
    
/*creo que tendria que ser una funcion thread*/
int entrada(void) {

    printf("por favor introducir el movimiento deseado\n");
    printf("tener en cuenta que w,a,d,s, son los movimientos permitidos\n");
    printf("(Esto es una funcion de prueba, ya que el movimiento dependera del hardware)\n");
    int i =getchar();
    if(i=='W' || i=='w'){ /*up*/
       getchar();       /*libero buffer*/
       return up; 
    }
    else if(i=='D' || i=='d'){/*right*/
        getchar();
        return right;
    }
    else if(i=='S' || i=='s'){/*down*/
        getchar();
        return down;
    }
    else if(i=='A' || i=='a'){/*left*/
        getchar();
        return left;
    }
    else{
        printf("introdujo un movimiento no permitido\n");
        return 0;
    }
}
void * caida (int arr[ALTURA][LARGO]){
    int boton_aux=down;
    int val;
    
    while(1){
        sleep(2);
        printf("entre al thread\n");
        ctrl_posicion(arr,pos);
        val=reglas(arr,boton_aux);
        if(val==0){                  /*si el movimiento esta permitido , lo mueve efectivamente*/
               movimiento(arr,boton_aux); /*realza el movimiento efectivo, solo de Mario*/
               printmat(arr);

        }
        else if(val==2){             /*recogio una moneda*/
               
               puntaje+=10;
               printf("PUNTAJE:%d\n",puntaje);
               movimiento(arr,boton_aux);
        }
        /*else if(val==4){      NO SE BIEN COMO HACER ESTA PARTE, ES DECIR COMO TRANSMITIR AL MOTOR QUE SE TERMINO EL PRIMER NIVEL
               puntaje+=100;
               printf("Bien jugado,pasaste primer nivel\n");
               printf("PUNTAJE: %d",puntaje);
            
        }*
        else if(val==3){
               
            vida-=1;
            if(vida<0){
                   printf("GAME OVER\n");
                   printf("PUNTAJE: %d",puntaje);
            }
        }*/
        sleep(2);
    }
}


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
            printf("introdujo un movimiento no permitido\n");
            return 0;
        }
    }    
}
