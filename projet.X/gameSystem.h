#ifndef GAMESYSTEM_H_INCLUDED
#define GAMESYSTEM_H_INCLUDED

void initialiseGame();

int rebondLargeur(int yBall, int dy);

int rebondBarre(int xBall, int yBall, int dx, int yBar, int yBarOppo);

int pointMarque(int xBall);

int positionBarreJoueur();

int positionBarreEnnemie(int yBarOppo, int yBall);

#endif