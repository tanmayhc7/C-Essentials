/*
 ============================================================================
 Name        : Structs&Unions.c
 Author      : Tanmay
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {
	uint8_t a;
	uint16_t b;
	uint32_t c;
}s1;

typedef struct {
	uint8_t a;
	uint32_t c;
	uint16_t b;
}s2;

typedef struct {
	uint8_t a;
	uint32_t c;
	uint16_t b;
}__attribute__((packed))s3;

typedef struct {
	unsigned a:1;
	unsigned b:1;
	uint32_t c;
}s4;

typedef struct {
	unsigned a:1;
	unsigned b:1;
	uint32_t c;
}__attribute__((packed))s5;

typedef union {
	uint8_t a;
	uint16_t b;
	uint32_t c;
}u1;

typedef union
{
    unsigned int full32bit;
    // This assumes Little Endian machine otherwise byte order is swapped.
    struct {
        unsigned int byte0 : 8; // b7  : b0
        unsigned int byte1 : 8; // b15 : b8
        unsigned int byte2 : 8; // b23 : b16
        unsigned int byte3 : 8; // b31 : b24
    }__attribute__((packed));
} u2;

int main(void) {

	s1 *p1=malloc(sizeof(s1));
	printf("A: Size: %d Address: 0x%.2x\n",sizeof(p1->a),&(p1->a)); //0x01 is padded for better access
	printf("B: Size: %d Address: 0x%.2x\n",sizeof(p1->b),&(p1->b));
	printf("C: Size: %d Address: 0x%.2x\n",sizeof(p1->c),&(p1->c));
	printf("S1: Size: %d Address: 0x%.2x\n",sizeof(s1),p1);
	printf("-------------------\n");
	free(p1);

	s2 *p2=malloc(sizeof(s2));
	printf("A: Size: %d Address: 0x%.2x\n",sizeof(p2->a),&(p2->a));//0x01 02 03 are padded
	printf("B: Size: %d Address: 0x%.2x\n",sizeof(p2->b),&(p2->b));
	printf("C: Size: %d Address: 0x%.2x\n",sizeof(p2->c),&(p2->c));
	printf("S2: Size: %d Address: 0x%.2x\n",sizeof(s2),p2);
	free(p2);
	printf("-------------------\n");

	s3 *p3=malloc(sizeof(s3));
	printf("A: Size: %d Address: 0x%.2x\n",sizeof(p3->a),&(p3->a));//attribute packed discards padding and saves memory
	printf("B: Size: %d Address: 0x%.2x\n",sizeof(p3->b),&(p3->b));
	printf("C: Size: %d Address: 0x%.2x\n",sizeof(p3->c),&(p3->c));
	printf("S3: Size: %d Address: 0x%.2x\n",sizeof(s3),p3);
	free(p3);
	printf("-------------------\n");

	s4 *p4=malloc(sizeof(s4));
	printf("C: Size: %d Address: 0x%.2x\n",sizeof(p4->c),&(p4->c));//aligned to byte boundary
	printf("S4: Size: %d Address: 0x%.2x\n",sizeof(s4),p4);
	free(p4);
	printf("-------------------\n");

	s5 *p5=malloc(sizeof(s5));
	printf("C: Size: %d Address: 0x%.2x\n",sizeof(p5->c),&(p5->c));//packing has no effect on bit fields
	printf("S5: Size: %d Address: 0x%.2x\n",sizeof(s5),p5);
	free(p5);
	printf("-------------------\n");

	u1 *p6=malloc(sizeof(u1));
	p6->c=0xffffffff;
	printf("A: Size: %d Address: 0x%.2x Data: %x\n",sizeof(p6->a),&(p6->a),p6->a);//all members share the same location and data
	printf("B: Size: %d Address: 0x%.2x Data: %x\n",sizeof(p6->b),&(p6->b),p6->b);
	printf("C: Size: %d Address: 0x%.2x Data: %x\n",sizeof(p6->c),&(p6->c),p6->c);
	printf("U1: Size: %d Address: 0x%.2x\n",sizeof(u1),p6);//Union size is the size of the largest element
	printf("-------------------\n");

	u2 var;
	var.byte0 = 1;
	var.byte1 = 1;
	printf("%i\n", var.full32bit); // This will print 257

	var.byte0 = 0;
	printf("%i\n", var.full32bit); // This will print 256

	return 0;
}
