// ----------------------------
// projects/collatz/Collatz.c++
// Copyright (C) 2016
// Glenn P. Downing
// ----------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <sstream>  // istringstream
#include <string>   // getline, string
#include <utility>  // make_pair, pair

// cache size is ~ 2^10
#define C_SIZE 1000000

#include "Collatz.h"

using namespace std;

// ------------
// collatz_read
// ------------

bool collatz_read (istream& r, int& i, int& j) {
    if (!(r >> i))
        return false;
    r >> j;
    return true;}

// ------------
// collatz_eval
// ------------

int cache[C_SIZE];

int collatz_eval (int i, int j) {
  // <your code>
  int lower = i;
  int upper = j;
  int max = 0;
  int count = 0;
  unsigned int y;

  if(i > j) {
    lower = j;
    upper = i;
  }

  int temp = (upper / 2) +1;
  if(temp > lower)
    lower = temp;
  for(int k = lower, k <= upper; k++) {
    count = 1;
    y = k;
    while(y > 1) {
      if(y > 0 && cache[y] != 0 && y < C_SIZE) {
        count += cache[y] - 1;
        y = 1;
      }
      else
        if(y % 2 == 0)
          y = y / 2;
        else
          y = 3 * y + 1;
        count += 1;
        //return false;
    }
    if
      return false;
  }
  return 1;
}



// -------------
// collatz_print
// -------------

void collatz_print (ostream& w, int i, int j, int v) {
    w << i << " " << j << " " << v << endl;}

// -------------
// collatz_solve
// -------------

void collatz_solve (istream& r, ostream& w) {
    int i;
    int j;
    while (collatz_read(r, i, j)) {
        const int v = collatz_eval(i, j);
        collatz_print(w, i, j, v);}}
