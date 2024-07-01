#ifndef OBIEKTGEOM_HH
#define OBIEKTGEOM_HH

#include <string>
#include "UklWspl.hh"
#include "MacRot.hh"
#include "wektor3d.hh"

#define NAZWA_KARTOTEKI_PLIKOW_DO_RYSOWANIA "pliki_do_rysowania"

class ObiektGeom : public UklWspl
{
  Wektor3D skala;
  std::string _NazwaPliku_BrylaWzorcowa;
  std::string _NazwaPliku_BrylaRysowana;
  std::string _NazwaObiektu;
  int _KolorID;

public:
  ObiektGeom(const char *sNazwaPliku_BrylaWzorcowa, const char *sNazwaObiektu, int KolorID);

  int WezKolorID() const { return _KolorID; }

  const std::string &WezNazweObiektu() const { return _NazwaObiektu; }

  const std::string &WezNazwePliku_BrylaRysowana() const
  {
    return _NazwaPliku_BrylaRysowana;
  }

  bool Przelicz_i_Zapisz_Wierzcholki();
};

#endif
