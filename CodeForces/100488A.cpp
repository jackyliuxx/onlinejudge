#include<bits/stdc++.h>
using namespace std;
int main(){
    double rr[5],r;
    cin>>rr[0]>>rr[1]>>rr[2]>>r;
    rr[3] = rr[0];
    rr[4] = rr[1];
    double fc= 0,ff;
    for(int i=0;i<3;i++){
        double a = rr[i],b = rr[i+1],c = rr[i+2];
        double cost = (a*a+b*b-c*c)/2/a/b;
        double sint = sqrt(1-cost*cost);
        double sint2 = sqrt((1-cost)/2);
        double cost2 = sqrt(1-sint2*sint2);
        if(i==0){
            ff = a*b*sint/2;
        }
        fc += r*r*cost2/sint2;
    }
    fc -= r*r*acos(-1);
    if(fc<0)
        fc = 0;
    //printf("%.12f %.12f\n",fc,ff);
    printf("%.15f\n",(ff-fc)/ff);
}
        
    

