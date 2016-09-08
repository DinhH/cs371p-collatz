// --------------------------
// projects/collatz/Collatz.h
// Copyright (C) 2016
// Glenn P. Downing
// --------------------------

#ifndef Collatz_h
#define Collatz_h

// --------
// includes
// --------

#include <iostream> // istream, ostream
#include <string>   // string
#include <utility>  // pair

using namespace std;

// ------------
// collatz_read
// ------------

/**
 * read two ints from r into i an j
 * @param r an istream
 * @param i an int
 * @param j an int
 * @return true if the read is successful, otherwise false
 */
//pair<int, int> collatz_read (const string& s);

bool collatz_read (istream& r, int& i, int& j);

// ------------
// collatz_eval
// ------------

/**
 * @param i the beginning of the range, inclusive
 * @param j the end       of the range, inclusive
 * @return the max cycle length of the range [i, j)
 */
int collatz_eval (int i, int j);

// -------------
// collatz_print
// -------------

/**
 * print three ints to w
 * @param w an ostream
 * @param i the beginning of the range, inclusive
 * @param j the end       of the range, inclusive
 * @param v the max cycle length
 */
void collatz_print (ostream& w, int i, int j, int v);

// -------------
// collatz_solve
// -------------

/**
 * @param r an istream
 * @param w an ostream
 */
void collatz_solve (istream& r, ostream& w);

#endif // Collatz_h
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


using namespace std;

int cache[C_SIZE];

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

int collatz_eval (int i, int j) {
  int lower = i;
  int upper = j;
  int max = 0;
  int count = 0;
  unsigned int y;

   //Starts the loop at lower value.
  if(i > j) {
      lower = j;
      upper = i;
  }
  //Initialize a temporary value that holes the lower value.
  int temp = upper / 2 + 1;
  if(temp > lower)
      lower = temp;
  for(int k = lower; k <= upper; k++) {
      count = 1;
      y = k;
      while(y > 1) {
          //make sure that y is within the bound.
          if(y > 0 && y < C_SIZE && cache[y] != 0) {
               //if we found the value in the cache, we need to add it.
              count += cache[y] - 1;
              y = 1;
          }
          //the simple algorithm for Collatz.
          else {
              if(y % 2 == 0)
                  y = y / 2;
              else
                  y = 3 * y + 1;
              count += 1;
          }
      }
       //we need to cache the value of the current set.
      if(k >= 0 && k < C_SIZE)
          cache[k] = count;
       //count = max.
      if(count > max)
          max = count;
  }
  return max;
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
// -------------------------------
// projects/collatz/RunCollatz.c++
// Copyright (C) 2015
// Glenn P. Downing
// -------------------------------

// -------
// defines
// -------

#ifdef ONLINE_JUDGE
    #define NDEBUG
#endif

// --------
// includes
// --------

#include <iostream> // cin, cout


// ----
// main
// ----

int main () {
    using namespace std;
    collatz_solve(cin, cout);
    return 0;
}
