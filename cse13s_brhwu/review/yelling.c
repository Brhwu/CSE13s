#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char **argv) {
  // You're going to have to use argc to decide whether to open up a file, or to
  // read from stdin.
  // If you haven't seen them before, you will likely want to use the functions
  // `fgetc()` and `fputc()`.
  
    int j = 0;
    char str[300];
    char ch;
    int c;
    
    
    if (argc >= 2) {
      FILE* fp = fopen(argv[1], "r");
      while(1) {
      c = fgetc(fp);
      if (c == EOF) {
          break;
      }
      putchar(toupper(c));
      }
      fclose(fp);
    }
    else {
        printf("Input: ");
        scanf("%[^\n]s", str);
	
 
    while (str[j]) {
        ch = str[j];
        putchar(toupper(ch));
        j++;
    }
    printf("\n");
}
return 0;
}
