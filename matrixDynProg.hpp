using namespace std;
#define INF 2147483647 

int matrixDynamicProgramming(int dimensions[], int lengthOfList)
{
    int table[lengthOfList][lengthOfList];
    int tableIndex1, tableIndex2;
    int scalarMultCount = 0;

    //fill table with 0s
    for (int dimensionIndex = 1; dimensionIndex < lengthOfList; dimensionIndex++)
        table[dimensionIndex][dimensionIndex] = 0;
 

    for (int chainLength = 2; chainLength < lengthOfList; chainLength++){
    
        for (int dimensionIndex = 1; dimensionIndex < lengthOfList - chainLength + 1; dimensionIndex++){
        
            tableIndex1 = dimensionIndex + chainLength - 1;
            table[dimensionIndex][tableIndex1] = INF;
            for (tableIndex2 = dimensionIndex; tableIndex2 <= tableIndex1 - 1; tableIndex2++){
            
                scalarMultCount = table[dimensionIndex][tableIndex2] + table[tableIndex2 + 1][tableIndex1] + 
                                  dimensions[dimensionIndex - 1] * dimensions[tableIndex2] * dimensions[tableIndex1];
                
                if (scalarMultCount < table[dimensionIndex][tableIndex1])
                    table[dimensionIndex][tableIndex1] = scalarMultCount;
            }
        }
    }
 
    return table[1][lengthOfList - 1];
}