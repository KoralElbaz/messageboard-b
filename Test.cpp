#include "doctest.h"
#include "Board.hpp"
#include <string>
using namespace std;
using namespace ariel;


TEST_CASE ("Empy borad") {
    Board board;


    //================ Horizontal - אופקי =====================//
    CHECK(board.read(15,25,Direction::Horizontal, 1) == "_");


    CHECK(board.read(15,25,Direction::Horizontal, 10) == "__________");


    //================ Vertical - אנכי =======================//

    CHECK(board.read(95,195,Direction::Vertical, 5) == "_____");


}

TEST_CASE("Read a word of length zero") {
    Board board;
     //================ Horizontal - אופקי =====================//
    CHECK(board.read(15,25,Direction::Horizontal, 0) == "");
    
    board.post(5,0,Direction::Horizontal,"My name is Koral");
    CHECK(board.read(5,0,Direction::Horizontal, 0) == "");




    //================ Vertical - אנכי =======================//
    CHECK(board.read(95,195,Direction::Vertical, 0) == "");

    board.post(5,0,Direction::Vertical,"My name is Koral");
    CHECK(board.read(5,0,Direction::Vertical, 0) == "");


}

TEST_CASE("Post out of range"){
Board board;
 //================ Horizontal - אופקי =====================//
    // start pos 10X10

    CHECK_NOTHROW(board.post(0,1000,Direction::Horizontal, "*"));
   
    CHECK_NOTHROW(board.post(0,10000,Direction::Horizontal, "**"));




//================ Vertical - אנכי =======================//


    CHECK_NOTHROW(board.post(1000,10000,Direction::Vertical, "*"));

    CHECK_NOTHROW(board.post(10000,10000,Direction::Vertical, "**"));


}

TEST_CASE("Read out of range") {
    Board board;
     //================ Horizontal - אופקי =====================//
    CHECK_NOTHROW(board.read(0,1000,Direction::Horizontal, 5));

    CHECK_NOTHROW(board.read(0,10000,Direction::Horizontal, 5));


    //================ Vertical - אנכי =======================//
    CHECK_NOTHROW(board.read(1000,0,Direction::Vertical, 10));

    CHECK_NOTHROW(board.read(10000,0,Direction::Vertical, 10));


}

TEST_CASE ("I hate corona virus") {
    Board board;
     //================ Horizontal - אופקי =====================//

     board.post(0, 2, Direction::Horizontal, "I hate corona virus");
                board.show();

            CHECK(board.read(0, 2, Direction::Horizontal, 6) == "I hate");
            CHECK(board.read(0, 0, Direction::Horizontal, 6) == "__I ha");
            CHECK(board.read(0, 10, Direction::Horizontal, 15) == "orona virus____");
            


    //================ Vertical - אנכי =======================//
    board.post(0, 2, Direction::Horizontal, "I hate corona virus");
    board.post(1, 0, Direction::Horizontal, "Happy Passover");
            CHECK(board.read(1, 0, Direction::Horizontal, 14) == "Happy Passover");
            CHECK(board.read(0, 0, Direction::Vertical, 6) == "_H____");
            CHECK(board.read(0, 4, Direction::Vertical, 3) == "hy_");

            

}


TEST_CASE("Overriding existing strings"){
    Board board;
    string s1="I hate corona virus";
    string s2="Looking for a private tutor for CPP";
    string s3="House for rent in Ariel";
    string s4="Sales workers are needed";
    string s5="New in cinema: 'Wonder women'";
    string s6="Happy Passover";
    string s7="Men's haircut for 20 shekels";
    string s8="Tests";

    board.post(0, 0, Direction::Horizontal, s1);
    board.post(1,0,Direction::Horizontal,s2);
    board.post(0,2,Direction::Vertical,s3);
    board.post(3,2,Direction::Horizontal,s4);
    board.post(0,6,Direction::Vertical,s5);
    board.post(5,0,Direction::Horizontal,s6);
    board.post(12,0,Direction::Horizontal,s7);
    board.post(4,5,Direction::Vertical,s8);
    board.show();


    CHECK(board.read(0, 0, Direction::Horizontal, 13) == "I HateNcorona");
    CHECK(board.read(0,0,Direction::Vertical,15)=="IL___H______M__");
    CHECK(board.read(5,4,Direction::Vertical,6)=="y_____");
}