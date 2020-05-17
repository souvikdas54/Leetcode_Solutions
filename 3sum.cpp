//Solution of Three sum problem
//Given a 2-D array find all unique arrays of size 3 such that the sum is equal to zero

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums){
    sort(nums.begin(),nums.end());
    vector<vector<int>> rtn;
    for(int i=0;i<nums.size();){
        int start=i+1,end=(nums.size()-1);
        while(start < end){
            if((nums[i]+nums[start]+nums[end])==0){
                rtn.push_back({nums[i],nums[start],nums[end]});
                start++;
                end--;
                while(start<end && nums[start]==nums[start-1])start++;
                while(start<end && nums[end]==nums[end+1])end--;
            }else if((nums[i]+nums[start]+nums[end])<0){
                    start++;
                    while(start<end && nums[start]==nums[start-1]) start++;
            }else{
                end--;
                while(start<end && nums[end]==nums[end+1]) end--;
            }
        }
        i++;
        while(i<nums.size() && nums[i]==nums[i-1])
            i++;
    }
    return rtn;
} 
int main(){
    vector<int> a;
    a.push_back(1);
    a.push_back(-1);
    a.push_back(2);
    a.push_back(-2);
    a.push_back(0);
    vector<vector<int>> result = threeSum(a);
    for (int i = 0; i < result.size(); i++) { 
        for (int j = 0; j < result[i].size(); j++){
            cout << result[i][j] << " ";
        }
        cout<<endl;
    }
    return 0;
}