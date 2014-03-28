#ifndef LLAMA_H
#define LLAMA_H
#include "Pelotita.h"


class llama : public  Pelotita
{
    public:
        llama();
        llama(int x,int y,int velocidad_x,int velocidad_y,SDL_Surface*surface);
        virtual ~llama();
        void moverse();
    protected:
    private:
};

#endif // LLAMA_H
