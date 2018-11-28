#ifndef GAMEGRAPHIQUE_H_INCLUDED
#define GAMEGRAPHIQUE_H_INCLUDED

void tracerBarre(int x, int y, int color);

void tracerBalle(int x, int y, int color);

void tracerMur();

void tracerNouveauScore(int nouveauMarquant, int point);

void messageGagnant(int opponentScore, int score);


#endif