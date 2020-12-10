#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Playlist.h"

using ::testing::Return;

/*
* Example of a stub that produces the series [0, 2, 4, 6, 8]
*/
class Even : public NumberGenerator {
public:
  Even() : count(0) { }
  unsigned int getNum(unsigned int max) {
    unsigned int num = count;

    count += 2;
    if(count > 8)
      count = 0;

    return num;
  }

private:
  unsigned int count;
};

/**
* Example of a mock that returns odd numbers
*/
class MockNumberGenerator : public NumberGenerator
{
public:
    explicit MockNumberGenerator() {}
    virtual ~MockNumberGenerator() {}

    //MOCK_METHOD(unsigned int, getNum, (unsigned int));
      MOCK_METHOD1(getNum, unsigned int(unsigned int));
};

/**
* Test using a getSongsStub
*/
TEST (PlaylistMockTest, stubTest)
{
    Playlist* pl = new Playlist();
    pl->setNumberGenerator(new Even());

    Playlist* list = Playlist::greatest();

    // Populate the playlist
    for(int i = 0; i < 10; i++) {
      pl->add(list->getSong());
    }

    // Exercise `getSong`
    for(int i = 0; i < 10; i++) {
      std::cout << pl->getSong()->name << std::endl;
    }
}

/**
* Test using a mock
*/
TEST (PlaylistMockTest, mockTest)
{
    MockNumberGenerator ng;

    EXPECT_CALL(ng, getNum(::testing::_))
      .Times(5)
      .WillOnce(Return(1))
      .WillOnce(Return(3))
      .WillOnce(Return(5))
      .WillOnce(Return(7))
      .WillOnce(Return(9));

    Playlist* pl = new Playlist();
    pl->setNumberGenerator(&ng);

    Playlist* list = Playlist::greatest();

    // Populate the playlist
    for(int i = 0; i < 10; i++) {
      pl->add(list->getSong());
    }

    // Exercise `getSong`
    for(int i = 0; i < 5; i++) {
      std::cout << pl->getSong()->name << std::endl;
    }

}
