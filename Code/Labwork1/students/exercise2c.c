#include <stdio.h>


//const int nb = 10;
//const int excluded = 5;

#define nb 10
#define excluded 5

int main ()
{
  printf("enter %d values\n",nb);
  int values[nb];
  int i;
  for (i=0; i<nb; i++)
    scanf("%d",&values[i]);

  int nbval = 0;
  for (i=0; i<nb; i++)
    switch (values[i]) {
    case excluded-1: break;
    case excluded  : break;
    case excluded+1:
      ++nbval;
      break;
    }

    printf("%d forbidden values\n",nbval);
  return 0;
}
