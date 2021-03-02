#include <iostream>
#include "Tour.h"
using namespace std;
Tour::Tour()
{
}
Tour::Tour(int numeroTour) : m_grandeur{ 0 }, m_top{ nullptr }, m_numeroTour{numeroTour}
{
}

Tour::~Tour()
{
}

Bloc* Tour::getTop()
{
	return m_top;
}

void Tour::setTop(Bloc* blocTop)
{
	m_top = blocTop;
}

int Tour::getGrandeur()
{
	return m_grandeur;
}

int Tour::getNumeroTour()
{
	return m_numeroTour;
}

bool Tour::tourVide()
{
	if (m_grandeur == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Tour::push(Bloc* bloc)
{

	bloc->setNext(m_top);
	m_top = bloc;

	m_grandeur++;

}

void Tour::pop()
{
	if (tourVide() == true)
	{
		return;
	}
	Bloc* temporaire{ m_top };
	m_top = m_top->getNext();
	temporaire->setNext(nullptr);

	m_grandeur--;
}

void Tour::deplacer(Tour* deplacementVers)
{
	deplacementVers->push(m_top);
	pop();
}

void Tour::afficheTour()
{
	Bloc* bloc{ m_top };
	while (!(bloc == nullptr))
	{
		string largeurBloc = bloc->getText();
		cout << largeurBloc << "\n";
		bloc = bloc->getNext();
	}
}

bool Tour::estEnpiler()
{
	return false;
}
