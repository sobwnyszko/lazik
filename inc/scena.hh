#include<iostream>
#include<list>
#include<memory>
#include"lazik.hh"
class Scena {
std::shared_ptr<Lazik> aktualny_lazik;
std::list<std::shared_ptr<ObiektGeom>> lista_obiektow;
};
