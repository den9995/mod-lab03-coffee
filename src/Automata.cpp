//Copyright 2023 den9995
#include "Automata.h"
#include <iostream>
#include <string>
#ifdef _WIN32
  #include <Windows.h>
#else
  #include <unistd.h>
#endif
Automata::Automata() {
  menu = {"кипяток", "кофе", "чай"};
  prices = {12, 51, 34};
  longitudes = {2, 3, 1};
  state = OFF;
  cash = 0;
}
void Automata::on() {
  if (state == OFF) state = WAIT;
}
void Automata::off() {
  if (state == WAIT) state = OFF;
}
void Automata::coin(int sum) {
  if (state == WAIT || state == ACCEPT) {
    state = ACCEPT;
    cash = cash + sum;
  }
}
void Automata::getMenu() {
  for (int i = 0; i < menu.capacity(); i++) {
    std::cout << i + 1 << ") " << menu[i] << " : " << prices[i] << "р\n";
  }
}
Automata::State Automata::getState() { 
  return state; 
}
void Automata::choice(int num) {
  if (state == ACCEPT) {
    if (num < 0 || num >  menu.capacity()) {
      std::cout << "Неправильно выбран напиток\n";
    } else {
      state = CHECK;
      check(num);
    }
  }
}
void Automata::check(int num) {
  if (state == CHECK) {
    if (cash < prices[num]) {
      std::cout << "Недостаточно денег\n";
      state = WAIT;
    } else {
      cook(num);
    }
  }
}
void Automata::cancel() {
  if (state == ACCEPT || state == CHECK) state = WAIT;
}
void Automata::cook(int num) {
  if (state == CHECK) {
    state = COOK;
    std::cout << "Приготовление напитка...\n";
    sleep(longitudes[num]);
    finish(cash - prices[num]);
  }
}
void Automata::finish(int rest) { 
  std::cout << "Напиток готов\n";
  if (rest > 0) std::cout << "Сдача: " << rest << "\n";
  cash = 0;
  state = WAIT; 
}
