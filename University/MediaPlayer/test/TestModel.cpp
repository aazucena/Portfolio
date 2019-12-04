#include "Model.h"
#include "Bottom.h"
#include "Middle.h"
#include "Top.h"
#include "MediaPlayer.h"
#include "gtest/gtest.h"

TEST(TestModel, constructorTest) {
  Model *b = new Bottom("Test 1");
  Model *t = new Top("Test 2");
  Model *m = new Middle("Test 3");
  EXPECT_EQ("Test 1", b->getModelName());
  EXPECT_EQ("Test 2", t->getModelName());
  EXPECT_EQ("Test 3", m->getModelName());
}
