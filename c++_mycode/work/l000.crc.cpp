#include <stdio.h>
typedef unsigned int hint_t;	/* we want a 32 bit unsigned integer here */

typedef struct hash_t {
	hint_t	h1;
	hint_t	h2;
} hash_t;

typedef struct Hash {
	struct Hash *ha_Next;
	hash_t	ha_Hv;
} Hash;

#define TESTHSIZE	(4 * 1024 * 1024)
#define TESTHMASK	(TESTHSIZE - 1)

void inithash(void);
hash_t testhash(const char *p);

Hash	*HashAry[TESTHSIZE];
int	UniqueOpt;
int	HashLimit = 64;
int	VerboseOpt = 0;
int	QuietOpt = 0;


#define HINIT1	0xFAC432B1UL
#define HINIT2	0x0CD5E44AUL

#define POLY1	0x00600340UL
#define POLY2	0x00F0D50BUL

hash_t CrcXor[256];
hash_t Poly[64 + 1];

void
inithash(void)
{
	int i;

	/*
	* Polynomials to use for various crc sizes.  Start with the 64 bit
	* polynomial and shift it right to generate the polynomials for fewer
	* bits.  Note that the polynomial for N bits has no bit set above N-8.
	* This allows us to do a simple table-driven CRC.
	*/

	Poly[64].h1 = POLY1;
	Poly[64].h2 = POLY2;
	for (i = 63; i >= 16; --i) {
		Poly[i].h1 = Poly[i + 1].h1 >> 1;
		Poly[i].h2 = (Poly[i + 1].h2 >> 1) | ((Poly[i + 1].h1 & 1) << 31) | 1;
	}

	for (i = 0; i < 256; ++i) {
		int j;
		int v = i;
		hash_t hv = { 0, 0 };

		for (j = 0; j < 8; ++j, (v <<= 1)) {
			hv.h1 <<= 1;
			if (hv.h2 & 0x80000000UL)
				hv.h1 |= 1;
			hv.h2 = (hv.h2 << 1);
			if (v & 0x80) {
				hv.h1 ^= Poly[HashLimit].h1;
				hv.h2 ^= Poly[HashLimit].h2;
			}
		}
		CrcXor[i] = hv;
	}
}

void inithash(void);
hash_t testhash(const char *p);
hash_t
testhash(const char *p)
{
	hash_t hv = { HINIT1, HINIT2 };

	if (HashLimit <= 32) {
		int s = HashLimit - 8;
		hint_t m = (hint_t)-1 >> (32 - HashLimit);

		hv.h1 = 0;
		hv.h2 &= m;

		while (*p) {
			int i = (hv.h2 >> s) & 255;
			/* printf("i = %d %08lx\n", i, CrcXor[i].h2); */
			hv.h2 = ((hv.h2 << 8) & m) ^ *p ^ CrcXor[i].h2;
			++p;
		}
	}
	else if (HashLimit < 32 + 8) {
		int s2 = 32 + 8 - HashLimit;	/* bits in byte from h2 */
		hint_t m = (hint_t)-1 >> (64 - HashLimit);

		hv.h1 &= m;
		while (*p) {
			int i = ((hv.h1 << s2) | (hv.h2 >> (32 - s2))) & 255;
			hv.h1 = (((hv.h1 << 8) ^ (int)(hv.h2 >> 24)) & m) ^ CrcXor[i].h1;
			hv.h2 = (hv.h2 << 8) ^ *p ^ CrcXor[i].h2;
			++p;
		}
	}
	else {
		int s = HashLimit - 40;
		hint_t m = (hint_t)-1 >> (64 - HashLimit);

		hv.h1 &= m;
		while (*p) {
			int i = (hv.h1 >> s) & 255;
			hv.h1 = ((hv.h1 << 8) & m) ^ (int)(hv.h2 >> 24) ^ CrcXor[i].h1;
			hv.h2 = (hv.h2 << 8) ^ *p ^ CrcXor[i].h2;
			++p;
		}
	}
	/* printf("%08lx.%08lx\n", (long)hv.h1, (long)hv.h2); */
	return(hv);
}
int main() {
	int i;
	inithash();
	hash_t hv;
	char *s = "12345";
	hv = testhash(s);
	i = (hv.h1 ^ hv.h2) & TESTHMASK;
	printf("%08x.%08x (%d) %s\n", hv.h1, hv.h2, i, s);
	return 0;
}