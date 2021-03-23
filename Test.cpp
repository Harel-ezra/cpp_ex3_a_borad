#include "doctest.h"
#include "Board.hpp"
using namespace ariel;

#include "Direction.hpp" //????
using ariel::Direction;  //????

#include <string>
using namespace std;

TEST_CASE("Good code")
{
    ariel::Board board;
    board.post(/*row=*/100, /*column=*/200, Direction::Horizontal, "abcd");
    CHECK("abcd" == board.read(/*row=*/100, /*column=*/200, Direction::Horizontal, 4));
    CHECK("ab" == board.read(/*row=*/100, /*column=*/200, Direction::Horizontal, 2));
    CHECK("cd" == board.read(/*row=*/100, /*column=*/202, Direction::Horizontal, 2));
    CHECK("d" == board.read(/*row=*/100, /*column=*/203, Direction::Vertical, 2));

    board.post(/*row=*/101, /*column=*/200, Direction::Horizontal, "hey how are you?");

    CHECK("hey how are you?" == board.read(/*row=*/101, /*column=*/200, Direction::Horizontal, 16));
    CHECK("hey how are you" == board.read(/*row=*/101, /*column=*/200, Direction::Horizontal, 15));
    CHECK("ey how are you?" == board.read(/*row=*/101, /*column=*/201, Direction::Horizontal, 15));
    CHECK("how " == board.read(/*row=*/101, /*column=*/204, Direction::Horizontal, 4));
    CHECK("ah" == board.read(/*row=*/100, /*column=*/200, Direction::Vertical, 2));
    CHECK("d " == board.read(/*row=*/100, /*column=*/203, Direction::Vertical, 2));

    board.post(/*row=*/102, /*column=*/200, Direction::Vertical, "show here..055-----987");

    CHECK("show here..055-----987" == board.read(/*row=*/102, /*column=*/200, Direction::Vertical, 22));
    CHECK("ahshow " == board.read(/*row=*/100, /*column=*/200, Direction::Vertical, 7));
    CHECK("w h" == board.read(/*row=*/105, /*column=*/200, Direction::Vertical, 3));
    CHECK("abcdc" == board.read(/*row=*/100, /*column=*/200, Direction::Horizontal, 4) + board.read(/*row=*/100, /*column=*/202, Direction::Horizontal, 1));

    board.post(/*row=*/102, /*column=*/201, Direction::Vertical, "cpp corse free!");

    CHECK("cpp corse free!" == board.read(/*row=*/102, /*column=*/201, Direction::Vertical, 15));
    CHECK("w h" == board.read(/*row=*/105, /*column=*/200, Direction::Vertical, 3));
    CHECK("sc" == board.read(/*row=*/102, /*column=*/200, Direction::Horizontal, 2));
    CHECK("___" == board.read(/*row=*/10, /*column=*/1, Direction::Horizontal, 3));
    CHECK("_____" == board.read(/*row=*/50, /*column=*/50, Direction::Vertical, 5));
    CHECK("becpp" == board.read(/*row=*/100, /*column=*/201, Direction::Vertical, 5));
}
