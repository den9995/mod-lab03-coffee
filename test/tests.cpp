// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"

TEST(actions, on) {
    Automata a = Automata();
    a.on();
    EXPECT_EQ(a.getState(), Automata::WAIT);
}

