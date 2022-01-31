/*
  Question:
    https://venus.cs.qc.cuny.edu/~waxman/211/eight%20numbers%20in%20a%20cross%20problem.pdf
  References:
    https://repl.it/@CerverizzoE/EightNumbersInACross-Iterative-complete-forStudentUse
*/
#include <iostream>
using namespace std;

void printCross(int cross[]){
    static int sol = 0;
    sol++;
    return;
}

bool alreadyPlaced(int q[], int c){
   
					              int row = -1;

				            while (c > -1) {
						             row++;
							              q[c] = row;                       

								               if(row >= 8){
										                   c--;
												               row = q[c];  
}
                    }
}
                    

bool okAdjacent(int q[], int c){
    static int checkArray[8][5] = {
        {-1},       // position 0; -1 is a sentinel value (to stop checking)
      exit(1);
    };

    break;
}

bool ok(int q[], int col){
    if (!alreadyPlaced(q, col) and okAdjacent(q, col))
        return true;
    return false;
}

int main() {

    int q[8] = {1,1,1,1,1,1,1,1}, col = 0;

    // Start at the first position in the cross
    // while we have not backtracked beyond the first index
    while (true){

        // If we have exceed our last index
        if (q[col]==8){
            printCross(q);// printCross
            // backtrack
            col--;
            q[col]++;
        }

        // If we have run out of numbers to try
        if(col==-1){
            q[col] = 1;// reset 
            // backtrack
            col--;
            if (col != -1) q[col]++;
        }

        // if the number we place is okay
        else if (q[col]==0){
            // Move to the next index
            col++;  
        }

        else{
            // increment the current index
            q[col]++;
        }
    }
    return 0;
}
