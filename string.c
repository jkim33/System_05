//Jason Kim & Richard Wong
//System Level Programming - Pd.5
//Work#05
//10-1-18

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int length(char *s) {
  int counter = 0;
  while(s[counter]) {
    counter++;
  }
  return counter;
}

char * copy(char *dest, char *source) {
  int i = 0;
  while(*(source+i)) {
    *(dest+i) = *(source+i);
    i++;
  }
  return dest;
}

char * catn(char *dest, char *source, int n) {
  int i = length(dest);
  int counter = 0;
  while(counter<n) {
    *(dest+i) = *(source+counter);
    i++;
    counter++;
  }
  return dest;
}

int cmp( char *s1, char *s2 )  {
  int i = 0;
  int stop;
  if (length(s1) < length(s2)){
    stop = length(s1);
  }
  else {
    stop = length(s2);
  }
  while(i <= stop){
    if (*(s1+i) < *(s2+i)) {
      return -1;
    }
    else if (*(s1+i) > *(s2+i)){
      return 1;
    }
    i++;
  }
  if (length(s1) < length(s2)){
    return -1;
  }
  else if(length(s1) > length(s2)){
    return 1;
  }
  else {
    return 0;
  }
}

char * search(char* s, char c) {
  int i = 0;
  while(*(s+i)) {
    if(*(s+i) == c) {
      return s+i;
    }
    i++;
  }
  return NULL;
}

int main() {
  char s1[64] = "anything";
  char s2[64] = "something";

  printf("s1:[%s]\n", s1);
  printf("s2:[%s]\n", s2);

  printf("=========================\n");
  
  printf("Testing strlen(s1):\n");
  printf("Ours: %d\n", length(s1));
  printf("Standard: %d\n", (int)strlen(s1));

  printf("=========================\n");

  printf("Testing strcpy(s1,s2):\n");
  printf("Ours: [%s]\n", copy(s1,s2));
  strcpy(s1, "anything");
  printf("Standard: [%s]\n", strcpy(s1,s2));
  strcpy(s1, "anything");

  printf("=========================\n");

  printf("Testing strcatn(s1,s2):\n");
  printf("Ours: [%s]\n", catn(s1,s2,4));
  strcpy(s1, "anything");
  printf("Standard: [%s]\n", strncat(s1,s2,4));
  strcpy(s1, "anything");

  printf("=========================\n");
  
  printf("Testing strcmp(char *s1, char *s2):\n");
  printf("Ours:     a, b: %d\n", cmp("a","b"));
  printf("Standard: a, b: %d\n", strcmp("a","b"));
  printf("Ours:     c, b: %d\n", cmp("c","b"));
  printf("Standard: c, b: %d\n", strcmp("c","b"));
  printf("Ours:     apple, apple: %d\n", cmp("apple","apple"));
  printf("Standard: apple, apple: %d\n", strcmp("apple","apple"));
  printf("Ours:     applez, apple: %d\n", cmp("applez","apple"));
  printf("Standard: applez, apple: %d\n", strcmp("applez","apple"));
  printf("Ours:     apple, applez: %d\n", cmp("apple","applez"));
  printf("Standard: apple, applez: %d\n", strcmp("apple","applez"));

  printf("=========================\n");

  printf("Testing strchr(s1,'t'):\n");
  printf("Ours: %d\n", search(s1,'t'));
  printf("Standard: %d\n", strchr(s1,'t'));
}
