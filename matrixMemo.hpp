#include <iostream>
#include <chrono>
using namespace std;
#define INF 2147483647 

int table[2049][2049];
int previous;

int matrixMemoisation(int *dimensions, int tableIndex1, int tableIndex2)
{
    if(table[tableIndex1][tableIndex2] != '\0'){
        return table[tableIndex1][tableIndex2];
    }

    if(tableIndex1 == tableIndex2){
        return 0;
    }

    table[tableIndex1][tableIndex2] = INF;
    for(int i = tableIndex1; i < tableIndex2; i++){
        table[tableIndex1][tableIndex2] = min(table[tableIndex1][tableIndex2],(matrixMemoisation(dimensions, tableIndex1, i) + matrixMemoisation(dimensions, i+1, tableIndex2) + dimensions[tableIndex1 - 1] * dimensions[i] * dimensions[tableIndex2]));
    }
    return table[tableIndex1][tableIndex2];
}

pair<int,int> matrixMemoisationDriver(int *dimensions, int lengthOfList)
{
    for(int i = 0;i<lengthOfList;i++){
        for(int j = 0;j<lengthOfList;j++){
            table[i][j] = 0;
        }
    }
    auto memoizedStart = chrono::steady_clock::now();
    int tableIndex1 = 1;
    int tableIndex2 = lengthOfList - 1;
    int scalarMultCount = matrixMemoisation(dimensions, tableIndex1, tableIndex2);
    auto memoizedEnd = chrono::steady_clock::now();
    int memoizedTimeTaken = chrono::duration_cast<chrono::microseconds>(memoizedEnd - memoizedStart).count();
    pair<int,int> retPair;
    retPair.first = memoizedTimeTaken;
    retPair.second = scalarMultCount;
    return retPair;
}