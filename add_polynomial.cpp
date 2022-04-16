#include <iostream>
using namespace std;
 
int main()
{
    int A[] = {5, -7, 0, 10, -4, 3};
    int B[] = {2, 4, -6, 9};
    int m = sizeof(A)/sizeof(A[0]);
    int n = sizeof(B)/sizeof(B[0]);
 
    cout << "First polynomial:   ";
    for(int i=0; i<m; i++){
        if (A[i]<0) cout<<"(";
        cout<<A[i];
        if (A[i]<0) cout<<")";
        cout<<"x^"<<m-i-1;
        if (i != m-1) cout<< " + ";
        else cout<<endl;
    }
    cout << "Second polynomial:  ";
    for(int i=0; i<n; i++){
        if (B[i]<0) cout<<"(";
        cout<<B[i];
        if (B[i]<0) cout<<")";
        cout<<"x^"<<n-i-1;
        if (i != n-1) cout<< " + ";
        else cout<<endl;
    }

    int size = (m>n) ? m:n;
    int C[size];
    for(int i=0; i<size; i++){
        if(m > n){
            if ( i < n) C[size-1-i] = A[m-1-i] + B[n-1-i];
            else C[size-1-i] = A[m-1-i];
        }
        else{
            if (i < m) C[size-1-i] = A[m-1-i] + B[n-1-i];
            else C[size-1-i] = B[n-1-i];
        }
    }

    cout<<"Sum =\t\t    ";
    for(int i=0; i<size; i++){
        if (C[i]<0) cout<<"(";
        cout<<C[i];
        if (C[i]<0) cout<<")";
        cout<<"x^"<<size-i-1;
        if (i != size-1) cout<< " + ";
    }
 
    return 0;
}
