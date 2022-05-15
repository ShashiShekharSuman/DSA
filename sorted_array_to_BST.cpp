#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    void sortedArrayToBSTUtil(vector<int> &nums, int l, int h, vector<int> &preorder) {
        if (l > h) return;
        int mid = l + (h-l)/2;
        preorder.push_back(nums[mid]);
        sortedArrayToBSTUtil(nums, l, mid-1, preorder);
        sortedArrayToBSTUtil(nums, mid+1, h, preorder);
    }
    
public:
    vector<int> sortedArrayToBST(vector<int>& nums) {
        // Code here
        int l = 0, h = nums.size()-1;
        vector<int> preorder;
        sortedArrayToBSTUtil(nums, l, h, preorder);
        return preorder;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int>ans = obj.sortedArrayToBST(nums);
		for(auto i: ans)
			cout << i <<" ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends