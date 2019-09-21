#ifdef _WIN32
#include <Windows.h>
#endif
#include <iostream>
#include "src/game/chessgame.h"

int main() {
  chess::ChessGame App;
  App.run();
  return 0;
}
