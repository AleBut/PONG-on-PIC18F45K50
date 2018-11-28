#include <xc.h>

#include "gameGraphique.h"
#include "glcd.h"
#include "config.h"


void tracerBarre(int x, int y, int color)
{
    for(int i=x; i<x+LARGEUR_BARRE; i++)
    {
        for(int j=y; j<y+HAUTEUR_BARRE; j++)
         glcd_PlotPixel(i,j,color);
    }
}

void tracerBalle(int x, int y, int color)
{
    for(int i=x; i<x+DIAMETRE_BALLE; i++)
    {
        for(int j=y; j<y+DIAMETRE_BALLE; j++)
            glcd_PlotPixel(i,j,color);
    }
}

void tracerMur()
{
    glcd_FillScreen(0);
    
    for(int i=0; i<LARGEUR; i++)
    {
        for(int j=0; j<LARGEUR_TRAIT; j++)
        {
            glcd_PlotPixel(i,j,'1');
            glcd_PlotPixel(i,HAUTEUR-1-j,'1');
        }
    }

}

void tracerNouveauScore(int nouveauMarquant, int point)
{
    int x;
    int step = (HAUTEUR-2*LARGEUR_TRAIT)/MAX_SCORE;
    
    if(nouveauMarquant == 1) // Je marque
        x = LARGEUR-LARGEUR_TRAIT;
    else // Ennemi marque
        x = 0;
    
    
    for(int i=x; i<x+LARGEUR_TRAIT; i++)
    {
        for(int j=LARGEUR-LARGEUR_TRAIT-point*step+1; j<LARGEUR-LARGEUR_TRAIT-(point-1)*step-1; j++)
            glcd_PlotPixel(i,j,1);
    }
         
} 

void messageGagnant(int opponentScore, int score)
{
    glcd_SetCursor(40, 4);
    if(opponentScore == MAX_SCORE)
        glcd_WriteString("AI",1 ,1);
    else if(score == MAX_SCORE)
        glcd_WriteString("YOU",1 ,1);
    
    glcd_SetCursor(70, 4);
    glcd_WriteString("WIN",1 ,1);
        
}