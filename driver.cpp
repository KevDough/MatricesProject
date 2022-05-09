#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <chrono>

#include "matrixDynProg.hpp"
#include "matrixMemo.hpp"

using namespace std;

void runTestCase(vector<int> testCaseInput,ofstream &outputFile,ofstream &performanceDiff) {
    int arrayTestCase[testCaseInput.size()];
    copy(testCaseInput.begin(), testCaseInput.end(), arrayTestCase);

    int dynamicResult;
    int dynamicTimeTaken = 0;
    int memoizedResult;
    int memoizedTimeTaken = 0;

    for (int i = 0; i < 3; i++) {
        auto dynamicStart = chrono::steady_clock::now();
        dynamicResult = matrixDynamicProgramming(arrayTestCase, sizeof(arrayTestCase) / sizeof(arrayTestCase[0]));
        auto dynamicEnd = chrono::steady_clock::now();
        dynamicTimeTaken += chrono::duration_cast<chrono::microseconds>(dynamicEnd - dynamicStart).count();
        
        pair<int,int> memoizedRetPair = matrixMemoisationDriver(arrayTestCase, sizeof(arrayTestCase) / sizeof(arrayTestCase[0]));
        memoizedTimeTaken += memoizedRetPair.first;
        memoizedResult = memoizedRetPair.second;
    }

    dynamicTimeTaken /= 3;
    memoizedTimeTaken /= 3;

    if (dynamicTimeTaken > memoizedTimeTaken) {
        outputFile << "The dynamic algorithm took " << double(double(dynamicTimeTaken) / double(memoizedTimeTaken)) << " times longer than the memoized algorithm" << endl; 
        performanceDiff << double(double(dynamicTimeTaken) / double(memoizedTimeTaken)) << " ";
    } else if (memoizedTimeTaken > dynamicTimeTaken) {
        outputFile << "The memoized algorithm took " << double(double(memoizedTimeTaken) / double(dynamicTimeTaken)) << " times longer than the dynamic algorithm" << endl; 
        performanceDiff << double(double(memoizedTimeTaken) / double(dynamicTimeTaken)) << " ";

    } else {
        outputFile << "The dynamic and memoized algorithms ran in the same amount of time" << endl;
    }
    outputFile << endl;
}

int main(int argc, char * argv[]) {
    if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            ofstream outputFile;
            ofstream performanceDiff;

            ifstream testInputs;
            testInputs.open(argv[i]);
            outputFile.open("output.txt");
            performanceDiff.open("performanceDiff.txt", std::ios_base::app);

            if (!testInputs.is_open()) {
                cout << "File was not able to be opened!" << endl;
                exit(1);
            }

            cout << "Using the testing file: " << argv[i] << endl;

            string stringNumberOfTestCases;
            getline(testInputs, stringNumberOfTestCases);
            string arrayDimensionsString;

            for (int i = 0; i < stoi(stringNumberOfTestCases); i++) {
                getline(testInputs, arrayDimensionsString);
                vector<int> testCase;
                string stringToken;
                int stringPosition;
                while ((stringPosition = arrayDimensionsString.find(" ")) != string::npos) {
                    stringToken = arrayDimensionsString.substr(0, stringPosition);
                    testCase.push_back(stoi(stringToken));
                    arrayDimensionsString.erase(0, stringPosition + 1);
                }
                testCase.push_back(stoi(arrayDimensionsString));
                runTestCase(testCase,outputFile,performanceDiff);
            }
            performanceDiff << endl;
        }
    }
    return 0;
}