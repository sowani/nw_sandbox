#include <stdio.h>

typedef enum DestType
{
  PC = 1,
  SC,
  EA,
  TA,
  ALL = 255
} DESTTYPE;

int main (void)
{
  int i;
  DESTTYPE j;

  i = PC;
  j = TA;
  printf ("dest = %d, %d\n", i, j);
  return (0);
}
