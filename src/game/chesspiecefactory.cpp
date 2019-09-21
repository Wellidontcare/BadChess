#include "chesspiecefactory.h"

chess::Piece *chess::ChessPieceFactory::create_piece(const int &color, const int &role)
{
    if(color == BLACK){
        return new Rook(BLACK);
    }
    else if (color == WHITE){
        return new Rook(WHITE);
    }
    else {
        return new EmptyField();
    }
}
