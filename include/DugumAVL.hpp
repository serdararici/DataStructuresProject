#ifndef DUGUMAVL_HPP
#define DUGUMAVL_HPP
#include "DogruKuyrugu.hpp"

#include <iostream>
using namespace std;

class DugumAVL{
    public:
        DugumAVL(DogruKuyrugu*,DugumAVL*,DugumAVL*);
        DogruKuyrugu *veri;
        DugumAVL *sol;
        DugumAVL *sag;
        int yukseklik;
};

#endif