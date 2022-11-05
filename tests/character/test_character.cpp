#include "../../src/character/character.h" //TODO: Take a look at these imports..

#include "gtest/gtest.h"

TEST(BaseCharacterTest, TestIsAlive)
{
    EXPECT_EQ(7 * 6, 42);
}

TEST(BaseCharacterTest, TestIsAliveFails)
{
    EXPECT_EQ(7 * 4, 42);
}