/*
 * main.c
 *
 *  Created on: Apr 12, 2025
 *      Author: bhara
 */

#include<stdio.h>
#include<stdint.h>

void ArrSwap(uint32_t *arr1, uint32_t *arr2, uint32_t i, uint32_t j);
void printArr(uint32_t *arr, uint32_t len);


int main()
{
	int len1;
	int len2;
	printf("Enter the length of arr1 and arr2 space seperated: ");
	scanf("%u %u",&len1, &len2);

	uint32_t arr1[len1];
	uint32_t arr2[len2];

	for(uint32_t i = 0; i<len1; i++)
	{
		printf("Enter %u value of arr1: ",i+1);
		scanf("%u", &arr1[i]);
	}

	printf("\n\n");

	for(uint32_t i = 0; i<len2; i++)
	{
		printf("Enter %u value of arr2: ",i+1);
		scanf("%u", &arr2[i]);
	}

	printf("\n\n");

	ArrSwap(arr1,arr2,len1,len2);

	printf("Printing Arr1: ");
	printArr(arr1,len1);
	printf("Printing Arr2: ");
	printArr(arr2,len2);

	while(getchar() != '\n');

	getchar();


}

void ArrSwap(uint32_t *arr1, uint32_t *arr2, uint32_t i, uint32_t j)
{
	uint32_t count = (i <= j) ? i : j;
	uint32_t k = 0;

	while(count--)
	{
		arr1[k] ^= arr2[k];
		arr2[k] ^= arr1[k];
		arr1[k] ^= arr2[k];
		k++;
	}
}


void printArr(uint32_t *arr, uint32_t len)
{
	for(uint32_t i=0; i<len; i++)
	{
		printf("%u\t", arr[i]);
	}
	printf("\n\n");
}
