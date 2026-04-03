#include <stdio.h>
#define MAXLINE 1000

int my_getline(char line[], int maxline);
void copy(char to[], char from[]);
void split(char w[],int s[] );
void indexing(min_data, max_data)
int main()
{
  int len;
  int max;
  char line[MAXLINE];
  char longest[MAXLINE];
  char spacing[MAXLINE];
  max = 0;
  while ((len = my_getline(line, MAXLINE)) > 0)
  {
    if (len > max)
    {
      max = len;
      copy(longest, line);
    }
  }
  split(longest,spacing);
  if (max > 0)
  {
    int min_i = 0;
    int max_i = -1;
    for(int i=0;longest[i] != NULL;i++) {
      max_i = i;
      char data_array[max_i - min_i];
      printf("%s", longest);
    }
    
  }
  return 0;
}
int my_getline(char s[], int lim)
{
  int c, i;
  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
  {
    s[i] = c;
  }
  if (c == '\n')
  {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

void copy(char to[], char from[])
{
  int i;

  i = 0;
  while ((to[i] = from[i]) != '\0')
  {
    ++i;
  }
}



void split(char word[],int space[] )
{
  int c = 0;
  for (int i=0;word[i] != '\0';i++) {
    if (word[i] == '\n') {
      space[c] = i;
      ++c;
    }
  }
}