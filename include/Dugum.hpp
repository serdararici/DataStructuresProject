#ifndef DUGUM_HPP
#define DUGUM_HPP
#include <iostream>
#include <fstream>

using namespace std;

class Dugum
{
public:
    Dugum(int,int,int,int);
    ~Dugum();
    
    int oncelik;
    int x;
    int y;
    int z;
    Dugum* onceki;
    Dugum* sonraki;
};



#endif