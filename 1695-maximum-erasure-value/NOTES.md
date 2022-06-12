int left = 0, right = 0;
int n = nums.size();
map<int, int> m;
int ans = 0, sum = 0;
while (right < n)
{
if (m[nums[right]] > 0)
{
while (nums[left] != nums[right])
{
sum -= nums[left];
m[nums[left]] = 0;
left++;
}
sum -= nums[left];
m[nums[left]] = 0;
left++;
}
•
sum += nums[right];
m[nums[right]]++;
ans = max(ans, sum);
right++;
}
return ans;
}
};
```