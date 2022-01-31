#include <iostream>
using namespace std;

class Rat{
private:
   int n;
   int d;
   
public:
   Rat(){
      n=0;
      d=1;
   }

   Rat(int i, int j){
      n=i;
      d=j;
   }
   
   Rat(int i){
      n=i;
      d=1;
   }

   int getN(){ return n;}
   int getD(){ return d;}
   
   void setN(int i){ n=i;}
   void setD(int i){ d=i;}
   
   Rat operator+(Rat r){
      Rat t;
      t.n = n*r.d + d*r.n;
      t.d = d*r.d;
      t.reduce();
      return t;
   }
   
   Rat operator-(Rat r){
      Rat t;
      t.n = n*r.d - d*r.n;
      t.d = d*r.d;
      t.reduce();
      return t;
   }
   
   Rat operator*(Rat r){
      Rat t;
      t.n = n*r.n;
      t.d = d*r.d;
      t.reduce();
      return t;
   }
   
   Rat operator/(Rat r){
      Rat t;
      t.n = n*r.d;
      t.d = d*r.n;
      t.reduce();
      return t;
   }
   
   void reduce(){
      int gcd_ = gcd(n, d);
      n /= gcd_;
      d /= gcd_;
      if (d < 0) {
         d = -d;
         n = -n;
      }
   }
   

   int gcd(int n, int d){
      return d == 0 ? n : gcd(d, n%d);
   }


   friend ostream& operator<<(ostream& os, Rat r);
   friend istream& operator>>(istream& is, Rat& r);
}; 

ostream& operator<<(ostream& os, Rat r){
   r.reduce();
   if (abs(r.n) >= r.d || r.n == 0)
      os << r.n/r.d << " ";
   if (r.d != 1)
      os << (r.n/r.d <= -1 ? abs(r.n%r.d) : r.n%r.d) << "/" << r.d;
   return os;
}

istream& operator>>(istream& is, Rat& r){
   is >> r.n >> r.d;
   r.reduce();
   return is;
}

int main() {
  int a,b;
  cout<<"Please enter numerator"<<endl;
  cin>>a;
  cout<<"Please enter denominator"<<endl; 
  cin>>b;
  Rat rat(a, b);
   cout << "rat: " << rat << endl;
   return 0;
}
