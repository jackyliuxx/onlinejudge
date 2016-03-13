#include <iostream>
using namespace std;
int main(){
	char ae,a1,a2,a3,a4,a5,a6,a7,a8,a9;
	int a,e,t;
	while(1){
		cin>>ae>>a1>>a2>>a3>>a4>>a5>>a6>>a7>>a8>>a9;
		if(cin.eof())break;
		if(ae<'I'){
			a = (ae-55)/10;
			e = (ae-55)%10;
		}
		else if(ae>'I' && ae<'O'){
			a = (ae-56)/10;
			e = (ae-56)%10;
		}
		else if(ae>'O'&& ae<'W'){
			a = (ae-57)/10;
			e = (ae-57)%10;
		}
		else if(ae>'W'&& ae<'Z'){
			a = (ae-58)/10;
			e = (ae-58)%10;
		}
		else{
			if(ae=='I'){
				a=(ae-39)/10;
				e=(ae-39)%10;
			}
			if(ae=='O'){
				a=(ae-44)/10;
				e=(ae-44)%10;
			}
			if(ae=='W'){
				a=(ae-55)/10;
				e=(ae-55)%10;
			}
			if(ae=='Z'){
				a=(ae-57)/10;
				e=(ae-57)%10;
			}
		}
		t= a + e*9 + (a1-48)*8+(a2-48)*7+(a3-48)*6+(a4-48)*5+
			(a5-48)*4+(a6-48)*3+(a7-48)*2+(a8-48)*1+(a9-48);
		if(t%10==0)
			cout<<"real\n";
		else
			cout<<"fake\n";
	}
}