#include<iostream>
using namespace std;
#include<string>
#include"file.h"
#include<vector>



string File:: filename = "AllFile.txt";//will convert to char* later.

string File::get_filename()
{
                return filename;
}
