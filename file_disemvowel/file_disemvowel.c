#include<stdlib.h>
#include<stdio.h>

int is_vowel(char c){
  /*Returns true if c is a vowel (upper or lower case), and false otherwise.*/

  char lower = tolower(c);

  if (lower != "a" && lower != "e" && lower != "i" && lower != "o" && lower != "u") {
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
    if(!isvowel(in_buf[i]) {
	out_buf[i] = in_buf[i];
	non_vowels++;
      } else {
	break;
      }
      return non_vowels;
}

int main(int argc, char **argv){

  copy_non_vowels(5, {"H", "e", "l", "l", "o"}, {});
  
}
