#ifndef ALLIEN_H
#define ALLIEN_H
#include "Pelotita.h"


class allien : public Pelotita
{
    public:



        allien(int x,int y,int velocidad_x,int velocidad_y,SDL_Surface*surface);
        virtual ~allien();
        void moverse();

    protected:
    private:
};

#endif // ALLIEN_H
