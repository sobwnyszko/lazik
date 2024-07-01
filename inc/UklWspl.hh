#include "wektor3d.hh"
#include "MacRot.hh"
class UklWspl
{
private:
    UklWspl *koordynata;
    MacRot orientacja;
    Wektor3D przesuniecie;

public:
void rotacja(MacRot nowa){
    orientacja=nowa*orientacja;//mnoz macrot o 1 stopien *macrot o 2 stop
}
void translacja(Wektor3D nowy){
    przesuniecie=przesuniecie+nowy;//przesun wektora o wektor
}
MacRot get_orientacja() const{
    return orientacja;
}
Wektor3D get_przesuniecie()const{
    return przesuniecie;
}
};
