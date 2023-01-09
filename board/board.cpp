#include "board.h"
#include <regex>
Board::Board(){
    isWhiteTurn=true;
}
void Board::printBoard(){
    for(int a = 0; a < 8; a++)
    {
        std::cout<<8-a<<"| ";
        for(int b = 0; b < 8; b++)
        {
            std::cout << board[7-a][7-b] << " ";
        }
        std::cout << std::endl;
    } 
    std::cout<<"   ---------------"<<std::endl;
    std::cout<<"   A B C D E F G H"<<std::endl;

}
void Board::move(std::string move){
    const char* cords = move.c_str();
    int startingfile =fileToIndex(cords[0]);
    int startingrank=cords[1]-1-'0';
    int endingfile =fileToIndex(cords[2]);
    int endingrank=cords[3]-1-'0';
    char piece = board[startingrank][startingfile];
    std::cout<<"Making Move: "<<cords<<std::endl;
    board[endingrank][endingfile]=piece;
    board[startingrank][startingfile]='0';
    isWhiteTurn= !isWhiteTurn;//other colors turn

}
/**
 * @brief Checks if legal move
 * 
 * @param move string uci of chess move ex e2e4
 * @return true if legal
 * @return false if not
 */
bool Board::checkLegalMove(std::string move){
    if(!std::regex_match(move,std::regex("[a-h][1-8][a-h][1-8]"))){
        throw std::runtime_error("move not possible on a chess 8x8 chess board");
    }
    const char* cords = move.c_str();
    int startingfile =fileToIndex(cords[0]);
    int startingrank=cords[1]-1-'0';
    int endingfile =fileToIndex(cords[2]);
    int endingrank=cords[3]-1-'0';
    char piece = board[startingrank][startingfile];
    if(isWhiteTurn!=isWhite(startingrank,startingfile)){
        return false;
    }
    switch (piece)
    {
    case 'P':
        return checkWhitePawnMove(startingfile, endingfile, startingrank, endingrank);
        break;
    default:
    return true;
        break;
    }
}
bool Board::checkWhitePawnMove(int startingfile,int endingfile,int startingrank, int endingrank){
    if (board[startingrank][startingfile]!='P')
    {
        throw std::runtime_error("not a white pawn move");
        return false;
    }
    if(endingfile==startingfile){
        for(int i= startingrank+1; i<=endingrank; i++){
            if(board[i][startingfile]!='0'){
                return false;
            }
        }
        if(startingrank==1&&(endingrank==2||endingrank==3)){
                return true;
        }
        else{
                return endingrank==startingrank+1;
        }
    }
    else if(endingfile==startingfile+1||endingfile==startingfile-1){
        return false;
    
    
    }
        
    else{
        return false;
    }
}
bool Board::isWhite(int startingrank,int startingfile){
    return !islower(board[startingrank][startingfile]);
}
int Board::fileToIndex(char file){
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