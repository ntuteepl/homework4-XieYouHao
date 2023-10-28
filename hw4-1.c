#include <stdio.h>
#include <assert.h>

int isPrime(int);

int main() {
  int input;
  scanf("%d", &input);
  assert(input >= 1 && input <= 50);
  
  for (int i = 0; i < input; i++) {
    int in;
    scanf("%d", &in);
    if (isPrime(in)) {
      printf("YES");
    } else {
      printf("NO");
    }
    if (i < input-1) {
      printf(" ");
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

