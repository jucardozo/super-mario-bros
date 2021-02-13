/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "myallegro.h"


ALLEGRO_DISPLAY *display;                       //se crean  puntero hacia estrucuras de allegro
ALLEGRO_BITMAP *mar;                         //que nos permitiran utilizar ciertas funciones de
ALLEGRO_BITMAP *agua;                           //allegro.
ALLEGRO_BITMAP *alga; 
ALLEGRO_BITMAP *lobby;
ALLEGRO_BITMAP *nintendo;
ALLEGRO_BITMAP *press_start;
ALLEGRO_BITMAP *bloque;
ALLEGRO_BITMAP *mario_adelante;
ALLEGRO_BITMAP *mario_atras;                         
ALLEGRO_BITMAP *moneda;                   
ALLEGRO_BITMAP *final;
ALLEGRO_BITMAP *pez;
ALLEGRO_BITMAP *pes;
ALLEGRO_BITMAP *pulpo;
ALLEGRO_SAMPLE *music = NULL;                  //Musica
ALLEGRO_TIMER *timer = NULL;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;        //Cola de eventos

/*ATENCION: TRATAR DE IMPLEMTAR PARA QUE SE PUEDA SALIR APLICANDO LA X EN CUALQUIER MOMENTO*/
extern int tecla;
extern int pos[3];


int inicializacion(){
 /*ALLEGROOOOOOO*/
    /*INICIALIZACION DE ALLEGRO*/
    if (!al_init()){
        fprintf(stderr, "Unable to start allegro\n");                        //realizo la inicializacion de allegro
        return -1;
    } 
    else if (!al_init_image_addon()) {
        fprintf(stderr, "Unable to start image addon \n");          //si hubo un error en la inicializacion imprimo el srderr
        al_uninstall_system();
        return -1;
    } 
    else if (!(display = al_create_display(LARGO_DISPLAY, ANCHO_DISPLAY))) {         //se controlan si hubo problemas en las
        fprintf(stderr, "Unable to create display\n");                              //distintas inicializaciones 
        al_uninstall_system();
        al_shutdown_image_addon();                              
        return -1;
    } 
    else if (!(nintendo = al_load_bitmap("nintendo.jpg"))) {           //se carga imagen de nintendo
        fprintf(stderr, "Unable to load nintendo\n");
        al_uninstall_system();
        al_shutdown_image_addon();
        al_destroy_display(display);
        return -1;
    }
    else if (!(lobby = al_load_bitmap("lobby.jpg"))) {           //se carga imagen de lobby
        fprintf(stderr, "Unable to load lobby\n");
        al_uninstall_system();
        al_shutdown_image_addon();
        al_destroy_display(display);
        return -1;
    }
    else if (!(press_start = al_load_bitmap("press_start.jpg"))) {           //se carga imagen de press_start
        fprintf(stderr, "Unable to load press_start\n");
        al_uninstall_system();
        al_shutdown_image_addon();
        al_destroy_display(display);
        return -1;
    }
    else if (!(mar = al_load_bitmap("mar.jpg"))) {              // se carga en un bitmap la imagen que usaremos de base
        fprintf(stderr, "Unable to load mar\n");
        al_uninstall_system();
        al_shutdown_image_addon();
        al_destroy_display(display);
        return -1;
    }
    else if (!(agua = al_load_bitmap("agua.png"))) {           //se carga imagen de agua
        fprintf(stderr, "Unable to load agua\n");
        al_uninstall_system();
        al_shutdown_image_addon();
        al_destroy_display(display);
        return -1;
    }
    else if (!(alga = al_load_bitmap("alga.png"))) {           //se carga imagen de alga
        fprintf(stderr, "Unable to load alga\n");
        al_uninstall_system();
        al_shutdown_image_addon();
        al_destroy_display(display);
        return -1;
    }
    else if (!(bloque = al_load_bitmap("bloque.png"))) {           //se carga imagen de bloque
        fprintf(stderr, "Unable to load bloque\n");
        al_uninstall_system();
        al_shutdown_image_addon();
        al_destroy_display(display);
        return -1;
    }
    else if (!(mario_adelante = al_load_bitmap("mario_adelante.png"))) {           //se carga imagen de mario mirando hacia adelante
        fprintf(stderr, "Unable to load mario_adelante\n");
        al_uninstall_system();
        al_shutdown_image_addon();
        al_destroy_display(display);
        return -1;
    }
    else if (!(mario_atras = al_load_bitmap("mario_atras.png"))) {           //se carga imagen de mario mirando hacia atras
        fprintf(stderr, "Unable to load mario_atras\n");
        al_uninstall_system();
        al_shutdown_image_addon();
        al_destroy_display(display);
        return -1;
    }
    else if (!(moneda = al_load_bitmap("moneda.png"))) {           //se carga imagen de moneda
        fprintf(stderr, "Unable to load moneda\n");
        al_uninstall_system();
        al_shutdown_image_addon();
        al_destroy_display(display);
        return -1;
    }
    else if (!(final = al_load_bitmap("final.png"))) {           //se carga imagen de final
        fprintf(stderr, "Unable to load final\n");
        al_uninstall_system();
        al_shutdown_image_addon();
        al_destroy_display(display);
        return -1;
    }
    else if (!(pez = al_load_bitmap("pez.png"))) {           //se carga imagen de pez
        fprintf(stderr, "Unable to load pez \n");
        al_uninstall_system();
        al_shutdown_image_addon();
        al_destroy_display(display);
        return -1;
    }
    else if (!(pes = al_load_bitmap("pes.png"))) {           //se carga imagen de pes
        fprintf(stderr, "Unable to load pes\n");
        al_uninstall_system();
        al_shutdown_image_addon();
        al_destroy_display(display);
        return -1;
    }
    else if (!(pulpo = al_load_bitmap("pulpo.png"))) {           //se carga imagen de pulpo
        fprintf(stderr, "Unable to load pulpo\n");
        al_uninstall_system();
        al_shutdown_image_addon();
        al_destroy_display(display);
        return -1;
    }
    /*INICIALIZACION TIMER*/
    timer = al_create_timer(1.0 / FPS); //crea el timer pero NO empieza a correr
    if (!timer) {
        fprintf(stderr, "failed to create timer!\n");
        return -1;
    }
    
    /*INICIALIZAION MUSICA*/
    if (!al_install_audio()) {                                      //Inicializo el audio                                                   //
        fprintf(stderr, "failed to initialize audio!\n");                                                                                   //
        al_uninstall_system();                                                                                                              //
        al_shutdown_image_addon();                                                                                                          //
        al_destroy_display(display);                                                                                                        //
        return -1;                                                                                                                          //
    }                                                                                                                                       //
                                                                                                                                            //
    if (!al_init_acodec_addon()) {                                                                                                          //
        fprintf(stderr, "failed to initialize audio codecs!\n");                                                                            //
        al_uninstall_system();                                                                                                              //
        al_shutdown_image_addon();                                                                                                          //
        al_destroy_display(display);                                                                                                        //
        return -1;                                                                                                                          //
    }                                                                                                                                       //
                                                                                                                                            //
    if (!al_reserve_samples(1)) {                                                                                                           //
        fprintf(stderr, "failed to reserve samples!\n");                                                                                    //
        al_uninstall_system();                                                                                                              //
        al_shutdown_image_addon();                                                                                                          //
        al_destroy_display(display);                                                                                                        //
        return -1;                                                                                                                          //
    }                                                                                                                                       //
                                                                                                                                            //
    music = al_load_sample("musica.wav");                                                                                                   //
                                                                                                                                            //
    if (!music) {                                                                                                                           //
        printf("Audio clip sample not loaded!\n");                                                                                          //
        al_uninstall_system();                                                                                                              //
        al_shutdown_image_addon();                                                                                                          //
        al_destroy_display(display);                                                                                                        //
        return -1;                                                                                                                          //
    }    
    
    
    //////////////////////////////////
    /*INICIALIZO EVENTOS Y TECLADO*///
    /////////////////////////////////////////////////////////////////////////////////////////////////////
    event_queue = al_create_event_queue();                                                             //
    if (!event_queue) {                                                                                //
        fprintf(stderr, "failed to create event_queue!\n");                                            //
        destroy_allegro();                                                                             //
        return -1;                                                                                     //
    }                                                                                                  //
    if (!al_install_keyboard()) {                                                                      //
        fprintf(stderr, "failed to initialize the keyboard!\n");                                       //
        destroy_allegro();                                                                             //
        return -1;                                                                                     //
    }                                                                                                  //
    al_register_event_source(event_queue, al_get_keyboard_event_source());       //Evento teclado      //
    al_register_event_source(event_queue, al_get_display_event_source(display)); //Cruz roja de salir  //
    /////////////////////////////////////////////////////////////////////////////////////////////////////
      
    /*BIENVENIDA POR DISPLAY Y PANTALLA*/
    
    /*PANTALLA NINTENDO + MUSICA*/
//    bienvenida();       //bienvenida por display, se comenta hasta que haga mejor en allegro
    al_clear_to_color(al_map_rgb(255, 255, 255));
    al_flip_display();
    al_rest(1.0);
    al_play_sample(music, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);              //Damos bienvenida al usuario 
    al_draw_scaled_bitmap(nintendo,0, 0, al_get_bitmap_width(nintendo), al_get_bitmap_height(nintendo),0, 0, LARGO_DISPLAY, ANCHO_DISPLAY,0);      //imprimo nintendo                                //
    al_flip_display();                                                      //Muestro la imagen de bienvenida
    al_rest(4.0);
    al_clear_to_color(al_map_rgb(255, 255, 255));
    al_flip_display();
    al_rest(1.0);
    al_draw_scaled_bitmap(lobby,0, 0, al_get_bitmap_width(lobby), al_get_bitmap_height(lobby),0, 0, LARGO_DISPLAY, ANCHO_DISPLAY,0);      //imprimo lobby
    al_flip_display();
    
    /*PANTALLA DE LOBBY + PRESS_START*/
    int mientras = 1;
    while (mientras){                                             //Me quedo aca hasta que se apriete enter o se cierre el programa                             //
        ALLEGRO_EVENT ev0;                                                 //Struct toma todos los eventos de la cola                                                    //
        if (al_get_next_event(event_queue, &ev0)){                   //Damos entrada de teclado por allegro                                                              //
            if (ev0.type == ALLEGRO_EVENT_DISPLAY_CLOSE){            //Si se quiso cerrar el display                                                                     //
                destroy_allegro();                                                                                                                                //
                return 0;                                                                                                                                                //
            }                                                                                                                                                            //
            else if ((ev0.type == ALLEGRO_EVENT_KEY_DOWN) && (ev0.keyboard.keycode == ALLEGRO_KEY_ENTER)|| (ev0.keyboard.keycode == ALLEGRO_KEY_SPACE)){              //sino tranqui, salgo del while sin problema     //
                mientras = 0;   
            }
        }    
        al_draw_bitmap(press_start,100,340,0);          //IMPRIMO PRESS START
        al_flip_display();
        al_rest(1.0);
        al_draw_scaled_bitmap(lobby,0, 0, al_get_bitmap_width(lobby), al_get_bitmap_height(lobby),0, 0, LARGO_DISPLAY, ANCHO_DISPLAY,0);        //HAGO TITILARLO
        al_flip_display();
        al_rest(1.0);
    }                               //HASTA QUE SE APRETE ENTER O ESPACIO
   
    
    
    
    
    /*SE ARRANCA A JUGAR*/
    al_draw_scaled_bitmap(mar,0, 0, al_get_bitmap_width(mar), al_get_bitmap_height(mar),0, 0, LARGO_DISPLAY, ANCHO_DISPLAY,0);      //CARGO BACKGROUND Y LO MUESTRO
    al_flip_display();
    al_rest(0.5);  
 }

void *entrad_allegro(){
    enum MYKEYS {
    KEY_W, KEY_S, KEY_A, KEY_D,ESC,ENTER,ESPACIO //enumero mis letras oa q quede mas fachero el arrgelo
    };
    bool key_pressed[7] = {false, false, false, false,false,false,false}; //Estado de teclas, true cuando esta apretada
    while(1){
        
        ALLEGRO_EVENT ev;
        if (al_get_next_event(event_queue, &ev)){ //Toma un evento de la cola.
            
            if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {       //pregunta si hay alguna tecla presionada,
                    switch (ev.keyboard.keycode) {         //en el caso de que lo haya marca como true, la presionada
                        case ALLEGRO_KEY_W:
                        case ALLEGRO_KEY_UP:
                            key_pressed[KEY_W] = true;
                            tecla=up;
                            break;

                        case ALLEGRO_KEY_S:
                        case ALLEGRO_KEY_DOWN:
                            key_pressed[KEY_S] = true;
                            tecla=down;
                            break;

                        case ALLEGRO_KEY_A:
                        case ALLEGRO_KEY_LEFT:
                            key_pressed[KEY_A] = true;
                            tecla=left;
                            break;

                        case ALLEGRO_KEY_D:
                        case ALLEGRO_KEY_RIGHT:
                            key_pressed[KEY_D] = true;
                            tecla=right;
                            break;
                            
                        case ALLEGRO_KEY_ESCAPE:
                            key_pressed[ESC]=true;
                            tecla=pausa;
                            break;

                    }
                }
                else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
                    switch (ev.keyboard.keycode) {
                        case ALLEGRO_KEY_W:
                        case ALLEGRO_KEY_UP:
                            key_pressed[KEY_W] = false;
                            break;

                        case ALLEGRO_KEY_S:
                        case ALLEGRO_KEY_DOWN:
                            key_pressed[KEY_S] = false;
                            break;

                        case ALLEGRO_KEY_A:
                        case ALLEGRO_KEY_LEFT:
                            key_pressed[KEY_A] = false;
                            break;

                        case ALLEGRO_KEY_D:
                        case ALLEGRO_KEY_RIGHT:
                            key_pressed[KEY_D] = false;
                            break;

                        case ALLEGRO_KEY_ESCAPE:
                            key_pressed[ESC]=false;
                            break;
                    }
                }
            }
    }
}


void destroy_allegro (void){
    al_destroy_display(display);                //se libera la memoria dinamica , destruyendo los elemntos usados
    al_destroy_bitmap(nintendo);
    al_destroy_bitmap(lobby);
    al_destroy_bitmap(press_start);
    al_destroy_bitmap(mar);
    al_destroy_bitmap(agua);
    al_destroy_bitmap(alga);
    al_destroy_bitmap(bloque);
    al_destroy_bitmap(mario_adelante);
    al_destroy_bitmap(mario_atras);
    al_destroy_bitmap(moneda);
    al_destroy_bitmap(final);
    al_destroy_bitmap(pez);
    al_destroy_bitmap(pes);
    al_destroy_bitmap(pulpo);
    al_uninstall_audio();                                                                                                                                    //
    al_destroy_sample(music);
    al_destroy_timer(timer);
    al_destroy_event_queue(event_queue); 
}

void print_map_allegro(int arr [ALTURA][LARGO]){
 
     int largo_elemento=0;
     int alto_elemento=0;
 
    if(((16+pos[2])-pos[1])<=8){        //se lee la columna en donde esta mario y se mueve le mapa si esta en la mitad
        pos[2]+=4;                      //la cantidad de este movimineto se guarda en el tercer elemento del arreglo, se elije por default que se mueva de a 4
    }  
 
    for (int i=0;i<16;i++){
        for(int p=pos[2]; p<(16+pos[2]);p++){
            switch(arr[i][p]){
                case AGUA:
                    al_draw_bitmap(agua,largo_elemento,alto_elemento,0);
                    break;
             /*   case BLOQUE:
                    al_draw_bitmap(bloque,largo_elemento,alto_elemento,0);
                    break;
                case ALGA:
                    al_draw_bitmap(alga,largo_elemento,alto_elemento,0);
                    break;
                case FINAL:
                    al_draw_bitmap(final,largo_elemento,alto_elemento,0);
                    break;
                case MONEDA:
                    al_draw_bitmap(moneda,largo_elemento,alto_elemento,0);
                    break;
                case PEZ:
                    al_draw_bitmap(pez,largo_elemento,alto_elemento,0);
                    break;
                case PES:
                    al_draw_bitmap(pes,largo_elemento,alto_elemento,0);
                    break;
                case PULPO:
                    al_draw_bitmap(pulpo,largo_elemento,alto_elemento,0);
                    break;
                case MARIO:
                    al_draw_bitmap(mario_adelante,largo_elemento,alto_elemento,0);
                    break;
                default:
                    break;*/
            }
            largo_elemento += LARGO_ELEMENTO;
        }
        largo_elemento = 0;
        alto_elemento += ALTO_ELEMENTO;
       
    }
     
    al_flip_display();
 }