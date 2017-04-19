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

3. Splitting the file into testing and training dataset after read_csv() was called. 

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


4. KNN



















5. Logistic Regression

Logistic regression is a classification algorithm and yields merely binary classes of 0 and 1.

The class contains three private variables constituting the training dataset (train_file), the int number of iterations to strive for as accurate model as possible (num_epochs), and a float learning rate, which specifies how much the coefficient values should change after each iteration in the hope of convergence (learning_rate).

a) The default constructor of the logistic regression class only requires the name of the training file, and can pass the default values of num_epochs as well as learning_rate to the constructor.

//default constructor
LogisticRegression(vector<vector<float> > train_file) : LogisticRegression(train_file, 100, 0.01){}

b) The constructor differs from the default constructor in that it enables to declare the number of epochs (num_epochs) as well as the learning rate (learning_rate).

//constructor
LogisticRegression(vector<vector<float> > train_file, int num_epochs, float learning_rate);

c) There are two getters that enable the user to get the num_epochs as well as the learning_rate. 

//get num_epochs
int get_num_epochs() { return num_epochs; }

//get learning_rate
float get_learning_rate() { return learning_rate; }

d) Similarly, there are two setters that allow to change the num_epochs and learning_rate for each logistic regression object.

//set num_epochs
void set_num_epochs(int num_epochs) { this->num_epochs = num_epochs; }

//set learning_rate
void set_learning_rate(float learning_rate) { this->learning_rate = learning_rate; }

e) Consequently, there is the sigmoid function which enables to cast a value between 0 and 1. Nevertheless, other s shaped functions could be used instead.

//calculate sigmoid function
float sigmoid_function(float z);

Consequently, there are the two core functions of the logistic regression algorithm - train and classify.

f) The train() function returns a vector<float> of coefficients. There are no arguments to train() as the algorithm object already has all necessary variables stored. This is enforced to enable to use the algorithm more simply for a novice user.

//Train - returns a vector of coefficients
vector <float> train();

g) The classify function makes a classification prediction and takes as parameters an instance that needs to be classified as well as the model represented as a vector<float> of coefficients returned by train(). 

There is an optional third parameter called binary, a boolean that specifies whether the function ought to return a class of 0 or 1, or the actual float value calculated, which is in between 0 and 1. By default, the binary boolean is false, and returns the computed float value.

//Classify
float classify(vector<float> instance, vector<float> coefficients, bool binary = false);




















