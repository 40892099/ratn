/* basic mutation stuff */

#include <stdlib.h>

#define FUZZ_RATIO_PC 0.05

unsigned char* do_byte_percent_mutate(unsigned char *databuf, unsigned int data_buffer_len)
{
	unsigned int bytes_to_fuzz, i, b;
	unsigned char c;
	bytes_to_fuzz = (data_buffer_len * FUZZ_RATIO_PC);
	for (i=0; i<bytes_to_fuzz; i++)
	{
		b = rand() % data_buffer_len;
		c = rand() % 256;
		databuf[b] = c;
	}
	return databuf;
}

// currently we only have 1x type of fuzz
unsigned char* do_fuzz_random(unsigned char *databuf, unsigned int data_buffer_len)
{
  char *retbuf;
  retbuf = do_byte_percent_mutate(databuf, data_buffer_len);
  return retbuf;
}
