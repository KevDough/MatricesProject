#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <fstream>

#include <math.h>

using namespace std;

void generateRandom1to10() {
    ofstream testingInput("1to10Testing.txt");
    testingInput << 7 << endl;
    for (int i = 3; i < 10; i++) {
        for (int j = 0; j < pow(2, i) + 1; j++) {
            if (j != pow(2, i)) {
                testingInput << rand() % 10 + 1 << " ";
            } else {
                testingInput << rand() % 10 + 1;
            }
        }
        testingInput << endl;
    }
}

void generateRandom1to100() {
    ofstream testingInput("1to100Testing.txt");
    testingInput << 7 << endl;
    for (int i = 3; i < 10; i++) {
        for (int j = 0; j < pow(2, i) + 1; j++) {
            if (j != pow(2, i)) {
                testingInput << rand() % 100 + 1 << " ";
            } else {
                testingInput << rand() % 100 + 1;
            }
        }
        testingInput << endl;
    }
}

int main() {
    generateRandom1to10();
    generateRandom1to100();
}