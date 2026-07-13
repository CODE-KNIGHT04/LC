class Solution {
public:
    double myPow(double x, int n){
        long long N = n;
        return pow(x,N);
    }
    double pow(double x , long long n){

        if(n==0){
            return 1;
        }
        if(n==1){
            return x;
        }
        if(x==0){
            return 0;
        }
        if(x==1){
            return 1;
        }
        if(n<0){
            x=1/x;
            n=abs(n);
        }
        double a = myPow(x,n/2);
        if(n%2==0){
                return a*a;
            }
            return x*a*a;
        return 0;
    }

};