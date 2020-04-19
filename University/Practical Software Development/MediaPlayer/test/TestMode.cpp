#include "ModeState.h"
#include "Mp3Mode.h"
#include "VideoMode.h"
#include "RadioMode.h"
#include "MediaPlayer.h"
#include "gtest/gtest.h"

TEST(TestMode, constructorTest) {
  ModeState *m = new Mp3Mode("Test 1");
  ModeState *v = new VideoMode("Test 2");
  ModeState *r = new RadioMode("Test 3");
  EXPECT_EQ("Test 1", m->getModeName());
  EXPECT_EQ("Test 2", v->getModeName());
  EXPECT_EQ("Test 3", r->getModeName());
}
