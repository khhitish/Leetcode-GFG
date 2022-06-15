class Solution {
private:// https://leetcode.com/problems/kth-largest-element-in-an-array/discuss/60294/Solution-explained
    int partition(int &start,int &end, vector<int> &arr)
    {
        int i=start,j=end;
        while(i<j)
        {
            do{
                i++;
            }while(arr[i]>arr[start]);
            while(arr[j]<arr[start])
            j--;
            if(i<j)
            {int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            }
        }
        int temp=arr[start];
        arr[start]=arr[j];
        arr[j]=temp;
        return j;
        
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        /*
        sort(nums.begin(),nums.end());
        return nums[nums.size()-k];
        */
        //using partition like quick sort,putting all elements greater than arr[start] before it ans all elements less than arr[start] after it then checking if arr[start] is the kth largest, if it is smaller than required, we reduce our range from 0 to j-1, ele vice versa
//         random_shuffle(nums.begin(),nums.end());
//         int start=0,end=nums.size()-1;
//         while(start<end)
//         {
//             int j=partition(start,end,nums);
//             if(j+1 > k)
//             {
//                 end=j-1;
//             }
//             else if(j+1<k)
//             {
//                 start=j+1;
//             }
//             else
//                 return nums[j];
                
//         }
//         return nums[start];
        // using min heap O(nlogk) time O(k) space
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0;i<nums.size();i++)
        {
            pq.push(nums[i]);
            if(pq.size()>k) pq.pop();
        }
        return pq.top();
    }
};