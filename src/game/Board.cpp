//
// Created by joris on 09.08.19.
//

#include "Board.h"
namespace chess {

chess::Board::Board()
    : m_board_matrix(BOARD_WIDTH, BOARD_HEIGHT), m_taken_pieces{} {
  //init black side pawns
  std::fill_n(m_board_matrix.begin()+BOARD_WIDTH, 8,chess::Piece(BLACK, PAWN));
  //init black side
  int current_piece = ROOK;
  std::generate_n(m_board_matrix.begin(), 5, [&current_piece](){return chess::Piece(BLACK, current_piece++);});
  current_piece = BISHOP;
  std::generate_n(m_board_matrix.begin()+5, 3, [&current_piece](){return chess::Piece(BLACK, current_piece--);});

  //init white side pawns
  std::fill_n(m_board_matrix.begin()+(BOARD_WIDTH*6), 8,chess::Piece(WHITE, PAWN));
  //init white side
  current_piece = ROOK;
  std::generate_n(m_board_matrix.end()-BOARD_WIDTH, 5, [&current_piece](){return chess::Piece(WHITE, current_piece++);});
  current_piece = BISHOP;
  std::generate_n(m_board_matrix.end()-3, 3, [&current_piece](){return chess::Piece(WHITE, current_piece--);});

}
void Board::set_piece(const int &x, const int &y, const chess::Piece &piece) {
  m_board_matrix[{x, y}] = piece;
}

//draws the board graphics
void chess::Board::show() {
  //draw taken pieces
  std::cout << "╔ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╗\n ";
  int piece_count = 0;
  for (const Piece &p : m_taken_pieces) {
    std::cout << p.get_icon() << " ";
    if (piece_count > 15) {
      std::cout << '\n';
      piece_count = 0;
    }
    piece_count++;
  }
  std::cout << "\n╚ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╝\n";

  //draw chessboard
  std::cout <<  "╔ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╗\n";
  for (
      int y = 0;
      y < BOARD_HEIGHT;
      ++y) {
    std::cout << "║  ";
    for (
        int x = 0;
        x < BOARD_WIDTH;
        ++x) {
      std::string current_icon = m_board_matrix[{x, y}].get_icon();
      std::string current_spacing = " ";
      if (current_icon == " ") {
        //generate checker pattern (if x+y odd)
        current_icon = (x + y) & 1 ? "██" : "▒▒";
        current_spacing = " ";
      } else {
        current_spacing = "  ";
      }
      std::cout << current_icon <<
                current_spacing;
    }
    std::cout << " ║" << (BOARD_WIDTH - y) << '\n';
  }
  std::cout << "╚ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╝\n";
  std::cout << "   a  b  c  d  e  f  g  h\n";
}

//Moves a piece and returns wether the move was valid, invalid moves contain an error message string,
//vaid moves contain the last move that happened as string
MoveMessage
chess::Board::move_piece(const std::string &from, const std::string &to, const int &current_turn_color) {
  std::vector<Coordinates> coords = parse_input(from, to);
  MoveMessage message = valid_move(coords[0], coords[1], current_turn_color);

  Piece selected_piece = m_board_matrix[coords[0]];
  Piece to_move_to = m_board_matrix[coords[1]];

  if (message.valid_move) {

    //check en passant
    Coordinates left_piece_coords =
        {(coords[0].x - 1), (selected_piece.get_color() == BLACK ? coords[0].y + 1 : coords[0].y - 1)};
    Coordinates right_piece_coords =
        {(coords[0].x + 1), (selected_piece.get_color() == BLACK ? coords[0].y + 1 : coords[0].y - 1)};
    if (en_passant(selected_piece, m_board_matrix[left_piece_coords], m_board_matrix[right_piece_coords])) {
      set_piece(coords[0].x, coords[0].y, chess::Piece{});
      set_piece(coords[1].x, coords[1].y, selected_piece);
      return {true, message.message + "Nice move, you took that pawn en passant :)\n"};
    }

    set_piece(coords[0].x, coords[0].y, chess::Piece{});
    set_piece(coords[1].x, coords[1].y, selected_piece);

    //if a piece was taken add it to taken pieces
    if (!to_move_to.empty()) {
      m_taken_pieces.push_back(to_move_to);
    }

    //returns what happened
    return {true, message.message + "The " + selected_piece.get_color_str() + " "
        + selected_piece.get_role_str() + " moved from " + from + " to " + to + " "
        + (!to_move_to.empty() ? std::string("and took the ")
            + to_move_to.get_color_str() + " "
            + to_move_to.get_role_str() + "!"
                               : std::string(""))
        + "\n"};
  }
  return message;
}

//checks if a move is a valid move
MoveMessage
chess::Board::valid_move(const Coordinates &from, const Coordinates &to,
                         const int &current_turn_color) const {
  std::string message;

  //checks if the same field was selected twice
  if (from == to)
    return {false,
            "Staying at the same place from where you started is not legal! This action will be reported <3"};

  //checks for empty selected field
  auto selected_piece = m_board_matrix[from];
  if (selected_piece.empty())
    return {false, "You can't move nothing dummy <3"};

  //checks for correct color
  if (!correct_color(current_turn_color, selected_piece))
    return {false, message + "You can't move that "
        + selected_piece.get_color_str() + " "
        + selected_piece.get_role_str()
        + ". It has the wrong color sweetheart <3"};

  //checks if the move would be inside the board
  if (!inside_board(to))
    return {false, message + "You can't move that "
        + selected_piece.get_color_str() + " "
        + selected_piece.get_role_str()
        + ". It would be outside of the board darling <3"};

  //checks if the piece can move that far
  int d_x = to.x - from.x;
  int d_y = to.y - from.y;
  if (!inside_mask(abs(d_x), abs(d_y), selected_piece))
    return {false, message + "You can't move that "
        + selected_piece.get_color_str() + " "
        + selected_piece.get_role_str()
        + ". This piece can't move that far honey <3"};

  //checks if the moved pattern matches the valid move pattern for that piece
  bool takes_piece = m_board_matrix[to].get_icon() != std::string(" ");
  if (!on_move_mask(d_x, d_y, selected_piece, takes_piece))
    return {false, message + "You can't move that "
        + selected_piece.get_color_str() + " "
        + selected_piece.get_role_str()
        + ". This is not a valid move for this piece sugar <3"};

  //checks if there are pieces in the way
  if (collides(from, to)) {
    return {false, message + "There is a piece in the way my dear ¯\\_(^-^)_/¯"};
  }

  //if all checks pass the move is valid
  return {true, ""};
}

//checks for en_passant and ensures the pawn can only move two steps on its first move
//returns true if a piece was taken en passant
bool chess::Board::en_passant(Piece &selected_piece, Piece &left_piece, Piece &right_piece) {
  bool ret = false;

  //if the mask is greater 2 the pawn hasn't moved yet
  if (selected_piece.get_role() == PAWN && selected_piece.get_mask().height() > 2) {

    //different checks for black and white pawn
    if (selected_piece.get_color() == WHITE) {
      if (!left_piece.empty()  || !right_piece.empty()) {
        //the piece that is taken en passant is the non empty piece if both pieces are non empty
        // the right piece is taken
        Piece &to_take = !left_piece.empty() ? left_piece : right_piece;
        if (to_take.get_color() != WHITE) {
          //add the taken pieces to the taken pieces and sets the cell to empty
          m_taken_pieces.push_back(to_take);
          to_take = Piece(NONE, EMPTY);
          ret = true;
        }
      }
      //pawn has moved, mask is now 1 x 2
      selected_piece.set_mask({{1, 0}, 1, 2});
    } else {
      //same but for black
      if (!left_piece.empty() || !right_piece.empty()) {
        Piece to_take = !left_piece.empty() ? left_piece : right_piece;
        if (to_take.get_color() != BLACK) {
          m_taken_pieces.push_back(to_take);
          to_take = Piece(NONE, EMPTY);
        }
      }
      selected_piece.set_mask({{0, 1}, 1, 2});
    }
  }
  return ret;
}

bool chess::Board::correct_color(const int &current_turn_color, const Piece &piece) {
  return current_turn_color == piece.get_color();
}

bool chess::Board::inside_board(const Coordinates &to) {
  return !(to.x > BOARD_WIDTH - 1 || to.y > BOARD_HEIGHT - 1);
}

bool chess::Board::inside_mask(const int &d_x, const int &d_y, const Piece &piece) {
  Mask mask = piece.get_mask();

  if (piece.get_role() != PAWN) {
    //checks if the proposed move is not greater than the distance from the center to the boarder of the mask
    return !((mask.width() / 2) + 1 <= d_x || (mask.height() / 2) + 1 <= d_y);
  } else {
    //for pawns we only need to check the y direction
    return mask.height() > d_y;
  }
}

bool chess::Board::on_move_mask(const int &d_x, const int &d_y, const Piece &piece, const bool &takes_piece) {
  Mask mask = piece.get_mask();
  //coordinates relative to the center of mask
  int c_x = 0;
  int c_y = 0;
  switch (piece.get_role()) {

    //Pawns can only move in one direction
  case PAWN: {
    if (piece.get_color() == BLACK) {
      c_x = d_x;
      c_y = d_y;
    } else {
      c_x = d_x;
      c_y = mask.height() + d_y - 1;
    }
    break;
  }
  default: {
    c_x = (mask.width() / 2) + d_x;
    c_y = (mask.height() / 2) + d_y;
    break;
  }
  }

  //pawns can take pieces diagonal
  if (takes_piece && piece.get_role() == PAWN) {
    return piece.get_color() == BLACK ? (d_x == -1 || d_x == 1) && (d_y == 1) : (d_x == -1 || d_x == 1)
        && (d_y == -1);
  }

  //returns wether the mask is 0 or 1 at the coordinates
  return mask[static_cast<unsigned long>(c_x + c_y * mask.width())];
}

//checks if there is a piece in the way
bool chess::Board::collides(const Coordinates &from, const Coordinates &to) const {
  Coordinates current_cell = from;
  Piece selected_piece = m_board_matrix[from];
  //check for direction
  Coordinates d_direction = to - from;

  //if pieces have the same color they colide
  if (selected_piece.get_color() == m_board_matrix[to].get_color())
    return true;

  //knights can leap over pieces, they cant't collide
  if (selected_piece.get_role() == KNIGHT)
    return false;

  Coordinates d_check_direction{0, 0};
  //case diagonal move
  if (d_direction.x && d_direction.y) {
    if (d_direction.x > 0) {
      //case NE
      if (d_direction.y < 0) {
        d_check_direction = {1, -1};
        std::clog << "Diagonal move NE from << " << selected_piece.get_color_str() << " "
                  << selected_piece.get_role_str() << "\n";
      }
      //case SE
      if (d_direction.y > 0) {
        d_check_direction = {1, 1};
        std::clog << "Diagonal move SE\n";
      }
    } else if (d_direction.x < 0) {
      //case SW
      if (d_direction.y > 0) {
        d_check_direction = {-1, 1};
        std::clog << "Diagonal move SW\n";
      }
      //case NW
      if (d_direction.y < 0) {
        d_check_direction = {-1, -1};
        std::clog << "Diagonal move NW\n";
      }
    }
  }
    //case straight move
  else if (d_direction.x == 0) {
    //case N
    if (d_direction.y < 0) {
      d_check_direction = {0, -1};
      std::clog << "Straight move N\n";
    }
    //case S
    if (d_direction.y > 0) {
      d_check_direction = {0, 1};
      std::clog << "Straight move S\n";
    } else if (d_direction.y == 0) {
      //case E
      if (d_direction.x > 0) {
        d_check_direction = {1, 0};
        std::clog << "Straight move E\n";
      }
      if (d_direction.x < 0) {
        d_check_direction = {-1, 0};
        std::clog << "Straight move W\n";
      }
    }
  }
  bool colides = false;
  bool last_check = false;
  while (current_cell != to) {
    current_cell += d_check_direction;
    last_check = colides;
    if (!m_board_matrix[current_cell].empty()) {
      colides = true;
    }
  }
  return last_check;
}

std::vector<Piece> Board::taken_pieces() const {
  return m_taken_pieces;
}
}//namespace chess
