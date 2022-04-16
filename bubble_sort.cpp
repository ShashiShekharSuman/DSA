#include <iostream>
#include <vector>

using namespace std;

void bubble_sort(vector<int> &v){
    for(int i=0; i<v.size()-1; i++){
        cout<<"Pass "<<i+1<<":"<<endl;
        for(int j=0; j<v.size()-i-1; j++){
            if(v[j] > v[j+1]){
                v[j] += v[j+1];
                v[j+1] = v[j] - v[j+1];
                v[j] -= v[j+1];
            }
            for(auto i: v){
                cout<<i<<"\t";
            }
            cout<<endl;
        }
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
    bubble_sort(vect);
    return 0;
}