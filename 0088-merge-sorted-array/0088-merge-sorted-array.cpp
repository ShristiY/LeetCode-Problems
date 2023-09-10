class Solution {
public:
    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
        for(int i=0;i<m;i++)
            nums1[i+n]=nums2[i];
        
        int gap=ceil((float)(n+m)/2);
        while(gap>0)
        {
            for(int i=0;i+gap<n+m;i++)
            {
                if(nums1[i]>nums1[i+gap])
                    swap(nums1[i],nums1[i+gap]);
            }
            if(gap==1) gap=0;
            else
                gap=ceil((float)gap/2);
        }
    }
};