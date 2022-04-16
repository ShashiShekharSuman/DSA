#include <iostream>
#include <vector>

using namespace std;

void insertion_sort(vector<int> &v){
    for(int i=1; i<v.size(); i++){
        cout<<"Pass "<<i<<":"<<endl;
        int temp = v[i];
        int j = i-1;
        while(j >= 0 && v[j]>temp){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = temp;
        for(auto i: v){
            cout<<i<<"\t";
        }
        cout<<endl;
    }
}

int main(){
    int n;
    vector<int> vect;
    cout<<"Enter no of elements: ";
    cin>>n;
    cout<<"Enter "<<n<<" numbers: ";
    while(n--){
        int element;
        cin>>element;
        vect.push_back(element);
    }
    insertion_sort(vect);
    return 0;
}