#include <xc.h>

#include "config.h"
#include "gameGraphique.h"
#include "gameSystem.h"

// Frequency
#define _XTAL_FREQ 20000000

void main()
{
    initialiseGame();
    
    // Position of the bar
    int previousYBar = 20, yBar = 0;
    
    // Position of the opponent bar
    int previousYBarOppo = 20, yBarOppo = 20;
    
    // Position of the ball
    int xBall = 20, yBall = 20, xBallPrev = LARGEUR/2, yBallPrev = HAUTEUR/2;
    int dx = 2, dy = 1;
    
    // Opponent score and personnal score
    int score = 0, opponentScore = 0;
        
    while(1)
    {
    // Recalculate the position of our bar
        yBar = positionBarreJoueur();

    // Recalculate the position of the ball
        if(rebondLargeur(yBall, dy) == 1)
            dy = -dy;

        if(rebondBarre(xBall, yBall, dx, yBar, yBarOppo) == 1)
            dx = -dx;

        // Apply the ball movement
        xBall += dx;
        yBall += dy;

    // If someone scored
        if(pointMarque(xBall) != 0)
        {
            if(pointMarque(xBall) == 1) // Je marque
            {
                score++;
                if(score <= MAX_SCORE )
                    tracerNouveauScore(pointMarque(xBall), score);
            }
            else // Il marque
            {
                opponentScore++;
                if(opponentScore <= MAX_SCORE )
                    tracerNouveauScore(pointMarque(xBall), opponentScore);
            }

        // If someone win
            if(opponentScore >= MAX_SCORE || score >= MAX_SCORE)
            {
              messageGagnant(opponentScore, score);
              __delay_ms(3000);
              tracerMur();
              opponentScore = score = xBall = yBall = 0;
            } 

            xBall = LARGEUR/2;
            yBall = HAUTEUR/2;
        }     


    // Recalculate the position of the opponent bar
        yBarOppo =  positionBarreEnnemie(yBarOppo, yBall);


    // Delete and add new sprites
        if(yBar != previousYBar)
        {
            tracerBarre(LARGEUR-DELTA-LARGEUR_BARRE, previousYBar, 0);
            tracerBarre(LARGEUR-DELTA-LARGEUR_BARRE, yBar, 1);
        }
        if(yBarOppo != previousYBarOppo)
        {
            tracerBarre(DELTA, previousYBarOppo, 0);
            tracerBarre(DELTA, yBarOppo, 1);
        }
        if( (xBall != xBallPrev) || (yBall != yBallPrev) )
        {
            tracerBalle(xBallPrev, yBallPrev, 0);
            tracerBalle(xBall, yBall, 1);
        }


    // Refresh position
        previousYBarOppo =  yBarOppo;
        previousYBar = yBar;
        xBallPrev = xBall;
        yBallPrev = yBall;

    __delay_ms(10);

    }
}
