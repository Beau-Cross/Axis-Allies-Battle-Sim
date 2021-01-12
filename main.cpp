/* 
 * File:   main.cpp
 * Author: Beau Cross
 *
 * Created on January 5, 2019, 7:58 PM
 */

#include <cstdlib>
#include <vector>
#include <iostream>
#include <random>
#include <ctime>
#include "player.h"

using namespace std;

int playerSum(vector<int> player){
    int total = 0;
    for (int x = 0; x < player.size(); x++){
        total += player[x];
    }
    return total;
}

int main() {
    srand(time(NULL));
    
    player player1("player1");
    player player2("player2");
    
    int games;
    cout << "How many games would you like to simulate? (Recommended: 200000)" << endl;
    cin >> games;
    
    //acquire data
    cout << "This is for player 1" << endl;
    for (int x = 1; x < 5; x++){
        player1.getInputs(x);
    }
    player1.calcNumber();
    cout << "This is for player 2" << endl;
    for (int x = 1; x < 5; x++){
        player2.getInputs(x);
    }
    player2.calcNumber();
    
    //do calculations
    double player1Chance;
    double player2Chance;
    
    int player1Win = 0;
    int player2Win = 0;
    int tie = 0;
    
    //Run sim game, see how many times each player wins
    cout << "-----------------------------" << endl;
    cout << "Battle Simulation Begin" << endl;
    bool show = false;
    for (int x = 0; x < games; x++){
        //srand(time(NULL));
        vector<int> playerOne;
        vector<int> playerTwo;

        playerOne.push_back(player1.ones);
        playerOne.push_back(player1.twos);
        playerOne.push_back(player1.threes);
        playerOne.push_back(player1.fours);

        playerTwo.push_back(player2.ones);
        playerTwo.push_back(player2.twos);
        playerTwo.push_back(player2.threes);
        playerTwo.push_back(player2.fours);
        
        while (playerSum(playerOne) > 0 && playerSum(playerTwo) > 0){
            //srand(time(NULL));
            
            //roll for player 1
            vector<int> rollOne;
            for (int y = 0; y < playerSum(playerOne); y++){
                rollOne.push_back(rand() % 6 + 1);
            }
            //roll for player 2
            vector<int> rollTwo;
            for (int y = 0; y < playerSum(playerTwo); y++){
                rollTwo.push_back(rand() % 6 + 1);
            }
            //Calculate the number of hits
            int playerOneHits = 0;
            for (int y = 0; y < playerSum(playerOne); y++){
                if (y < playerOne[0]){
                    if (rollOne[y] < 2)
                        playerOneHits += 1;
                } else if (y < playerOne[0]+playerOne[1]){
                    if (rollOne[y] < 3)
                        playerOneHits += 1;
                } else if (y < playerOne[0]+playerOne[1]+playerOne[2]) {
                    if (rollOne[y] < 4)
                        playerOneHits += 1;
                } else if (y < playerOne[0]+playerOne[1]+playerOne[2]+playerOne[3]){
                    if (rollOne[y] < 5)
                        playerOneHits += 1;
                }
            }
            int playerTwoHits = 0;
            for (int y = 0; y < playerSum(playerTwo); y++){
                if (y < playerTwo[0]){
                    if (rollTwo[y] < 2)
                        playerTwoHits += 1;
                } else if (y < playerTwo[0]+playerTwo[1]){
                    if (rollTwo[y] < 3)
                        playerTwoHits += 1;
                } else if (y < playerTwo[0]+playerTwo[1]+playerTwo[2]) {
                    if (rollTwo[y] < 4)
                        playerTwoHits += 1;
                } else if (y < playerTwo[0]+playerTwo[1]+playerTwo[2]+playerTwo[3]){
                    if (rollTwo[y] < 5)
                        playerTwoHits += 1;
                }
            }
            
            //take hit totals and remove pieces accordingly
            int i = 0;
            while(playerTwoHits > 0){
                if (playerOne[i] == 0){
                    i += 1;
                }
                playerOne[i] -= 1;
                playerTwoHits -= 1;
            }
            
            i = 0;
            while(playerOneHits > 0){
                if (playerTwo[i] == 0){
                    i += 1;
                }
                playerTwo[i] -= 1;
                playerOneHits -= 1;
            } 
        }
        if (playerSum(playerOne) > playerSum(playerTwo)){
            player1Win += 1;
        }
        if (playerSum(playerTwo) > playerSum(playerOne)){
            player2Win += 1;
        }
        if (playerSum(playerOne) == playerSum(playerTwo)){
            tie += 1;
        }
        if ((x*100/games % 2 == 0)){
            if (!show)
                cout << (double)x/games * 100 << "%" << endl;
            show = true;
        } else {
            show = false;
        }
    }
    cout << "100%" << endl;
    cout << "Simulation Completed" << endl;
    cout << "-----------------------------" << endl;
    
    
    player1Chance = (double)player1Win/games;
    player2Chance = (double)player2Win/games;
    
    cout << "Out of " << games << " games... " << endl;
    cout << "\tPlayer 1 won " << player1Win << " time(s) (" << player1Chance*100 << "%)" << endl;
    cout << "\tPlayer 2 won " << player2Win << " time(s) (" << player2Chance*100 << "%)" << endl;
    cout << "\tThere were " << tie << " tie(s) (" << (double)tie/games*100 << "%)" << endl;
    
    cout << "-----------------------------" << endl;
    cout << "Quick Stats" << endl;
    cout << "Player 1 - " << endl;
    int player1OP = player1.ones*1+player1.twos*2+player1.threes*3+player1.fours*4;
    cout << "\tOffensive Power = " << player1OP << endl;
    cout << "\tDefensive Power = " << player1.getNumberPieces() << endl;
    cout << "\tRatio (OP/DP) = " << (double)player1OP/player1.getNumberPieces() << endl;
    cout << "Player 2 - " << endl;
    int player2OP = player2.ones*1+player2.twos*2+player2.threes*3+player2.fours*4;
    cout << "\tOffensive Power = " << player2OP << endl;
    cout << "\tDefensive Power = " << player2.getNumberPieces() << endl;
    cout << "\tRatio (OP/DP) = " << (double)player2OP/player2.getNumberPieces() << endl;
    
    
    
    //player1.printStats();
    //player2.printStats();
    
    return 0;
}