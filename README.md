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

2. Splitting the file into testing and training dataset after read_csv() was called. 

Use the predefined function:

//Split the dataset into a train and test section
void split_test_train(vector<vector<float> > file, 
		      float train_part,
		      vector<vector<float> >& train_file,
		      vector<vector<float> >& test_file
		     );

The first argument is passing the file as read in from read_csv().

The second argument, train_part, is a value between 0 and 1 and states what portion the training part ought to constitute after splitting.

The last two arguments are blank vector<vector<float> >, which after the function's call will contain the training and the testing part.
