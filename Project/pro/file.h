#ifndef FIL_E
#define FIL_E
#include<iostream>
using namespace std;
#include<string>
#include <vector>
#include"Nationalities.h"
class File
{

	string filename = "AllFile.txt";//will convert to char* later.

	public:

	vector<Nationalities>Nationality;
        string get_filename();



};
#endif
