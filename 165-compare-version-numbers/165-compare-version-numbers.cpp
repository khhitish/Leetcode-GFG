class Solution {
public:
    int compareVersion(string version1, string version2) {
        int m=version1.size(), n=version2.size();
        int i=0,j=0;
        while(i<m || j<n)
        {
            int v1=0, v2=0;
            string t1,t2;
            while(i<m && version1[i]!='.')
            {
                t1+=version1[i];
                i++;
            }
            i++;
            if(t1.size()>0) v1=stoi(t1);
            while(j<n && version2[j]!='.')
            {
                t2+=version2[j];
                j++;
            }
            j++;
            if(t2.size()>0) v2=stoi(t2);
            if(v1<v2) return -1;
            else if(v1>v2) return 1;
        }
        return 0;
    }
};