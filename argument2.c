#include<stdio.h>

int main(int argc, char *argv[]) {

  if (argc == 0) return 0;
  printf("main recursive no.%d [%s]\n", argc-1, argv[argc-1]);
  main(argc-1, argv);

  return 0;
}
