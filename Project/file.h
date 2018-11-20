#ifndef FILE
#define FILE
#include<iostream>
using namespace std;
#include<string>
#include <vector>

class File
{
	public:
        string nationality;
        vector<Recipe> breakfast;
        vector<Recipe> lunch;
        vector<Recipe> dinner;
        vector<Recipe> snack;
        vector<Recipe> desert;
        void add_file();
        void modify_file();
        void delete_file();
};
#endif
