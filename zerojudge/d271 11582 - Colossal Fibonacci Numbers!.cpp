#include <iostream>
using namespace std;
int f[1000000],g[1000000];
int main () {
	unsigned long long a,b;
	int t,n,x,m,f1,f2,l,i,j,fn,ax,ft,gt;
	cin>>t;
	while(t--){
		cin>>a>>b>>n;
		x=0;        //第一循環和
		l=0;        //下一循環
		m=1;        //幾個一循環
		f1=0,f2=1;
		ft=gt=0;
		f[0]=0;
		while(f2%n){               //第一循環
			x+=f2;
			x%=n;
			f[++ft]=f2;
			fn=(f1+f2)%n;
			f1=f2;
			f2=fn;
			m++;
		}
		l=x;
		i=1;
		g[0]=1;
		while(l){
			g[++gt]=l+1;
			i++;
			l=(l*x+x+l)%n;
		}
		m*=i;
		a%=m;
		ax=1;
		while(b){
			if(b%2)
				ax=(ax*a)%m;
			a=(a*a)%m;
			b/=2;
		}
		cout<<(f[ax%(m/i)]*g[ax/(m/i)])%n<<endl;
	}
}