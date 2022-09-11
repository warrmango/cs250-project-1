#include <stdio.h>
#include <string.h>
#include <math.h>

int* creatmap(unsigned int bitmap) {
  int r = 0;
  int value = bitmap;
  static int map[32];
  int i = 0;
  int negative = 0;
  if (value < 0) {
    negative = 1;
    value = 0 - value - 1;
  }
  while(value != 0) {
    r = value % 2;
    map[i] = r;
    value /= 2;
    i++;
  }
  while(i != 32) {
    map[i] = 0;
    i++;
  }
  return map;
}
// It prints the bits in bitmap as 0s and 1s.
void printBits(unsigned int bitmap) {
  int r = 0;
  int value = bitmap;
  int bitMap[32];
  int i = 0;
  int negative = 0;
  if (value < 0) {
    negative = 1;
    value = 0 - value - 1;
  }
  while(value != 0) {
    r = value % 2;
    bitMap[i] = r;
    value /= 2;
    i++;
  }
  while(i != 32) {
    bitMap[i] = 0;
    i++;
  }
  if (negative == 0) {
    for(int k = 31; k >= 0; k--) {
      printf("%d", bitMap[k]);
    }
  }
  else {
    for(int k = 31; k >= 0;k--) {
      if(bitMap[k] == 1) {
        bitMap[k] = 0;
      }
      else {
        bitMap[k] = 1;
      }
      printf("%d", bitMap[k]);
    }
  }
  printf("\n");
  printf("10987654321098765432109876543210\n");
}



// Sets the ith bit in *bitmap with the value in bitValue (0 or 1)
void setBitAt( unsigned int *bitmap, int i, int bitValue ) {
  int mask = 0;
  unsigned int * x = bitmap;
  if(bitValue == 1) {
    mask = (1 << i);
    *x = (*x | mask);
  } else {
    mask = (1 << i);
    mask = ~mask;
    *x = (*x & mask);
  }
}

// It returns the bit value (0 or 1) at bit i
int getBitAt( unsigned int bitmap, unsigned int i) {
  int mask = (1 << i);
  bitmap = (bitmap & mask);
  if(bitmap==0) {
    return 0;
  }
  return 1;
}

// It returns the number of bits with a value "bitValue".
// if bitValue is 0, it returns the number of 0s. If bitValue is 1, it returns the number of 1s.
int countBits( unsigned int bitmap, unsigned int bitValue) {
  int mask = 0;
  int count = 0;
  mask = ~mask;
  bitmap = (bitmap & mask);
  for(int i = 0; i < 32; i++){
    if(getBitAt(bitmap,i) == 1){
      count++;
    }  
  }
  if(bitValue == 1){
    return count;
  }
  return 32-count;
}

// It returns the number of largest consecutive 1s in "bitmap".
// Set "*position" to the beginning bit index of the sequence.
int maxContinuousOnes(unsigned int bitmap, int * position) {
  int a = 0;
  int count1 = 0;
  int countMax = 0;
  *position = 0;
  for (int i = 0; i< 32; i++){
    if(getBitAt(bitmap,i) == 1){
      count1++;
    }else {
      if(countMax < count1){
        countMax = count1;
        *position = i - count1;
      }
      count1 = 0;
    }
  }
  if(countMax < count1){
    *position = 31 - count1;
    return count1;
  }
  return countMax;
}


