/** 
* @file AVL.cpp
* @description AVL ağacı olusturuluyor. Ekleme, yükseklik hesaplama ve dolaşma gibi işlemler yapılıyor. 
* @course 2.Öğretim B grubu
* @assignment 2
* @date 25.12.2021
* @author Serdar Arıcı serdar.arici1@ogr.sakarya.edu.tr
*/

#include "AVL.hpp"
#include "math.h"
#include <iostream>
#include "DugumAVL.hpp"

using namespace std;

AVL::AVL(){
    
    kok = NULL;
    Yukseklik = 0;
}
bool AVL::Bosmu(){
    return true;
}
void AVL::Ekle(DugumAVL *yeni){
    if (kok == NULL)
    {
        kok=yeni;
        yeni->sag = NULL;
        yeni->sol = NULL;
        yeni->yukseklik =0;
    }
    else
    {
        //cout<<yeni->veri->toplamUzunluk<<endl;
        AraVeEkle(NULL,kok,yeni);
    //    kok->yukseklik = YukseklikHesapla(kok);
     //   AgacKaydirma(NULL,kok);
      //  yazdir();
    }

}
void AVL::AraVeEkle(DugumAVL *ustDugum,DugumAVL *kontrolEdilen,DugumAVL *yeni)
{
    if (kontrolEdilen->veri->toplamUzunluk >= yeni->veri->toplamUzunluk)
    {
        if(kontrolEdilen->sol == NULL)
        {
            kontrolEdilen->sol = yeni;
            yeni->yukseklik = 0;
        }
        else
        {
            AraVeEkle(kontrolEdilen,kontrolEdilen->sol,yeni);
        }
    }
    else
    {
        if(kontrolEdilen->sag == NULL)
        {
            kontrolEdilen->sag = yeni;
            yeni->yukseklik = 0;
        }
        else
        {
            AraVeEkle(kontrolEdilen,kontrolEdilen->sag,yeni);
        }
    }

    YukseklikHesapla(kontrolEdilen);

    int sagYukseklik = -1;
    int solYukseklik = -1;
    int altSolYukseklik = -1;
    int altSagYukseklik = -1;
    if (kontrolEdilen->sag != NULL) sagYukseklik = kontrolEdilen->sag->yukseklik;
    if (kontrolEdilen->sol != NULL) solYukseklik = kontrolEdilen->sol->yukseklik;


    if (sagYukseklik - solYukseklik == 2)
    {
        if (kontrolEdilen->sag->sag != NULL) altSagYukseklik = kontrolEdilen->sag->sag->yukseklik;
        if (kontrolEdilen->sag->sol != NULL) altSolYukseklik = kontrolEdilen->sag->sol->yukseklik;
        if (altSolYukseklik > altSagYukseklik)
                SagaKaydir(kontrolEdilen,kontrolEdilen->sag);
        SolaKaydir(ustDugum,kontrolEdilen);
        
    }
    if (solYukseklik - sagYukseklik == 2)
    {
        if (kontrolEdilen->sol->sag != NULL) altSagYukseklik = kontrolEdilen->sol->sag->yukseklik;
        if (kontrolEdilen->sol->sol != NULL) altSolYukseklik = kontrolEdilen->sol->sol->yukseklik;
        if (altSagYukseklik > altSolYukseklik)
            SolaKaydir(kontrolEdilen,kontrolEdilen->sol);
        SagaKaydir(ustDugum,kontrolEdilen);
    }
    
    
}

int AVL::YukseklikHesapla(DugumAVL *dugumPtr)
{
    if (dugumPtr->sag == NULL&& dugumPtr->sol == NULL)
    {
        dugumPtr->yukseklik = 0;
        return dugumPtr->yukseklik;
    }
        else if (dugumPtr->sag != NULL && dugumPtr->sol == NULL)
        {
            dugumPtr->yukseklik = YukseklikHesapla(dugumPtr->sag)+1;
            return dugumPtr->yukseklik;
        }
        else if (dugumPtr->sag == NULL && dugumPtr->sol != NULL)
        {
            dugumPtr->yukseklik = YukseklikHesapla(dugumPtr->sol)+1;
            return dugumPtr->yukseklik;
        }
        else
        {   
            dugumPtr->yukseklik = max(YukseklikHesapla(dugumPtr->sol), YukseklikHesapla(dugumPtr->sag))+1;
            return dugumPtr->yukseklik;
        }
}

void AVL::SagaKaydir(DugumAVL *ustDugum,DugumAVL *dugum)
{
    DugumAVL *gecici;
    gecici = dugum->sol->sag;
    if (ustDugum == NULL)
    {
       /* cout<<"Sag 1 - U NULL - d "<<dugum->veri->toplamUzunluk;
        if (dugum->sag != NULL) cout<<" - d sag "<<dugum->sag->veri->toplamUzunluk;
        if (dugum->sol != NULL) cout<<" - d sol "<<dugum->sol->veri->toplamUzunluk;
        cout<<endl;*/
        kok = dugum->sol;
        kok->sag = dugum;
        dugum->sol = gecici;
        YukseklikHesapla(kok->sag);
        YukseklikHesapla(kok);
    }
    else if (dugum == ustDugum->sag)
    {
      /*  cout<<"Sag 2 - U "<<ustDugum->veri->toplamUzunluk<<" - d "<<dugum->veri->toplamUzunluk;
        if (dugum->sag != NULL) cout<<" - d sag "<<dugum->sag->veri->toplamUzunluk;
        if (dugum->sol != NULL) cout<<" - d sol "<<dugum->sol->veri->toplamUzunluk;
        cout<<endl;*/
        ustDugum->sag = dugum->sol;
        ustDugum->sag->sag = dugum;
        dugum->sol = gecici;
        YukseklikHesapla(ustDugum->sag->sag);
        YukseklikHesapla(ustDugum->sag);
    }
    else
    {
     /*   cout<<"Sag 3 - U "<<ustDugum->veri->toplamUzunluk<<" - d "<<dugum->veri->toplamUzunluk;
        if (dugum->sag != NULL) cout<<" - d sag "<<dugum->sag->veri->toplamUzunluk;
        if (dugum->sol != NULL) cout<<" - d sol "<<dugum->sol->veri->toplamUzunluk;
        cout<<endl;*/
        ustDugum->sol = dugum->sol;
        ustDugum->sol->sag = dugum;
        dugum->sol = gecici;
        YukseklikHesapla(ustDugum->sol->sag);
        YukseklikHesapla(ustDugum->sol);
    }
}

void AVL::SolaKaydir(DugumAVL *ustDugum,DugumAVL *dugum)
{
    DugumAVL *gecici;
    gecici = dugum->sag->sol;
    if (ustDugum == NULL)
    {
      /*  cout<<"Sol 1 - U NULL - d "<<dugum->veri->toplamUzunluk;
        if (dugum->sag != NULL) cout<<" - d sag "<<dugum->sag->veri->toplamUzunluk;
        if (dugum->sol != NULL) cout<<" - d sol "<<dugum->sol->veri->toplamUzunluk;
        cout<<endl;*/
        kok = dugum->sag;
        kok->sol = dugum;
        dugum->sag = gecici;
        kok->sol->yukseklik = YukseklikHesapla(kok->sol);
        YukseklikHesapla(kok);
    }
    else if (dugum == ustDugum->sag)
    {
       /* cout<<"Sol 2 - U "<<ustDugum->veri->toplamUzunluk<<" - d "<<dugum->veri->toplamUzunluk;
        if (dugum->sag != NULL) cout<<" - d sag "<<dugum->sag->veri->toplamUzunluk;
        if (dugum->sol != NULL) cout<<" - d sol "<<dugum->sol->veri->toplamUzunluk;
        cout<<endl;*/
        ustDugum->sag = dugum->sag;
        ustDugum->sag->sol = dugum;
        dugum->sag = gecici;
        YukseklikHesapla(ustDugum->sag->sol);
        YukseklikHesapla(ustDugum->sag);
    }
    else
    {
     /*   cout<<"Sol 3 - U "<<ustDugum->veri->toplamUzunluk<<" - d "<<dugum->veri->toplamUzunluk;
        if (dugum->sag != NULL) cout<<" - d sag "<<dugum->sag->veri->toplamUzunluk;
        if (dugum->sol != NULL) cout<<" - d sol "<<dugum->sol->veri->toplamUzunluk;
        cout<<endl;*/
        ustDugum->sol = dugum->sag;
        ustDugum->sol->sol = dugum;
        dugum->sag = gecici;
        YukseklikHesapla(ustDugum->sol->sol);
        YukseklikHesapla(ustDugum->sol);
    }
}


void AVL::yazdir()
{
    cout<<endl<<endl<<endl;
    cout<<"AVL yukseklik | AVL uzunluk = Orjine uzakliklar"<<endl;
    postorder(kok);
}

void AVL::postorder(DugumAVL *altDugum){
            if(altDugum != NULL){
                postorder(altDugum->sol);
                postorder(altDugum->sag);
                cout<<altDugum->yukseklik<<" | ";
                if (altDugum->veri->toplamUzunluk < 10 ) cout<<" ";
                if (altDugum->veri->toplamUzunluk < 100 ) cout<<" ";
                if (altDugum->veri->toplamUzunluk < 1000 ) cout<<" ";
                cout<<altDugum->veri->toplamUzunluk<< " =  ";
                    
                    for (;;)
                    {
                        int sontur = 0;
                       /* cout<<"("<<
                        altDugum->veri->enYakinGetir()->x<<","<<
                        altDugum->veri->enYakinGetir()->y<<","<<
                        altDugum->veri->enYakinGetir()->z<<") "; */
                    if (altDugum->veri->enYakinGetir()->oncelik < 10 ) cout<<" ";
                    if (altDugum->veri->enYakinGetir()->oncelik < 100 ) cout<<" ";
                    if (altDugum->veri->enYakinGetir()->oncelik < 1000 ) cout<<" ";
                        cout<<altDugum->veri->enYakinGetir()->oncelik<<" ";

                        if (altDugum->veri->enYakinGetir()->onceki == 0 && altDugum->veri->enYakinGetir()->sonraki== 0) sontur++;
                        
                        altDugum->veri->dugumSil(altDugum->veri->enYakinGetir());
                        
                        if (sontur == 1) break;
                       // cout<<" - ";
                    }
            cout<<endl;
            }
        }

