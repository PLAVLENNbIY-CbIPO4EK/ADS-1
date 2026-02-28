// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
  if (value <= 1)
    return false;
  for (int i = 2; i < value, ++i) {
    if (value % i == 0)
      return false;
  } 
  return true;
}

uint64_t nPrime(uint64_t n) {
  int k = 0;
  if (n <= 1)
    return -1;
  for (int i = 2; i < n, ++i) {
    if (n % i == 0)
      return -1;
    else 
      k += 1;
  } 
  return printf(k, "-е простое число");
}

uint64_t nextPrime(uint64_t value) {
  while (true) {
    uint64_t value += 1;
    for (int i = 2; i < value, ++i) {
      if (value % i == 0)
        return -1;
    }
    return value;
    break;
  }
}

uint64_t sumPrime(uint64_t hbound) {
   int sum = 0;
   for (int i = 2; i < hbound; ++i) {
       bool p = true;
       for (int j = 2; j * j <= i; ++j) {
           if (i % j == 0) {
               p = false;
               break;
           }
       }
       if (p) sum += i;
   }
   return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
   int k = 0;
   for (int i = lbound; i <= hbound - 2; ++i) {
       if (checkPrime(i) && checkPrime(i + 2)) {
           k++;
       }
   }
   return k;
}
