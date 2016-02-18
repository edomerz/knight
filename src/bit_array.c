#include "bit_array.h"

#define WORD uint64_t

size_t AllOn(void)
{
	return (~(size_t)0);
}

size_t AllOff(void)	
{
	return ((size_t)0);
}

size_t SetOn(size_t barr, unsigned int index)
{
	return(barr | ((size_t)1 << index));
}
					
size_t SetOff(size_t barr, unsigned int index)
{
	return(barr & ((size_t)0 << index));
}

/*return true or false if bit at the index is on or off respectfully*/
int IsOn(size_t barr, unsigned int index)
{
	return( (barr & ((size_t)1 << index)) ? 1 : 0 );
	/* return( (barr >> index) & 1 ) */
}					

int IsOff(size_t barr, unsigned int index)
{
	return( (barr & ((size_t)1 << index)) ? 0 : 1 );
	/* return(! ((barr >> index) & 1) ) */
}	

/*toggle the state of a bit at index */
size_t WordToggle(size_t barr, unsigned int index)
{
	return( barr ^ ((size_t)1 << index));
}

/*rotate left /right n bits*/
size_t RotL(size_t barr, size_t n)
{
	unsigned int mask = (sizeof(n) * 8 - 1);
	return( (barr << n) | (barr >> ((-n)&mask)) );
}
size_t RotR(size_t barr, size_t n)
{
	unsigned int mask = (sizeof(n) * 8 - 1);
	return( (barr >> n) | (barr << ((-n)&mask)) );
}

/*return mirror image */
size_t WordMirror(size_t barr)
{ 							 
	size_t r = barr;					/* r will be reverset bits of v; first get LSB of v */ 
	int s = (sizeof(barr) * 8) - 2;		/* extra shift needed at end */ 
	
	for(barr >>= 1; barr; barr>>= 1)	
	{
		r <<= 1;
		r |= (barr & (size_t)1);
		--s;
	}
	r <<= s;					/* shift when v's highest bits are zero */ 
	return(r);
}

/*returns the amount of on / off bits*/
unsigned int CountOn(size_t barr)
{
	unsigned int count = 0;
	for( ; barr; ++count)
	{
		barr &= (barr - 1); 			/* clear the LSB  */
	}
	return(count);
	/* alternative
	 unsigned int count = 0;
	 
	 while(count)
	 {
	 	if(barr & (size_t)1)
	 	{
	 		++count;
	 	}
	 	barr >>= 1;
	 }
	 return(count);
	*/
}

unsigned int CountOff(size_t barr)
{
	unsigned int count = 0;
	for( ; barr; ++count)
	{
		barr &= (barr - 1); 			/* clear the LSB  */
	}
	return((sizeof(barr) * 8) - count);
}

/*prints the word in binary representation*/
void PrintBinary(size_t barr)
{
	int i = sizeof(barr) * 8 - 1;
	while(i--)
	{
		(barr >> i) & (size_t)1 ? (printf("1")) : (printf("0"));
	}
}
