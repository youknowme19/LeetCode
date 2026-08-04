int mySqrt(int x) {
    int low = 0;
    int high = x;
    int ans = 0;
    
    while (low <= high){
       int mid = (low + high)/2;
       long long square = mid * mid;
        
        if(square == x)
            return mid;
        else if(square < x){
            ans = mid; 
            low = mid + 1;
        }
        else
            high = mid - 1 ;
    }      
    return ans;

}