#include "Gra.hpp"

int main() {
  Gra g;
  while (g.get_state())
    g.akcja_gracza();
  return 0;
}