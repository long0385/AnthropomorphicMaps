#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include <unistd.h>

int is_vowel(char c) {
  /*Returns true if c is a vowel (upper or lower case), and false otherwise.*/

  char lower = tolower(c);

  if (lower != 'a' && lower != 'e' && lower != 'i' && lower != 'o' && lower != 'u') {
    return 0;
  } else {
    return 1;
  }
  
}

int copy_non_vowels(int num_chars, char* in_buf, char* out_buf){
  /*Copy all the non-vowels from in_buf to out_buf.  num_chars indicates how many
characters are in in_buf, and this should return the number of non-vowels that were
copied over*/

  int i = 0;
  int non_vowels = 0;
  for (i; i < num_chars; i++) {
    if(is_vowel(in_buf[i]) == 0) {
	out_buf[i] = in_buf[i];
	non_vowels++;
    } else {
      break;
    }
    printf("%d \n", non_vowels);
}

void disemvowel(FILE* inputFile, FILE* outputFile) {
  /* 
   * Copy all the non-vowels from inputFile to outputFile.
   * Create input and output buffers, and use fread() to repeatedly read
   * in a buffer of data, copy the non-vowels to the output buffer, and
   * use fwrite to write that out.
   */

  
}

int main(int argc, char **argv){
  FILE *inputFile;
  FILE *outputFile;

  /* Code that processes the command line arguments and sets up inputFile and outputFile */

  disemvowel(inputFile, outputFile);

  return 0;
}
