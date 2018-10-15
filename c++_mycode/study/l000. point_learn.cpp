using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define INT_MAX 0x7fffffff

#define INT_MIN 0x80000000

int countt = 0;
static void print_point_list_8bit(uint8_t *p)
{
	printf("printf point p: count = %d\n", countt);
	for (int i = 0; i < 8; i++) {
		printf("%02x ", p[i]);
	}
	printf("\n");
	countt++;
}
static void print_point_list_8bit(void *p)
{
	printf("printf point p: count = %d\n", countt);
	for (int i = 0; i < 8; i++) {
		printf("%02x ", ((uint8_t *)p)[i]);
	}
	printf("\n");
	countt++;
}
static void __put_unaligned_be16(uint16_t val, uint8_t *p)
{
	*p++ = val >> 8;
	*p++ = val;
}
static void __put_unaligned_be32(uint32_t val, uint8_t *p)
{
	//printf("%I64x\n", val);
	__put_unaligned_be16(val >> 16, p);
	__put_unaligned_be16(val, p + 2);
}
static void __put_unaligned_be64(uint64_t val, uint8_t *p)
{
	__put_unaligned_be32(val >> 32, p);
	//print_point_list_8bit(p);
	__put_unaligned_be32(val, p + 4);
}
static void sg_put_unaligned_be64(uint64_t val, void *p)
{
	//print_point_list_8bit(p);
	__put_unaligned_be64(val, (uint8_t *)p);
}
static void set_64_8(uint64_t val, uint8_t *p)
{
	*p = val;
}
static void set_64_int(uint64_t val, int *p)
{
	printf("指针（地址）的值为：OX%p\n", p);
	*p = val;
	//p = (int*)&val;
	printf("指针（地址）的值为：OX%p\n", p);
}
static void set_32_int(uint32_t val, int *p)
{
	*p = val;
}
bool IsBig_Endian()
{
	unsigned short test = 0x1234;
	if (*((unsigned char*)&test) == 0x12)
		return true;
	else
		return false;
}
bool point_IsBig_Endian()
{
	unsigned short test = 0x1234;
	unsigned short *p = &test;
	if (p[0] == 0x12)
		return true;
	else
		return false;
}
void print_list(unsigned char *num, int start, int size) {
	for (int i = start; i < start + size; i++){
		printf("%02x ", num[i]);
	}
}
void main() {
	int l_test = 0x12345678;
	char *p = (char*)(&l_test);
	cout << sizeof(l_test) << endl;
	if (*p == 0x78) {
		cout << "letter" << endl;
	}
	else {
		cout << "bigger" << endl;
	}
}
void main2()
{
	uint64_t val_64 = 0x123456780a0b0c0d;
	printf("val is: %I64x\n\n", val_64);

	uint8_t *p;
	p = (uint8_t*)malloc(sizeof(uint8_t)*8);
	print_point_list_8bit(p);
	sg_put_unaligned_be64(val_64, p);	//递归赋值
	print_point_list_8bit(p);
	//把一个64bit的值 逐次 从低到高 每8位为一组 赋给 一组指针 指向的空间
	exit(0);
	printf("\n");

	uint8_t p2[8];
	print_point_list_8bit((uint8_t *)p2);
	set_64_8(val_64, p2);				//只赋一次
	print_point_list_8bit((uint8_t *)p2);
	//把一个64bit的值赋给一个    指向8bit空间的指针   那么只会把这个64bit的低8bit赋给这个指针指向的空间

	printf("\n");

	int p3[2];
	print_point_list_8bit((uint8_t *)p3);
	set_64_int(val_64, p3);				//只赋一次
	print_point_list_8bit((uint8_t *)p3);
	//把一个64bit的值赋给一个    指向int空间的指针     那么只会把这个64bit的低32bit倒序赋给这个指针指向的空间

	printf("\n");

	uint32_t val_32 = 0x12345678;
	printf("val is: %I32x\n", val_32);
	int p4[1];
	print_point_list_8bit((uint8_t *)p4);
	set_32_int(val_32, p4);				//只赋一次
	print_point_list_8bit((uint8_t *)p4);
	//把一个32bit的值赋给一个    指向int空间的指针     那么只会把这个64bit的低32bit倒序赋给这个指针指向的空间


	unsigned char scsi_cmd[16];
	uint64_t lba = 0x0000000011112222;
	scsi_cmd[8] = lba;                //08-09             LBA   07:00
	scsi_cmd[9] = lba >> 24;          //                  LBA   31:24
	scsi_cmd[10] = lba >> 8;          //10-11             LBA   15:08
	scsi_cmd[11] = lba >> 32;         //                  LBA   39:32
	scsi_cmd[12] = lba >> 16;         //12-13             LBA   23:16
	scsi_cmd[13] = lba >> 40;         //                  LBA   47:40
	print_list(scsi_cmd, 8, 6);



	uint16_t segment = 4 * 1024 * 8  ;   // 1 MB   max is 32MB  
	printf("%\n");
	printf("%d\n", segment);
	



}
