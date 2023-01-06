#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
      phtread_create thread_id;
      /* a buffer to hold the count of characters 0,...,256; it is
   * initialized to zero on every element */
  int count[256] = { 0 };

  /* loop counter */
  int k;

  /* file handle --- in this case I am parsing this source code */
  FILE *fp = fopen("ccount.c", "r");

  /* a holder for each character (stored as int) */
  int c;

  /* for as long as we can get characters... */
  while((c=fgetc(fp))) {

    /* break if end of file */
    if(c == EOF) break;

    /* otherwise add one to the count of that particular character */
    count[c]+=1;
  }

  /* now print the results; only if the count is different from
   * zero */
  for(k=0; k<256; k++) {
    if(count[k] > 0) {
      printf("char %c: %d times\n", k, count[k]);
    }
  }
  /* close the file */
  fclose(fp);

  /* that's it */
  return 0;
}
