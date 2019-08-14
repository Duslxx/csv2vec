#include <Windows.h>
#include <vector>
#include <string>
#include <iostream>

std::vector<std::string> get_all_files_win(std::string folder){
	std::vector<std::string> names;
    std::string search_path = folder + "/*.*";
	//std::string search_path ="ALL_Files/*.*";
    WIN32_FIND_DATA fd; 
    HANDLE hFind = ::FindFirstFile(search_path.c_str(), &fd); 
    if(hFind != INVALID_HANDLE_VALUE) { 
        do { 
            // read all (real) files in current folder
            // , delete '!' read other 2 default folder . and ..
            if(! (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) ) {
                names.push_back(fd.cFileName);
				//std::cout<<fd.cFileName<<std::endl;
            }
        }while(::FindNextFile(hFind, &fd)); 
        ::FindClose(hFind); 
    } 
    return names;
	
	
}