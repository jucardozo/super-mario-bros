/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "levels.h"
extern int lvl_1[ALTURA][LARGO];

void creacionmap(void){ //creacion de los mapas 
        
        lvl_1[7][0]=MARIO;
        lvl_1[7][3]=PEZ;
        lvl_1[9][5]=PULPO;
        lvl_1[4][9]=PES;
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