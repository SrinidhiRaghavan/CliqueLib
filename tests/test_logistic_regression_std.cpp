//============================================================================
// Name        : test_logistic_regression_std.cpp
// Author      : CliqueLib
// Version     :
// Copyright   : 
// Description : CliqueLib Logistic Regression Std testing
//============================================================================

#include "tests.h"

void test_logistic_regression_std()
{
    //TEST LOGISTIC REGRESSION OF CSV FILES
    vector<vector<float> > file;
    vector<vector<float> > train_file;
    vector<vector<float> > test_file;

    //Test 1
    std::cout << "\nTESTING Sigmoid Function" << std::endl;
    file = read_csv("./samples_csv/test_file_1_title_true.csv", true);

    LogisticRegressionStd lr1 (file);
    cout << endl;
    cout << lr1.sigmoid_function(1) << " ~ " << 0.731 << endl;
    cout << lr1.sigmoid_function(0) << " ~ " << 0.5 << endl;
    cout << lr1.sigmoid_function(2) << " ~ " << 0.881 << endl;

    //test the predict function with predetermined coefficients
    std::cout << "\nTESTING PREDICT_LABEL() OF LOGISTIC REGRESSION WITH CSV FILE 10" << std::endl;
    file = read_csv("./samples_csv/test_file_10_logistic.csv", ',');
    LogisticRegressionStd lr2 (file); 
    //coefficients - http://machinelearningmastery.com/
    vector<float> coefficients = {-0.406605464, 0.852573316, -1.104746259};

    cout << "\nbinary = false" << endl;
    cout << "predicted: " << lr2.predict_label(file[0], coefficients, false) 
         << " real: " << file[0][file[0].size() - 1] << endl;
    cout << "predicted: " << lr2.predict_label(file[1], coefficients, false) 
         << " real: " << file[1][file[1].size() - 1] << endl;
    cout << "predicted: " << lr2.predict_label(file[2], coefficients, false) 
         << " real: " << file[2][file[2].size() - 1] << endl;
    cout << "predicted: " << lr2.predict_label(file[6], coefficients, false) 
         << " real: " << file[6][file[6].size() - 1] << endl;

    cout << "\nbinary = true" << endl;
    cout << "predicted: " << lr2.predict_label(file[0], coefficients, true) 
         << " real: " << file[0][file[0].size() - 1] << endl;
    cout << "predicted: " << lr2.predict_label(file[1], coefficients, true) 
         << " real: " << file[1][file[1].size() - 1] << endl;
    cout << "predicted: " << lr2.predict_label(file[2], coefficients, true) 
         << " real: " << file[2][file[2].size() - 1] << endl;
    cout << "predicted: " << lr2.predict_label(file[6], coefficients, true) 
         << " real: " << file[6][file[6].size() - 1] << endl;
 
    //test the train function
    std::cout << "\nTESTING PREDICT_LABEL() OF LOGISTIC REGRESSION WITH CSV FILE 10" << std::endl;
    LogisticRegressionStd lr3 (file, 100, 0.3); 
    vector<float> coefficients_trained = lr3.train();
    //coefficients - http://machinelearningmastery.com/
    vector<float> coefficients_expected = {-0.859644, 1.522382, -2.218700};
    assert(coefficients_trained.size() == coefficients_expected.size());
    cout << endl;
    for (unsigned int i = 0; i < coefficients_expected.size(); i++)
        cout << "predicted: " <<  coefficients_trained[i]
         << " real: " << coefficients_expected[i] << endl;
    assert(lr3.get_learning_rate() == float(0.3));
    assert(lr3.get_num_epochs() == 100);
}

