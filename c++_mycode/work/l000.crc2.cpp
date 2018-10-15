#include <stdio.h>
#include <stdlib.h>

typedef unsigned char byte;

//CRC-8 - based on the CRC8 formulas by Dallas/Maxim
//code released under the therms of the GNU GPL 3.0 license
byte CRC8(const byte *data, byte len) {
	byte crc = 0x00;
	while (len--) {
		byte extract = *data++;
		for (byte tempI = 8; tempI; tempI--) {
			byte sum = (crc ^ extract) & 0x01;
			crc >>= 1;
			if (sum) {
				crc ^= 0x8C;//1000 1100
			}
			extract >>= 1;
		}
	}
	return crc;
}

void main()
{
	const byte test1[6] = { 3, 2, 10, 56, 23, 0 };
	const byte test2[6] = { 2, 3, 10, 56, 23, 0 };

	printf("\r\n CRC8 for test1: %d  CRC8for test2: %d \r\n", CRC8(&test1[0], 6), CRC8(&test2[0], 6));
}
