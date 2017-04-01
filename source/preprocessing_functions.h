/**
preprocessing_functions.h
Stan Peceny
skp2140
4/1/2017
*/

#ifndef __PREPROCESSING_FUNCTIONS_H__
#define __PREPROCESSING_FUNCTIONS_H__

#include <iostream>
#include <string>

//Reading a *.csv file
void read_csv(std::string file,
	      bool title = false,
	      char separate_ex = ',', 
              char comment = '#'
             );

#endif
