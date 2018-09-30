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

}
