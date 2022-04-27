#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <fstream>

#include <math.h>

using namespace std;

void generateRandom0to10() {
    ofstream testingInput("0to10Testing.txt");
    cout << "Random Generation " << 0 << " to " << 10 << endl;
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

void generateRandom0to100() {
    ofstream testingInput("0to100Testing.txt");
    cout << "Random Generation " << 0 << " to " << 100 << endl;
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

// void generateRandom0to1000() {
//     ofstream testingInput("0to1000Testing.txt");
//     cout << "Random Generation " << 0 << " to " << 1000 << endl;
//     testingInput << 5 << endl;
//     for (int i = 3; i < 8; i++) {
//         for (int j = 0; j < pow(2, i) + 1; j++) {
//             if (j != pow(2, i)) {
//                 testingInput << rand() % 1000 + 1 << " ";
//             } else {
//                 testingInput << rand() % 1000 + 1;
//             }
//         }
//         testingInput << endl;
//     }
// }

int main() {
    generateRandom0to10();
    generateRandom0to100();
    // generateRandom0to1000();
}