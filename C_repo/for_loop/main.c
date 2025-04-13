/*
 * main.c
 *
 *  Created on: Mar 31, 2025
 *      Author: bhara
 */


#include<stdio.h>
#include<stdint.h>

void wait();

int main()
{
	int start;
	int end;
	printf("\nEnter the start and end numbers(give space between 2 nos): ");
//	fflush(stdout); // use this if you are using IDE console for observing output
	scanf("%d %d", &start, &end);

	if(start>end)
	{
		printf("Ending number > starting number");
		wait();
		return 0;

	}
	int count = 0;

	for(; start<=end; start++)
	{
		if(!(start % 2))
		{
			printf("%5d ", start);
			count++;
		}
	}

	printf("\nNo. of even numbers is %d\n", count );
	wait();
	return 0;
}

void wait(void)
{
	printf("Press enter key to exit this application");
	while(getchar() != '\n');
	getchar();

}

