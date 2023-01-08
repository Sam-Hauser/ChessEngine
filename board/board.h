#ifndef board_H // include guard
#define board_H
#include<iostream>
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
        {'R','N','B','K','Q','B','N','R'},
        {'P','P','P','P','P','P','P','P'},
        {'0','0','0','0','0','0','0','0'},
        {'0','0','0','0','0','0','0','0'},
        {'0','0','0','0','0','0','0','0'},
        {'0','0','0','0','0','0','0','0'},
        {'p','p','p','p','p','p','p','p'},
        {'r','n','b','k','q','b','n','r'},
        
    };
public:
    Board();
    void printBoard();
};


#endif /* board_H */