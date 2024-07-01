#ifndef MACIERZ_HH_INCLUDED
#define MACIERZ_HH_INCLUDED



#endif // MACIERZ_HH_INCLUDED
#ifndef Macierz_HH
#define Macierz_HH

#include <iostream>
#include "Wektor.hh"

template<class sTyp, int sWymiar>
class Macierz
{
  std::array<Wektor<sTyp,sWymiar>,sWymiar> Mac;
 sTyp det;
public:
   //sTyp get_det() const{return det;}
   int get_wymiar(){
       return Mac.size(); //zwroc wielkosci mac z array
   }
  Wektor<sTyp,sWymiar> operator[](int i) const;
  Wektor<sTyp,sWymiar> &operator[](int i);
  Wektor<sTyp,sWymiar> operator*(Wektor<sTyp,sWymiar> wek);
  Macierz<sTyp,sWymiar> operator *(Macierz<sTyp,sWymiar> mac); //mnoz mac na mac
  sTyp Gauss();
};

template<class sTyp, int sWymiar>
Wektor<sTyp,sWymiar> Macierz<sTyp,sWymiar>::operator[](int i) const
{
    return Mac[i];
}
template<class sTyp, int sWymiar>
Wektor<sTyp,sWymiar> &Macierz<sTyp,sWymiar>::operator[](int i)
{
    return Mac[i];
}
template<class sTyp, int sWymiar>
std::istream &operator>>(std::istream &Strm, Macierz<sTyp,sWymiar> &Mac)
{
    for (unsigned int i = 0; i < sWymiar; ++i)
    {
        Strm >> Mac[i];
        if (Strm.fail())
            return Strm;
    }
    return Strm;
}
template<class sTyp, int sWymiar>
std::ostream &operator<<(std::ostream &Strm, const Macierz<sTyp,sWymiar> &Mac)
{
    for (unsigned int i = 0; i < sWymiar; ++i)
    {
        Strm << Mac[i] << std::endl;
    }
    return Strm;
}
template<class sTyp, int sWymiar>
sTyp Macierz<sTyp,sWymiar>::Gauss()
{
    Macierz<sTyp,sWymiar> Mac = *this; // Macierz<sTyp,sWymiar> robi swoja kopije
    double a = 1;           // odpowiada za znak wyznacz
    sTyp skl;          // wspolczynik mnozenia
    Wektor<sTyp,sWymiar> w;            // wektot po wymnorzeniu przez skl

    for (unsigned int i = 0; i < sWymiar; ++i) //przechod po wiersz
    {
        for (unsigned int j = 0; j < sWymiar; ++j)//przechod po kol
        {
            if (Mac[i][i] == 0)
            {
                for (unsigned int k = i + 1; k < sWymiar; ++k) // wierszy
                {
                    if (Mac[k][j] != 0) //jezeli katy wiersz jtakolumna nie jest 0
                    {
                        std::swap(Mac[i], Mac[k]);  //przestawiamy
                        a = a * -1;
                    }
                }
            }
            for (unsigned int k = i + 1; k < sWymiar; ++k)//przechod na nast wiersz
            {
                skl = Mac[k][i] / Mac[i][i]; //skl wspolcz przez kt mnoz, mac[k][i] -to co nizej diagonal
                w = Mac[i] * skl; // wymnozony wiersz przez skalar
                Mac[k] = Mac[k] - w;//odejm wymnoz wiersz od katego
            }
        }
    }
    sTyp Iloczyn = {1.0};//zm przez kt wymnoz cala przekatna //w {} bo przypis z 2 typ
    for (unsigned int i = 0; i < sWymiar; ++i)
    {
        Iloczyn = Iloczyn * Mac[i][i];
    }
    det = Iloczyn *a;
    return det;
}
template<class sTyp, int sWymiar>
Wektor<sTyp,sWymiar> Macierz<sTyp,sWymiar>::operator*(Wektor<sTyp,sWymiar> wek)
{
    Wektor<sTyp,sWymiar> wynik;
    for (unsigned int i = 0; i < sWymiar; ++i)
    {
        for (unsigned int j = 0; j < sWymiar; ++j)
    {
        wynik[i]=  wynik[i]+ Mac[j][i]*wek[j];//wymnoz dany wiersz przez elem wektora i sumuj
    }
    }
    return wynik;
}
template<class sTyp, int sWymiar>
Macierz<sTyp,sWymiar> Macierz<sTyp,sWymiar>::operator *(Macierz<sTyp,sWymiar> mac){
    Macierz<sTyp,sWymiar> wynik;
    if(mac.get_wymiar()==get_wymiar()){ //sprawdz czy mozna wymnoz mac przez mac
        for(unsigned int i=0;i<sWymiar;++i ){//wier
           for(unsigned int k=0;k<sWymiar;++k)//dodatk przejscie po kol albo po wiersz
           {
            for(unsigned int j=0; j<sWymiar;++j){ // kol
                wynik[i][k]=Mac[k][j]*mac[j][i];         //Mac macierz kt mnoz , mac macierz na kt mnoz
            }
           }
        }
    }
return wynik;
}
#endif
