#include <stdio.h>
#include <stdlib.h>

#include "submax.h"

/***
 * This function implements a greedy algorithm whitch test all all availaible possibilities 
 * to compute the maximum sum of consecutive items of a given array.
 * Here is the pseudo code and a c-program implemented in a order to verify the result of our
 * idea.
 * 
 * Pseudo Code 
 * Input : Array of integers (long, float, Double) 
 * Initialize current maximum with the the first array item.
 * Initialize the computed sum to 0
 * for indexI<-- 1 : arrayLength	
 * 		for indexJ <-- inxdexI : arrayLength
 *			computedSum = 0
 * 			for indexK <-- indexI : indexJ
 * 				computedSum += array[indexK];
 *				compare and store if needed the new values.
 *
 * Note that this algorithm is provided with a strickly positive indexes it your duty to implement with 
 * indexes coorresponding to your programming language.
 */
void greedyAlgorithm(int *array, int dataLength){
	int indexI, indexJ, indexK, k_max, l_max, currentMax, currentSum;
	currentMax = *array;

	for (indexI = 0; indexI < dataLength; indexI++){
		for(indexJ = indexI; indexJ < dataLength; indexJ++){
			currentSum = 0;
			indexK = indexJ;
			for(indexK = indexI; indexK <= indexJ; indexK++){
				currentSum += *(array + indexK);
				if(currentSum > currentMax){
					k_max = indexI;
					l_max = indexJ;
					currentMax = currentSum;
					printf("Step max value found with the following results [%d, %d], where the maximum value of : %d\n", k_max, l_max, currentMax);
				}
			}
		}
	}
	
}
/**
 * This function implements an enhanced algorithm to compute the maximum successicive sub array based on the assumption that the sum
 * of an array items is equal to the sum of its previous items plus the last item. We intend to enhance our previous algorithm in order
 * to improve it perf.
 * 
 * Pseudo Code
 * Input Array
 * Initialize the current maximum with the first array item.
 * Initialize the computed sum to 0.
 *
 * for indexI <-- 1 : arrayLength - 1
 *		set current sum to zero
 *		for indexJ <-- indexI : arrayLength - 1
 * 			compute the current sum, compare to the current maximum and update if needed 
 * 			
 * Note that these algorithm is provided with indexes stated from one to the length of the the given array, it up to you to make it 
 * fit your programming language.
 */
void enhancedAlgorithm(int *array, int dataLength){
	int indexI, indexJ, k_max, l_max, currentMax, currentSum;
	currentMax = *array;
	for(indexI = 0; indexI < dataLength - 1; indexI++){
		currentSum = 0;
		for(indexJ = indexI; indexJ < dataLength - 1; indexJ++){
			currentSum += *(array + indexJ + 1);
			if(currentSum > currentMax){
				k_max = indexI + 1;
				l_max = indexJ + 1;
				currentMax = currentSum;
				printf("Step max value found with the following results [%d, %d], where the maximum value of : %d\n", k_max, l_max, currentMax);
			}
		}
	}
}

/**
 * The divide and conquer is our third algorithm, this algorithm principle is to split a given problem to small ones that are easy to
 * process and has an advantage of improving the processing performance when large arrays are supplied.
 *
 * Pseudo Code :
 * given an array A, a starting and ending points 
 * compute : the middle point so that the array is half splitted 
 * 			 call the algorithm to each half array and sum the whole items in the array from starting to the ending point and 
 *			 compare to find out the maximum of the three computed values.
 * 
 * Here is our algorithm 
 * if startPoint == endingPoint 
 *		maximum = item at the startingPoint
 * else
 * 		max1 = divideAndConquerAlgorithm of first half
 * 		max2 = divideAndConquerAlgorithm of second half
 *      max3 = sum of items from startingPoint to endingPoint 
 * 		max = (max1, max2, max3);
 *
 * Get bounderies of a choosen max subsequence.
 */
struct SubMax divideAndConquerAlgorithm(int *array, int start, int end, struct SubMax subMax){
	int middlePoint, index;
	struct SubMax subMaxPre, subMaxForward;
	int stepSum = 0;

	if(start == end){
		subMax.sub_max = array[start];
		subMax.k_max = start;
		subMax.l_max = end; /** printf("%d value is %d \n", end, subMax.sub_max); **/
	}else{
		middlePoint = (int)((start + end)/2); /*printf("%d\n", middlePoint); */
		subMaxPre = divideAndConquerAlgorithm(array, start, middlePoint, subMax);
		subMaxForward = divideAndConquerAlgorithm(array, middlePoint + 1, end, subMax);
		/**printf("pre tab [%d , %d] sum %d\n", start, middlePoint, subMaxPre.sub_max);
		printf("next tab [%d , %d] sum %d\n", middlePoint, end, subMaxForward.sub_max);
		printf("\n"); **/
		for(index = start; index < end; index++){ 			
			stepSum += array[index]; /** printf("%d ", stepSum); **/
		}
		/** printf("\nStep Sum %d\n", stepSum); **/
		if(stepSum > subMax.sub_max){
			subMax.sub_max = stepSum;
			subMax.k_max = start;
			subMax.l_max = end;
		}

		if (subMaxPre.sub_max > subMax.sub_max){
			subMax.sub_max = subMaxPre.sub_max;
			subMax.k_max = start;
			subMax.l_max = middlePoint;
		}

		if(subMaxForward.sub_max > subMax.sub_max){
			subMax.sub_max = subMaxForward.sub_max;
			subMax.k_max = middlePoint + 1;
			subMax.l_max = end;
		}
	}
	return subMax;
}

/**
 *
 */
void subSequenceAlgotithm(int *array, int dataLength){}