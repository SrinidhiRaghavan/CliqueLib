/**
preprocessing_functions.cpp
Stan Peceny
skp2140
4/1/2017
*/

#include "preprocessing_functions.h"
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
    for(auto row : vec_of_vec) {
        for(auto element : row) {
            data_flat.push_back(element);
            //cout << element << " ";
        }
        //cout << endl;
    }
    auto m = vec_of_vec.size();
    auto n = data_flat.size()/m;
    //cout << "m,n " << m << " , " << n << endl;

    for (auto x : data_flat) {
        //cout << x << " ";
    }
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

//Split the dataset into a train and test section
void split_test_train(vector<vector<float> > file, 
		      float train_part,
		      vector<vector<float> >& train_file,
		      vector<vector<float> >& test_file
		     )
{    
    int train_size = train_part * file.size();
    int test_size = file.size() - train_size;
    //size of dataset is 1
    if (file.size() == 1)
    {
        train_size = 1;
        test_size = 0;
    }
    vector<vector<float> > train (file.begin(), file.end() - test_size);
    vector<vector<float> > test (file.begin() + train_size, file.end());
    train_file = train;
    test_file = test;
}

