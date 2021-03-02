#ifndef TOUR_H
#define TOUR_H

#include "Bloc.h"
class Tour
{
private:
	Bloc* m_top;
	int m_grandeur;
	int m_numeroTour;
public:
	Tour();
	Tour(int);
	~Tour();
	Bloc* getTop();
	void setTop(Bloc*);
	int getGrandeur();
	int getNumeroTour();
	bool tourVide();
	void push(Bloc*);
	void pop();
	void deplacer(Tour* deplacementVers);
	void afficheTour();
	bool estEnpiler();
};

#endif