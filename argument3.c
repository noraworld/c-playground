#include<stdio.h>

int main(int argc, char *argv[], char *env[]) {

  int i = 0;
  while (env[i] != NULL) {
    printf("env[%2d] = %s\n", i, env[i]);
    i++;
  }

  return 0;
}
