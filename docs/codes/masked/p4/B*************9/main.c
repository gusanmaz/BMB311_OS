1 #include <stdio.h>
2 #include <stdlib.h>
3 int main(int argc, char *argv[]) {
4 printf("location of code : %p\n", main);
5 printf("location of heap : %p\n", malloc(100e6));
6 int x = 3;
7 printf("location of stack: %p\n", &x);
8 return x;
9 }
