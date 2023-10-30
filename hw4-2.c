#include <stdio.h>
#include <stdbool.h>
#define ARRAYSIZE 50

int main() {
  int data[6][3] = {
    {123, 456, 9000}, 
    {456, 789, 5000}, 
    {789, 888, 6000}, 
    {336, 558, 10000}, 
    {775, 666, 12000}, 
    {566, 221, 7000}
  };
  int input;
  scanf("%d", &input);
  int test[ARRAYSIZE][2];
  int output[ARRAYSIZE];

  for (int i = 0; i < input; i++) {
    int acc, pass;
    scanf("%d %d", &acc, &pass);
    test[i][0] = acc;
    test[i][1] = pass;   
  }

  for (int i = 0; i < input; i++) {
    bool ok = false;
    for (int j = 0; j < 6; j++) {
      if (data[j][0] == test[i][0]) {
        if(data[j][1] == test[i][1]) {
          printf("%d", data[j][2]);
          ok = !ok;
        }
      }
    }
    if (!ok) {
      printf("error\n");
    }
  }

  return 0;
}
