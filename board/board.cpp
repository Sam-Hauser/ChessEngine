#include "board.h"

Board::Board(){
}
void Board::printBoard(){
    for(int a = 0; a < 8; a++)
    {
        std::cout<<a+1<<"| ";
        for(int b = 0; b < 8; b++)
        {
            std::cout << board[a][b] << " ";
        }
        std::cout << std::endl;
    } 
    std::cout<<"   ---------------"<<std::endl;
    std::cout<<"   A B C D E F G H"<<std::endl;

}