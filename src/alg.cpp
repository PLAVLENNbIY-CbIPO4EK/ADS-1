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
    int count = 0, number = 2;
    while (count < n) {
        int prime = 1;
        for (int i = 2; i < number; i++) {
            if (number % i == 0) {
                prime = 0;
                break;
            }
        }
        if (prime) count++;
        number++;
    }
    return number - 1;
}


uint64_t nextPrime(uint64_t value) {
    int d = 0;
    while (true) {
        if (value - d >= 2 && prime(value - d))
            return value - d;
        if (prime(value + d))
            return value + d;
        d++;
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
