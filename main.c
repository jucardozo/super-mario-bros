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
#define pausa 104
#define salir 105

/* prototipos*/
void printmat(int arr[ALTURA][LARGO]); /*creo que no es necesario pasarle una arreglo*/
void movimiento(int arr[ALTURA][LARGO],int boton);  /*realiza el movimiento efectivo de mario*/
void ctrl_posicion(int arr[ALTURA][LARGO],int pos[3]);  /*Funcion que busca la posicion de mario en el mapa (Matriz), se le pasa el nivel y la cantidad de movimiento del mapa*/
int reglas (int arr[ALTURA][LARGO],int boton);      /*evalua la validez del movimietno del mario*/
void * caida ();    /*caida de mario , impuesta por la gravedad */
void * entrad();    /*recibe por comando el movimiento deseado por el jugador*/
void * enemigo_pez();
void * enemigo_pes();
void * enemigo_pulpo();
int menu();


/*Globales*/
int nivel=1;
int stop;           //variable que uso para pausar el juego
int puntaje=0;      /*se lleva el conteo del puntaje*/
int vida=3;         /*se lleva el conteo de las vidas*/
int tecla;          /*guarda el valor de tecla apretado*/
int(*niveles[2])[ALTURA][LARGO];        // es un arreglo de 3 punteros que apuntan a una matriz  
int pos[3];         /*es un arreglo que tiene en el primer elemento la fila , en el segundo la col(de la pos de mario) y en el ultimo la cantidad de movimineto del mapa*/
int lvl_1 [ALTURA][LARGO];  /*niveles vacios*/
int lvl_2 [ALTURA][LARGO];  
 /*int lvl_3 [ALTURA][LARGO];  */
/**********************************/
/*OBSERVACIONES: el motor del juego , se podria hacer con un mutex, de esta manera , se escribiria menos codigo.
/**********************************/
/*MUTEX Y THREAD*/
pthread_t th1,th2,th3,th4,th5,th6,th7;                  /*se crean thread para funciones necesarias*/
pthread_mutex_t lock1,lock2;        /*creo un candado para dos funciones que controlan el movimiento*/

int main() {

    
    niveles[0]=&lvl_1;
    niveles[1]=&lvl_2;
    //nivel[3]=lvl_3;
    
    printf("Bienvenido a la beta del super mario\n");
   
    int fin, boton=0 ,i;
    
    
    pthread_create(&th1,NULL,entrad,NULL);
    pthread_create(&th2,NULL,caida,NULL);
    
    
    while(vida>0){
        switch(nivel){          //habilita el control, automatico, de cada enemigo en cada nivel//
            case 1 :
                    printf("**************NIVEL 1*****************\n");
                    creacionmap(nivel);
                    printmat(*niveles[0]);  //imprime el nivel
                    pthread_create(&th3,NULL,enemigo_pez,NULL);
                    pthread_create(&th4,NULL,enemigo_pes,NULL);
                    pthread_create(&th5,NULL,enemigo_pulpo,NULL);
                    i=0;fin=1; break;
            case 2 :
                    printf("**************NIVEL 2*****************\n");
                    creacionmap(nivel);
                    pos[0]=0;
                    pos[1]=0;
                    pos[2]=0;
                    printmat(*niveles[1]);  //
                    i=1;fin=1;boton=0;break;
                    //pthread_create(&th6,NULL,entrad,NULL);        //ENEMIGOOOOOOOSSSSSSSSSS
            case 3 :
                    creacionmap(nivel);
                    printmat(*niveles[2]);  //
                    pthread_create(&th7,NULL,entrad,NULL);i=2;fin=1;break;
        }
        
        while(fin){
            if(tecla !=0 ){       /*si el boton es igual a cero , entonces hubo problema en la entrada*/
            
                ctrl_posicion(*niveles[i],pos);    /*busca a mario en el mapa y devuelve su posicion en pos */
                boton=tecla;
                if(boton==pausa){
                    stop=1;
                    tecla=0;
                    menu();
                    if(tecla==salir){
                        return 0;
                    }
                }
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
                    printf("PUNTAJE: %d\n",puntaje);
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


int menu(){
    printf("************MENU(BETA)*************\n");
    printf("PUNTAJE:%d\n",puntaje);
    printf("VIDA:%d\n",vida);
    printf("NIVEL:%d\n",nivel);

    printf("Para reanudar el juego presione nuevamente p, para finalizar la partida presione f\n");
    int fin=1;
    while(fin){
        if( tecla==pausa){
            stop=0;
            fin=0;
            tecla=0;
             printf("reanudando juego...\n");
        }  
        else if( tecla==salir){
            fin=0;
            printf("saliendo del juego....\n");
        }
            
    }
   
    return 0;
}











////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                                                //
//                                                    /////////////////////////                                                   //
//                                                    ///*FUNCIONES THREADS*///                                                   //
//                                                    /////////////////////////                                                   //
//                                                                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void*  caida ( ){
    int boton_aux=down;
    int val;
    
    while(1){
        while(stop){        //paauso el thread , porque pausaron le juego
        }
        sleep(2);
        ctrl_posicion(*niveles[nivel-1],pos);
        val=reglas(*niveles[nivel-1],boton_aux);
        if(val==0){                  /*si el movimiento esta permitido , lo mueve efectivamente*/
            movimiento(*niveles[nivel-1],boton_aux); /*realza el movimiento efectivo, solo de Mario*/
            printmat(*niveles[nivel-1]);
        }
        else if(val==2){             /*recogio una moneda*/          
            puntaje+=10;
            printf("PUNTAJE:%d\n",puntaje);
            movimiento(*niveles[nivel-1],boton_aux);
            printmat(*niveles[nivel-1]);
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
        sleep(2);
    }
    
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
        else if(i=='P'|| i=='p'){
            getchar();
            tecla=pausa;
        }
        else if(i=='F' || i=='f'){
            getchar();
            tecla=salir;
            printf("se presiono f\n");
        }
        else{
            //printf("introdujo un movimiento no permitido\n");
            return 0;
        }
    }    
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                                                //
//                                                    ////////////////////////                                                    //
//                                                    ///*ENEMIGOS THREADS*///                                                    //
//                                                    ////////////////////////                                                    //
//                                                                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void * enemigo_pez(){           //este thread controla los movimientos del pez que va mas rapido en el mapa

    int pez = 1;                //variable que uso para el while
    
    int *pezes [MAX_ENEM];             //creo arreglo de punteros para guardar las posiciones de los peces  
    int * dir_niveles [2] = {&lvl_1[0][0],&lvl_2[0][0]};       //arreglo depunteros que contiene la direccion del primer elemento de la matriz de cada nivel
    
    pezes[0]= &lvl_1[7][3];     //estas son las posiciones iniciales de los peces en la matriz
    pezes[1]= &lvl_1[9][5];     //PARA EL NIVEL 1
    pezes[2]= &lvl_1[4][9];  
    
    pezes[3]= &lvl_2[8][5];     //estas son las posiciones iniciales de los peces en la matriz
    pezes[4]= &lvl_2[8][18];     //PARA EL NIVEL 2
    pezes[5]= &lvl_2[6][24];
    pezes[6]= &lvl_2[10][34];     
    pezes[7]= &lvl_2[10][43];
    pezes[8]= &lvl_2[12][58]; 
    
    int cant_pez = 3*nivel;           //cantidad de enemigos PEZ por nivel 
    int q=0;
    int i;
    int valor1 [MAX_ENEM];		//arreglo que guardo las posiciones de los peZes
    int valor2 [MAX_ENEM];		//arreglo que salvo las posiciones de los peZes
    
    if(nivel == 1){                     //cantidad de enemigos PEZ por nivel
        i=0;
    }
    else if (nivel == 2){
        i=3;
    }
    else{
        i=9;
    }
    
    while (pez){                
        
        if(cant_pez == 0){
            
            pez = 0;
        }
        
        else if (  (  ( pezes[i] - (dir_niveles[nivel-1]) )    % LARGO  )  == 0){         //si esta en la columna 0, entonces listo el PEZ

            *pezes[i]=AGUA;                                                     //que me ponga agua
                                                                  //ya el primer PEZ no existe
            while(i < (cant_pez-1)){                               //ahora el arreglo tiene solo dos pescados, en pezes[0] y en pezes[1] .
                pezes[i]=pezes[i+1];
                i++;
            }		
            cant_pez -=1;                                                   //bajo la cantidad de PEZ porque van desapareciendo
            
        }		

        else{								//SI NO ESTA EN LA PRIMER COLUMNA
            if(q<cant_pez){								//SI SE MUEVE POR PRIMERA VEZ
                while (i < cant_pez){		            
                    valor1[i] = *(pezes[i]-1);               //guardo el valor para salvar lo que valia antes de que caiga el pez               
                    if(valor1[i]==1){       
                        vida-=1;
                        printf("Perdiste una vida , te quedan:%d\n",vida);
                    }        
		            //aca ya salve el valor de lo que habia y se guarda en valor
		            
                    *(pezes[i]-1) = PEZ;            //muevo el PEZ para la izquierda        
                    * pezes[i] = AGUA;             //cuando se movio por primera vez, que me ponga agua donde arranco el PEZ
                    q++;                                            //todo es para que avance un pez, aumento i para que vaya al otro pez
		
                    pezes [i] -= 1;					//la nueva direeccion del pez es la de la izquuierda
                    i++;
                }
                sleep(3.5);
            }			
            else{
		while (i < cant_pez){		        
                    valor2[i] = *(pezes[i]-1);               //guardo el valor para salvar lo que valia antes de que caiga el pez		        
			        //aca ya salve el valor de lo que habia y se guarda en valor
                    *(pezes[i]-1) = PEZ;            //muevo el PEZ para la izquierda	
                    * pezes [i] = valor1[i];        //salvo lo que habia antes	       
				        
				        
                    pezes [i] -= 1;					//la nueva direeccion del pez es la de la izquuierda
                    valor1 [i]= valor2[i];			//pongo en valor 1 lo que esta valor 2  asi ya se vuelve a poner otra vez
                    i++;                            //todo es para que avance un pez, aumento i para que vaya al otro pez
                }
                sleep(3.5);
            }
           
        }		
        
        if(nivel == 1){                     //vuelvo a arrancar desde el primer pez
            i=0;
        }
        else if (nivel == 2){
            i=3;
        }
        else{
            i=9;
        }
        
    }  

}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void * enemigo_pes(){           //este thread controla los movimientos del pez que va mas lento en el mapa

    int pes = 1;                //variable que uso para el while
    
    int *peses [MAX_ENEM];             //creo arreglo de punteros para guardar las posiciones de los peces
    int * dir_niveles [2] = {&lvl_1[0][0],&lvl_2[0][0]};       //arreglo depunteros que contiene la direccion del primer elemento de la matriz de cada nivel
    
    peses[0]= &lvl_1[8][5];     //estas son las posiciones iniciales de los peces en la matriz
    peses[1]= &lvl_1[11][6];
    peses[2]= &lvl_1[6][7];      
    
    peses[3]= &lvl_2[12][9];     //estas son las posiciones iniciales de los peces en la matriz
    peses[4]= &lvl_2[6][21];     //PARA EL NIVEL 2
    peses[5]= &lvl_2[11][28];
    peses[6]= &lvl_2[4][35];     
    peses[7]= &lvl_2[4][46];
    peses[8]= &lvl_2[9][61];
    
    int cant_pes = 3*nivel;     //cantidad de enemigos PES por nivel 
    int q=0;
    int i;
    int valor3 [MAX_ENEM];		//arreglo que guardo las posiciones de los peSes
    int valor4 [MAX_ENEM];		//arreglo que salvo las posiciones de los peSes
    
    if(nivel == 1){                     //cantidad de enemigos PES por nivel
        i=0;
    }
    else if (nivel == 2){
        i=3;
    }
    else{
        i=9;
    }
    
    while (pes){  
        
        if(cant_pes == 0){
            
            pes = 0;
        }
        
        else if (  (  ( peses[i] - (dir_niveles[nivel-1]) )    % LARGO  )  == 0){         //si esta en la columna 0, entonces listo el PEZ

            *peses[i]=AGUA;                                                     //que me ponga agua
                                                                  //ya el primer PES no existe
            while(i < (cant_pes-1)){                               //ahora el arreglo tiene solo dos pescados, en peses[0] y en pezes[1] .
                peses[i]=peses[i+1];
                i++;
            }		
            cant_pes -=1;                                                   //bajo la cantidad de PEZ porque van desapareciendo
            
        }
       else{                                                        //SI NO ESTA EN LA PRIMER COLUMNA
            if(q<cant_pes){								//SI SE MUEVE POR PRIMERA VEZ
                while (i < cant_pes){
		            
                    valor3[i] = *(peses[i]-1);               //guardo el valor para salvar lo que valia antes de que caiga el pes
                    if(valor3[i]==1){       
                        vida-=1;
                        printf("Perdiste una vida , te quedan:%d\n",vida);
                    }
		            //aca ya salve el valor de lo que habia y se guarda en valor	            
                    *(peses[i]-1) = PES;            //muevo el PES para la izquierda		            
                    * peses[i] = AGUA;             //cuando se movio por primera vez, que me ponga agua donde arranco el PES
                    q++;                                            //todo es para que avance un pes, aumento i para que vaya al otro pes
                    peses [i] -= 1;					//la nueva direeccion del pes es la de la izquuierda
                    i++;
                }
                sleep(3.5);
            }			
            else{
                while (i < cant_pes){				        
                    valor4[i] = *(peses[i]-1);               //guardo el valor para salvar lo que valia antes de que caiga el pes				        
			        //aca ya salve el valor de lo que habia y se guarda en valor				        
                    *(peses[i]-1) = PES;            //muevo el PES para la izquierda				        
                    * peses [i] = valor3[i];        //salvo lo que habia antes			       
				        	        
                    peses [i] -= 1;					//la nueva direeccion del pes es la de la izquuierda
                    valor3 [i]= valor4[i];			//pongo en valor 1 lo que esta valor 2  asi ya se vuelve a poner otra vez
                    i++;                            //todo es para que avance un pes, aumento i para que vaya al otro pes
                }
                sleep(3.5);
            }
           
        }		
        
        if(nivel == 1){                     //vuelvo a arrancar desde el primer pes
            i=0;
        }
        else if (nivel == 2){
            i=3;
        }
        else{
            i=9;
        }
        
    }  

}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void * enemigo_pulpo(){             ////este thread controla los movimientos del pulpo en el mapa


    int *pulpos [MAX_ENEM];             //creo arreglo de punteros para guardar las posiciones de los pulpos
    
    pulpos[0]= &lvl_1[10][23];     //estas son las posiciones iniciales de los pulpos en la matriz
    pulpos[1]= &lvl_1[12][25];     //PARA EL NIVEL 1
    pulpos[2]= &lvl_1[11][45];
    
    pulpos[3]= &lvl_2[6][13];     //estas son las posiciones iniciales de los pulpos en la matriz
    pulpos[4]= &lvl_2[11][22];     //PARA EL NIVEL 2
    pulpos[5]= &lvl_2[7][31];
    pulpos[6]= &lvl_2[8][38];    
    pulpos[7]= &lvl_2[9][53];     
    pulpos[8]= &lvl_2[9][63];
    
    int cant_pulpo = 3*nivel;     //cantidad de enemigos PULPO por nivel 
    int f;
    int q=0;
    int k;
    int valor5 [MAX_ENEM];	//arreglo que guardo las posiciones de los pulpos
    int valor6 [MAX_ENEM];	//arreglo que salvo las posiciones de los pulpos
    
    if(nivel == 1){                     //cantidad de enemigos PEZ por nivel
        f=0;
    }
    else if (nivel == 2){
        f=3;
    }
    else{
        f=9;
    }
    
    while (1){
        if(q<cant_pulpo){
            while(f<cant_pulpo){				
                valor5 [f]= *(pulpos[f]-LARGO);               //guardo el valor para salvar lo que valia antes de que caiga el pulpo				
				//aca ya salve el valor de lo que habia y se guarda en valor
		*(pulpos[f]-LARGO) = PULPO;            //muevo el PULPO 
                * pulpos[f] = AGUA;             //cuando se movio por primera vez, que me ponga agua donde arranco el PULPO			
                q++;
                pulpos [f] -= LARGO;					//la nueva direeccion del pulpo es la de una para arriba
                f++;							//hasta el ultimpo pulpo, todos se mueven para arriba
            }
            sleep(2.5);
	}	
        else{		
            for(k=0;k<MOV_PULPO;k++){				//MOVIMIENTO DEL PULPO PARA ARRIBA
                while(f<cant_pulpo){			
                    valor6 [f]= *(pulpos[f]-LARGO);               //guardo el valor para salvar lo que valia antes de que caiga el pulpo		
					//aca ya salve el valor de lo que habia y se guarda en valor
                    *(pulpos[f]-LARGO) = PULPO;            //muevo el PULPO 
                                                               //aca entro cuando el PULPO ya se movio mas de una vez
                    * pulpos [f] = valor5[f];        //salvo lo que habia antes		
                    pulpos [f] -= LARGO;				//la nueva direeccion del pulpo es la de una para arriba
                    valor5 [f]= valor6[f];				//pongo en valor 1 lo que esta valor 2  asi ya se vuelve a poner otra vez
                    f++;							//hasta el ultimpo pulpo, todos se mueven para arriba
		}
                sleep(2.5);
                if(nivel == 1){                     //vuelvo a arrancar desde el primer pulpo
                    f=0;
                }
                else if (nivel == 2){
                    f=3;
                }
                else{
                    f=9;
                }
            }		
            for(k=0;k<MOV_PULPO;k++){				//MOVIMIENTO DEL PULPO PARA ABAJO
                while(f<cant_pulpo){					
                    valor6 [f]= *(pulpos[f]+LARGO);               //guardo el valor para salvar lo que valia antes de que caiga el pulpo		
                                                               //aca ya salve el valor de lo que habia y se guarda en valor
                    *(pulpos[f]+LARGO) = PULPO;            //muevo el PULPO 
                                                            //aca entro cuando el PULPO ya se movio mas de una vez
                    * pulpos [f] = valor5[f];        //salvo lo que habia antes                                        
                    pulpos [f] += LARGO;				//la nueva direeccion del pulpo es la de una para abajo
                    valor5 [f]= valor6[f];				//pongo en valor 1 lo que esta valor 2  asi ya se vuelve a poner otra vez
                    f++;							//hasta el ultimpo pulpo, todos se mueven para abajo
		}
                sleep(2.5);
                if(nivel == 1){                     //vuelvo a arrancar desde el primer pulpo
                    f=0;
                }
                else if (nivel == 2){
                    f=3;
                }
                else{
                    f=9;
                }
            }		
	}		
        if(nivel == 1){                     //vuelvo a arrancar desde el primer pulpo
            f=0;
        }
        else if (nivel == 2){
            f=3;
        }
        else{
            f=9;
        }
    }		
}	



