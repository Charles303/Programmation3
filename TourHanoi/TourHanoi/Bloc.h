#ifndef BLOC_H
#define BLOC_H
#include <string>
#include <iostream>
using namespace std;
class Bloc
{
private:
	int m_largeur;
	string m_visual;
	Bloc* m_next;
public:
	Bloc(string text);
	int getLargeur();
	string getText();
	Bloc* getNext();
	void setNext(Bloc* next);
};

#endif