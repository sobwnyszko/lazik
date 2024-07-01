#include <iostream>
#include <fstream>
#include "ObiektGeom.hh"



using namespace std;

ObiektGeom::ObiektGeom( const char*  sNazwaPliku_BrylaWzorcowa, const char*  sNazwaObiektu,int  KolorID):_NazwaPliku_BrylaWzorcowa(sNazwaPliku_BrylaWzorcowa), _KolorID(KolorID)
{
  _NazwaObiektu = sNazwaObiektu;
  _NazwaPliku_BrylaRysowana = NAZWA_KARTOTEKI_PLIKOW_DO_RYSOWANIA;
  _NazwaPliku_BrylaRysowana += "/";
  _NazwaPliku_BrylaRysowana += sNazwaObiektu;
  _NazwaPliku_BrylaRysowana += ".dat";
}



bool ObiektGeom::Przelicz_i_Zapisz_Wierzcholki()
{
  ifstream  StrmWe(_NazwaPliku_BrylaWzorcowa);
  ofstream  StrmWy(_NazwaPliku_BrylaRysowana);

  if (!(StrmWe.is_open() && StrmWy.is_open())) {
    cerr << endl << "Nie mozna otworzyc jednego z plikow:" << endl
	 << "    " << _NazwaPliku_BrylaWzorcowa << endl
	 << "    " << _NazwaPliku_BrylaRysowana << endl
	 << endl;
    return false;
  }

  Wektor3D dane;
  int Indeks_Wiersza = 0;

  StrmWe >> dane;

  if (StrmWe.fail())return false;

  do {
    dane = dane*20+get_przesuniecie();///skalowanie czy mozna zrobic z dodatkowym mnozeniem wektor razy wektor ale gdzie kazdy element wektora mnozy sie przez sibie np. [a1,a2,a3]*[b1,b2,b3]=[a1*b1,a2*b2,a3*b3]

    StrmWy << dane << endl;
    ++Indeks_Wiersza;

    if (Indeks_Wiersza >= 4) {
      StrmWy << endl;
      Indeks_Wiersza = 0;
    }

    StrmWe >> dane;

  } while (!StrmWe.fail());

  if (!StrmWe.eof()) return false;

  return Indeks_Wiersza == 0 && !StrmWy.fail();
}
