
// file upper.h
// upper triangle matrix

#ifndef Upper_
#define Upper_


#include <stdlib.h>
#include <iostream.h>
#include "xcept.h"

template<class T>
class UpperMatrix {
   public:
      UpperMatrix(int size = 10)
         {n = size; t = new T [n*(n+1)/2];}
      ~UpperMatrix() {delete [] t;}
      UpperMatrix<T>& Store(const T& x, int i, int j);
      T Retrieve(int i, int j) const;
   private:
      int n; //  matrix dimension
      T *t;  // 1D array for upper triangle
};

template<class T>
UpperMatrix<T>& UpperMatrix<T>::
          Store(const T& x, int i, int j)
{// Store x as L(i,j).
   if ( i < 1 || j < 1 || i > n || j > n)
       throw OutOfBounds();


   // (i,j) in upper triangle iff i <= j
   if (i <= j) t[j*(j-1)/2+i-1] = x;
   else if (x != 0) throw MustBeZero();

   return *this;
}
   
template <class T>
T UpperMatrix<T>::Retrieve(int i, int j) const
{// Retrieve L(i,j).
   if ( i < 1 || j < 1 || i > n || j > n)
       throw OutOfBounds();

   // (i,j) in upper triangle iff i <= j
   if (i <= j) return t[j*(j-1)/2+i-1];
   else return 0;
}

#endif
