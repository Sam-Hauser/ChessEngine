#ifndef move_H // include guard
#define move_H
#include<iostream>

class Move
{
private:
    char piece;//enventaully change
    char endingrank;
    char endingfile;
    char startingrank;
    char startingfile;
    int fileToIndex(char);
public:
    Move(std::string,char);
    int checkmove();
    
};


#endif /* move_H */