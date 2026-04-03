#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>

int main(void)
{int a = 11;
int *b = &a;
int **c = &b;
int ***d = &c;

printf("%d", ***d);
}


#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n)
{
  if (allocbuf + ALLOCSIZE - allocp >= n)
  {
    allocp += n;
    return allocp - n;
  }
  else
  {
    return 0;
  }
}

void afree(char *p)
{
  if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
  {
    allocp = p;
  }
}

int strlen(char *s)
{
  char *p = s;

  for (int i = 0; *p != '\0'; p++)
  {
  }
  return p - s;
}

void strcpy(char *s, char *t)
{
  int i;
  i = 0;
  while ((s[i] = t[i]) != '\0')
  {
    i++;
  }
}

char strcmp(char *s, char *t)
{
  for (;*s == *t ;s++, t++) {
    if (*s == '\0') {
      return 0;
    }
  }
  return *s - *t;
}

