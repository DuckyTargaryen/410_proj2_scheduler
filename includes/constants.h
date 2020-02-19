#pragma once
#include <iostream>

const int 			SUCCESS										= 0;
const int 			FAIL												= SUCCESS - 1;
const int 			USER_CHOSE_TO_EXIT		= SUCCESS - 2;
const int 			COULD_NOT_OPEN_FILE 	= SUCCESS - 3;
const int 			COULD_NOT_READ_FILE 	= SUCCESS - 4;
const int				UNINITIALIZED						= SUCCESS - 5;
const int				NO_JOBS									= SUCCESS - 7;

const char			CHAR_TO_SEARCH_FOR 	= ',';
const int				TIMER_BEGIN 							= 0;
const int				DEFAULT_TIME_SLICE			= 2;
//const int				EXPECTED_NUMBER_ARGUMENTS = 3;
//const int 				FAIL_WRONG_NUMBER_ARGS = -5;
//const std::string WRONG_NUMB_ARGS = "This program expects 2 arguments, infile, [FIFO,FCFS,STCF]";

//default files
const char*	const 	SOURCE_FILE_1 = "./data/testdata1.txt";
const char* const	SOURCE_FILE_2 = "./data/testdata2.txt";

#define _SHOWLOG
#ifdef _SHOWLOG
#define PRINT1(txt) std::cout<<txt<<std::endl;
#define PRINT2(txt,txt1) std::cout<<txt<<txt1<<std::endl;
#define PRINT3(txt,txt1,txt2) std::cout<<txt<<txt1<<txt2<<std::endl;
#define PRINT4(txt,txt1,txt2,txt3) std::cout<<txt<<txt1<<txt2<<txt3<<std::endl;
#else
//compiler will optimize this to nothing for a release build
#define PRINT1(txt);
#define PRINT2(txt,txt1);
#define PRINT3(txt,txt1,txt2);
#define PRINT4(txt,txt1,txt2,txt3);
#endif
