#include <bits/stdc++.h>
using namespace std;

int maxSubsetSum(vector<int> arr) {

    int n = arr.size(), max_subset_sum = 0, odd_sum = 0, even_sum = 0;
    bool flag;
    vector<int> positive_index_subset;
    unordered_map<int, int> index_value;
    
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            index_value[i] = arr[i];
            positive_index_subset.push_back(i);
        } 
    }
    
    int positive_index_subset_size = positive_index_subset.size();
    
    if (positive_index_subset_size <= 0) return 0;
    else if (positive_index_subset_size == 1) 
        return index_value[positive_index_subset[0]];
    else {
        even_sum = index_value[positive_index_subset[0]];
        for (int i = 1; i < positive_index_subset_size; i++) {
            if (positive_index_subset[i] - positive_index_subset[i-1] == 1) {
                flag = true;
                if (i % 2 == 0) even_sum += index_value[positive_index_subset[i]];
                else odd_sum += index_value[positive_index_subset[i]];
            }
            else {
                flag = false;
                max_subset_sum += (even_sum > odd_sum ? even_sum : odd_sum);
                even_sum = odd_sum = 0;
                if (i % 2 == 0) even_sum += index_value[positive_index_subset[i]];
                else odd_sum += index_value[positive_index_subset[i]];
            }
        }
        if (flag) max_subset_sum += (even_sum > odd_sum ? even_sum : odd_sum);        
    }
    
    return max_subset_sum;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr;
    while(n--) {
        int element;
        cin>>element;
        arr.push_back(element);
    }
    cout<<maxSubsetSum(arr);
    return 0;
}