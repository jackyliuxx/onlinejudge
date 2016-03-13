#include <iostream>
using namespace std;
int main(){
	int m,d,s;
	while(cin>>m>>d){
		s=(m*2+d)%3;
		if(s==0)
			cout<<"´¶³q\n";
		else
			if(s==1)
				cout<<"¦N\n";
			else
			cout<<"¤j¦N\n";
	}
}