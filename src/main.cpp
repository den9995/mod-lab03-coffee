#include "Automata.h"
#include <iostream>
#include <string>
using namespace std;
int main()
{
   setlocale(LC_ALL, "Russian");
   Automata cafe;
   cafe.getMenu();
   cafe.on();
   cafe.coin(30);
   cafe.choice(0);
   cafe.coin(30);
   cafe.choice(1);
}
