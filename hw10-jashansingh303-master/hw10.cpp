#include <iostream>
using namespace std;

bool ok(int q[], int c) {
   for (int i = 0; i < c; i++)
      if (q[i] == q[c] || abs(q[i] - q[c]) == c - i)
         return false;
   return true;
}

int nq(int n) {
   int* q = new int[n];
   q[0] = 0;
   int c = 0; 
   int sol = 0;
   while (c >= 0) {
      if (c == n - 1) {
         sol++;
         c--;
      }
else
    q[++c] = -1;
      while (c >= 0) {
         q[c]++;
         if (q[c] == n)
            c--;
    else if (ok(q, c))
         break;
      }
   }
   delete[] q;
   return sol;
}

int main() {
   int n;
   cout<<"Please enter your desired chessboard size"<<endl;
   cin>>n;
   for (int i = 1; i <= n; i++)
      cout << "There are " << nq(i) << " solutions to the " << i << " queens problem."<<endl;
   return 0;
}
