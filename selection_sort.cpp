#include <iostream>
#include <vector>

using namespace std;

void selection_sort(vector<int> &v){
    for(int i=0; i<v.size()-1; i++){
        cout<<"Pass "<<i+1<<":"<<endl;
        int min = i;
        for(int j=i+1; j<v.size(); j++){
            if(v[j] < v[min]){
                min = j;
            }
        }
        if (min != i){
            v[i] += v[min];
            v[min] = v[i] - v[min];
            v[i] -= v[min];
        }
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
    selection_sort(vect);
    return 0;
}