#include<ftw.h>

static int num_dirs, num_regular;

static int callback(const char *fpath, const struct stat *sb, int typeflag) {


  if(typeflag == FTW_D) {
    num_dirs++;
  } else if(typeflag == FTW_F) {
    num_regular++;
  } else {
    printf("%s\n", "Neither a regular file or directory.");
  }

  return 0;
}

int main(int argc, char** argv) {
  /* Check arguments & set things up */

  if (argc != 2) {
    printf ("Usage: %s <path>\n", argv[0]);
    printf ("       where <path> is the file or root of the tree you want to summarize.\n");
    return 1;
  }

  ftw(argv[1], callback, 16);

  /* Print out the results */
  printf("Processed all the files from <%s>.\n", argv[1]);
  printf("There were %d directories.\n", num_dirs);
  printf("There were %d regular files.\n", num_regular);

  return 0;


}
