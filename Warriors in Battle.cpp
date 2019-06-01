//============================================================================
// Name        : Warriors.cpp
// Author      : Rebecca Su
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

int main () {
    int num_war, min_battle, shots, counter;
   std::cin >> num_war >> min_battle;


   int *warriors = new int[num_war];
   int *men_standing = new int[num_war];
   int *arrows = new int[min_battle];

   for(int i = 0; i < num_war; i++)
   {
       std::cin >> warriors[i];
       men_standing[i] = warriors[i];
   }

   for(int i = 0; i < min_battle; i++)
   {
       std::cin >> arrows[i];
   }

   for(int i = 0; i < min_battle; i++)
   {
       shots = arrows[i];
       for(int j = 0; j < num_war; j++)
       {
           if(shots < men_standing[j])
           {
               men_standing[j] = men_standing[j] - shots;
               break;
           }
           else if(shots == men_standing[j])
           {
               men_standing[j] = 0;
               counter++;
               break;
           }
           else
           {
               shots = shots - men_standing[j];
               if(men_standing[j] != 0)
               {
                   counter ++;
               }
               men_standing[j] = 0;
           }
       }
       if(counter >= num_war)
       {
           counter = 0;
           for(int i = 0; i < num_war; i++)
           {
               men_standing[i] = warriors[i];
           }
       }
       std::cout << num_war - counter << std::endl;
   }

   delete [] men_standing;
   delete [] arrows;
   delete [] warriors;
    return 0;
}
