class Solution {
public:
    
    bool ispossible( vector<int> &stalls , int k , int dist){
         
         int cntcows = 1;
         int lastplacedcow =stalls[0];
         
         for(int i = 1; i < stalls.size() ; i++){
             
             if( stalls[i] - lastplacedcow >= dist){
                 
                 cntcows++;
                 lastplacedcow = stalls[i];
             }
         }
         
         if(cntcows >= k)
         return true;
         
         return false;
     }
    int maxDistance(vector<int>& arr, int k) {
         sort(arr.begin() , arr.end());
       int n=arr.size();
        int low = 1;
        int high = arr[n-1] - arr[0];
        
        while( low <= high){
            
            int mid = low+(high-low)/2;
            
            if( ispossible( arr ,  k , mid)){
                
                low = mid + 1;
            }
            
            else{
                high = mid -1;
            }
            
            
        }
        
        return high;
    }
};