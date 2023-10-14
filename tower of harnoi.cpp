/*  Author: chester_king  */
#include<iostream>
using namespace std;
#include<string>
#include<cmath>
#include<math.h>
#include<climits>
#include<algorithm>
#include<cstring>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<map>
#include<set>
#define ll long long
#define pb push_back
#define mod 1000000007

void move(int n,char scr,char helper,char dest){
	if(n==0){
		return;
	}

	move(n-1,scr,dest,helper);
	cout<<"shift disk "<<n<<" from "<<scr<<" to "<<dest<<endl;
	move(n-1,helper,scr,dest);
}


int main(){
	int num;
	cin>>num;
	
	move(num,'A','B','C');
}
