#include "Jeu.h"
#include "Bloc.h"
#include "Tour.h"
#include <iostream>
using namespace std;
Jeu::Jeu()
{
}

void Jeu::deplacerPion(Tour* tourDepart, Tour* tourDestination)
{
	tourDepart->deplacer(tourDestination);
	cout << "deplace " << tourDepart->getNumeroTour() << " vers " << tourDestination->getNumeroTour();
}
