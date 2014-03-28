#include "llama.h"

llama::llama(int x,int y,int velocidad_x,int velocidad_y,SDL_Surface*surface)
{
    this->x=x;
    this->y=y;
    this->velocidad_x=velocidad_x;
    this->velocidad_y=velocidad_y;
    this->surface=surface;
    this->sig=NULL;
    this->width=surface->w;
    this->height=surface->h;
}

llama::~llama()
{
    //dtor
}

void llama::moverse()
{
    this->x-=this->velocidad_x;


}
