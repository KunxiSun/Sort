#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define LEN (1024)  // length of buffer

/*
 * convert char type interger to int type
 */
int convert_int(char num) {
  return num - '0';
}

/*
 * helper function of numerical_compare
 */
int get_num(char** str, int num) {
  /* in the case the char is alpha */
  if (!isdigit(**str)) {
    (*str)++;
    return num;
  }

  /* in the case the first char is digit,
  then trying to find the digit after it*/
  num = 0;
  while (isdigit(**str)) {
    num = num * 10 + convert_int(**str);
    (*str)++;
  }
  return num;
}

/**
 * Return positive if str1>str2
 * return negative if str1<str2
 * return 0 if str1 equals str2
 */
double numerical_compare(char* str1, char* str2) {
  int c1, c2;

  char* ptr1 = &(str1[0]);
  char* ptr2 = &(str2[0]);

  do {
    c1 = get_num(&ptr1, *ptr1);
    c2 = get_num(&ptr2, *ptr2);

    if (c1 == '\0') {
      return c1 - c2;
    }

  } while (c1 == c2);

  return c1 - c2;
}

/**
 * Return positive if str1>str2
 * return negative if str1<str2
 * return 0 if str1 equals str2
 *
 * USYD CODE CITATION ACKNOWLEDGEMENT
 * I declare that the following lines of code have been copied from the
 * website titled: "Browse the source code of glibc/string/strcmp.c" and it is
 * not my own work.
 *
 * Original URL
 * https://code.woboq.org/userspace/glibc/string/strcmp.c.html
 * Last access 10, Sep, 2020
 */
double alpha_num_compare(char* str1, char* str2) {
  double c1, c2;
  do {
    c1 = *str1++;
    c2 = *str2++;
    if (c1 >= 'A' && c1 <= 'Z') {
      c1 += 31.5; /* +32 will equal to the lowercase of
                      if only +31.5, the uppercase will
                      always be 0.5 smaller than lowercase */
    }
    if (c2 >= 'A' && c2 <= 'Z') {
      c2 += 31.5;
    }
    if (c1 == '\0') {
      return c1 - c2;
    }
  } while (c1 == c2);
  return c1 - c2;
}
/* end of copied code */


/**
 *  sort in ascending order
 *  src: the content which need to be sorted
 *  line_num: number of line of src
 *  compare: function pointer to different compare strategies
 */
void sort(char src[LEN][LEN],
          int line_num,
          double (*compare)(char* str1, char* str2)) {
  /* check inputs*/
  if (src == NULL || compare == NULL || line_num < 0) {
    return;
  }

  /* USYD CODE CITATION ACKNOWLEDGEMENT
   * I declare that the following lines of code have been copied from the
   * website titled: "Insertion Sort" and it is not my own
   * work.
   *
   * Original URL
   * https://www.geeksforgeeks.org/insertion-sort/
   * Last access 10, Sep, 2020
   */
  char key[LEN];
  int i, j;
  for (i = 0; i < line_num; i++) {
    strcpy(key, src[i]);
    j = i - 1;
    while (j >= 0 && compare(src[j], key) > 0) {
      strcpy(src[j + 1], src[j]);
      j = j - 1;
    }
    strcpy(src[j + 1], key);
  }
  /* end of copied code */
}

/**
 *  print file in ascending order
 */
void ascending_print(char src[LEN][LEN], int line_num) {
  for (int i = 0; i < line_num; i++) {
    printf("%s", src[i]);
  }
}

/**
 *  print file in descending order
 */
void descending_print(char src[LEN][LEN], int line_num) {
  for (int i = line_num - 1; i >= 0; i--) {
    printf("%s", src[i]);
  }
}

int main(int argc, char* argv[]) {
  /* Too less arguments or too much arguments*/
  if (argc < 2 || argc > 4) {
    puts("Invalid argument");
    return 1;
  }

  /* set the order 1: -a for ascending, 2: -d for descending*/
  int order = 1;

  /* set the compare type 1: -alpha for alpha-numeric, 2: -num for numerical*/
  int compare = 1;

  /* update oder by the given argument*/
  if (argc == 3 || argc == 4) {
    if (strcmp(argv[2], "-a") == 0) {
      order = 1;
    } else if (strcmp(argv[2], "-d") == 0) {
      order = 2;
    } else {
      puts("No such options\nTry:\n-a for ascending\n-d for descending");
      return 1;
    }
  }

  /* update compare by the given argument*/
  if (argc == 4) {
    if (strcmp(argv[3], "-alpha") == 0) {
      compare = 1;
    } else if (strcmp(argv[3], "-num") == 0) {
      compare = 2;
    } else {
      puts(
          "No such options\nTry:\n-alpha for alpha-numerical\n-num for "
          "numerical");
      return 1;
    }
  }

  /* read and store file content*/
  char buf[LEN][LEN];
  FILE* fp = fopen(argv[1], "r");
  int line_num = 0;
  while (fgets(buf[line_num], LEN, fp) != NULL) {
    line_num++;
  }

  double (*compare_func)(char*, char*);
  if (compare == 1) {
    compare_func = &alpha_num_compare;
  } else if (compare == 2) {
    compare_func = &numerical_compare;
  }

  sort(buf, line_num, compare_func);

  if (order == 1) {
    ascending_print(buf, line_num);
  } else if (order == 2) {
    descending_print(buf, line_num);
  }
}