#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>

#include "matrixDynProg.hpp"
#include "matrixMemo.hpp"

using namespace std;

void runTestCase(vector<int> testCaseInput) {
    int arrayTestCase[testCaseInput.size()];
    copy(testCaseInput.begin(), testCaseInput.end(), arrayTestCase);
    cout << "Dynamic: " << matrixDynamicProgramming(arrayTestCase, sizeof(arrayTestCase) / sizeof(arrayTestCase[0])) << endl;
    cout << "Memoized: " << matrixMemoisationDriver(arrayTestCase, sizeof(arrayTestCase) / sizeof(arrayTestCase[0])) << endl;
}

int main() {
    ifstream testInputs;
    testInputs.open("testingInputs.txt");

    if (!testInputs.is_open()) {
        cout << "File was not able to be opened!" << endl;
    }
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
    // int arr[] = { 30, 35, 15, 5, 10, 20, 25};
    // int n = sizeof(arr) / sizeof(arr[0]);
    // cout << "Dynamic: " << matrixDynamicProgramming(arr,n) << endl;
    // cout << "Memo: " << matrixMemoisationDriver(arr, n) << endl;
    return 0;
}