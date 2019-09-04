#ifdef _WIN32
#include <Windows.h>
#endif
#include <iostream>
#include "src/game/ChessGame.h"

int main() {
#ifdef _WIN32
	SetConsoleOutputCP(65001);
#endif
  chess::ChessGame App;
  std::cout << "If you can't see this: ♘ as a white knight, you need to change your console font\n";
  std::cout << "Press any key to start the game...";
	std::cin.get();
  App.run();
  return 0;
}
