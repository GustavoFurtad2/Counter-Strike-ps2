#include <tyra>
#include "rise.hpp"

int main() {
  
  Tyra::Engine engine;
  Rise::RiseGame game(&engine);
  engine.run(&game);
  SleepThread();
  return 0;
}
