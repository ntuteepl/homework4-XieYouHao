#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#define ARRAYSIZE 50
#define TIME 24

int main() {
  int s, d;
  int z = 0;
  int arr[ARRAYSIZE][3];
  while (scanf("%d %d", &s, &d) != EOF) {
    assert(s >= 1 && s <= TIME && d >= 1 && d <= TIME && d > s);
    arr[z][0] = s;
    arr[z][1] = d;
    arr[z][2] = -1; // represent driver number
    z++;
  }
  bool arrDriver[ARRAYSIZE][TIME];
  for (int i = 0; i <= z; i++) { //seed boolean for driver schedule
    for (int j = 0; j < TIME; j++) {
      arrDriver[i][j] = false;
    }
  }

  // assign schedule to driver
  for (int i = 0; i < z; i++) { //loop drivers
    for (int j = 0; j < z; j++) { //loop schedule
      if (arr[j][2] == -1) { //check driver taken or not
        int empty = 0;
        for (int k = arr[j][0]; k < arr[j][1]; k++) { // check driver schedule
          if (arrDriver[i][k] == false) {
            empty++;
          }
        }
        if (empty == arr[j][1] - arr[j][0]) {
          for (int k = arr[j][0]; k < arr[j][1]; k++) { //seed boolean for driver schedule
            arrDriver[i][k] = true;
          }
          arr[j][2] = i;
        }
      }
    }
  }

  int driver = 0;
  for (int i = 0; i < z; i++) { //loop drivers
    if (arr[i][2] > driver) {
      driver = arr[i][2];
    }
  }
  driver++;
  printf("%d\n", driver);
  driver--;
  
  for (int i = 0; i <= driver; i++) { //loop drivers
    int out = i + 1;
    printf("Driver %d's schedule is ", out);
    for (int j = 0; j < z; j++) { //loop schedule
      if (arr[j][2] ==  i) {
        printf("%d %d ", arr[j][0], arr[j][1]);
      }
    }
    printf("\n");
  }
  return 0;
}