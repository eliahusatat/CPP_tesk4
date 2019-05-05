/**
 * A demo program for bull-pgia.
 * 
 * @author Erel Segal-Halevi
 * @since  2019-04
 */


#include <iostream>
using namespace std;

#include "play.hpp"
#include "DummyChoosers.hpp"
#include "DummyGuessers.hpp"
#include "SmartGuesser.hpp"
#include "badkan.hpp"
#include "calculate.hpp"
#define COMMA ,

using namespace bullpgia;

int main() {

	badkan::TestCase testcase;
	int grade=0;
	int signal = setjmp(badkan::longjmp_buffer);
	if (signal == 0) {

		// BASIC TESTS - DO NOT CHANGE
		ConstantChooser c1234{"1234"}, c12345{"12345"}, c9999{"9999"};
		ConstantGuesser g1234{"1234"}, g12345{"12345"}, g9999{"9999"};

		testcase.setname("Calculate bull and pgia")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","1234"), "4,0")      // 4 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1234","4321"), "0,4")      // 0 bull, 4 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1234","5243"), "1,2")      // 4 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("6789","6879"), "2,2")      // 0 bull, 4 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1234","2678"), "0,1")      // 0 bull, 1 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1234","5678"), "0,0")    	// 0 bull, 0 pgia	
		.CHECK_OUTPUT(calculateBullAndPgia("1234","1238"), "3,0")    // 3 bull, 0 pgia  
		.CHECK_OUTPUT(calculateBullAndPgia("1234","4213"), "1,3")      // 1 bull, 3 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("12345","12342"), "4,0")      // 4 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("123456","123455"), "5,0")     // 5 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("123456","654321"), "0,6")      // 0 bull, 6 pgia
		
		
		/*
		in all of this cases threre should be an extion  , case letters in the string , spaces ,tabs and other things
		*/
		.CHECK_THROWS(calculateBullAndPgia("12345k","12345y")) 
		.CHECK_THROWS(calculateBullAndPgia("12345","12345k"))
		.CHECK_THROWS(calculateBullAndPgia("hello","world"))
		.CHECK_THROWS(calculateBullAndPgia("erel","sgal"))
		.CHECK_THROWS(calculateBullAndPgia("123","-123"))
		.CHECK_THROWS(calculateBullAndPgia("",""))
		.CHECK_THROWS(calculateBullAndPgia("","1"))
		.CHECK_THROWS(calculateBullAndPgia("","k"))
		.CHECK_THROWS(calculateBullAndPgia("123",""))
		.CHECK_THROWS(calculateBullAndPgia("5y6y","5y6y"))
		.CHECK_THROWS(calculateBullAndPgia("123","123."))
		.CHECK_THROWS(calculateBullAndPgia("123","1234."))
		.CHECK_THROWS(calculateBullAndPgia("123","+123"))
		.CHECK_THROWS(calculateBullAndPgia("123","321."))
		.CHECK_THROWS(calculateBullAndPgia("//","\\"))
		.CHECK_THROWS(calculateBullAndPgia("1|1","1|1"))
		.CHECK_THROWS(calculateBullAndPgia("0_0","0_0"))
		.CHECK_THROWS(calculateBullAndPgia("90","90~"))
		.CHECK_THROWS(calculateBullAndPgia("10        1","101"))
		.CHECK_THROWS(calculateBullAndPgia("000","00             0"))

		;





		ConstantChooser c123456{"123456"}, c99999{"99999"}, c01234567{"01234567"};
		ConstantGuesser g123456{"123456"}, g123455{"123455"}, g99999{"99999"}, g8888{"8888"};
		testcase.setname("Play with dummy choosers and guessers")
		.CHECK_EQUAL(play(c1234, g1234, 4, 100), 1)      // guesser wins in one turn.
		.CHECK_EQUAL(play(c1234, g9999, 4, 100), 101)    // guesser loses by running out of turns 
		.CHECK_EQUAL(play(c1234, g12345, 4, 100), 101)   // guesser loses technically by making an illegal guess (too long).
		.CHECK_EQUAL(play(c12345, g1234, 4, 100), 0)     // chooser loses technically by choosing an illegal number (too long).
		.CHECK_EQUAL(play(c1234, g123456, 4, 100), 101)      
		.CHECK_EQUAL(play(c1234, g8888, 4, 100), 101)    
		.CHECK_EQUAL(play(c123456, g1234, 4, 100), 0)  
		.CHECK_EQUAL(play(c12345, g1234, 4, 100), 0)
		.CHECK_EQUAL(play(c123456, g123456, 6, 100), 1)      
		.CHECK_EQUAL(play(c99999, g9999, 4, 100), 0)    
		.CHECK_EQUAL(play(c123456, g123455, 6, 100), 101)  
	
		;

		testcase.setname("Play with smart guesser");
		RandomChooser randy;
		SmartGuesser smarty;
		for (uint i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(play(randy, smarty, 4, 100)<=100, true);  // smarty should always win in at most 10 turns!
		}

    grade = testcase.grade();
	} else {
		testcase.print_signal(signal);
		grade = 0;
	}
	cout << "Your grade is: "  << grade << endl;
	return 0;
}

