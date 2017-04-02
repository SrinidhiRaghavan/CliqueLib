/**
preprocessing_functions.cpp
Stan Peceny
skp2140
4/1/2017
*/

#include "preprocessing_functions.h"

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
		      float train_ratio,
		      vector<vector<float> >& train_file,
		      vector<vector<float> >& test_file
		     )
{

}

