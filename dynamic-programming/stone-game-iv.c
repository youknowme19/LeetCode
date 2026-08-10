bool winnerSquareGame(int n) {
    if(n==1){
        return true;
    }
   
    int a = sqrt(n);
    if(a*a==n){
        return true;
    }
    return false;
}