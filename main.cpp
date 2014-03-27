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
SDL_Surface *pelotita_azul;
SDL_Surface *pelotita_roja;
SDL_Surface *lose=NULL;
SDL_Surface *menu=NULL;
SDL_Surface *instru=NULL;
SDL_Surface *puntaje=NULL;
SDL_Surface *selva=NULL;
SDL_Surface *agua=NULL;
SDL_Surface *desierto=NULL;
SDL_Color textColor={225, 225, 255 };
TTF_Font *font=NULL;
SDL_Surface *msj=NULL;

SDL_Event *event;


SDL_Surface *load_image( std::string filename )
{
    return IMG_Load(filename.c_str());
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
    TTF_Init();

    //Set up the screen
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

    //If there was an error in setting up the screen
    if( screen == NULL )
    {
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
    SDL_FreeSurface( cohe[0] );
    SDL_FreeSurface( cohe[1] );
    SDL_FreeSurface( cohe[2] );
    SDL_FreeSurface( cohe[3] );
    SDL_FreeSurface( cohe[4] );
    SDL_FreeSurface( cohemar[0] );
    SDL_FreeSurface( cohemar[1] );
    SDL_FreeSurface( cohemar[2] );
    SDL_FreeSurface( cohemar[3] );
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


int main( int argc, char* args[] )
{

  ofstream fs("scores.txt", ios::app);

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


    int a2=0;
    int b2=0;
    bool cont = true;
    int x=0;
    int ci = 0;
    int co=0;
    int ai = 0;
    int asterfre=500;
    int ciclo=0;

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
            apply_surface(0,0,puntaje,screen);
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


        //If there's events to handle
        if(frame%10==0){
        l.agregar(new Pelotita(asterfre,y_pos,10,10,pelotita_azul));

        }

        //____________________________________________________________________________



        int ys = rand()%401;
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
        }else if(score>=600)
        {
           apply_surface(a2,b2, agua,screen);
        }


        l.moverTodos();
        l.imprimirTodos(screen);
        if(score>=600)
        {
            apply_surface(a,navecarril,cohemar[co],screen);
        }else
        {
            apply_surface( a, navecarril, cohe[ci], screen );
        }
        if(l.detectarClick(a,navecarril)==true)
        {
            fs << score <<" ";
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
