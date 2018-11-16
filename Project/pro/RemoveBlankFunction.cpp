#include<iostream>
#include<string>
#include<vector>
#include<memory>
#include<fstream>
#include<cstring>
#include<stdlib.h>
#include<algorithm>

using namespace std;




int main(int argc,char**argv)
{
ifstream inFile;
inFile.open("tr.txt");
if(!inFile.is_open())
                {cout<<"file not found.";
                        //exit(1);
                }

             //   string rope;
                char rope[100];
                inFile>>rope;
                int f =0;
                char *token;
                char *e;
token=strtok(rope,"\n");
int g=0;
for(g=0;g<100;g++)
{

if(token[g]=='_')
token[g]=' ';
}
		string name(rope);
			cout<<"*****"<<name<<" "<<endl;
                while(!inFile.eof())
                {
//                       inFile.getline(rope,100);
//		if(f==0)
		{
		inFile >> rope;
//		
		}

//int g=0;
for(g=0;g<100;g++)
{

if(token[g]=='_')
token[g]=' ';
}
token=strtok(rope,"\n");
			cout<<"*****"<<token<<" "<<endl;
		}




}
