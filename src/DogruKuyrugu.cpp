/** 
* @file DogruKuyrugu.cpp
* @description DogruKuyrugu adında bir kuyruk oluşturma ve kuyruğa ekleme gibi işlemler yapılıyor.
* @course 2.Öğretim B grubu
* @assignment 2
* @date 23.12.2021
* @author Serdar Arıcı serdar.arici1@ogr.sakarya.edu.tr
*/
#include "DogruKuyrugu.hpp"
#include "DosyaOku.hpp"
#include <iostream>
#include <math.h>

using namespace std;

DogruKuyrugu::DogruKuyrugu(){
    ilk=son=0;
}

DogruKuyrugu::~DogruKuyrugu(){
    while(ilk!=0){
        Dugum* gec = ilk;
        ilk =ilk->sonraki;
        delete gec;
    }
}

void DogruKuyrugu::ekle(int oncelik, int x, int y, int z){
    if(ilk==0){
        ilk=new Dugum(oncelik,x,y,z);
        toplamUzunluk = 0;
        son=ilk;
    }
    else{
        Dugum* yeni = new Dugum(oncelik,x,y,z);
        yeni->onceki = son;
        son->sonraki = yeni;
        son = yeni;
        toplamUzunluk +=sqrt(pow(abs(x-yeni->onceki->x),2)+pow(abs(y-yeni->onceki->y),2)+pow(abs(z-yeni->onceki->z),2));
    }
  //  cout<<x<<" "<< toplamUzunluk<<endl;
}

Dugum* DogruKuyrugu::enYakinGetir(){
    
    Dugum* kontrol = ilk;
    Dugum* enYakin = ilk;
    for(;;)
    {
        if (kontrol->sonraki == 0)
        {
        return enYakin;
        }
       // cout<<".."<<kontrol->sonraki->oncelik<<" kontrol"<<endl;
      //  cout<<".."<<enYakin->oncelik<<" enyakın"<<endl;
        if (kontrol->sonraki->oncelik < enYakin->oncelik)
                enYakin = kontrol->sonraki;
        kontrol = kontrol->sonraki;
      //  cout<<".."<<enYakin->oncelik<<" yeni enyakın"<<endl;
    }
    
}
void DogruKuyrugu::dugumSil(Dugum* silinecekDugum){
    if (ilk == silinecekDugum)
    {
        if (ilk == son)
            {
                ilk== NULL;
                son == NULL;
            }
            else
            {
                ilk = silinecekDugum->sonraki;
                silinecekDugum->sonraki->onceki =0;
            }
    }
    else if (son == silinecekDugum)
    {
        son = silinecekDugum->onceki;
        silinecekDugum->onceki->sonraki=0;
    }
    else {
        silinecekDugum->onceki->sonraki =silinecekDugum->sonraki;
        silinecekDugum->sonraki->onceki = silinecekDugum->onceki;
    }
    silinecekDugum->~Dugum();
}

int DogruKuyrugu::orjineUzaklik(int x,int y, int z){
    int sonuc;
    sonuc = sqrt((x*x)+(y*y)+(z*z));
    return sonuc; 
}
