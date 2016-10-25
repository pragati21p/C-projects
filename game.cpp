#include<iostream>

using namespace std;
char matrix[3][3]={'1','2','3','4','5','6','7','8','9'};
char player='X';
int x,y;
void draw(){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout<<matrix[i][j]<<" ";
		}
		cout<<"\n";
	}
}

int input(){
	char a;
	int i;
	cout<<"choose any number given above : ";
	cin>>a;
	if(a<='9' && a>'0'){
		for(i=0;i<3;i++){
			for(int j=0;j<3;j++){
				if(a==matrix[i][j]){
					matrix[i][j]=player;
					x=i; y=j;
					return 1;
				}
			}	
		}
		if(i==3) {
			cout<<"digit already choosen"<<endl;
			input();
		}
		
	}
	else{
		cout<<"wrong input"<<endl;
		input();
		return 1;
	}	
}

void toggleplayer(){
	if(player=='X')
		player='O';
	else
		player='X';

}

int check(){
	int set=0,j;
	for(j=0;j<3;j++){
		if(matrix[x][j]!=player){
			set=0;
			break;
		}
		else set=1;
	}
	if(j==3 && set==1){
		cout<<"player "<<player<<" is winner"<<endl;
		exit 0;
	}
	for(j=0;j<3;j++){
		if(matrix[j][y]!=player){
			set=0;
			break;
		}
		else set=1;
	}
	if(j==3 && set==1){
		cout<<"player "<<player<<" is winner"<<endl;
		exit 0;
	}
	
	if(x==y){
		for(j=0;j<3;j++){
			if(matrix[j][j]!=player){
				set=0;
				break;
			}
			else set=1;
		}
		if(j==3 && set==1){
			cout<<"player "<<player<<" is winner"<<endl;
			exit 0;
		}
	}
}

int main(){
	int count=0;
	draw();
	while(count<9){
		input();
		draw();
		check();
		toggleplayer();
		count++;
	}
	
	return 0;
}
