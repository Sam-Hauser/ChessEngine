#ifndef board_H // include guard
#define board_H
#include<iostream>
enum file{
    A=0,
    B=1,
    C=2,
    D=3,
    E=4,
    F=5,
    G=6,
    H=7
};

class Board
{
private:
    char board[8][8]={
        {'R','N','B','K','Q','B','N','R'},
        {'P','P','P','P','P','P','P','P'},
        {'0','0','0','0','0','0','0','0'},
        {'0','0','0','0','0','0','0','0'},
        {'0','0','0','0','0','0','0','0'},
        {'0','0','0','0','0','0','0','0'},
        {'p','p','p','p','p','p','p','p'},
        {'r','n','b','k','q','b','n','r'},
    };
    char StartingBoard[8][8]={
        {'R','N','B','Q','K','B','N','R'},
        {'P','P','P','P','P','P','P','P'},
        {'0','0','0','0','0','0','0','0'},
        {'0','0','0','0','0','0','0','0'},
        {'0','0','0','0','0','0','0','0'},
        {'0','0','0','0','0','0','0','0'},
        {'p','p','p','p','p','p','p','p'},
        {'r','n','b','q','k','b','n','r'},
        
    };
    int fileToIndex(char file);
    bool checkWhitePawnMove(int,int,int,int);
    bool checkBlackPawnMove(int,int,int,int);
    bool checkRookMove(int,int,int,int);
    bool isWhiteTurn;
    //bool checkWhitePawnMove(int,int,int,int);
    bool isWhite(int startingfile,int startingrank);
public:
    Board();
    std::string getTurn();
    void printBoard();
    void move(std::string);
    bool checkLegalMove(std::string move);

};
#endif /* board_H */