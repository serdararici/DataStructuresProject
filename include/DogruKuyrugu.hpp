#ifndef DOGRUKUYRUGU_HPP
#define DOGRUKUYRUGU_HPP
#include<exception>
#include <iostream>
#include "Dugum.hpp"

class DogruKuyrugu
{
    public:
        DogruKuyrugu();
        ~DogruKuyrugu();
        void ekle(int,int,int,int);   
        Dugum* enYakinOncekiDugum();
        Dugum* enYakinGetir();
        int orjineUzaklik(int,int,int);
        int toplamUzunluk;
       
        void dugumSil(Dugum* silinecekDugum);
        
    
    private:
        Dugum* ilk;
        Dugum* son;
        

};


#endif