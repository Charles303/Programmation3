#include <iostream>
#include "Tour.h"
#include "Bloc.h"
#include "Jeu.h"

using namespace std;

int main()
{
    Jeu jeu;
    //initialisation tours et blocs
    const int grandeurTour = 3;
    Tour tourArray[grandeurTour];

    Tour tourUn(1);
    tourArray[0] = tourUn;
    Tour tourDeux(2);
    tourArray[1] = tourDeux;
    Tour tourTrois(3);
    tourArray[2] = tourTrois;

    Bloc blocUn("#####");
    Bloc blocDeux("###");
    Bloc blocTrois("#");
    //mettre blocs dans tour 1
    tourArray[0].push(&blocUn);
    tourArray[0].push(&blocDeux);
    tourArray[0].push(&blocTrois);
    tourArray[0].afficheTour();
    int nombreDeBloc = tourArray->getGrandeur();

    int choixDepart;
    int choixDestination;
    bool tourFait = 0;
    bool jeuTermine = 0;
    while (jeuTermine == 0)
    {
        cout << "choix tour depart?\n";
        cin >> choixDepart;
        cout << "choix vers tour ?\n";
        cin >> choixDestination;
        //prend top tour depart dans variable temporaire, enlève le top en question et met la variable temporaire dans le
        //tableau de la tour choisi
        Bloc* temp = tourArray[choixDepart - 1].getTop();
        if (!temp)
        {
            cout << "pas de bloc dans cette tour \n";
        }
        string texteDepart = temp->getText();
        int grandeurTextDepart = (texteDepart).length();

        Bloc* temp2 = tourArray[choixDestination - 1].getTop();
        string texteDestination;
        int grandeurTextDestination = 7;

        if (temp2)
        {
            texteDestination = temp2->getText();
            grandeurTextDestination = (texteDestination).length();
        }
        if (grandeurTextDepart > grandeurTextDestination)
        {
            cout << "mouvement illegal \n";
        }
        else
        {
            tourArray[choixDepart - 1].pop();
            tourArray[choixDestination - 1].push(temp);

            for (size_t i = 0; i < (sizeof(tourArray) / sizeof(*tourArray)); i++)
            {
                tourArray[i].afficheTour();
                cout << "\n";
            }
        }
        if (tourArray[1].getGrandeur() == nombreDeBloc || tourArray[2].getGrandeur() == nombreDeBloc)
        {
            cout << "Jeu gagne Bravo \n";
            jeuTermine = 1;
        }
    }
}