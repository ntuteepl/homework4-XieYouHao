#include <stdio.h>
#include <assert.h>
#define ARRAYSIZE 10

int main() {
  int input;
  scanf("%d", &input);
  assert(input >= 1 && input <= ARRAYSIZE);
  int arr[ARRAYSIZE][ARRAYSIZE];

  for (int i = 0; i < input; i++) {
    for (int j = 0; j < input; j++) {
      int in;
      scanf("%d", &in);
      arr[i][j] = in;
    }
  }

  for (int i = 0; i < input; i++) {
    int max = 0;
    int boy;
    int girl;
    for (int j = 0; j < input; j++) {
      for (int k = 0; k < input; k++) {
        if (arr[j][k] > max) {
          max = arr[j][k];
          boy = j;
          girl = k;
        }
      }
    }
    // printf("%d", max);
    for (int j = 0; j < input; j++) {
        arr[boy][j] = 0;
        arr[j][girl] = 0;
    }
    boy++;
    girl++;
    printf("boy %d pair with girl %d\n", boy, girl);
  }

  return 0;
}