// Assignment name  : reverse_bits
// Expected files   : reverse_bits.c
// Allowed functions:
// --------------------------------------------------------------------------------
//
// Write a function that takes a byte, reverses it, bit by bit (like the
// example) and returns the result.
//
// Your function must be declared as follows:
//
// unsigned char	reverse_bits(unsigned char octet);
//
// Example:
//
//   1 byte
// _____________
//  0010  0110
// 	 ||
// 	 \/
//  0110  0100


/*
*	1. assign bit with 7
*	2. initialize res
*	3. loop the bit and start from back (start from 0)
*	4. "res * 2 + (octet % 2)" to input 0 from right
*	5. "octet / 2" to remove 0 from left
*	6. return res
*/
unsigned char	reverse_bits(unsigned char octet)
{
	int		bit = 7;
	unsigned char	res = 0;

	while (0 <= bit)
	{
		res = res * 2 + (octet % 2); //shift left and add the last bit (this to cal res to use)
		octet = octet / 2; //shift right (this to cal octet to use)
		bit--;
	}
	return (res);
}

/*
*	example:
*	a = ascii(97) = 01100001
*
*	iteration 1:
*	res = 0 * 2 + (97 % 2) = 1(00000001)
*	octet = 97 / 2 = 48(00110000)
*
*	iteration 2:
*	res = 1 * 2 + (48 % 2) = 2(00000010)
*	octet = 48 / 2 = 24(00011000)
*
*	iteration 3:
*	res = 2 * 2 + (24 % 2) = 4(00000100)
*	octet = 24 / 2 = 12(00001100)
*
*	iteration 4:
*	res = 4 * 2 + (12 % 2) = 8(00001000)
*	octet = 12 / 2 = 6(00000110)
*
*	iteration 5:
*	res = 8 * 2 + (6 % 2) = 16(00010000)
*	octet = 6 / 2 = 3(00000011)
*
*	iteration 6:
*	res = 16 * 2 + (3 % 2) = 33(00100001)
*	octet = 3 / 2 = 1(00000001)
*
*	iteration 7:
*	res = 33 * 2 + (1 % 2) = 67(01000011)
*	octet = 1 / 2 = 0(00000000)
*
*	iteration 8:
*	res = 67 * 2 + (0 % 2) = 134(10000110)
*	octet = 0 / 2 = 0(00000000)
*	
*	result: 
*	134 that is 10000110
 * */
