/*
Assignment name  : print_bits
Expected files   : print_bits.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a function that takes a byte, and prints it in binary WITHOUT A NEWLINE
AT THE END.

Your function must be declared as follows:

void	print_bits(unsigned char octet);

Example, if you pass 2 to print_bits, it will print "00000010"
*/

#include <unistd.h>

/*
*	1. assign 7 bit for it
*	2. loop through the bit and start from back (must start from 0)
*	3. use "octet & (1 << bit)" to get 1 or 0
*	note: bitwise left to open the position 1
	      bitwise and to compare if both same then return
*	4. if return 1 then write 1
*	5. if is 0 write 0
*/
void	print_bits(unsigned char octet)
{
	int bit = 7;
	while (0 <= bit)
	{
		if (octet & (1 << bit)) // "<<" 1 stating position is 8 and count from right. "&" is to compare the both bit
			write(1, "1", 1);
		else
			write(1, "0", 1);
		bit--;
	}
}

int main()
{
	print_bit(2);
}
/*
*example: 0000 0010 & 1000 0000 = 0
	  0000 0010 & 0100 0000 = 0
   	  0000 0010 & 0010 0000 = 0
   	  0000 0010 & 0001 0000 = 0
          0000 0010 & 0000 1000 = 0
	  0000 0010 & 0000 0100 = 0
	  0000 0010 & 0000 0010 = 1
	  0000 0010 & 0000 0001 = 0
	  result will be 0000 0010
*/
