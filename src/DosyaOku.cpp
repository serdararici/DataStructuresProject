/** 
* @file DosyaOku.cpp
* @description Noktalar.txt dosyası satır satır okunuyor. Belirlenen noktalar kuyruğa ekleniyor. Kuyruk nesneleri de ağaca ekleniyor ve ağacın ekrana yazdırılma işlemi yapılıyor.  
* @course 2.Öğretim B grubu
* @assignment 2
* @date 25.12.2021
* @author Serdar Arıcı serdar.arici1@ogr.sakarya.edu.tr
*/
#include "DosyaOku.hpp"
#include "DogruKuyrugu.hpp"
#include "DugumAVL.hpp"
#include "AVL.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <math.h>

void dosyaOku(){
    ifstream dosya;
    
    AVL AVLAGACI;
    string satir;
    //string nokta;

    dosya.open("Noktalar.txt", ios::in);  //dosyayi okuma modunda acıyor.
    if (dosya.is_open())
    {
        //dosya>>nokta;

        while (getline (dosya, satir))
        {
            DogruKuyrugu* kuyruk = new DogruKuyrugu;
            int koordinatlar [3] = {-1,-1,-1};
            int koordinatKontrol = 0;
         //   cout<<satir<<endl;
            int bosluk = 0;
            int boslukSiradaki = 0;
            
            // Koordinatlar arası birden fazla boşluk varsa, boşluk sayısını 1e indiriyor.
            int boslukAyikla;
            for (;;)
            {
                int ikiBoslukKontrol = satir.find("  ");
                if(ikiBoslukKontrol > 0)
                    satir = satir.replace(ikiBoslukKontrol, 2, " ");
                else break;
            }

            // Satır sonunda boşluk varsa silmek için.
            if (satir.length() > 1)
            if (satir[satir.length()-1] == ' ')
                satir = satir.replace(satir.length()-1,1,"");

            //    cout<<satir<<endl;
            for (;;)
            {
                boslukSiradaki = satir.find(" ",bosluk+1);

                // Satırdaki koordinat sayısı bittiğinde doğru kuyruğunu AVL ağacına eklemek ve sıradaki satıra geçiyor.
                if (bosluk >= satir.length() || bosluk <0 )
                { 
                    DugumAVL* yeniDugumAVL = new DugumAVL(kuyruk,NULL,NULL);
                   // cout<<&yeniDugumAVL<<endl;
                    AVLAGACI.Ekle(yeniDugumAVL);
                    break; 
                }
                

                string koordinat = satir.substr(bosluk,boslukSiradaki-bosluk);
                bosluk= boslukSiradaki;
                if (koordinat.find(" ",0) != -1) koordinat = koordinat.substr(1,koordinat.length()-1);
                //cout<<koordinat<<","<<bosluk<<",,"<<boslukSiradaki<<endl;

                koordinatlar[koordinatKontrol] = stoi(koordinat);
                koordinatKontrol++;
                if (koordinatKontrol ==3)
                {   
                    int uzunluk = koordinatlar[0]*koordinatlar[0]+koordinatlar[1]*koordinatlar[1]+koordinatlar[2]*koordinatlar[2];
                 //   cout<<uzunluk<<"=";
                    uzunluk = sqrt(uzunluk);
                 //   cout<<koordinatlar[0]<<","<<koordinatlar[1]<<","<<koordinatlar[2]<<"="<<uzunluk<<endl;
                    kuyruk->ekle(uzunluk,koordinatlar[0],koordinatlar[1],koordinatlar[2]);
                    koordinatKontrol =0;
                }
            }
            
        }
        
    }
    
    AVLAGACI.yazdir();
    
    dosya.close();
}