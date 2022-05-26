#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#include "names.h"

typedef enum { SIDE , RAZORBACK , TROTTER , SNOUTER , JOWLER } Position ;
const Position pig [7] = {
    SIDE,
    SIDE,
    RAZORBACK,
    TROTTER,
    SNOUTER,
    JOWLER,
    JOWLER,
};

int main()
{
        int players;
        unsigned int seed_value;
        int score[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        int gamestart = 0;
    
        printf("How many players? ");
        scanf("%d", &players);
        if (2 > players||10 < players) 
        {
		fprintf(stderr, "Invalid number of players. Using 2 instead.\n");
                players = 2; 
	}

        printf("Random seed: ");
        scanf("%d", &seed_value);
        
	if (seed_value < 0||seed_value > UINT_MAX)
        {
		fprintf(stderr, "Invalid random seed. Using 2022 instead.\n");
                seed_value = 2022;
        }
    
        #define SEED seed_value
        srandom(SEED);
    
        while(gamestart < 1)
        {  /*Starts the game*/
		for (int i = 0; i < players; ++i)
        {  /*Cycles turns*/
	    	    printf("%s rolls the pig... ", names[i]);
		    while (gamestart < 1)
		    { /*die roll*/
			    int d = (random() % 7); /*Pulls a number from 0-6*/
                            int numpull = pig[d];
			    if (numpull == 0)                 
			    {  /*On back*/
				    printf("pig lands on side \n");
                                    break;
                            }
			    if (numpull == 1) 
                            { /*razorback*/
                                    printf("pig lands on back ");
                                    score[i] = score[i] + 10;
                                    if (score[i] >= 100) 
                                    {
					    printf("\n%s wins with %d points!\n", names[i], score[i]);
                                            return 0;
				    }
			    }  
                            if (numpull == 2)
                            { /*troutter*/
				    printf("pig lands upright ");
                                    score[i] = score[i] + 10; 
                                    if (score[i] >= 100)
                                    {
                                            printf("\n%s wins with %d points!\n", names[i], score[i]);
                                            return 0;
                                    }   
			    }    
                 
                            if (numpull == 3)
                            { /*snouter*/
                                    printf("pig lands on snout ");
                                    score[i] = score[i] + 15; 
                                    if (score[i] >= 100)
                                    {
                                            printf("\n%s wins with %d points!\n", names[i], score[i]);
                                            return 0;
                                    }   
			    } 
                 
                            if (numpull == 4)
                            { /*jowler*/
				    printf("pig lands on ear ");
                                    score[i] = score[i] + 5; 
                                    if (score[i] >= 100)
                                    {
                                            printf("\n%s wins with %d points!\n", names[i], score[i]);
                                            return 0;
                                    }   
			    } 
                    }
        }
        }
}    
