#include <tyra>
#include "cs.hpp"

int main() {
  
  Tyra::Engine engine;
  Cs::CsGame game(&engine);
  engine.run(&game);
  SleepThread();
  return 0;
}