#include<stdio.h>

struct Packet
{
	char data1;
	int data2;
	char data3;
	short data4;
};

int main(void)
{
	struct DataSet data;

	data.data1 = 0x11;
	data.data2 = 0xFFFFEEEE;
	data.data3 = 0x22;
	data.data4 = 0xABCD;

	printf("Before: %X\n", data.data1);

	struct DataSet *ptr;

	ptr = &data;

	printf("after: %X", ptr->data1);

	while(getchar() != '\n');

	getchar();

	return 0;

}
