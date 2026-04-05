#include <stdio.h>
#include <stdlib.h>

int main(void) {
  unsigned char data[8] = {0};  

  data[0] = 'A'; 
  *(short*)&data[1] = 12345; 
  *(int*)&data[3] = 67890; 

  char *c_ptr = (char*)&data[0];
  short *s_ptr = (short*)&data[1];
  int *i_ptr = (int*)&data[3];

  printf("Char: %c\n", *c_ptr);
  printf("Short: %d\n", *s_ptr);
  printf("Int: %d\n", *i_ptr);

  return 0;
}