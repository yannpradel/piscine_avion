#include <iostream>
#include "Simulateur.h"
#include "Affichage.h"
#include <stdio.h>




void initialiser_allegro()
{
    srand(time(NULL));
    // initialisation allegro obligatoire
    allegro_init() ;

    // sélection de la profondeur de couleur, si rien n'est spécifié le mode couleur est en 8 bits
    set_color_depth(32);

    // définir un mode graphique en contrôlant qu'il fonctionne

    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,1824,1026,0,0)!=0)
    {
        allegro_message("l'ecran est trop petit il faut mettre la resolution a 100 dans parametres -> systeme -> resolution");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    set_window_title("ECE Flight Simulator");
    set_close_button_callback(allegro_exit);

    // pour disposer du clavier (si besoin)
    install_keyboard();

    // pour disposer de la souris (si besoin)
    install_mouse();

    //musique
    install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL);
    int play_sample(const SAMPLE *spl, int vol, int pan, int freq, int loop);

    //autres initialisations
    install_timer();
}
END_OF_FUNCTION(initialiser_allegro)

void delay(int milli_seconds)//https://www.geeksforgeeks.org/time-delay-c/
{

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}

void menu(Simulateur Sim)
{
    Allegro a;

    ///BITMAPS
    BITMAP* buffer = create_bitmap(SCREEN_W, SCREEN_H);

    bool sortie=false;
    int i=36+18;
    int b=0,c=0,d=0,e=0,f=0;

    ///GAME LOOP
    do
    {




        draw_sprite(buffer, a.getImage(2), 0, 0);

        if(b==0)
            textprintf_ex(buffer, a.getFont2(), 50, 724+i*0, a.getCoul(2), -1, "Aeroports");
        else
            textprintf_ex(buffer, a.getFont2(), 50, 720+i*0, a.getCoul(3), -1, "Aeroports");
        if(c==0)
            textprintf_ex(buffer, a.getFont2(), 50, 720+i*1, a.getCoul(2), -1, "Commencer");
        else
            textprintf_ex(buffer, a.getFont2(), 50, 724+i*1, a.getCoul(3), -1, "Commencer");
        if(d==0)
            textprintf_ex(buffer, a.getFont2(), 50, 720+i*2, a.getCoul(2), -1, "Commencer");
        else
            textprintf_ex(buffer, a.getFont2(), 50, 724+i*2, a.getCoul(3), -1, "Commencer");
        if(e==0)
            textprintf_ex(buffer, a.getFont2(), 50, 720+i*3, a.getCoul(2), -1, "Commencer");
        else
            textprintf_ex(buffer, a.getFont2(), 50, 724+i*3, a.getCoul(3), -1, "Commencer");
        if(f==0)
            textprintf_ex(buffer, a.getFont2(), 50, 720+i*4, a.getCoul(2), -1, "Quitter");
        else
            textprintf_ex(buffer, a.getFont2(), 50, 724+i*4, a.getCoul(3), -1, "Quitter");




        //rect(buffer, 50, 724+18, 324, 724+36+18, a.getCoul(1));



        b=0;
        if((mouse_x>=50) && (mouse_x<=36*9) & (mouse_y>=724+18+i*0) && (mouse_y<=724+36+18+i*0))
        {
            b=1;
            if(mouse_b==1)
            {
                play_sample(a.getClique(),255,128,1000,0);
                delay(300);
                Sim.afficher2();
            }
        }

        c=0;
        if((mouse_x>=50) && (mouse_x<=36*9) & (mouse_y>=724+18+i*1) && (mouse_y<=724+36+18+i*1))
        {
            c=1;
            if(mouse_b==1)
            {
                play_sample(a.getClique(),255,128,1000,0);
                delay(300);
                Sim.lancerSimu();
            }
        }

        d=0;
        if((mouse_x>=50) && (mouse_x<=36*9) & (mouse_y>=724+18+i*2) && (mouse_y<=724+36+18+i*2))
        {
            d=1;
            if(mouse_b==1)
            {
                play_sample(a.getClique(),255,128,1000,0);
                delay(300);
                std::string Ssommet_i,Ssommet_a;
                std::vector<std::string> z;
                std::cout<<"Sommet initial (New-York, Haiti, Paz, Paris, CapeTown, Bangkok, Perth) : ";
                std::cin>>Ssommet_i;
                std::cout<<"Sommet d'arrivee (New-York, Haiti, Paz, Paris, CapeTown, Bangkok, Perth) : ";
                std::cin>>Ssommet_a;
                z = Sim.Dijkstra(Sim.getTaille(),Sim.getOrdre(),Sim.getID(),Ssommet_i,Ssommet_a);
            }
        }

        e=0;
        if((mouse_x>=50) && (mouse_x<=36*9) & (mouse_y>=724+18+i*3) && (mouse_y<=724+36+18+i*3))
        {
            e=1;
            if(mouse_b==1)
            {
                play_sample(a.getClique(),255,128,1000,0);
                delay(300);
                Sim.lancerAleatoireComplet();
            }
        }

        f=0;
        if((mouse_x>=50) && (mouse_x<=36*9) & (mouse_y>=724+18+i*4) && (mouse_y<=724+36+18+i*4))
        {
            f=1;
            if(mouse_b==1)
            {
                play_sample(a.getClique(),255,128,1000,0);
                delay(300);
                sortie=true;
            }
        }


        ///Images
        draw_sprite(buffer, a.getImage(1), mouse_x, mouse_y);///souri
        draw_sprite(screen, buffer, 0, 0);
        clear(buffer);
    }while(!sortie);


    ///destruction
    destroy_bitmap(buffer);
    delay(500);
    a.destruction();///destruction methode sinon mega crash
}END_OF_FUNCTION(menu)









int main()
{

    initialiser_allegro();

     Simulateur a;



     std::vector<int> z;

     a.load_aeroport();

     a.load_avion();


   menu(a);



    return 0;
}END_OF_MAIN();




