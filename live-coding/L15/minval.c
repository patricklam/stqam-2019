#include <stdlib.h>
#include <stdio.h>

int min0(int a, int b) {
  int minVal;
  minVal = a;
  if (b < a) {
    minVal = b;
  }
  return minVal;
}

int min1(int a, int b) {
  int minVal;
  minVal = b;
  if (b < a) {
    minVal = b;
  }
  return minVal;
}

int min2(int a, int b) {
  int minVal;
  minVal = a;
  if (b > a) {
    minVal = b;
  }
  return minVal;
}

int min3(int a, int b) {
  int minVal;
  minVal = a;
  if (b < minVal) {
    minVal = b;
  }
  return minVal;
}

int min4(int a, int b) {
  int minVal;
  minVal = a;
  if (b < a) {
    // abort();
    return -99;
    minVal = b;
  }
  return minVal;
}

int min5(int a, int b) {
  int minVal;
  minVal = a;
  if (b < a) {
    minVal = a;
  }
  return minVal;
}

int min6(int a, int b) {
  int minVal;
  minVal = a;
  if (b < a) {
    minVal = (b == 0) ? -99 : b;
  }
  return minVal;
}

void test1(int (*mutant) (int, int), char * id) {
  int a = 0, b = 1;
  int expected = min0(a, b);
  int actual = mutant(a, b);
  if (expected != actual) printf("[test1] assert failed: %s\n", id);
}

void test2(int (*mutant) (int, int), char * id) {
  int a = 1, b = 0;
  int expected = min0(a, b);
  int actual = mutant(a, b);
  if (expected != actual) printf("[test2] assert failed: %s, actual %d expected %d\n", id, actual, expected);
}

void test3(int (*mutant) (int, int), char * id) {
  int a = 1, b = 1;
  int expected = min0(a, b);
  int actual = mutant(a, b);
  if (expected != actual) printf("[test3] assert failed: %s\n", id);
}

void test4(int (*mutant) (int, int), char * id) {
  int a = 1, b = 349;
  int expected = min0(a, b);
  int actual = mutant(a, b);
  if (expected != actual) printf("[test4] assert failed: %s\n", id);
}

int (*mutants[6]) (int a, int b);

int main() {
  mutants[0] = min1;
  mutants[1] = min2;
  mutants[2] = min3;
  mutants[3] = min4;
  mutants[4] = min5;
  mutants[5] = min6;

  for (int i = 0; i < 6; i++) {
    char s[5];
    sprintf(s, "min%d", i+1);
    test1(mutants[i], s);
    test2(mutants[i], s);
    test3(mutants[i], s);
    test4(mutants[i], s);
  }
}
