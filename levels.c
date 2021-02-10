/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "levels.h"
extern int lvl_1[ALTURA][LARGO];
extern int lvl_2[ALTURA][LARGO];
extern int lvl_3[ALTURA][LARGO];

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
            
            lvl_2[10][0]=MARIO;
            //ENEMIGOS
            lvl_2[8][5]=PEZ;
            lvl_2[8][18]=PEZ;
            lvl_2[6][24]=PEZ;
            lvl_2[10][34]=PEZ;
            lvl_2[10][43]=PEZ;
            lvl_2[12][58]=PEZ;

            lvl_2[12][9]=PES;
            lvl_2[6][21]=PES;
            lvl_2[11][28]=PES;
            lvl_2[4][35]=PES;
            lvl_2[4][46]=PES;
            lvl_2[9][61]=PES;

            lvl_2[6][13]=PULPO;
            lvl_2[11][22]=PULPO;
            lvl_2[7][31]=PULPO;
            lvl_2[8][38]=PULPO;
            lvl_2[9][53]=PULPO;
            lvl_2[9][63]=PULPO;
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

            for(int k=11;k<13;k++)
            {
                    lvl_2[15][k]=PRECIPICIO;
             }		

            for(int j= ((LARGO/7)+3) ;j<(LARGO-40);j++)
            {
                    lvl_2[14][j]=BLOQUE;
                    lvl_2[15][j]=BLOQUE;
            }
            
            for(int k=31;k<33;k++)
            {
                    lvl_2[15][k]=PRECIPICIO;
            }
            
            for(int j= 33 ;j<49;j++)
            {
                    lvl_2[14][j]=BLOQUE;
                    lvl_2[15][j]=BLOQUE;
            }
            
            for(int k=49;k<52;k++)
            {
                    lvl_2[15][k]=PRECIPICIO;
            }
            
            for(int j= 52 ;j<= LARGO ;j++)
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
                    lvl_2[9][k]=BLOQUE;
            }

            lvl_2[13][11]=MONEDA;

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
                    lvl_2[k][30]=BLOQUE;    //
            }
            
            for(int k=11;k<14;k++)
            {
                lvl_2[k][33]=BLOQUE;        //
            }

            for(int k=37;k<39;k++)
            {
                    lvl_2[6][40]=BLOQUE;    //
            }
            for(int k=37;k<39;k++)
            {
                    lvl_2[11][k]=BLOQUE;    //
            }

            lvl_2[13][38]=MONEDA;   //
            lvl_2[2][41]=MONEDA;    //
            
            for(int k=40;k<42;k++)
            {
                    lvl_2[9][k]=BLOQUE;    //
            }

            for(int k=41;k<46;k++)
            {
                    lvl_2[13][k]=BLOQUE;    //
            }

            for(int k=42;k<45;k++)
            {
                    lvl_2[12][k]=BLOQUE;    //
            }
            lvl_2[13][40]=MONEDA;
            lvl_2[12][41]=MONEDA;
            
            for(int k=42 ;k<45 ;k++)
            {
                    lvl_2[11][k]=MONEDA;        //
            }
            
            lvl_2[12][45]=MONEDA;   //
            lvl_2[13][46]=MONEDA;   //

            for(int k=43;k<45;k++)
            {
                    lvl_2[5][k]=BLOQUE;     //
            }

            for(int k=45;k<47;k++)
            {
                    lvl_2[9][k]=BLOQUE;     //
            }
            
            for(int k=2;k<8;k++)
            {
                for(int j=48; j<53;j++)
                {
                    lvl_2[k][j]=BLOQUE;         //
                }
            }
            

            lvl_2[13][50]=MONEDA;           //

            lvl_2[13][51]=MONEDA;           //

            for(int k=11;k<14;k++)
            {
                    lvl_2[k][48]=BLOQUE;
            }

            for(int k=11;k<14;k++)
            {
                    lvl_2[k][52]=BLOQUE;        //
            }

            lvl_2[13][53]=MONEDA;           //

            for(int k=2;k<6;k++)
            {
                    lvl_2[k][55]=ALGA;          //
            }
            
            for(int k=7;k<12;k++)
            {
                    lvl_2[k][58]=ALGA;          //
            }

            for(int i=(LARGO-5);i<LARGO;i++)
            {
                    for(int k=2;k<10;k++)
                    {
                            lvl_2[k][i]=BLOQUE;
                            lvl_2[k][i]=BLOQUE;
                    }
            }

            for(int k=10;k<14;k++)
            {
                    lvl_2[k][LARGO-1]=BLOQUE;
            }

            for(int k=60;k<(LARGO-1);k++)
            {
                    lvl_2[13][k]=BLOQUE;
            }

            lvl_2[12][61]=MONEDA;
            lvl_2[12][62]=MONEDA;

            lvl_2[11][LARGO-2]=FINAL;
            lvl_2[12][LARGO-2]=FINAL;
            break;
       
        
        case 3:
             lvl_2[10][0]=MARIO;
            //ENEMIGOS
            lvl_2[8][5]=PEZ;
            lvl_2[8][18]=PEZ;
            lvl_2[6][24]=PEZ;
            lvl_2[10][34]=PEZ;
            lvl_2[10][43]=PEZ;
            lvl_2[12][58]=PEZ;

            lvl_2[12][9]=PES;
            lvl_2[6][21]=PES;
            lvl_2[11][28]=PES;
            lvl_2[4][35]=PES;
            lvl_2[4][46]=PES;
            lvl_2[9][61]=PES;

            lvl_2[6][13]=PULPO;
            lvl_2[11][22]=PULPO;
            lvl_2[7][31]=PULPO;
            lvl_2[8][38]=PULPO;
            lvl_2[9][53]=PULPO;
            lvl_2[9][63]=PULPO;
            //
            for(int i=0;i<(LARGO-5);i++)
            {
                    lvl_3[0][i]=SUPERFICIE; ///
                    lvl_3[1][i]=SUPERFICIE;
            }

            for(int i=(LARGO-5);i<LARGO;i++)
            {
                    lvl_3[0][i]=BLOQUE;     ///
                    lvl_3[1][i]=BLOQUE;
            }	

            for(int i=0;i<23;i++)
            {
                    lvl_3[14][i]=BLOQUE;          ///
                    lvl_3[15][i]=BLOQUE;
            }

            for(int k=23;k<25;k++)
            {
                    lvl_3[15][k]=PRECIPICIO;      ///
             }		

            for(int j=25 ;j<31;j++)
            {
                    lvl_3[14][j]=BLOQUE;        ///
                    lvl_3[15][j]=BLOQUE;
            }
            
            for(int k=31;k<33;k++)
            {
                    lvl_3[15][k]=PRECIPICIO;        ///
            }
            
            for(int j= 33 ;j<59;j++)
            {
                    lvl_3[14][j]=BLOQUE;
                    lvl_3[15][j]=BLOQUE;        ///
            }
            
            for(int k=59;k<62;k++)
            {
                    lvl_3[15][k]=PRECIPICIO;        ///
            }
            
            for(int j= 62 ;j<= LARGO ;j++)
            {
                    lvl_3[14][j]=BLOQUE;
                    lvl_3[15][j]=BLOQUE;            ///
            }
            

            for(int k=2;k<4;k++)
            {
               for(int j=10;j<14;j++)
               {
                    lvl_3[j][k]=ALGA;       ///
               }
            }
            
            for(int k=4;k<6;k++)
            {
               for(int j=2;j<7;j++)
               {
                    lvl_3[j][k]=ALGA;       ///
               }
            }
            
            for(int k=2;k<7;k++)            ///
            {
                for(int j=6;j<10;j++)
                {
                    lvl_3[k][j]=BLOQUE;
                }
            }
            
            for(int k=8;k<10;k++)
            {
               for(int j=5;j<10;j++)
               {
                    lvl_3[j][k]=BLOQUE;       ///
               }
            }
            

            lvl_2[2][6]=MONEDA;                 ///
            lvl_2[10][10]=MONEDA;               ///

            for(int k=11;k<13;k++)
            {
               for(int j=2;j<7;j++)
               {
                    lvl_3[j][k]=BLOQUE;       ///
               }
            }
            
            for(int k=13;k<15;k++)
            {
               for(int j=5;j<7;j++)
               {
                    lvl_3[j][k]=BLOQUE;       ///
               }
            }
            
            for(int k=12;k<15;k++)               
            {                                   /// 
                for(int j=10 ;j<12 ;j++)
                {
                    lvl_3[j][k]=BLOQUE;
                }
            
            }
            
            for(int k=17;k<21;k++)               
            {                                   
                for(int j=5 ;j<7 ;j++)
                {
                    lvl_3[j][k]=BLOQUE;     ///
                }

            }
            
            for(int k=17;k<21;k++)               
            {                                   
                for(int j=9 ;j<11 ;j++)
                {
                    lvl_3[j][k]=BLOQUE;     ///
                }

            }
            

            lvl_3[2][21]=MONEDA;            ///
            lvl_3[13][23]=MONEDA;            ///

            for(int k=10;k<14;k++)
            {
                    lvl_3[k][22]=ALGA;       ///       
            }

            for(int k=10;k<14;k++)
            {
                    lvl_3[k][25]=ALGA;      ///         
            }

            
            for(int k=2;k<6;k++)              
            {
                for(int j=22 ;j<26 ;j++)
                {
                    lvl_3[k][j]=BLOQUE;     ///
                }
            }
            
            lvl_3[13][23]=MONEDA;
            lvl_3[13][24]=MONEDA;
            lvl_3[2][26]=MONEDA;

            for(int k=7;k<11;k++)
            {
                    lvl_3[k][27]=ALGA;      /// 
            }

            for(int k=2;k<5;k++)
            {
                    lvl_3[k][28]=ALGA;      ///
            }

            for(int k=2;k<5;k++)
            { 
                for(int j=30; j<34;j++)
                {    
                    lvl_3[k][j]=BLOQUE;
                }                           ///
            }
            
            
            for(int k=31;k<34;k++)          ///
            {
                lvl_3[5][k]=BLOQUE;
            }
            
            for(int k=32;k<34;k++)
            {
                lvl_3[6][k]=BLOQUE;     ///
            }
            
            lvl_3[7][33]=BLOQUE;            ///
            lvl_3[13][24]=MONEDA;           ///
            
            lvl_3[5][30]=MONEDA;        ///
            lvl_3[6][31]=MONEDA;        ///
            lvl_3[7][32]=MONEDA;           ///
            lvl_3[8][33]=MONEDA;        ///
            lvl_3[2][34]=MONEDA;    ///

            for(int k=11;k<14;k++)
            {
                    lvl_3[k][33]=BLOQUE;    ///
            }

            for(int k=11;k<14;k++)
            {
                    lvl_3[k][30]=BLOQUE;   /// 
            }
            
            lvl_3[2][35]=BLOQUE;    ///
            
            for(int k=36;k<40;k++)
            {
                for(int j=2;j<4;j++)
                {
                    lvl_3[j][k]=BLOQUE;     ///
                }
            }
            
            for(int k=37;k<40;k++)
            {
                lvl_3[4][k]=BLOQUE;         ///
            }
            
            for (int k=38;k<40;k++)
            {
                lvl_3[5][k]=BLOQUE;
            }
            
            lvl_3[6][39]=BLOQUE;    /// 
            
            lvl_3[13][35]=BLOQUE;   /// 
                                   
            for(int k=12;k<14;k++)
            {
                for(int j=12;j<14;j++)      ///
                {
                    lvl_3[k][j]=BLOQUE;
                }
            }
            
            for(int k=37; k<40;k++)
            {
                lvl_3[11][k]=BLOQUE;        ///
            }
            
            for(int k=38;k<40;k++)
            {
                lvl_3[10][k]=BLOQUE;        ///
            }
            
            lvl_3[9][39]=BLOQUE;        /// 
            
            
            
            for(int k=2;k<5;k++)
            {
                lvl_3[k][43]=ALGA;    ///
            }
            
            for(int k=8;k<11;k++)
            {
                lvl_3[k][45]=ALGA;        ///
            }

            for(int k=2;k<6;k++)
            {
                lvl_3[k][46]=ALGA;    ///
            }
            
            for(int k=7;k<12;k++)
            {
                for(int j=49;j<53;j++)
                {
                    lvl_3[k][j]=BLOQUE;     ///
                }
            }

            lvl_3[6][50]=MONEDA;   ///
            lvl_3[12][50]=MONEDA;    ///
            
            for(int k=50;k<52;k++)
            {
                for(int j=2;j<4;j++)
                {
                    lvl_3[j][k]=BLOQUE;         ///
                }

            }

            for(int k=6;k<11;k++)
            {
                    lvl_3[k][50]=ALGA;    ///
            }

            for(int k=11;k<14;k++)
            {
                    lvl_3[k][58]=BLOQUE;    ///
            }
            lvl_3[2][60]=MONEDA; ///
            lvl_3[8][61]=MONEDA; ///
         
            lvl_3[13][61]=MONEDA;   ///
            lvl_3[13][63]=MONEDA;   ///

            for(int k=11;k<14;k++)
            {
                    lvl_3[k][62]=BLOQUE;     ///
            }

            for(int k=2;k<5;k++)
            {
                    lvl_3[k][59]=ALGA;     ///
            }
            
            for(int k=6;k<9;k++)
            {
                    lvl_3[k][60]=BLOQUE;         ///
                
            }
            
            for(int k=2;k<5;k++)        ///
            {
                lvl_3[k][62]=ALGA;
            }

            for(int i=(LARGO-5);i<LARGO;i++)
            {
                    for(int k=2;k<10;k++)
                    {
                            lvl_2[k][i]=BLOQUE;
                            lvl_2[k][i]=BLOQUE;
                    }
            }

            for(int k=10;k<14;k++)
            {
                    lvl_2[k][LARGO-1]=BLOQUE;
            }

            for(int k=60;k<(LARGO-1);k++)
            {
                    lvl_2[13][k]=BLOQUE;
            }

            lvl_2[12][61]=MONEDA;
            lvl_2[12][62]=MONEDA;

            lvl_2[11][LARGO-2]=FINAL;
            lvl_2[12][LARGO-2]=FINAL;
            break;
        default:
            break;
    }

} 