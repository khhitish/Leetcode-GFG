class Solution
{
    public:
        vector<int> maxSlidingWindow(vector<int> &nums, int k)
        {
            vector<int> ans;
            int n = nums.size();
            
            // deque solution
            // deque<int> d;
            // for (int i = 0; i < n; i++)
            // {
            //     if (i >= k)	//only after the initial window is formed we start deleting
            //     {
            //         ans.push_back(nums[d.front()]);	//max for the windows from (i-1)-k+1 to i-1
            //         if (!d.empty() && d.front() <= i - k)	//removing out of window element
            //         {
            //             d.pop_front();
            //         }
            //     }
            //     while (!d.empty() && nums[d.back()] <= nums[i])	//getting rid of smaller elements because they wont be max in this or in future subarrays
            //     {
            //         d.pop_back();
            //     }
            //     d.push_back(i);
            // }
            // ans.push_back(nums[d.front()]);
            // return ans;
            
            // priority_queue solution, just need to handle the index, no need to delete smaller values
            priority_queue<pair<int,int>> pq; //val,index
            for(int i=0;i<k;i++)
            {
                pq.push({nums[i],i});
            }
            ans.push_back(pq.top().first);
            for(int i=k;i<n;i++)
            {
                pq.push({nums[i],i});
                while(pq.top().second<=i-k)
                {
                    pq.pop();
                }
                ans.push_back(pq.top().first);
            }
            return ans;
        }
};