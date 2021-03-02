#include "Bloc.h"

Bloc::Bloc(string text) : m_visual{ text }, m_next{ nullptr }, m_largeur{ 0 }
{
}

int Bloc::getLargeur()
{
	return m_largeur;
}

string Bloc::getText()
{
	return m_visual;
}

Bloc* Bloc::getNext()
{
	return m_next;
}

void Bloc::setNext(Bloc* next)
{
	m_next = next;
}
