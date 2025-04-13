/*
 * main.c
 *
 *  Created on: Mar 31, 2025
 *      Author: bhara
 */


#include<stdio.h>
#include<stdint.h>

void wait(void)
{
	printf("Please press enter key to exit the application");
	while(getchar() != '\n');

	getchar();

}

int main()
{
	int height;
	printf("Enter the height of the pyramid: ");
	scanf("%d", &height);
	for(int i=1; i<=height; i++)
	{
		for(int j=i; j>0; j--)
			printf("%4d ",j);
		printf("\n");
	}

	wait();
	return 0;
}
