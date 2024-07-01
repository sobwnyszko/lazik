#ifndef Wektor_HH
#define Wektor_HH
#include <iostream>
#include<array>
#include<cmath>
using namespace std;

template < class sTyp, int sWymiar> // zmiena ktora miesci typ zmiennych
class Wektor {
  private:
std::array<sTyp, sWymiar> tab;

  public:
 Wektor();
  Wektor (sTyp a, sTyp b, sTyp c);

 sTyp operator [] (unsigned int i) const;  //cala funkcja stala
 sTyp& operator [] (unsigned int i); //zwracamy zmienna
 Wektor<sTyp,sWymiar> operator +(Wektor<sTyp,sWymiar> skl)const;
 Wektor<sTyp,sWymiar> operator -(Wektor<sTyp,sWymiar> skl)const;
 sTyp operator *(Wektor<sTyp,sWymiar> skl)const; //mnozenie scalarne Wektor<sTyp,sWymiar>ow
 Wektor<sTyp,sWymiar> operator *(sTyp skl)const; //mnozenie Wektor<sTyp,sWymiar>a przez skalar
 Wektor<sTyp,sWymiar> operator /(sTyp skl)const; //dzielenie Wektor<sTyp,sWymiar>a przez skalar
double modul() const;
};




template < class sTyp, int sWymiar>
sTyp Wektor<sTyp,sWymiar>::operator[](unsigned int i) const
{
    return tab[i];
}
template < class sTyp, int sWymiar>
sTyp &Wektor<sTyp,sWymiar>::operator[](unsigned int i)
{
    return tab[i];
}
template < class sTyp, int sWymiar>
Wektor<sTyp,sWymiar> Wektor<sTyp,sWymiar>::operator+(Wektor<sTyp,sWymiar> skl) const
{
    Wektor<sTyp,sWymiar> wynik;
    for (unsigned int i = 0; i < sWymiar; ++i)
    {
        wynik[i] = tab[i] + skl[i];
    }
    return wynik;
}
template < class sTyp, int sWymiar>
Wektor<sTyp,sWymiar> Wektor<sTyp,sWymiar>::operator-(Wektor<sTyp,sWymiar> skl) const
{
    Wektor<sTyp,sWymiar> wynik;
    for (unsigned int i = 0; i < sWymiar; ++i)
    {
        wynik[i] = tab[i] - skl[i];
    }
    return wynik;
}
template < class sTyp, int sWymiar>
sTyp Wektor<sTyp,sWymiar>::operator*(Wektor<sTyp,sWymiar> skl) const
{
    sTyp wynik = 0;
    for (unsigned int i = 0; i < sWymiar; ++i)
    {
        wynik = wynik + (tab[i] * skl[i]);
    }
    return wynik;
}
template < class sTyp, int sWymiar>
Wektor<sTyp,sWymiar> Wektor<sTyp,sWymiar>::operator*(sTyp skl) const
{
    Wektor<sTyp,sWymiar> wynik;
    for (unsigned int i = 0; i < sWymiar; ++i)
    {
        wynik[i] = tab[i] * skl;
    }
    return wynik;
}
template < class sTyp, int sWymiar>
Wektor<sTyp,sWymiar> Wektor<sTyp,sWymiar>::operator/(sTyp skl) const
{
    Wektor<sTyp,sWymiar> wynik;
    for (unsigned int i = 0; i < sWymiar; ++i)
    {
        wynik[i] = tab[i] / skl;
    }
    return wynik;
}
template < class sTyp, int sWymiar>
std::istream &operator>>(std::istream &Strm, Wektor<sTyp,sWymiar> &Wek)
{
    for (unsigned int i = 0; i < sWymiar; ++i)
    {
        Strm >> Wek[i];
    }
    return Strm;
}
template < class sTyp, int sWymiar>
std::ostream &operator<<(std::ostream &Strm, const Wektor<sTyp,sWymiar> &Wek)
{
    for (unsigned int i = 0; i < sWymiar; ++i)
    {
        Strm << Wek[i] << " ";
    }
    return Strm;
}
template < class sTyp, int sWymiar>
Wektor<sTyp,sWymiar>::Wektor()
{
    for (unsigned int i = 0; i < sWymiar; ++i)
    {
        tab[i] = {0};
    }
}
template < class sTyp, int sWymiar>
Wektor<sTyp,sWymiar>::Wektor(sTyp a, sTyp b, sTyp c) : tab{a, b, c} // lista inicializ przypis do zm tab wart a,b,c
{
}
template < class sTyp, int sWymiar>
double Wektor<sTyp,sWymiar>::modul() const
{
    double wynik = 0;
    for (unsigned int i = 0; i < sWymiar; ++i)
    {
        wynik = wynik + (abs(tab[i]) * abs(tab[i]));
    }
    wynik = sqrt(wynik);
    return wynik;
}

#endif
