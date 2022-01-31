#include <iostream>
using namespace std;

bool ok(int q[], int col) {
    static int mp[3][3] = { {0,2,1},  
                            {0,2,1},  
                            {1,2,0}}; 

    static int wp[3][3] = { {2,1,0},  
                            {0,1,2},  
                            {2,0,1}}; 

    for(int i = 0; i < col; i++){
        if(q[i] == q[col])
            return false;
    }

    for(int i = 0; i < col; i++){
        if(mp[i][q[col]] < mp[i][q[i]] && wp[q[col]][i] < wp[q[col]][col]) 
            return false;
    }

    for(int i = 0; i < col; i++){
        if(wp[q[i]][col] < wp[q[i]][i] && mp[col][q[i]] < mp[col][q[col]])
            return false;
    }

return true;
}

void print(int q[]) {
   static int sol = 0;
   cout << "Solution " << sol++ << ":\nMan\tWoman\n";
   for (int i = 0; i < 3; i++)
      cout << i << "\t" << q[i] <<endl;
   
}

void next(int q[], int col) {
   if (col == 3)
      print(q);
   else for (q[col] = 0; q[col] < 3; q[col]++)
      if (ok(q, col))
         next(q, col+1);
}

int main() {
   int q[3];
   next(q, 0);
   return 0;
}
