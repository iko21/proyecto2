#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <cstdlib>
#include <string>
#include <vector>
#include "Pelotita.h"
#include "Lista.h"
#include <string>
#include "SDL/SDL_ttf.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include "allien.h"
#include "llama.h"
#include "piranha.h"

using namespace std;

//Screen attributes

extern const int SCREEN_WIDTH ;
extern const int SCREEN_HEIGHT;
const int SCREEN_BPP = 32;

//The surfaces
SDL_Surface *image = NULL;
SDL_Surface *screen = NULL;
SDL_Surface *cohetio = NULL;
SDL_Surface *cohe[5];
SDL_Surface *cohemar[4];
SDL_Surface *aster[4];
SDL_Surface *ali=NULL;
SDL_Surface *fuego=NULL;
SDL_Surface *pira=NULL;
SDL_Surface *pelotita_azul;
SDL_Surface *pelotita_roja;
SDL_Surface *lose=NULL;
SDL_Surface *menu=NULL;
SDL_Surface *instru=NULL;
SDL_Surface *puntaje=NULL;
SDL_Surface *selva=NULL;
SDL_Surface *agua=NULL;
SDL_Surface *desierto=NULL;
SDL_Surface *cielo=NULL;
SDL_Color textColor={225, 225, 255 };
TTF_Font *font=NULL;
SDL_Surface *msj=NULL;
SDL_Surface *message= NULL;


SDL_Event *event;


SDL_Surface *load_image( std::string filename )
{
    //The image that's loaded
    SDL_Surface* loadedImage = NULL;
    //The optimized surface that will be used
    SDL_Surface* optimizedImage = NULL;
    //Load the image l
    loadedImage = IMG_Load( filename.c_str() );
    //If the image loaded
    if( loadedImage != NULL )

             //Return the optimized surface
    return loadedImage;
}

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination )
{
    //Rectangle to hold the offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = x;
    offset.y = y;

    //Blit the surface
    SDL_BlitSurface( source, NULL, destination, &offset );
}

bool init()
{
    //Initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return false;
    }


    //Set up the screen
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

    //If there was an error in setting up the screen
    if( screen == NULL )
    {
        return false;
    }

    if( TTF_Init() == -1 ) {
        return false;
    }
    //Set the window caption
    SDL_WM_SetCaption( "PNG test", NULL );

    //If everything initialized fine
    return true;
}

void clean_up()
{
    //Free the surface
    SDL_FreeSurface( image );
    SDL_FreeSurface(selva);
    SDL_FreeSurface(desierto);
    SDL_FreeSurface(agua);
    SDL_FreeSurface(cielo);
    SDL_FreeSurface( cohe[0] );
    SDL_FreeSurface( cohe[1] );
    SDL_FreeSurface( cohe[2] );
    SDL_FreeSurface( cohe[3] );
    SDL_FreeSurface( cohe[4] );
    SDL_FreeSurface( cohemar[0] );
    SDL_FreeSurface( cohemar[1] );
    SDL_FreeSurface( cohemar[2] );
    SDL_FreeSurface( cohemar[3] );
    SDL_FreeSurface(ali);
    SDL_FreeSurface( aster[0] );
    SDL_FreeSurface( aster[1] );
    SDL_FreeSurface( aster[2] );
    SDL_FreeSurface( aster[3] );
    TTF_CloseFont(font);
    TTF_Quit();
    //Quit SDL
    SDL_Quit();
}

string refreshScore(int score)
{
    stringstream ss;
    ss << score;
    return ss.str();
}

bool load_files() {
    //Load the background image
    SDL_Surface *background = load_image( "background.png" );
    //Open the font
    font = TTF_OpenFont( "lazy.ttf", 28 );
    //If there was a problem in loading the background
    if( background == NULL ) { return false; }
    //If there was an error in loading the font
    if( font == NULL ) { return false; }
    //If everything loaded fine
    return true;
}


int main( int argc, char* args[] )
{



do{
    //Initialize
    if( init() == false )
    {
        return 1;
    }

    bool cohete=true, arriba=true;

    SDL_Surface* images[4];
    image = load_image("vida.png");
    selva= load_image("selva.png");
    desierto=load_image("desierto.png");
    agua=load_image("agua.png");
    cielo=load_image("cielo.png");
    cohetio = load_image("cohete.png");
    lose=load_image("lose.png");
    menu=IMG_Load("menu.jpg");
    instru=load_image("instrucciones.jpg");
    puntaje=load_image("puntaje.jpg");
    font=TTF_OpenFont("lazy.ttf", 28);
    if(font==NULL)
    exit(0);

    cohe[0]= load_image( "cohe1.png" );
    cohe[1]= load_image( "cohe2.png" );
    cohe[2]= load_image( "cohe3.png" );
    cohe[3]= load_image( "cohe4.png" );
    cohe[4]= load_image( "cohe5.png" );

    cohemar[0]= load_image( "cohemar1.png" );
    cohemar[1]= load_image( "cohemar2.png" );
    cohemar[2]= load_image( "cohemar3.png" );
    cohemar[3]= load_image( "cohemar4.png" );
    ali=load_image("alien.png");
    fuego=load_image("llama.png");
    pira=load_image("pira.png");

    pelotita_azul=load_image("aster1.png");
    pelotita_roja=load_image("aster1.png");
    Lista l;

    aster[0]= load_image( "aster1.png" );
    aster[1]= load_image( "aster2.png" );
    aster[2]= load_image( "aster3.png" );
    aster[3]= load_image( "aster4.png" );



    int a=-5;
    int b=50;

    int navecarril = 3;
    int navecursor = 228;
     int fre=15;

    int a2=0;
    int b2=0;
    bool cont = true;
    int x=0;
    int ci = 0;
    int co=0;
    int ai = 0;
    int asterfre=500;
    int ciclo=0;
    int y3=0;
    int tempo;

    int frame=0;

    while(true)
    {
        SDL_Event event;
        apply_surface(0,0,menu,screen);

        //While there's events to handle
        while( SDL_PollEvent( &event ) )
        {

            //If the user has Xed out the window
            if( event.type == SDL_QUIT )
            {
                //Quit the program
//                quit = true;
                cont = false;
                break;
            }

        }

        Uint8 *keystates = SDL_GetKeyState( NULL );


        if(keystates[SDLK_1])
        {
            break;

        }
        if(keystates[SDLK_2])
        {
            char cadena[120];

            ifstream fe("scores.txt");
            fe.getline(cadena,120);

            message = TTF_RenderText_Solid(font,cadena,textColor);
            if(message==NULL){
                exit(0);
            }
            apply_surface(0,0,puntaje,screen);
            apply_surface(220,250,message,screen);

            if(SDL_Flip(screen)==-1){
                return 1;
            }

        }
        if(keystates[SDLK_3])
        {
               apply_surface(0,0,instru,screen);
        }
        SDL_Flip(screen);
    }

    int score=0;
    while(cont)
    {
        //__________________________________________________________________________

        std::stringstream str;
        str<<"score: "<<score;
        cout<<str.str().c_str()<<endl;
        //if(font==NULL)
        //exit(0);
        msj=TTF_RenderText_Solid(font, str.str().c_str(), textColor);
        frame++;
        int x_pos=rand()%540;
        int y_pos=rand()%480;

        if(score>600)
        {
            fre=8;
        }

        //If there's events to handle
        if(frame%fre==0){
            if(score<200)
            {
                l.agregar(new Pelotita(asterfre,y_pos,10,10,pelotita_azul));
            }else if(score>=200 && score<400){
                l.agregar(new allien(asterfre, y_pos, 20, 20, ali));
            }else if(score>=400 && score<600){
                l.agregar(new llama(asterfre,y_pos, 20, 20, fuego));
            }else
            {
                l.agregar(new piranha(asterfre,y_pos, 23, 23,pira));
            }
        }

        //____________________________________________________________________________



        int ys = rand()%401;
            if(ys%3==0)
           {
            y3=0;
           }else
           {
               y3=400;
           }
        ciclo++;
        //If there was a problem in loading the image
        if( cohe[ci] == NULL )
        {
            return 1;
        }

        SDL_Event event;
        //While there's events to handle
        while( SDL_PollEvent( &event ) )
        {

            //If the user has Xed out the window
            if( event.type == SDL_QUIT )
            {
                //Quit the program
//                quit = true;
                cont = false;
            }
        }

        Uint8 *keystates = SDL_GetKeyState( NULL );


        if(keystates[SDLK_UP])
        {
               navecarril=navecarril-10;
        }
        if(keystates[SDLK_DOWN])
        {
                navecarril=navecarril+10;
        }
        int posi[5];
        posi[0]=36;
        posi[1]=132;
        posi[2]=228;
        posi[3]=324;
        posi[4]=420;






        a2=a2-5;


        //Apply the surface to the screen
        if(a2<-540)
        {
           a2=0;
        }

        if(ci > 4)
        {
            ci = 0;
        }
        if(ai>3)
        {
            ai=0;
        }
        if(co>3)
        {
            co=0;
        }



        if(score<200){
            apply_surface(a2,b2, image,screen);
        }else if(score>=200 && score<400)
        {
             apply_surface(a2,b2, selva,screen);
        } else if(score>=400 && score<600)
        {
           apply_surface(a2,b2, desierto,screen);
        }else if(score>=600 && score<800)
        {
           apply_surface(a2,b2, agua,screen);
        }else
        {
             apply_surface(a2,b2, cielo,screen);
        }


        l.moverTodos();
        l.imprimirTodos(screen);
        if(score>=600 && score<800)
        {
            apply_surface(a,navecarril,cohemar[co],screen);
        }
        else
        {
            apply_surface( a, navecarril, cohe[ci], screen );
        }

        if(l.detectarClick(a,navecarril)==true)
        {
            ifstream is ("scores.txt");
            int pos[3];
            int c=0;
            while (is >> pos[c])
                c++;
            if (score > pos[0])
                {
                    pos[2]=pos[1];
                    pos[1]=pos[0];
                    pos[0]=score;
                }
                else if(score > pos[1])
                {
                    pos[2]=pos[1];
                    pos[1]=score;
                }
                else if (score > pos[2])
                {
                    pos[2]=score;
                }
                is.close();


            ofstream fs("scores.txt");

            for (int i=0; i<3; i++)
            {
                fs<< pos[i] << ' ';
            }
            fs.close();
            for(int i=0; i<500; i++)
            {
                apply_surface(0,0,lose,screen);
                SDL_Flip(screen);
            }
            cont=false;

        }
        //if(msj==NULL)
        //exit(0);

        apply_surface(0,0,msj,screen);

          //if()


        //Update the screen
        if( SDL_Flip( screen ) == -1 )
        {
            return 1;
        }

        //Wait 2 seconds
        SDL_Delay( 20 );
        ci++;
        co++;
        ai++;
        tempo++;
        x++;
        score++;
        //asterfre--;


        SDL_FreeSurface(msj);

    }



    //Free the surface and quit SDL
}while(true);
    clean_up();

    return 0;
}
