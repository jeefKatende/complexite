#include <stdio.h>
#include <stdlib.h>

int dataLength = 10;

//La sous séquence de somme maximale est [2:4]



//La sous séquence de somme maximale est [7:94]

void greedyAlgorithm(){
	int indexI, indexJ, indexK, k_max, l_max;
	int tmpSum = 0, currentSum = 0;

	for(indexI = 0; indexI < dataLength; indexI++){
		for(indexJ = indexI; indexJ < dataLength; indexJ++){
			currentSum = 0;
			for(IndexK = IndexJ; indexk < dataLength; indexK){
				currentSum += data[indexK]; 
				if(currentSum > tmpSum){
					k_max = indexI;
					l_max = IndexJ;
					tmpSum = currentSum;
					printlf("Step max value found with the following results [%d, %d], where the maximum value of : %d\n", k_max, l_max, tmpSum);
				}
			}
			
		}
	}

}


void enhancedAlgorithm(){
	int indexI, indexJ, currentSum, tmpSum;
	int currentMax = data[0];
	for(indexI = 0; indexI < dataLength; indexI++){
		currentSum = data[indexI];
		for (indexJ = indexI+1; indexJ < dataLength; indexJ++){
			/* code */
			currentSum += data[indexJ];
			if(currentSum > currentMax){
				k_max = indexI;
				l_max = IndexJ;
				currentMax = currentSum;
				printlf("Step max value found with the following results [%d, %d], where the maximum value of : %d\n", k_max, l_max, tmpSum);
			}
		}
		
	}
}

void divideAndConquerAlgorithm(int *data, int start, int end){

}

