//============================================================================
// Name        : knnstd.h
// Author      : CliqueLib
// Version     :
// Copyright   : 
// Description : CliqueLib Knnstd definition
//============================================================================

#ifndef __KNNSTD_H__
#define __KNNSTD_H__

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <map>
#include <utility>
#include <limits>

using namespace std;

/**
 * KNNStd is CliqueLib's implementation of the K-Nearest Neighbors algorithm with vector<vector> >
 * data structures rather than Armadillo. KNN differs greatly from many machine learning algorithms
 *  since it does not implement a model. In fact, the entire training dataset could be considered 
 * as the model for kNN. The kNN algorithm searches through the training example for k closest
 * instances. The prevailing prediction of these k nearest neighbors is returned as the prediction 
 * for the new input. Euclidean distance is used for measuring the similarity between instances.
 */
class KNNStd
{
    public:
        //default constructor
        KNNStd(vector<vector<float> > train_file) : KNNStd(train_file, 3){} /**< A default constructor
                                                                                 for KNN is available
                                                                                  and sets the default
                                                                                  value of k to 3 as
                                                                                  well as declares the
                                                                                  training dataset.
                                                                             */

        //constructor
        KNNStd(vector<vector<float> > train_file, int k); /**< A KNN object is created by a
                                                               constructor wherein the user must
                                                               specify the training .csv dataset
                                                               and the value k representing k nearest
                                                               neighbors.
                                                           */

        //get k
        int getK() { return k; } /**< The user can retrieve k by calling the function's getter. */

        //set k
        void setK(int k) { this->k = k; } /**< The user can change the value of k by calling 
                                               the function's setter. 
                                           */
        
        // calculate Euclidean Distance
        float euclideanDistance (int, vector<float>, vector<float>); /**< The euclideanDistance method
                                                                          takes int num_attributes as
                                                                          a parameter representing
                                                                          number of attributes of
                                                                          every example, and two
                                                                          examples between which
                                                                          Euclidean distance is
                                                                          calculated and returned as
                                                                          float.
                                                                       */

        //find K neighbors
        vector<vector<float> > findNeighbors(vector<float>); /**< findNeighbors takes the instance to be
                                                                  predicted and finds the k nearest
                                                                  neighbors, which are returned in a
                                                                  vector<vector<float> > 
                                                              */

        //determine class
        float findClass(vector<vector<float> >); /**< This function is called by predict_label to find the
                                                      best class from all neighbors. The label is returned
                                                      as a float. 
                                                  */

        //Train 
        vector<vector<float> > train(); /**< The train function is only kept for consistency and
                                             returns the vector<vector<float> > that it accepts as
                                             input. This is only done for consistency with other
                                             algorithms. 
                                         */

        //Predict a single label
        float predict_label(vector<float>); /**< The predict_label function accepts a single input
                                                 example and predicts a corresponding label. This is
                                                 achieved by first calling a function that finds all
                                                 neighbors (findNeighbors) before calling findClass that
                                                 finds the actual label. The predict function iteratively
                                                 calls predict_label to
                                                 generate a vector of float labels that is
                                                 consequently returned.
                                            */

        //Predict multiple labels
        vector<float> predict(vector<vector<float> >); /**< Predict_label predicts the label for a
                                                            single example. On the other hand, the
                                                            predict function takes a vector of
                                                            examples and predicts a label for every
                                                            one of them.
                                                        */
       
    private:
        int k; /*!< k represents the number of nearest neighbors of an input instance. */
        vector<vector<float> > train_file; /*!<  train_file is the dataset that is part of 
                                                 KNN's model 
                                            */
}; 

#endif
