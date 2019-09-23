//
// Created by joris on 17.08.19.
//

#include "chessgame.h"
#ifdef _WIN32
#include <Windows.h>
#endif
void chess::ChessGame::run()
{
#ifdef _WIN32
    SetConsoleOutputCP(65001);
#endif
    std::cout << "If you can't see this: ♘ as a white knight, you need to change your console font\n";
    std::cout << "Press any key to start the game...";
    std::cin.get();
    std::string last_move = "Nothing happened\n";
    while (true) {
        int turn;
        std::string from;
        std::string to;
        bool black_moved = false;
        if (check_game_over()) {
            std::cout << std::string(50, '\n');
            std::cout << R"(_______       ___  _____  _   __  _    _  _____ _   _ _
                     | ___ \ |     / _ \/  __ \| | / / | |  | ||  _  | \ | | |
                     | |_/ / |    / /_\ \ /  \/| |/ /  | |  | || | | |  \| | |
                     | ___ \ |    |  _  | |    |    \  | |/\| || | | | . ` | |
                     | |_/ / |____| | | | \__/\| |\  \ \  /\  /\ \_/ / |\  |_|
                     \____/\_____/\_| |_/\____/\_| \_/  \/  \/  \___/\_| \_(_))" << '\n';

            std::cin.get();
            getchar();
            break;
        }
        while (!black_moved) {
            turn = chess::BLACK;
            black_moved = false;
            //clear the screen
            std::cout << std::string(50, '\n');
            m_board.show();
            std::cout << "Current turn: Black\n";
            std::cout << "Last move: " << last_move;
            std::cout << "Move (from to): ";
            std::cin >> from;
            std::cin >> to;
            if (!valid_input(from, to)) {
                std::cout
                    << "That is not a valid input. Valid input is space separated chess-coordinated. Example: a2 a3\n";
                std::cout << "\nPress any key to try again:)\n";
                std::cin.get();
                getchar();
                continue;
            }
            const std::shared_ptr<MoveMessage> move = m_board.move_piece(from, to, turn);
            if (!move->is_valid_move()) {
                std::cout << move->get_message() << '\n';
                std::cout << "\nPress any key to try again:)\n";
                std::cin.get();
                getchar();
            }
            else {
                last_move = move->get_message();
                black_moved = true;
            }
        }
        bool white_moved = false;
        while (!white_moved) {
            turn = chess::WHITE;
            white_moved = false;
            //clear the screen
            std::cout << std::string(50, '\n');
            m_board.show();
            std::cout << "Current turn: White\n";
            std::cout << "Last move: " << last_move;
            std::cout << "Move (from to): ";
            std::cin >> from;
            std::cin >> to;
            if (!valid_input(from, to)) {
                std::cout
                    << "That is not a valid input. Valid input is space separated chess-coordinated. Example: a2 a3\n";
                std::cout << "\nPress any key to try again:)\n";
                std::cin.get();
                getchar();
                continue;
            }
            const std::shared_ptr<MoveMessage> move = m_board.move_piece(from, to, turn);
            if (!move->is_valid_move()) {
                std::cout << move->get_message() << '\n';
                std::cout << "\nPress any key to try again:)\n";
                std::cin.get();
                getchar();
            }
            else {
                last_move = move->get_message();
                white_moved = true;
            }
        }
        if (check_game_over()) {
            std::cout << std::string(50, '\n');
            std::cout << R"( _    _ _   _ _____ _____ _____   _    _  _____ _   _ _
                       | |  | | | | |_   _|_   _|  ___| | |  | ||  _  | \ | | |
                       | |  | | |_| | | |   | | | |__   | |  | || | | |  \| | |
                       | |/\| |  _  | | |   | | |  __|  | |/\| || | | | . ` | |
                       \  /\  / | | |_| |_  | | | |___  \  /\  /\ \_/ / |\  |_|
                        \/  \/\_| |_/\___/  \_/ \____/   \/  \/  \___/\_| \_(_))" << '\n';
            std::cin.get();
            getchar();
            break;
        }
    }
}
bool chess::ChessGame::check_game_over()
{
    return std::any_of(m_board.taken_pieces().begin(), m_board.taken_pieces().end(), [](const std::shared_ptr<Piece>& piece){return piece->get_role() == KING;});
}
