#include "board/board.h"

int main(){
    Board board;
    board.printBoard();
    while(true){
        std::string move;
        std::cin>>move;
        try{
        if(board.checkLegalMove(move)){
            board.move(move);
            board.printBoard();
        }
            else{
                std::cout<<"Not a leagal move"<<std::endl;
            }
        }
        catch(std::runtime_error error){
            std::cout<<"An error has occured try again"<<std::endl;
        }
        
    }
    
}
