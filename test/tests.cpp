// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"

TEST(actions, on) {
  Automata a = Automata();
  a.on();
  EXPECT_EQ(a.getState(), Automata::WAIT);
}
TEST(actions, off) {
  Automata a = Automata();
  a.on();
  a.off();
  EXPECT_EQ(a.getState(), Automata::OFF);
}
TEST(actions, finish) {
  Automata a = Automata();
  a.on();
  a.coin(34);
  a.choice(2);
  EXPECT_EQ(a.getState(), Automata::WAIT);
}
TEST(actions, cancel) {
  Automata a = Automata();
  a.on();
  a.coin(1);
  a.cancel();
  EXPECT_EQ(a.getState(), Automata::WAIT);
}
/*
TEST(actions, ) {
  Automata a = Automata();
  EXPECT_EQ(a.getState(), Automata::);
}
*/

