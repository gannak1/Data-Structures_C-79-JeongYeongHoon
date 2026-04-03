#include <stdio.h>

void main()
{
  printf("1");
  int a;
  int b;

  a = 100;
  b = &a;

  int *p = (int *)malloc(sizeof(int));
  p = &a;
}

void strcat(char s[], char t[])
{
  int i;
  while (s[i] != '\0')
  {
    i++;
  }
  while ((s[i++] = t[i]) != '\0')
  {
  }
}

int binarySearch(int a[], int num, int len)
{
  int low, mid, high, return_index;
  low = 0;
  high = len;
  mid = (low + high) / 2;
  return_index = -1;
  while (low <= high)
  {
    if (a[mid] == num)
    {
      return mid;
    }
    else if (a[mid] < num)
    {
      low = mid;
    }
    else
    {
      high = mid;
    }
    mid = (low + high) / 2;
  }
}

void itoa(int n, char s[])
{
  int i, sign;

  if ((sign = n) < 0)
  {
    n = -n;
  }
  i = 0;
  do
  {
    s[i++] = n % 10 + '0';
  } while ((n /= 10) > 10);
  if (sign < 0)
  {
    s[i++] = '-';
  }
  s[i] = '\0';
  reverse(s);
}

int bitcount(unsigned x)
{
  int b;
  for (b = 0; x != 0; x >>= 1)
  {
    if (x & 01)
    {
      b++;
    }
    return b;
  }
}

unsigned getbits(unsigned x, int p, int n)
{
  return (x >> (p + 1 - n) & ~(~0 << n));
}

void squeeze(char s[], int c)
{
  int i, j;
  for (i = j = 0; s[i] != '\0'; i++)
  {
    if (s[i] != c)
    {
      s[j++] = s[i];
    }
    s[j] = '\0';
  }
}
int rower(int c)
{
  if (c >= 'A' && c <= 'Z')
  {
    return c + 'a' - 'A';
  }
  else
  {
    return c;
  }
}

int strlen(char s[])
{
  int i;

  i = 0;
  while (s[i] != '\0')
  {
    ++i;
  }
  return i;
}

// revers String s in place
void reverse(char s[])
{
  int c, i, j;

  for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
  {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

int trim(char s[])
{
  int n;

  for (n = strlen(s) - 1; n >= 0; n--)
  {
    if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
    {
      break;
    }
    s[n + 1] = '\0';
  }
  return n;
}

// return index of t in s, -1 if none
int strindex(char s[], char t[]) {
  int i,j,k;

  for (i = 0; s[i]!= '\0' && s[j] == t[k]; j++,k++) {

  }
  if (k >0 && t[k] == '\0') {
    return i;
  }
  return -1;
}

double atof(char s[]) {
  double val, power;
  int i,sign;

  for (i=0;isspace(s[i]);i++){}
  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-') {
    i++;
  }
  for (val = 0.0; isdigit(s[i]);i++) {
    val =  10.0 * val + (s[i] - '0');
  }
  if (s[i] == '.') {
    i++;
  }
  for (power = 1.0;isdigit(s[i]);i++) {
    val = 10.0 * val + (s[i] - '0');
    power *= 10.0;
  }
  return sign * val / power;
}
int atoi(char s[]) {
  double atof(char s[]);
  return (int) atof(s);
 }


int isdigit(char n) {
  if (n >= '0' && n <= '9' ) {
    return 1;
  }
  else {
    return 0;
  }
}

int isspace(char n) {
  if (n == ' ') {
    return 1;
  } 
  else {
    return 0;
  }
}

int my_getline(char s[], int lim) {
  int c,i;
  i=0;
  while (--lim > 0 && (c=getchar()) != EOF && c != '\n') {
    s[i++]= c;
  }
  if (c == '\n') {
    s[i++] = c;
  }
  s[i] = '\0';
  return i;
}
