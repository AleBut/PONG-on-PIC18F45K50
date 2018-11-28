#include <xc.h>

#include "potentiometer.h"
#include "glcd.h"
#include "gameSystem.h"
#include "gameGraphique.h"
#include "config.h"

void initialiseGame()
{
    // Initialize potentiometer
    pot_Init();
    
    // Initialize LCD screen
    glcd_Init(GLCD_ON);
    
    // Clearing screen and plotting walls
    tracerMur();
}

int rebondLargeur(int yBall, int dy)
{
    if( (yBall+DIAMETRE_BALLE+dy > HAUTEUR-LARGEUR_TRAIT) || (yBall+dy < LARGEUR_TRAIT) )
        return 1;
    else
        return 0;
}

int rebondBarre(int xBall, int yBall, int dx, int yBar, int yBarOppo)
{
    for(int i=yBall; i<yBall + DIAMETRE_BALLE; i++)
    {
        for(int j=yBar; j<yBar + HAUTEUR_BARRE; j++)
        {
            if(i == j)
                if(xBall+DIAMETRE_BALLE+dx > LARGEUR-DELTA-LARGEUR_BARRE)
                    return 1;

        }
        for(int j=yBarOppo; j<yBarOppo + HAUTEUR_BARRE; j++)
        {
            if(i == j)
                if(xBall+dx < DELTA+LARGEUR_BARRE)
                    return 1;     
        }
     
    }
    return 0;
  
}

int pointMarque(int xBall)
{
    if(xBall+DIAMETRE_BALLE > LARGEUR-DELTA-LARGEUR_BARRE)
        return -1; // Ennemi marque
    else if(xBall < DELTA+LARGEUR_BARRE)
        return 1; // je marque
    else
        return 0;
}

int positionBarreJoueur()
{
    int y = getPotValue()*(HAUTEUR-2*LARGEUR_TRAIT-HAUTEUR_BARRE);
    y /= 100;
    y += LARGEUR_TRAIT;
    
    return y;
}

int positionBarreEnnemie(int yBarOppo, int yBall)
{
    int yBallIdeal = yBall + DIAMETRE_BALLE/2 - HAUTEUR_BARRE/2;
    
    if(yBallIdeal > yBarOppo)
        yBarOppo++;
    if(yBallIdeal < yBarOppo)
        yBarOppo--;
            
    if(yBarOppo < LARGEUR_TRAIT)
        yBarOppo = LARGEUR_TRAIT;

    if(yBarOppo + HAUTEUR_BARRE > HAUTEUR - LARGEUR_TRAIT)
        yBarOppo = HAUTEUR - LARGEUR_TRAIT - HAUTEUR_BARRE;
    
    return yBarOppo;
}