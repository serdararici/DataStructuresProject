/** 
* @file DugumAVL.cpp
* @description AVL ağacı oluşturmak için kullanılan bir düğüm sınıfı oluşturuluyor. 
* @course 2.Öğretim B grubu
* @assignment 2
* @date 25.12.2021
* @author Serdar Arıcı serdar.arici1@ogr.sakarya.edu.tr
*/
#include "DugumAVL.hpp"

DugumAVL::DugumAVL(DogruKuyrugu *vr,DugumAVL *sl=NULL,DugumAVL *sg=NULL)
{
    veri = vr;
    sol = sl;
    sag = sg;
    yukseklik = 0;

}   
