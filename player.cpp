/* 
 * File:   player.cpp
 * Author: Beau Cross
 * 
 * Created on January 5, 2019, 8:09 PM
 */



#include "player.h"

player::player() {
    numberPieces = 0;
}

player::player(string input) {
    name = input;
    numberPieces = 0;
}

player::~player() {
}

int player::getNumberPieces(){
    return numberPieces;
}

player::piece player::getPiece(int index){
    return pieces[index];
}

vector<player::piece> player::findPieces(int kind){
    vector<player::piece> tmp;
    for (int x = 0; x < pieces.size(); x++){
        if (pieces[x].pieceType == kind){
            tmp.push_back(pieces[x]);
        }
    }
    return tmp;
}

void player::setNumberPieces(int amount){
    numberPieces = amount;
}

void player::printStats(){
    for (int x = 0; x < 30; x++){
        cout << "-";
    }
    cout << endl;
    cout << "Number of pieces = " << numberPieces << endl;
    cout << endl;
    cout << "Pieces contain: " << endl;
    cout << "\tones = " << ones << endl;
    cout << "\ttwos = " << twos << endl;
    cout << "\tthrees = " << threes << endl;
    cout << "\tfours = " << fours << endl;
    cout << endl;
    cout << "Number of correct dice sides = " << ones*1 + twos*2 + threes*3 + fours*4 << endl;
    for (int x = 0; x < 30; x++){
        cout << "-";
    }
    cout << endl;
}

void player::getInputs(int choice){
    int input;
    if (choice > 0)
        cout << "how units do you have with a power of " << choice << endl;
    cin >> input;
    while (input < 0){
        input = 0;
        if (choice > 0)
            cout << "have a power of " << choice << endl;
        cin >> input;
    }
    if (choice == 1)
        ones = input;
    if (choice == 2)
        twos = input;
    if (choice == 3)
        threes = input;
    if (choice == 4)
        fours = input;
}

void player::calcNumber(){
    int total = ones + twos + threes + fours;
    setNumberPieces(total);
}