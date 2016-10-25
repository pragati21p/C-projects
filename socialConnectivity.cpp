#include<iostream>
using namespace std;
class community{
	int par[1001],n,rot,i,j,child[1001];
	
	string s;
	
	public:
		void input(){
			cout<<"enter the no. of elements\n";
			cin>>n;
			for(i=1;i<=n;i++){ par[i]=i;child[i]=1;}
		}
		int command(){
			cin>>s;
			int pp=community::check();
			return pp;
		}
		
		int check(){
			if(s[0]=='C'||s[0]=='c'){
				cout<<"Update\n";
				community::update();
			}
			
			else if(s[0]=='Q'||s[0]=='q'){
				cout<<"query\n";
				community::query();
			}
			else{
				cout<<"\nEnd of input\n";
				return 0;
			}
			return 1;
		}
		
		void query(){
			cin>>i>>j; // Just to adjust the input 0 0 in Q 0 0...0 0 of no use :P
			int count=0;
			for(i=1;i<=n;i++){
				if((child[i]!=0) && (child[i]%2==0)) count++;
			}
			cout<<"Ans= "<<count<<endl;
		}
		
		void update(){
			int a,b,c,d;
			cin>>a>>b;
			c=par[a];d=par[b];
			if(c!=d){
				child[c]=child[c]+child[d];
				child[d]=0;
			}
			for(i=1;i<=n;i++){
				if(par[i]==d) par[i]=c;
			}
		}
};

int main(){
	community c;
	c.input();
	while(1){
		int status=c.command();
		if(status==0) break;
	}
}
