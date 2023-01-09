#include "move.h"

Move::Move(std::string move, char piece){
    const char* cords = move.c_str();
    std::cout<<"Making Move: "<<cords<<std::endl;
    Move::startingfile =fileToIndex(cords[0]);
    Move::startingrank=cords[1]-1-'0';
    Move::endingfile =fileToIndex(cords[2]);
    Move::endingrank=cords[3]-1-'0';
    Move::piece = piece;
}

int Move::fileToIndex(char file){
    switch (file)
    {
    case 'a':
        return 7;
        break;
    case 'b':
        return 6;
        break;
    case 'c':
        return 5;
        break;
    case 'd':
        return 4;
        break;
    case 'e':
        return 3;
        break;
    case 'f':
        return 2;
        break;
    case 'g':
        return 1;
        break;
    case 'h':
        return 0;
        break;
    default:
        return -1;//TODO proper error handling
        break;
    }
}

