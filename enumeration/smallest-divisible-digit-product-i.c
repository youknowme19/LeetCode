int smallestNumber(int n, int t) {
    int mul=1;
    int dup=n;
    while(dup!=0){
        dup=dup%10;
        mul=mul*dup;
        dup/=10;
    }
    if(mul%t==0){
        return n;
    }
    else{
        n++;
        smallestNumber(n,t);
    }
    return n;
}