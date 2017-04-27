//============================================================================
// Name        : preprocessing_functions.cpp
// Author      : CliqueLib
// Version     :
// Copyright   : 
// Description : CliqueLib Preprocessing functions implementation
//============================================================================

#include <cmath>
#include "preprocessing_functions.h"
#include <cassert>
using namespace arma;

void read_csv(string file,
                               mat& X,
                               colvec& Y,
	                       bool title,
	                       char separate_ex, 
                               char comment
                              )
{
    auto vec_of_vec = read_csv(file, title, separate_ex, comment);
    std::vector<double> data_flat;
    for(auto row : vec_of_vec) 
    {
        for(auto element : row) 
        {
            data_flat.push_back(element);
            //cout << element << " ";
        }
        //cout << endl;
    }
    auto m = vec_of_vec.size();
    auto n = data_flat.size()/m;
    //cout << "m,n " << m << " , " << n << endl;

    //for (auto x : data_flat) {
        //cout << x << " ";
    //}
    //cout << endl;

    mat data(data_flat);
    //cout << "before reshape data:" << data << endl;
    data = reshape(data, n, m);
    //cout << "after reshape data:" << data << endl;
    data = data.t();
    //cout << "after transpose data:" << data << endl;
    auto cols = size(data, 1);
    X = data.cols(0, cols-2);
    Y = data.col(cols-1);
}

//Reading a *.csv file
vector<vector<float> > read_csv(string file,
	                       bool title,
	                       char separate_ex, 
                               char comment
                              )
{
    vector<vector<float>> data_csv;
    ifstream parse_file(file);
    while(parse_file)
    {
        string ln;
        if (!getline(parse_file, ln))
            break;
        //skip first line's description of the attributes
        if (title)
        {
            title = false;
            continue;
        }
        //check if the line is a comment
        if (ln[0] == comment)
            continue;        
        istringstream parse_line (ln);
        vector<float> split_ln;
        while (parse_line)
        {
            string split_el;
            string::size_type sz;
            if (!getline(parse_line, split_el, separate_ex))
                break;
            split_ln.push_back(stof(split_el, &sz));
        }
        data_csv.push_back(split_ln);
    }
    if (parse_file.eof())
        return data_csv;
    else
    {
        cerr << file << " could not be parsed" << endl;
        exit(0);
    }
}

void split_train_test(const mat& X, const colvec& Y, Dataset& data, double trainProportion)
{
	uword n = size(X, 0);
    uvec randIdx = randi<uvec>(n, 1, distr_param(0, n-1));
    assert(trainProportion > 0);
    uword ntrain = ceil(trainProportion * n);
    cout << "ntrain: " << ntrain << endl;

    data.Xtrain = X.rows(randIdx.rows(0, ntrain-1));
    data.Ytrain = Y.rows(randIdx.rows(0, ntrain-1));
    data.Xtest = X.rows(randIdx.rows(ntrain, n-1));
    data.Ytest = Y.rows(randIdx.rows(ntrain, n-1));
}
