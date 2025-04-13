/*
 * main.c
 *
 *  Created on: Apr 5, 2025
 *      Author: bhara
 */


#include<stdio.h>
#include<stdint.h>

union Packet
{
	uint32_t packet;

	struct{
	uint32_t crc:2;
	uint32_t status:1;
	uint32_t payload:12;
	uint32_t bat:3;
	uint32_t sensor:3;
	uint32_t longAddr:8;
	uint32_t shortAddr:2;
	uint32_t addrMode:1;
	}fields;
};

int main()
{
	union Packet a;
	printf("Enter the 32-bit packet: ");
	scanf("%X", &a.packet);


	//how extract each field using bit manipulation technique

//	a.crc = (uint8_t)(packet & 0x3);
//	a.status = (uint8_t)((packet>>3) & 0x1);
//	a.payload = (uint16_t)((packet>> 4) & 0xFFF);
//	a.bat = (uint8_t)((packet >> 16) & 0x7);
//	a.sensor = (uint8_t)((packet >> 18) & 0x7);
//	a.longAddr = (uint8_t)((packet >> 21) & 0xFF);
//	a.shortAddr = (uint8_t)((packet >> 29) & 0x3);
//	a.addrMode = (uint8_t)((packet >> 31) & 0x1);

	printf("crc: %#X\n", a.fields.crc);
	printf("status: %#X\n", a.fields.status);
	printf("payload: %#X\n", a.fields.payload);
	printf("bat: %#X\n", a.fields.bat);
	printf("sensor: %#X\n", a.fields.sensor);
	printf("longAddr: %#X\n", a.fields.longAddr);
	printf("shortAddr: %#X\n", a.fields.shortAddr);
	printf("addrMode: %#X\n", a.fields.addrMode);

	printf("Size of the union packet is %llu", sizeof(union Packet));


	while(getchar() != '\n');
	getchar();




	return 0;
}
