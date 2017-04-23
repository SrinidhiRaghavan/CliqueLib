/**
logistic_regression.cpp
Stan Peceny
skp2140
4/18/2017
*/

#include "logistic_regression.h"

//Constructor
LogisticRegression::LogisticRegression(float learning_rate)
{
    this->learning_rate = learning_rate;
}

//calculate sigmoid function
float LogisticRegression::sigmoid_function(float z)
{
    float e = 2.718282;
    return 1.0 / (1.0 + pow(e, -z));
}


//Train - returns a vector of coefficients
//Uses stochastic gradient descent
void LogisticRegression::train(vector<vector<float> >& train_file, vector<float>& labels_sample, int num_epochs)
{
    vector<float> labels_train;
    for (unsigned int num_lb = 0; num_lb < train_file.size(); num_lb++)
        labels_train.push_back(0.0);
    //iterate over all vectors of coefficients
    for (auto& coef : this->coefficients)
    {
        //assign coefficients each to 0
        for (unsigned int i = 0; i < train_file[0].size(); i++)        
           coef.push_back(0.0);
        
        //iterate num_epochs times as using stochastic gradient descent
        for (int i = 0; i < num_epochs; i++)
        {
            float error_sum = 0;
            predict(train_file, labels_train, false);
            //iterate over each row in the training file
            for (unsigned int j = 0; j < train_file.size(); j++)
            {
                float f_x = labels_train[j];
                float error = labels_sample[j] - f_x;
                error_sum += pow(error, 2);
                coef[0] += learning_rate * error * f_x * (1.0 - f_x);
                //iterate over each attribute in a row
                for (unsigned int k = 0; k < train_file[j].size() - 1; k++)
                {
                    coef[k + 1] += learning_rate * error * f_x * (1.0 - f_x) * train_file[j][k];    
                }
            }
        }
    }
}

//Predict
void LogisticRegression::predict(vector<vector<float> >& instances, vector<float>& labels_found, bool binary)
{
    int idx = 0;
    //iterate over all instances
    for (auto& instance : instances)
    {
	//iterate over all attributes

	//MAKE COEFFICIENTS VECTOR OF VECTORS

	float z = this->coefficients[idx][0];
	for (unsigned int i = 0; i < instance.size(); i++)
	    z += this->coefficients[idx][i + 1] * instance[i];
	   
	if (binary == true)
	{
	    if (sigmoid_function(z) >= 0.5)
		labels_found[idx] = 1;
   	    else
		labels_found[idx] = 0;
	}
	else
	    labels_found[idx] = sigmoid_function(z);
        idx++;
    }   
}

