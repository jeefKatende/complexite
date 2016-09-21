#ifndef SUBMAX_H_ 
#define SUBMAX_H_

struct SubMax 
{
	int k_max;
	int l_max;
	int sub_max;	
};

void greedyAlgorithm(int *array, int dataLength);

void enhancedAlgorithm(int *array, int dataLength);

struct SubMax divideAndConquerAlgorithm(int *array, int start, int end, struct SubMax subMax);

void subSequenceAlgotithm(int *array, int dataLength); 

#endif