#include<iostream>
#include<cstdio>
int main(){
	double fo,fe,fa;
	while(scanf("%lf%lf%lf",&fo,&fe,&fa),fo+fe+fa)
		printf("%.2lf %.2lf\n",fo/fe,fa/(fo/fe));
}