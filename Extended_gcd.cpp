#include<bits/stdc++.h>
using namespace std;
void call(int a, int b, int &x, int &y)
{
    if(b==0){
        x=1,y=0;
        return ;
    }
    int x1,y1;
    call(b, a%b, x1,y1);
    y= x1- (a/b)*y1;
    x=y1;
}
int main()
{
    int a, b,x,y,c;
    while(cin>>a>>b>>c){

        call(a, b, x, y);

        int gcd = (x*a + b*y);
        x*=(c/gcd);
        y*= (c/gcd);
        cout<<"x= "<<x<<"\ny= "<<y<<endl;

    }
    return 0;
}
