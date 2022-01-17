#ifndef AVL_HPP
#define AVL_HPP

#include "DugumAVL.hpp"
#include <iostream>
using namespace std;


class AVL{
    private:
        DugumAVL *kok;
        void postorder(DugumAVL *altDugum);

    public:
        AVL();
        void Ekle(DugumAVL *yeni);
        void AraVeEkle(DugumAVL *ustDugum,DugumAVL *kontrolEdilen,DugumAVL *yeni);
        void SagaKaydir(DugumAVL *ustDugum,DugumAVL *dugum);
        void SolaKaydir(DugumAVL *ustDugum,DugumAVL *dugum);
        bool Bosmu();
        void yazdir();
        int Yukseklik;
        int YukseklikHesapla(DugumAVL *dugum);
        void Temizle();
        int sayac = 0;
      //  ~AVL();

       
};




#endif