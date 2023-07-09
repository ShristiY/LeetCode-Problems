class Solution {
public:
    
    int maxElement(vector<int>& arr){
        int maxi = INT_MIN;
        for(int i=0; i<arr.size(); i++){
            maxi = max(maxi, arr[i]);
        }
        return maxi;
    }

    long long calculate_totalhrs(vector<int>& arr, int hourly){
        long long totalhrs = 0;
        for(int i=0; i<arr.size(); i++){
            totalhrs += (arr[i] + hourly - 1) / hourly;
        }
        return totalhrs;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1; 
        int high = maxElement(piles);
        int ans=maxElement(piles);
        while(low < high){
            int mid = low + (high-low)/2;
            int totalhrs = calculate_totalhrs(piles, mid);

            if(totalhrs <= h){
                ans=mid;
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }

        return ans;
    }
};