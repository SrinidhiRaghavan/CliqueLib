//============================================================================
// Name        : logistic_regression_std.cpp
// Author      : Logistic Regression
// Version     :
// Copyright   : 
// Description : CliqueLib Logistic Regression definition
//============================================================================

#include "logistic_regression_std.h"

//Constructor
LogisticRegressionStd::LogisticRegressionStd(vector<vector<float> > train_file, int num_epochs, float learning_rate)
{
    this->train_file = train_file;
    this->num_epochs = num_epochs;
    this->learning_rate = learning_rate;
}

//calculate sigmoid function
float LogisticRegressionStd::sigmoid_function(float z)
{
    float e = 2.718282;
    return 1.0 / (1.0 + pow(e, -z));
}


//Train - returns a vector of coefficients
//Uses stochastic gradient descent
vector<float> LogisticRegressionStd::train()
{
    //initialize vector of coefficients and assign each to 0
    vector<float> coefficients;
    for (unsigned int i = 0; i < train_file[0].size(); i++)
    {
        coefficients.push_back(0.0);
    }
    //iterate num_epochs times as using stochastic gradient descent
    for (int i = 0; i < num_epochs; i++)
    {
        float error_sum = 0;
        //iterate over each row in the training file
        for (unsigned int j = 0; j < train_file.size(); j++)
        {
            float f_x = predict(train_file[j], coefficients);
            float error = train_file[j][train_file[j].size() - 1] - f_x;
            error_sum += pow(error, 2);
            coefficients[0] += learning_rate * error * f_x * (1.0 - f_x);
            //iterate over each attribute in a row
            for (unsigned int k = 0; k < train_file[j].size() - 1; k++)
            {
                coefficients[k + 1] += learning_rate * error * f_x * (1.0 - f_x) * train_file[j][k];
            }
        }
    }
    return coefficients;
}

//Predict
float LogisticRegressionStd::predict(vector<float> instance, vector<float> coefficients, bool binary)
{
    //Last column contains the labels
    int num_attributes = instance.size() - 1;
    if ((unsigned int)num_attributes != this->train_file[0].size() - 1)
    {
        cerr << "Wrong number of attributes for the example to be classified";
        return 0;
    }

    //iterate over all attributes, the last column is the label
    float z = coefficients[0];
    for (unsigned int i = 0; i < instance.size() - 1; i++)
    {
        z += coefficients[i + 1] * instance[i];
    }	
    
    if (binary == true)
    {
        if (sigmoid_function(z) >= 0.5)
            return 1;
        else
            return 0;
    }
    else
        return sigmoid_function(z);    
}
