#include<bits/stdc++.h>
#include<iostream>
using namespace std;


//Brute Force Approach
int reverse(int num)
{
    int rev_num = 0;

        while(num>0)
        {
            rev_num = rev_num*10+num%10;
            num =num/10;
        }

     return rev_num;
}

int goodPair(vector<int> nums)
{
       int count =0;
          vector<int> arr;
          for(int i =0;i<nums.size();i++)
          {
              arr.push_back(reverse(nums[i]));
          }
          
          for(int i =0;i<arr.size();i++)
          {
                cout<<arr[i]<<" ";
          }

          for(int i =0;i<nums.size()-1;i++)
          {
              if(nums[i]+arr[i+1]==arr[i]+nums[i+1])
              {
                  count++;
              }
          }

          return count;
}



//Optimal Approach

class Solution {
public:
    int M = 1e9+7;
    int reverse(int num) {
        int rev = 0;
        
        while(num > 0) {
            int rem = num%10;
            rev = rev*10 + rem;
            num /= 10;
        }
        
        return rev;
    }
    
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        
        unordered_map<int, int> mp;
        
        //nums[i] - rev(nums[i]) ==  nums[j] - rev(nums[j])
        for(int i = 0; i<n; i++) {
            nums[i] = nums[i] - reverse(nums[i]);
        }
        
        int result = 0;
        for(int i = 0; i<n; i++) {
            
            result = (result + mp[nums[i]]) % M;
            
            mp[nums[i]]++;
        }
        
        return result;
    }
};



int main()
{
 
        int n,x;
        cout<<"Enter the size of the array";
        cin>>n;
        vector<int> v;   

        for(int i =0;i<n;i++)
        {   
            cin>>x;
            v.push_back(x);
        }

       int ans =  goodPair(v);

      cout<<ans;
         
}
