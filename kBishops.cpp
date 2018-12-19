

#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

bool ok(int *q, int now, int n){//this checks whether or not a bishop can be placed in a certain location
    for(int j=0;j<now;j++)
        if(q[j]/n+q[j]%n==q[now]/n+q[now]%n || q[j]/n-q[j]%n==q[now]/n-q[now]%n)//this checks for whether bishops are attacking each other
            return false;
    return true;
}

int factorial(int n){
    if (n==1) return n;
    return n*factorial(n-1);
}

void move(int *q, int i, int k, int n, int &count){
    bool from_backtrack=false;
    while(true){
        while(i<k){//if we hit i=k we have found a solution
            if(!from_backtrack)
                q[i]=-1; //we must now go through all the rows again so we start from the top
            from_backtrack=false;
            while(q[i]<n*n){
                q[i]++; //running through all the rows
                if(q[i]==n*n){//if the row hits 8 we have gone too far and must backtrack
                    i--;
                    if(i==-1){
                        cout<<"Number of solutions: "<<count/factorial(k);//we've found the solution so we return it
                        exit(1);
                    }
                    from_backtrack=true;
                    continue;
                }
                if(ok(q,i,n)){//check if the bishop can be placed in that location if it can then go to the next column
                    i++;
                    break;
                }
            }
        }
        count++;//we've found a solution so we add to the count
        i--;//backtrack to find another solution
        if(i==-1){
            cout<<"Number of solutions: "<<count/factorial(k);//we've found the solution so we return it
            exit(1);
        }
        from_backtrack=true;
    }
    delete []q;
}

int main(){
    int i_n, i_k; //i_n is the size of board, i_k is the # of bishops
    
    do{
        cout << "Enter value of i_n: ";
        cin >> i_n;
        if(i_n == -1)
            return 0;
        cout << "Enter value of i_k: ";
        cin >> i_k;
        
        int count = 0;
        int *q = new int[i_k];
        move(q, 0, i_k, i_n, count);//does all the work in finding the answer
        cout << "Number of solutions: " << count << endl;
        delete []q;//must delete the dynamic array before you're finished
    }while(true);
    
    return 0;
}
