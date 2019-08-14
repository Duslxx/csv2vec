#include <iostream>     // std::cout
#include <fstream>      // std::ifstream
#include <vector>
#include <stdlib.h>
#include <string>
#include <sstream>
#include "csv2matrix.h"
#include "winfiles.h"

int main(){
	int i;
	
	vector<string> names=get_all_files_win("ALL_Files");
	
	char file[]="ALL_Files/All_Applications-Active_and_Not_CSV-en.csv";
	vector<vector<string> > matrix;
	vector<vector<vector<string> > > ALL;
	string path;
	char *B;
	for(i=0;i<names.size();i++){
	//cout<<matrix[0].size()<<endl;
	//cout<<matrix[i][1]<<endl;
	cout<<names[i]<<endl;
	path="ALL_Files/"+names[i];
	//cout<<path<<endl;
	//cin>>i;
	B=&path[0];
	matrix=csv2matrix(B);
	ALL.push_back(matrix);
	cout<<ALL[i][0][0]<<endl;
	cout<<ALL[i][0][1]<<endl<<endl;
	
	
	}
	std::cin>>i;	


return(0);	
}