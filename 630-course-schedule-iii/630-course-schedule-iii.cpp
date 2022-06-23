class Solution {
    // https://youtu.be/Z-jQUO07dm0
private:
    static bool compare(vector<int>& v1, vector<int>& v2)
    {
        return v1[1]<v2[1];
    }
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        priority_queue<int> pq;
        int totalduration=0;
        sort(courses.begin(), courses.end(), compare);
        for(int i=0;i<courses.size();i++)
        {
            int curr=courses[i][0];
            int lastdate = courses[i][1];
            // just take this current course
            totalduration+=curr;
            pq.push(curr);
            
            // if we can not take the current course, then skip the courses with max duration out of all the courses taken: greedy aopproach
            if(totalduration>lastdate)
            {
                totalduration-=pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};