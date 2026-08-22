bool checkDivisibility(int n) {
    int sum=0;
    int product=1;
    int d=n;
    while(d>0){
        int a=d%10;
        sum=sum+a;
        product=product*a;
        d=d/10;
    }
    int di=sum+product;
    if(n%di==0){
        return true;
    }
    else
    return false;
}