# Stanislav Peceny

CC = g++-6
CXX = g++-6
INCLUDES = -I ./armadillo-7.800.2/include/ -I ./source/Commons/ -I./tests -I./source  -I./source/Preprocessing -I./source/KNN -I./source/KNNStd -I./source/LogisticRegression -I./source/LogisticRegressionStd -I./source/NaiveBayes -I./source/AdaBoost -I./source/SVM
CXXFLAGS = -g -Wall --std=c++1z -fconcepts -o prog -O2 -larmadillo $(INCLUDES) 
LDFLAGS = -L ./armadillo-7.800.2/include/armadillo
LDLIBS  =

main: tests/test_read_csv.o tests/test_split_test_train_dataset.o tests/test_knn.o tests/test_knn_std.o tests/test_logistic_regression.o tests/test_logistic_regression_std.o tests/test_naive_bayes.o tests/test_adaboost.o tests/test_svm.o source/Preprocessing/preprocessing_functions.o source/KNN/knn.o source/KNNStd/knnstd.o source/LogisticRegression/logistic_regression.o source/LogisticRegressionStd/logistic_regression_std.o source/NaiveBayes/naive_bayes.o source/AdaBoost/Stump.o source/AdaBoost/AdaBoost.o source/SVM/SVM.o source/AdaBoost/BaggingClassifier.o source/VotingClassifier/VotingClassifier.o source/VotingClassifier/VotingClassifier.o

#main: tests/test_read_csv.o tests/test_split_test_train_dataset.o tests/test_knn.o tests/test_logistic_regression.o  source/Preprocessing/preprocessing_functions.o source/KNN/knn.o source/LogisticRegression/logistic_regression.o 

main.o: tests/tests.h

tests/test_read_csv.o: tests/tests.h

tests/test_split_test_train_dataset.o: tests/tests.h

tests/test_knn.o: tests/tests.h

tests/test_knn_std.o: tests/tests.h

tests/test_logistic_regression.o: tests/tests.h

tests/test_logistic_regression_std.o: tests/tests.h

tests/test_naive_bayes.o: tests/tests.h

tests/test_adaboost.o: tests/tests.h

tests/test_svm.o: tests/tests.h

source/Prepocessing/preprocessing_functions.o: source/Preprocessing/preprocessing_functions.h

source/KNN/knn.o: source/KNN/knn.h

source/KNNStd/knnstd.o: source/KNNStd/knnstd.h

source/LogisticRegression/logistic_regression.o: source/LogisticRegression/logistic_regression.h

source/LogisticRegressionStd/logistic_regression_std.o: source/LogisticRegressionStd/logistic_regression_std.h

source/NaiveBayes/naive_bayes.o: source/NaiveBayes/naive_bayes.h

source/AdaBoost/Stump.o: source/AdaBoost/Stump.h

source/SVM/SVM.o: source/SVM/SVM.h

source/AdaBoost/AdaBoost.o: source/AdaBoost/AdaBoost.h

source/AdaBoost/BaggingClassifier.o: source/AdaBoost/BaggingClassifier.h

.PHONY: clean
clean:
	rm -f *.o *~ tests/*.o  tests/*~ source/*.o  source/*~ source/Preprocessing/*.o source/Preprocessing/*~ source/KNN/*.o source/KNN/*~ source/KNNStd/*.o source/KNNStd/*~ source/LogisticRegression/*.o source/LogisticRegression/*~ source/LogisticRegressionStd/*.o source/LogisticRegressionStd/*~  source/NaiveBayes/*.o source/NaiveBayes/*~  source/AdaBoost/*.o source/AdaBoost/*~ source/SVM/*.o source/SVM/*~ a.out core main

.PHONY: all
	all: clean main

.PHONY: valgrind
valgrind: main
	valgrind -v --num-callers=20 --leak-check=yes --leak-resolution=high --show-reachable=yes ./main
