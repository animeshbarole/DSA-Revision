#include<bits/stdc++.h>
#include<iostream>
using namespace std;



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
