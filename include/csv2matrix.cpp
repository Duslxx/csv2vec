#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <fstream>
#include <iterator>
#include <time.h> 
using namespace std;
#include "csv2matrix.h"


vector<vector<string> > csv2matrix(char *array){


char* B;
ifstream sData;
	sData.open(array,ios_base::in | ios_base::binary);
	sData.clear();
	
int N;
	if (sData) {
		
    	sData.seekg (0, sData.end);
     	 N = sData.tellg();
    	sData.seekg (0, sData.beg);
		N=N-sData.tellg();
		
	B = new char [2*N];
	sData.read (B,N);
	sData.close();
}


char delimiter;
vector<int> umlaut;

	int i,k,j;
	char c;
	int del=0;
k=0;
j=0;
del=0;
for(i=0;i<N;i++)
{
//if(B[i]=='Ä' || B[i]=='ä' || B[i]=='Ö' || B[i]=='ö' || B[i]=='Ü' || B[i]=='ü'){umlaut.push_back(i);}	

if(B[i]=='\t'){del++;}
if(B[i]==';'){del--;}	
if(int(B[i])==0 || B[i]=='\0' || int(B[i])==-1 || int(B[i])==-2 || int(B[i])==int('') || int(B[i])==13){}

else{	
if(int(B[i])<91 && int(B[i])>64){B[j]=B[i]+32;}	
else{B[j]=B[i];}
j++;}
}
N=j;




if(del>0){delimiter='\t';}
if(del<0){delimiter=';';}
//cout<<delimiter<<" "<<N<<endl;
int m;

int inside=0;
int in=0;
int affe=0;
	i=0;
int	l=0;
	in=1;
	int lp;
	string BS(B,N);
	m=1;
	i=0;
while(B[i]!='\n'){
	
	if(B[i]==delimiter){m++;}
	i++;
}
m=m-1;
int po;
for(po=0;po<N;po++)
{

}
//cout<<m;

	int kmax=m+1;
	int errorflag=0;
	vector<vector<string> > smatrix(kmax);
	//cout<<smatrix.size()<<endl;
	i=0;
	k=0;
	inside=0;
while(i<N){
	
	if(inside==1 && B[i]=='"'){affe++;}
	if(inside==1 && affe %2==0 && B[i]!='"'){inside=0;}
	if(B[i]=='"' && inside==0){inside=1;affe=1;}

	if(((B[i]==delimiter || B[i]=='\n') && inside==0)  || i==N ){
	
	m=i;
	
	smatrix[k].push_back(BS.substr(l,m-l));
	
	if(k>kmax || k<0){errorflag++;}
	k++;
	if(B[i]=='\n'){k=0;}
	
	l=i+1;}
	
	i++;
}
	delete[] B;
if(errorflag>0){cout<<"some error in "<<array<<endl;}
else{
	//cout<<array<<" :all good!"<<endl;
}
	return(smatrix);
	}


	
	

	void analyzeC(char *A){
		
	//0..random string
	//0...time: dd.mm.yyyy hh.mm.ss
	//1...time: dd.mm.yyyy hh.mm
	//2...time: dd.mm.yyyy
	//3...time: yyyy.dd.mm
	//4...time: dd.mm
	//5...time: yyyy.dd.mm hh.mm.ss
	//5...time: yyyy.dd.mm hh.mm
	
	//if(d==16 || d==19 || d==10){cout<<"time? ";
	int i;
	if(A[2]=='.' && A[5]=='.'){
		//cout<<"hit"<<endl;
		//cin>>i;
	//for(i=10;i<4;i--){
	char h,p,k,i;
	h=A[0];
	p=A[1];
	k=A[3];
	
	A[0]=A[6];
	A[1]=A[7];
	A[2]=A[8];
	A[3]=A[9];
	
	A[8]=h;
	A[9]=p;
	A[7]='-';
	
	
	A[6]=A[4];
	A[5]=k;
	
	//A[3]=A[9];
	A[4]='-';	
		
	//}	
	
	}	
	}