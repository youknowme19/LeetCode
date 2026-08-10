bool winnerSquareGame(int n) {
    if(n==1){
        return true;
    }
    else if(n%2!=0){
        return false;
    }
    int a = sqrt(n);
    if(a*a==n){
        return true;
    }
    return false;
}