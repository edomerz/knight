/*******************************************************************************

bit_array
WORD size  =  (64 bits) uint64_t.
bits index starts at 0  

******************************************************************************/
	

#ifndef __bit_array_h__
#define __bit_array_h__


#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdint.h>

/*turns all the bits in a word  On or off*/ 		
size_t AllOn(void);						
size_t AllOff(void);	

/*turns on / off a bit at the given index (0 to 63) */
size_t SetOn(size_t barr, unsigned int index);						
size_t SetOff(size_t barr, unsigned int index);	

/*return true or false if bit at the index is on or off respectfully*/
int IsOn(size_t barr, unsigned int index);						
int IsOff(size_t barr, unsigned int index);		

/*toggle the state of a bit at index */
size_t WordToggle(size_t barr, unsigned int index);	

/*rotate left /right n bits*/
size_t RotL(size_t barr, size_t n);						
size_t RotR(size_t barr, size_t n);	

/*return mirror image */
size_t WordMirror(size_t barr);						

/*returns the amount of on / off bits*/
unsigned int CountOn(size_t barr);						
unsigned int CountOff(size_t barr);

/*prints the word in binary representation*/
void PrintBinary(size_t barr);

#endif /* ifndef __bit_array_h__ */

