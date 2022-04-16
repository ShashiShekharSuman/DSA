#include <iostream>
using namespace std;
 
int main()
{
    int A[] = {1, 2, 3};
    int B[] = {7, 0, -5};
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

    int size = m + n - 1;
    int C[size];
    for(int i=0; i<size; i++) C[i] = 0;
    
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            C[i+j] += A[i]*B[j];


    cout<<"Product =\t    ";
    for(int i=0; i<size; i++){
        if (C[i]<0) cout<<"(";
        cout<<C[i];
        if (C[i]<0) cout<<")";
        cout<<"x^"<<size-i-1;
        if (i != size-1) cout<< " + ";
    }
 
    return 0;
}
