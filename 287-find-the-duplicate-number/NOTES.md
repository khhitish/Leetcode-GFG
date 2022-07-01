Fast Slow Pointers
This problem is as same as 142. Linked List Cycle II, you can refer to this solution for the explanation of the slow fast pointer approach to solve this problem.
​
The key is to understand how to treat the input array as a linked list.
​
Take the array [1,3,4,2] as an example, the index of this array is [0, 1, 2, 3], we can map the index to the nums[n].
​
0->1
1->3
2->4
3->2
Start from 0， use value nums[n] as a new index, and so on, until the index exceeds the bounds. This produces a sequence similar to a linked list.
​
0->1->3->2->4->null
If there are a repeated numbers in the array, take the array [1,3,4,2,2] as an example,
​
0->1
1->3
2->4
3->2
4->2
Similarly, a linked list is like that:
​
0->1->3->2->4->2->4->2->…