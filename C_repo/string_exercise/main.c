/*
 * main.c
 *
 *  Created on: Apr 13, 2025
 *      Author: bhara
 */

#include<stdio.h>
#include<stdint.h>

typedef struct
{
	int rollnumber;
	char name[40];
	char branch[30];
	char dob[10];
	int semester;

}STUDENT_INFO_t;

//prototype
void display_record(STUDENT_INFO_t *, int *);
void new_record(STUDENT_INFO_t *, int *, int);
void delete_record(STUDENT_INFO_t *, int *);

int main()
{
	int size = 10;
	STUDENT_INFO_t database[size];
	int count = 0;
	int *record_count = &count;
	printf("Student Record Management Program\n\n");
	//super loop
	while(1)
	{
		int option;
		printf("Display all record --> 1\n");
		printf("Add new record --> 2\n");
		printf("Delete a record --> 3\n");
		printf("Exit application --> 0\n");
		printf("Enter your option here: ");
		scanf("%d", &option);

		switch(option){
		case 1:
			display_record(database,record_count);
			break;

		case 2:
			new_record(database, record_count, size);
			break;

		case 3:
			delete_record(database, record_count);
			break;

		case 0:
			return 0;

		default:
			printf("\nInvalid Option\n\n");
			continue;
		}
	}


}

void display_record(STUDENT_INFO_t *database, int *record_count)
{
	printf("\nDisplaying all records\n");

	if(*record_count == 0)
	{
		printf("No records found\n");
		return;
	}
	else
	{
		for(int i=0; i< *record_count; i++)
		{
			printf("\nRollnumber : %d", database[i].rollnumber);
			printf("\nName : %s", database[i].name);
			printf("\nDOB : %s", database[i].dob);
			printf("\nBranch : %s", database[i].branch);
			printf("\nSemester : %d\n\n", database[i].semester);
		}
	}
}

void new_record(STUDENT_INFO_t *database, int *record_count, int size){
	printf("Add a record\n");
	if(*record_count >= size)
	{
		printf("Maximum records reached");
		return;
	}
	else
	{
		printf("Enter the rollnumber: ");
		int temp_roll;
		scanf("%d", &temp_roll);

		//check roll number exists or not

		for(int i=0; i<*record_count; i++)
		{
			if(database[i].rollnumber == temp_roll)
			{
				printf("Roll number already exists\n\n");
				return;
			}
		}

		database[*record_count].rollnumber = temp_roll;
		printf("Enter name : ");
		scanf(" %[^\n]s",database[*record_count].name);
		printf("\nEnter branch name : ");
		scanf(" %[^\n]s",database[*record_count].branch);
		printf("Enter DOB in dd/mm/yyyy : ");
		scanf(" %[^\n]s",database[*record_count].dob);
		printf("Enter Semester : ");
		scanf("%d",&database[*record_count].semester);
		printf("\nRecord created successfully\n");
		*record_count +=1;
	}

}

void delete_record(STUDENT_INFO_t *database, int *record_count)
{
	printf("\nDelete a Record\n");

	if(*record_count == 0)
	{
		printf("No records to delete\n");
		return;
	}
	else
	{
		int roll;
		printf("Enter roll number to delete: ");
		scanf("%d", &roll);

		int found = 0;
		for(int i = 0; i < *record_count; i++)
		{
			if(database[i].rollnumber == roll)
			{
				// Shift all records after the deleted one
				for(int j = i; j < *record_count - 1; j++)
				{
					database[j] = database[j + 1];
				}
				(*record_count)--;
				printf("Record deleted successfully\n");
				found = 1;
				break;
			}
		}

		if(!found)
			printf("Record with roll number %d not found\n", roll);
	}
}
