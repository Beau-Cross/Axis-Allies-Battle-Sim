/* 
 * File:   player.h
 * Author: Beau Cross
 *
 * Created on January 5, 2019, 8:09 PM
 */

#ifndef PLAYER_H
#define PLAYER_H

using namespace std;

#include <vector>
#include <iostream>

class player {
public:
    player();
    player(string input);
    virtual ~player();
    
    struct piece {
        enum type {fighter, bombers, infantry, tanks, antiAir, prodution, transport, battleship, destroyer, carrier, cruiser};
        type pieceType;
        int attack = 0;
        int defence = 0;
    };
    
    //Getters
    int getNumberPieces();
    piece getPiece(int index);
    vector<piece> findPieces(int kind);
    
    //Setters
    void setNumberPieces(int amount);
    void calcNumber();
    
    //Other functions
    void getInputs(int choice);
    void printStats();
    
    //Public Variables
    vector<piece> pieces;
    string name;
    int ones;
    int twos;
    int threes;
    int fours;
private:
    int numberPieces;

};

#endif /* PLAYER_H */