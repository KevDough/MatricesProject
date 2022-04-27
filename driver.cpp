#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <chrono>

#include "matrixDynProg.hpp"
#include "matrixMemo.hpp"

using namespace std;

void runTestCase(vector<int> testCaseInput) {
    int arrayTestCase[testCaseInput.size()];
    copy(testCaseInput.begin(), testCaseInput.end(), arrayTestCase);
    auto dynamicStart = chrono::steady_clock::now();
    int dynamicResult = matrixDynamicProgramming(arrayTestCase, sizeof(arrayTestCase) / sizeof(arrayTestCase[0]));
    auto dynamicEnd = chrono::steady_clock::now();
    int dynamicTimeTaken = chrono::duration_cast<chrono::nanoseconds>(dynamicEnd - dynamicStart).count();
    cout << "Dynamic: " << dynamicResult << "\t\tTime Taken: " << dynamicTimeTaken << " nanoseconds" << endl;
    auto memoizedStart = chrono::steady_clock::now();
    int memoizedResult = matrixMemoisationDriver(arrayTestCase, sizeof(arrayTestCase) / sizeof(arrayTestCase[0]));
    auto memoizedEnd = chrono::steady_clock::now();
    int memoizedTimeTaken = chrono::duration_cast<chrono::nanoseconds>(memoizedEnd - memoizedStart).count();
    cout << "Memoized: " << memoizedResult << "\t\tTime Taken: " << memoizedTimeTaken << " nanoseconds" << endl;

    if (dynamicTimeTaken > memoizedTimeTaken) {
        cout << "The dynamic algorithm took " << 1 + double(double(dynamicTimeTaken) / double(memoizedTimeTaken)) << " times longer than the memoized algorithm" << endl; 
    } else if (memoizedTimeTaken > dynamicTimeTaken) {
        cout << "The memoized algorithm took " << 1 + double(double(memoizedTimeTaken) / double(dynamicTimeTaken)) << " times longer than the dynamic algorithm" << endl; 
    } else {
        cout << "The dynamic and memoized algorithms ran in the same amount of time" << endl;
    }
    cout << endl;
}

int main(int argc, char * argv[]) {
    if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            ifstream testInputs;
            testInputs.open(argv[i]);

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
                runTestCase(testCase);
            }
        }
    }
    return 0;
}