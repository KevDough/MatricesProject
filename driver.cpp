#include "matrixDynProg.hpp"
#include <iostream>

using namespace std;
int main(){
    int arr[] = { 30, 35, 15, 5, 10, 20, 25};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << matrixDynamicProgramming(arr,n) << endl;
    return 0;
}