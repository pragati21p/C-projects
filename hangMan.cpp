#include<iostream>
#include <string>
#include <conio.h>
#include<vector>
using namespace std;
char ch,a;
int life=6,num=1;
string pass ="";
vector<char> v1;
vector<char> v2;
void check(){
	cout<<"guess the letter : "<<endl;
	int i;
	cin>>a;
	if(num==2){
		for(i=0;i<v1.size();i++){
			if(v1[i]==a){
				cout<<"already chosen"<<endl;
				check();
			}
		}
		v1.push_back(a);
	}
	else {
		num=2;
		v1.push_back(a);
	}
}

void getWord(){
	int i,z=0;
	
	for(i=0;pass[i]!='\0';i++){
		if(v1[v1.size()-1]==pass[i]){
			v2[i]=pass[i];
			z=1;
		}
	}
	if(z==0){
		life--;
	}
}

void print(){
	for(int i=0;i<v2.size();i++){
		cout<<v2[i];
	}
	cout<<endl;
}


int end(){
	for(int i=0;i<v2.size();i++){
		if(v2[i]=='*'){
			return 0;
		}
	}
	cout<<"you win"<<endl;
		exit(0);
}

int main(){
	int x,i;
   cout << "Enter pass\n";
   ch = _getch();
   while(ch != 13){//character 13 is enter
      pass.push_back(ch);
      cout << '*';
      ch = _getch();
   }
   cout<<endl;
   cout<<"you can give upto 6 wrong letters"<<endl;
	for(i=0;pass[i]!='\0';i++){
		v2.push_back('*');
	}
	while(life>0){
		check();
		getWord();
		print();
		end();
	}
	cout<<"Sorry, you are disqualified!!"<<endl;
	return 0;
}
