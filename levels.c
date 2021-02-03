/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "levels.h"
extern int lvl_1[ALTURA][LARGO];
extern int lvl_2[ALTURA][LARGO];
//extern int lvl_3[ALTURA][LARGO];

void creacionmap(int que_nivel){        //creacion de los mapas, niveles: 1,2 y 3.
    
    switch(que_nivel){
    
        case 1:                             
            lvl_1[7][0]=MARIO;
            //ENEMIGOS
            lvl_1[7][3]=PEZ;
            lvl_1[9][5]=PEZ;
            lvl_1[4][9]=PEZ;

            lvl_1[8][5]=PES;
            lvl_1[11][6]=PES;
            lvl_1[6][7]=PES;

            lvl_1[10][23]=PULPO;
            lvl_1[12][25]=PULPO;
            lvl_1[11][45]=PULPO;
            //
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
                
                break;
        case 2:
            lvl_2[7][0]=MARIO;
            //ENEMIGOS
            lvl_2[7][7]=PEZ;
            lvl_2[][]=PEZ;
            lvl_2[4][9]=PEZ;
            lvl_2[7][3]=PEZ;
            lvl_2[9][5]=PEZ;
            lvl_2[4][9]=PEZ;

            lvl_2[8][5]=PES;
            lvl_2[11][6]=PES;
            lvl_2[6][7]=PES;
            lvl_2[8][5]=PES;
            lvl_2[11][6]=PES;
            lvl_2[6][7]=PES;

            lvl_2[10][23]=PULPO;
            lvl_2[12][25]=PULPO;
            lvl_2[11][45]=PULPO;
            lvl_2[10][23]=PULPO;
            lvl_2[12][25]=PULPO;
            lvl_2[11][45]=PULPO;
            //
            for(int i=0;i<(LARGO-5);i++)
            {
                    lvl_2[0][i]=SUPERFICIE;
                    lvl_2[1][i]=SUPERFICIE;
            }

            for(int i=(LARGO-5);i<LARGO;i++)
            {
                    lvl_2[0][i]=BLOQUE;
                    lvl_2[1][i]=BLOQUE;
            }	

            for(int i=0;i<(LARGO/7);i++)
            {
                    lvl_2[14][i]=BLOQUE;
                    lvl_2[15][i]=BLOQUE;
            }

            for(int j= ((LARGO/7)+3) ;j<(LARGO-40);j++)
            {
                    lvl_2[14][j]=BLOQUE;
                    lvl_2[15][j]=BLOQUE;
            }

            for(int k=9;k<14;k++)
            {
                    lvl_2[k][3]=BLOQUE;
            }
            for(int k=2;k<7;k++)            //SEGUNDA PARED DE ARRIBA 
            {
                lvl_2[k][5]=BLOQUE;
            }

            lvl_2[13][4]=MONEDA;
            lvl_2[2][6]=MONEDA;

            for(int k=6;k<8;k++)              //PRIMER ESCALON 
            {
                    lvl_1[9][k]=BLOQUE;
            }

            lvl_1[13][11]=MONEDA;

            for(int k=8;k<10;k++)
            {
                    lvl_2[5][k]=BLOQUE;       //SEGUNDO ESCALON 
            }

            for(int k=10;k<14;k++)
            {
                    lvl_2[k][10]=ALGA;         //pared de alga antes del pozo
            }

            
            for(int k=10;k<14;k++)             //pared trasera 
            {
                    lvl_2[k][13]=ALGA;
            }
            
            lvl_2[13][14]=MONEDA;
            lvl_2[2][16]=MONEDA;
            lvl_2[13][18]=MONEDA;

            for(int k=8;k<14;k++)
            {
                    lvl_2[k][20]=ALGA;      //alga flotante 
            }

            

            for(int k=3;k<6;k++)
            {
                    lvl_2[k][22]=ALGA;      //
            }

            for(int k=11;k<14;k++)
            { 
                    lvl_2[k][23]=BLOQUE;        //
            }
            
            lvl_2[13][24]=MONEDA;           //
            

            for(int k=5;k<11;k++)
            {
                    lvl_2[k][25]=ALGA;    //
            }

            for(int k=2;k<8;k++)
            {
                    lvl_2[k][30]=BLOQUE;   //tunel 
            }		

            for(int k=11;k<14;k++)
            {
                    lvl_1[k][30]=BLOQUE;    //
            }
            
            for(int k=11;k<14;k++)
            {
                lvl_2[k][33]=BLOQUE;        //
            }

            for(int k=5;k<7;k++)
            {
                    lvl_2[k][40]=BLOQUE;
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
            break;
        /*case 3:
            break;*/
        default:
            break;
    }

} 