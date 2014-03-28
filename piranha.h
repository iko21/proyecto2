#ifndef PIRANHA_H
#define PIRANHA_H
#include "Pelotita.h"


class piranha : public  Pelotita
{
    public:
        piranha();
        piranha(int x,int y,int velocidad_x,int velocidad_y,SDL_Surface*surface);
        virtual ~piranha();
        void moverse();
    protected:
    private:
};

#endif // PIRANHA_H
