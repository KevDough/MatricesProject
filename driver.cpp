#include "matrixDynProg.hpp"
#include <iostream>

using namespace std;

int table[150][150];


int matrixMemoisation(int *dimensions, int tableIndex1, int tableIndex2)
{
    if(table[tableIndex1][tableIndex2] != NULL){
        return table[tableIndex1][tableIndex2];
    }

    if(tableIndex1 == tableIndex2){
        return 0;
    }

    table[tableIndex1][tableIndex2] = 2147483647;
    for(int i = tableIndex1; i < tableIndex2; i++){
        table[tableIndex1][tableIndex2] = min(table[tableIndex1][tableIndex2],(matrixMemoisation(dimensions, tableIndex1, i) + matrixMemoisation(dimensions, i+1, tableIndex2) + dimensions[tableIndex1 - 1] * dimensions[i] * dimensions[tableIndex2]));
    }
    return table[tableIndex1][tableIndex2];
}

int matrixMemoisationDriver(int *dimensions, int lengthOfList)
{
    int tableIndex1 = 1;
    int tableIndex2 = lengthOfList - 1;
    int scalarMultCount = matrixMemoisation(dimensions, tableIndex1, tableIndex2);
    return scalarMultCount;
}

int main(){
    int arr[] = { 30, 35, 15, 5, 10, 20, 25};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << matrixDynamicProgramming(arr,n) << endl;
    cout << matrixMemoisationDriver(arr, n) << endl;
    return 0;
}