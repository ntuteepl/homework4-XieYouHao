#include <stdio.h>
#include <assert.h>
#define ARRAYSIZE 50

int isPrime(int);

int main() {
  int input;
  scanf("%d", &input);
  assert(input >= 1 && input <= ARRAYSIZE);
  int arr[ARRAYSIZE];
  
  for (int i = 0; i < input; i++) {
    int in;
    scanf("%d", &in);
    arr[i] = in;
  }

  for (int i = 0; i < input; i++) {
    if (isPrime(arr[i])) {
      printf("YES ");
    } else {
      printf("NO ");
    }
  }

  return 0;
}

int isPrime(int n) {
  static int x = 2;
  if (n <= 1) {
    return 0;
  }
  if (n % x == 0 && n != x) {
    return 0;
  }
  if (n == x) {
    x = 2;
    return 1;
  }
  x++;
  isPrime(n);
}

