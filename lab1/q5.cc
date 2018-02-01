#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>

int main () {
    srand(time(NULL));
    int randomNumber = rand() % 10 + 1;
    int guessNumber = 0;
    std::string guessinput; // complier does not know about this magically, need std::
    //int numberOfTries;
    
    while (randomNumber!=guessNumber) {
        std::cout << "Guess a number between 1 - 100 ? " << std::endl;
        std::cin >> guessinput;
        guessNumber = atoi(guessinput.c_str());
        
        if (randomNumber<guessNumber){
            printf ( "Lower \n");
        }
        else if (randomNumber>guessNumber) {
            printf ("Higher \n");
        }
        std::cout << "Congrats!" << std::endl;
    }
}
