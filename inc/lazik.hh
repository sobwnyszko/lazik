#include<iostream>
#include"ObiektGeom.hh"
 #include <unistd.h>
class Lazik : public ObiektGeom
{
    double KatOrientacji;
    double szybkosc;
    double OdlegloscDoPrzyjechania;
    public:
    double get_KatOrientacji()
    {
        return  KatOrientacji;
    }
    double get_szybkosc(){
        return szybkosc;

    }
    double get_OdlegloscDoPrzyjechania()
    {
        return  OdlegloscDoPrzyjechania;
    }
    double &set_KatOrientacji()
    {
        return  KatOrientacji;
    }
    double &set_szybkosc(){
        return szybkosc;

    }
    double &set_OdlegloscDoPrzyjechania()
    {
        return  OdlegloscDoPrzyjechania;
    }


  Lazik(const char *sNazwaPliku_BrylaWzorcowa, const char *sNazwaObiektu, int KolorID):ObiektGeom(sNazwaPliku_BrylaWzorcowa,sNazwaObiektu,KolorID)
  {

  }
  void Przesun(){
      Wektor3D wektor_predkosci;
     wektor_predkosci[0]=get_szybkosc();

        translacja(wektor_predkosci);
        Przelicz_i_Zapisz_Wierzcholki();
        usleep(10000);

  }
};
