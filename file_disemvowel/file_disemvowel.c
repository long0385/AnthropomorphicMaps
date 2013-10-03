#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include <unistd.h>

#define BUF_SIZE 1024

int is_vowel(char c) {
  /*Returns true if c is a vowel (upper or lower case), and false otherwise.*/

  char lower = tolower(c);

  if (lower != 'a' && lower != 'e' && lower != 'i' && lower != 'o' && lower != 'u') {
    return 0;
  } else {
    return 1;
  }
  
}

int copy_non_vowels(int num_chars, char* in_buf, char* out_buf) {
  /*Copy all the non-vowels from in_buf to out_buf.  num_chars indicates how many
characters are in in_buf, and this should return the number of non-vowels that were
copied over*/

  int i = 0;
  int non_vowels = 0;
  for (i; i < num_chars; i++) {
    if(!is_vowel(in_buf[i])) {
	out_buf[non_vowels] = in_buf[i];
	non_vowels++;
    }
  }
    return non_vowels;
}

void disemvowel(FILE* inputFile, FILE* outputFile) {
  /* 
   * Copy all the non-vowels from inputFile to outputFile.
   * Create input and output buffers, and use fread() to repeatedly read
   * in a buffer of data, copy the non-vowels to the output buffer, and
   * use fwrite to write that out.
   */
  char* in_buf = calloc(BUF_SIZE, sizeof(char));
  char* out_buf = calloc(BUF_SIZE, sizeof(char));
  int size_vowels = fread(in_buf, sizeof(char), BUF_SIZE, inputFile);
  int size_no_vowels = copy_non_vowels(size_vowels, in_buf, out_buf);

  fwrite(out_buf, sizeof(char), size_no_vowels, outputFile);
  free(in_buf);
  free(out_buf);


  
}

int main(int argc, char **argv) {
  FILE *inputFile;
  FILE *outputFile;

  /* Code that processes the command line arguments and sets up inputFile and outputFile */

  if(argc == 1) {
    inputFile = stdin;
    outputFile = stdout;

  } else if (argc == 2) {
    inputFile = fopen(argv[1], "r");
    outputFile = stdout;
  } else if (argc == 3) {
    inputFile = fopen(argv[1], "r");
    outputFile = fopen(argv[2], "w+");
  }

  disemvowel(inputFile, outputFile);

  return 0;
}
