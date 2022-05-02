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
    auto dynamicStart = chrono::steady_clock::now();
    int dynamicResult = matrixDynamicProgramming(arrayTestCase, sizeof(arrayTestCase) / sizeof(arrayTestCase[0]));
    auto dynamicEnd = chrono::steady_clock::now();
    int dynamicTimeTaken = chrono::duration_cast<chrono::microseconds>(dynamicEnd - dynamicStart).count();
    outputFile << "Dynamic: " << dynamicResult << "\t\tTime Taken: " << dynamicTimeTaken << " microseconds" << endl;
    //auto memoizedStart = chrono::steady_clock::now();
    pair<int,int> memoizedRetPair = matrixMemoisationDriver(arrayTestCase, sizeof(arrayTestCase) / sizeof(arrayTestCase[0]));
    int memoizedTimeTaken = memoizedRetPair.first;
    int memoizedResult = memoizedRetPair.second;
    //auto memoizedEnd = chrono::steady_clock::now();
    //int memoizedTimeTaken = chrono::duration_cast<chrono::microseconds>(memoizedEnd - memoizedStart).count();

    outputFile << "Memoized: " << memoizedResult << "\t\tTime Taken: " << memoizedTimeTaken << " microseconds" << endl;

    if (dynamicTimeTaken > memoizedTimeTaken) {
        outputFile << "The dynamic algorithm took " << double(double(dynamicTimeTaken) / double(memoizedTimeTaken)) << " times longer than the memoized algorithm" << endl; 
        performanceDiff << double(double(dynamicTimeTaken) / double(memoizedTimeTaken)) << endl;
    } else if (memoizedTimeTaken > dynamicTimeTaken) {
        outputFile << "The memoized algorithm took " << double(double(memoizedTimeTaken) / double(dynamicTimeTaken)) << " times longer than the dynamic algorithm" << endl; 
        performanceDiff << double(double(memoizedTimeTaken) / double(dynamicTimeTaken)) << endl;

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
            performanceDiff.open("performanceDiff.txt");

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
        }
    }
    return 0;
}