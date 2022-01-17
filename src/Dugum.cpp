/** 
* @file Dugum.cpp
* @description DogruKuyrugu sınıfında kulllanmak için bir düğüm sınıfı
* @course 2.Öğretim B grubu
* @assignment 2
* @date 20.12.2021
* @author Serdar Arıcı serdar.arici1@ogr.sakarya.edu.tr
*/


#include "Dugum.hpp"

Dugum::Dugum(int oncelik, int x, int y, int z)
{
    this->oncelik = oncelik;
    this->x = x;
    this->y = y;
    this->z = z;
    //this->veri = veri;

    onceki = sonraki = 0;
}   

Dugum::~Dugum()  //yıkıcı fonksiyon. Hangi dugumun nerede silindigini gostermek icin
{
   // delete silinecekDugum;
    //cout<<this<<x<<y<<z<<" adresindeki dugum silindi."<<endl;
}