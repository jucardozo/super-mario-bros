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
/*define*/
#define SUPERFICIE 7
#define ALTURA 16
#define LARGO 70
#define BLOQUE 4
#define ALGA 2
#define FINAL 5
#define MONEDA 3
#define PRECIPICIO 9
#define MARIO 1
/* prototipos*/
void creacionmap(void);
void printmat(int arr[ALTURA][LARGO]);
void control_mov(int arr[ALTURA][LARGO]);
void ctrl_posicion(int arr[ALTURA][LARGO],int pos[3]);  /*Funcion que busca la posicion de mario en el mapa (Matriz), se le pasa el nivel y la cantidad de movimiento del mapa*/

int reglas (int arr[ALTURA][LARGO]);
/*Globales*/
int pos[3];         /*es un arreglo que tiene en el primer elemento la fila , en el segundo la col(de la pos de mario) y en el ultimo la cantidad de movimineto del mapa*/
int lvl_1 [ALTURA][LARGO];  /*niveles vacios*/
 /*int lvl_2 [ALTURA][LARGO];  
 int lvl_3 [ALTURA][LARGO];  
/*
 * 
 */
int main() {
    
    creacionmap();          /*se crea el espacio donde van a escribirse los niveles*/
    ctrl_posicion(lvl_1,pos);
    printmat(lvl_1);
    printf("%d",pos[0]);
    printf("%d",pos[1]);
    printf("%d",pos[2]);
   /* control_mov();*/
    
    
    return (EXIT_SUCCESS);
}

void creacionmap(void){ /*creacion de los mapas */
        
        lvl_1[7][8]=MARIO;
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
/*CREO QUE ESTO TIENE QUE SER SI O SI UNA FUNCION THREAD...*/
/*void control_mov(int arr[ALTURA][LARGO]){         /*necesito pasarle de alguna forma la posicion de mario*/
   /* int i=0;
    int valido=0;
    i= getchar();
    switch(i){
        case 'W':
            valido=reglas();
    }
}*/

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
    if(pos[1]>=((16+pos[2])/2)){        /*se lee la columna en donde esta mario y se mueve le mapa si esta en la mitad*/
        pos[2]=+4;                      /*la cantidad de este movimineto se guarda en el tercer elemento del arreglo, se elije por default que se mueva de a 4*/
    }    
    for (int i=0;i<16;i++){
        for(int p=pos[2]; p<(16+pos[2]);p++){
            printf("%d",arr[i][p]);
        }
        printf("\n");
    }
}
