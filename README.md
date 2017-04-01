# CliqueLib
A Machine Learning Library aiming to provide reliable ensemble classifiers

Stanislav Karel Peceny III (skp2140@columbia.edu)



Tutorial

1. Building CliqueLib

Download the library in the home directory with 'git clone https://github.com/skp2140/CliqueLib.git'

The library can then be built in ~/CliqueLib with 'make'.


2. Reading *.csv file

Use the predefined function:

//Reading a *.csv file
void read_csv(std::string file,
	      bool title = false,
	      char separate_ex = ',', 
              char comment = '#'
             );

The first argument is the name of the file. The remaining arguments are optional and have default values. 

Title is a boolean stating whether the *.csv file contains a line at the top describing the name of the attributes and labels.

Separate_ex states how the attributes are separated. ',' is the default value.

Finally, the 'comment' argument asks how the function ought to distinguish a comment.



