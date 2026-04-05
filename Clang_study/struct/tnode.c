#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100
struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);

main()
{
  struct tnode *root;
  char word[MAXWORD];

  root = NULL;
  while (getword(word, MAXWORD) != EOF)
  {
    if (isalpha(word[0]))
    {
      root = addtree(root, word);
    }
    treeprint(root);
    return 0;
  }
}
// addtree : add a node with w, at or below p
struct tnode *addtree(struct tnode *p, char *w)
{
  int cond;

  if (p == NULL) // a new word has arrived
  {
    p = talloc(); // make a new node
    p -> word = strdup(w);
    p -> count = 1;

  }
}





struct tnode *talloc(void) {
  return (struct tnode *) malloc(sizeof(struct tnode));
}
char *strdup(char *s) {
  chat *p;

  p = (char *) malloc(strlen(s) +1);
  if (p != NULL) {
    strcpy(p,s);
  }
  return p;
  
}