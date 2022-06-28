class Solution {
    // https://youtu.be/m18Hntz4go8
public:
    int trap(vector<int>& height) {
        // int n=height.size();
        // vector<int> maxl(n), maxr(n);
        // int max=height[0];
        // for(int i=0;i<n;i++)
        // {
        //     if(height[i]>max)
        //     {
        //         max=height[i];
        //     }
        //     maxl[i]=max;
        // }
        // max=height[n-1];
        // for(int i=n-1;i>=0;i--)
        // {
        //     if(height[i]>max)
        //     {
        //         max=height[i];
        //     }
        //     maxr[i]=max;
        // }
        // int ans=0;
        // for(int i=0;i<n;i++)
        // {
        //     int temp=min(maxr[i],maxl[i]);
        //     //if(temp==height[i]) continue;
        //     ans+=temp-height[i];
        // }
        // return ans;
        
        // constant space two pointers
        int left=0, right=height.size()-1;
        int ans=0, leftmax=0, rightmax=0;
        while(left<=right)
        {
            if(height[left]<=height[right])
            {
                if(leftmax<=height[left])
                {
                    leftmax=height[left];
                }
                else
                {
                    ans+=leftmax - height[left];
                }
                left++;
            }
            else
            {
                if(rightmax<=height[right])
                {
                    rightmax=height[right];
                }
                else
                {
                    ans+=rightmax - height[right];
                }
                right--;
            }
        }
        return ans;
    }
};