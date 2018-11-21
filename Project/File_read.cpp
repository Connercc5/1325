#include<iostream>
#include<string>
#include<vector>
//#include<memory>
#include<fstream>
#include<cstring>
#include<stdlib.h>
#include<algorithm>
#include<stdlib.h>
#include"ingredient.h"
#include"recipe.h"
using namespace std;
	Recipe::Recipe(string recipe_name ,vector <ingredient> ingr,int num_of_ingredients)
{
	this->recipe_name=recipe_name;
	this->ingr=ingr;
	this->num_of_ingredients=num_of_ingredients;
}
ingredient::ingredient(double amount,string unit,string ingre_name)
{
	this->quantity=amount;
	this->unit=unit;
	this->name=ingre_name;

}



class File
{
	public:
		string nationality;
		vector<Recipe> L1;//LUNCH RECIPES
		vector<Recipe> D1;//DINNER RECIPES
		vector<Recipe> B1;//BREAKFEST RECIPES
		vector<Recipe> E1;//DESSERT RECIPES
		vector<Recipe> S1;//SNACK RECIPES
int B_num;//num of Breakfest recipes
int L_num;//num of Lunch recipes
int D_num;//num of Dinner recipes
int S_num;//num of Snack recipes
int E_num;//num of Dessert recipes

};
class Nationalities
{
	string filename="AllFile.txt";//will convert to char* later.

	public:
	vector<File>Foo;
		string get_filename()
		{
			return filename;
		}
		void get_file_input()
		{



		}
};
string get_underscore(string s)
{
int f =s.length();
char token[f+1];
int p=0;
strcpy(token,s.c_str());
while(p<s.length())
        {
                if(token[p]==' ')
                        token[p]='_';
                p++;
        }

string see(token);
return see;
}
void BlankC(char*token)
{
	int f=0;
	string t(token);
	while(f<t.length())
	{
		if(token[f]=='_')
			token[f]=' ';
		f++;
	}
}
void File_write(Nationalities N1)
{
	int g =N1.get_filename().length();
	char file[g+1];
	strcpy(file,N1.get_filename().c_str());
	ofstream outFile;
	outFile.open(file);
	outFile<<"BEGIN"<<endl;
	g=0;
	int j=0;
	while(g<N1.Foo.size())
	{

//Get the modified amount of meals for Breakfest-Dessert
		
		
		
		
		
		j=0;	
		//Breakfest
		while(j<N1.Foo[g].B1.size())
                {
                      int b=0;
                      string name = get_underscore(N1.Foo[g].B1[j].recipe_name);
                      if(name.compare("DELETE")==0)
                      {
                         N1.Foo[g].B_num--;
                      }
		      j++;
                }

		j=0;	
		//Lunch
		  while(j<N1.Foo[g].L1.size())
                {
                      int b=0;
                      string name = get_underscore(N1.Foo[g].L1[j].recipe_name);
                      if(name.compare("DELETE")==0)
                      {
                         N1.Foo[g].L_num--;
                      }
		      j++;

                }

		j=0;	
		//Dinner
		  while(j<N1.Foo[g].D1.size())
                {
                      int b=0;
                      string name = get_underscore(N1.Foo[g].D1[j].recipe_name);
                      if(name.compare("DELETE")==0)
                      {
                         N1.Foo[g].D_num--;
                      }
		      j++;

                }

		j=0;	
		//Snack
		while(j<N1.Foo[g].S1.size())
                {
                      int b=0;
                      string name = get_underscore(N1.Foo[g].S1[j].recipe_name);
                      if(name.compare("DELETE")==0)
                      {
                         N1.Foo[g].S_num--;
                      }
		      j++;

                }

		j=0;	
		//Dessert
		while(j<N1.Foo[g].E1.size())
                {
                      int b=0;
                      string name = get_underscore(N1.Foo[g].E1[j].recipe_name);
                      if(name.compare("DELETE")==0)
                      {
                    	 N1.Foo[g].E_num--;
		      }
		      j++;

                }

//Write to file
	
		j=0;
		outFile<<N1.Foo[g].nationality<<endl;
		outFile<<"Breakfest#"<<N1.Foo[g].B_num<<endl;
		while(j<N1.Foo[g].B1.size())
		{

			int b=0;

			string name = get_underscore(N1.Foo[g].B1[j].recipe_name);
                      	if(name.compare("DELETE")!=0)
			{
				outFile<<name<<":"<<N1.Foo[g].B1[j].ingr.size()<<endl;
				outFile<<"START_";
				while(b<N1.Foo[g].B1[j].ingr.size())
				{
					outFile<<N1.Foo[g].B1[j].ingr[b].quantity<<"_"<<get_underscore(N1.Foo[g].B1[j].ingr[b].unit)<<"_"<<get_underscore(N1.Foo[g].B1[j].ingr[b].name)<<",";
					b++;	
				}	
				outFile<<endl;
			}
			j++;	
		}
		j=0;
		outFile<<"Lunch#"<<N1.Foo[g].L_num<<endl;
		while(j<N1.Foo[g].L1.size())
		{
			int b=0;
			string name = get_underscore(N1.Foo[g].L1[j].recipe_name);
                        if(name.compare("DELETE")!=0)
		        {
				outFile<<name<<":"<<N1.Foo[g].L1[j].ingr.size()<<endl;
				outFile<<"START_";
				while(b<N1.Foo[g].L1[j].ingr.size())
				{
              				  outFile<<N1.Foo[g].L1[j].ingr[b].quantity<<"_"<<get_underscore(N1.Foo[g].L1[j].ingr[b].unit)<<"_"<<get_underscore(N1.Foo[g].L1[j].ingr[b].name)<<",";
					b++;
				}
				outFile<<endl;
		        }
		        j++;
		}
		j=0;
                outFile<<"Dinner#"<<N1.Foo[g].D_num<<endl;
                while(j<N1.Foo[g].D1.size())
                {
                       	int b=0;
                       	string name = get_underscore(N1.Foo[g].D1[j].recipe_name);
                      if(name.compare("DELETE")!=0)
		      {
		      	      outFile<<name<<":"<<N1.Foo[g].D1[j].ingr.size()<<endl;
                       	      outFile<<"START_";
                       	      while(b<N1.Foo[g].D1[j].ingr.size())
                        	{
                        	       	 outFile<<N1.Foo[g].D1[j].ingr[b].quantity<<"_"<<get_underscore(N1.Foo[g].D1[j].ingr[b].unit)<<"_"<<get_underscore(N1.Foo[g].D1[j].ingr[b].name)<<",";
                               		 b++;
                        	}
                        	outFile<<endl;
		      }
		      j++;
		}

		j=0;
               	outFile<<"Snack#"<<N1.Foo[g].S_num<<endl;
               	while(j<N1.Foo[g].S1.size())
               	{
                       	int b=0;
                       	string name = get_underscore(N1.Foo[g].S1[j].recipe_name);
			if(name.compare("DELETE")!=0)
			{
				outFile<<name<<":"<<N1.Foo[g].S1[j].ingr.size()<<endl;
                      		outFile<<"START_";
                        	while(b<N1.Foo[g].S1[j].ingr.size())
                        	{
                             		outFile<<N1.Foo[g].S1[j].ingr[b].quantity<<"_"<<get_underscore(N1.Foo[g].S1[j].ingr[b].unit)<<"_"<<get_underscore(N1.Foo[g].S1[j].ingr[b].name)<<",";
                               		b++;
                        	}
                        	outFile<<endl;
			}
			j++;
		}
		j=0;
                outFile<<"Dessert#"<<N1.Foo[g].E_num<<endl;
                while(j<N1.Foo[g].E1.size())
                {
                      int b=0;
                      string name = get_underscore(N1.Foo[g].E1[j].recipe_name);
                      if(name.compare("DELETE")!=0)
		      {
		     	 	outFile<<name<<":"<<N1.Foo[g].E1[j].ingr.size()<<endl;
                     	 	outFile<<"START_";
                     	 	while(b<N1.Foo[g].E1[j].ingr.size())
                     	 	{
                      				outFile<<N1.Foo[g].E1[j].ingr[b].quantity<<"_"<<get_underscore(N1.Foo[g].E1[j].ingr[b].unit)<<"_"<<get_underscore(N1.Foo[g].E1[j].ingr[b].name)<<",";
                        	        	b++;
                      		 }
                       		 outFile<<endl;
		      }
		      
		      j++;

		}
		g++;
	}
	outFile.close();
}

int main(int argc,char**argv)
{
	vector<ingredient> G;
	ifstream inFile;
	Nationalities N1;
	File F1;
	int g =N1.get_filename().length();
	char file[g+1];
	strcpy(file,N1.get_filename().c_str());
	inFile.open(file);//opens AllFile.txt
	if(!inFile.is_open())
	{
		cout<<"file not found.";
                        //exit(1);
	}
	char rope[900];
	inFile>>rope;
	int f =0;
	char *token;
	char *e;
	token=strtok(rope,"\n");
	g=0;
	int i=0;
	int fi=0;
	int s=0;
	int l=0;
	int Num=0;
	inFile >> rope;
	double amount=0;                
	//intializing all meal nums to 0
	F1.B_num=0;//number of Breakfest recipes
	F1.L_num=0;//number of Lunch recipes
	F1.D_num=0;//number of Dinner recipes
	F1.S_num=0;//number of Snack recipes
	F1.E_num=0;//number of Dessert recipes
	
	
	while(!inFile.eof())
        {
		token=strtok(rope,"\n");
		BlankC(token);
		string Nation(token);
		F1.nationality=Nation;
		//cout<<"Nationality: "<<Nation<<" "<<endl;
		while(fi<5)
		{
			inFile >> rope;
			token=strtok(rope,"#");
			string t_name(token);
			token=strtok(NULL,"\n");
			Num=0;
			Num=atoi(token);
//			cout<<"TIME: "<<t_name<<"NUM: "<<Num<<endl;
			if(fi==0)
				F1.B_num=Num;
			else if(fi==1)
				F1.L_num=Num;	
			else if(fi==2)
				F1.D_num=Num;
			else if(fi==3)
				F1.S_num=Num;
			else if(fi==4)
				F1.E_num=Num;
			while(s<Num)
			{
				inFile >> rope;
				token=strtok(rope,":");

				BlankC(token);
				string Rep_name(token);						
				token=strtok(NULL,"\n");
				int Rep_num=atoi(token);
			//	cout<<"RECIPE NAME:"<<Rep_name<<" RECIPE INGERDENT NUMBER: "<<Rep_num<<endl;


				inFile >> rope;

				token=strtok(rope,"_");
				i=0;
				while(i<Rep_num)
				{	
					token=strtok(NULL,"_");
					amount=atof(token);
					BlankC(token);
					token=strtok(NULL,"_");
					BlankC(token);
					string unit(token);
					token=strtok(NULL,",");
					BlankC(token);
					string ingre_name(token);
					//cout<<"INGREDIENT "<<i<<": "<<amount<<" "<<unit<<" "<<ingre_name<<endl;
					G.push_back(ingredient(amount,unit,ingre_name));
					i++;

				}
				i=0;
				//PUSHES RECIPES INTO THE BREAKFEST-DESSERT CATAGORIES
				if(fi==0)
				{
					F1.B1.push_back(Recipe(Rep_name,G,Rep_num));
				}
				else if(fi==1)
				{
					F1.L1.push_back(Recipe(Rep_name,G,Rep_num));
				}
				else if(fi==2)
				{
					F1.D1.push_back(Recipe(Rep_name,G,Rep_num));
				}
				else if(fi==3)
				{
					F1.S1.push_back(Recipe(Rep_name,G,Rep_num));
				}
				else if(fi==4)
				{	
					F1.E1.push_back(Recipe(Rep_name,G,Rep_num));
				}
				G.clear();
				s++;

			}
			s=0;
			fi++;
		}
		fi=0;
		
		N1.Foo.push_back(F1);
		i++;	
		F1.B1.clear();
		F1.L1.clear();
		F1.D1.clear();
		F1.S1.clear();
		F1.E1.clear();
		inFile >> rope;
	}

	//cout<<N1.Foo.size()<<endl;
	g=0;
/*	while(g<N1.Foo.size())
	{
		cout<<N1.Foo[g].nationality<<endl;
		cout<<N1.Foo[g].B_num<<endl;
		cout<<N1.Foo[g].L_num<<endl;
		cout<<N1.Foo[g].D_num<<endl;
		cout<<N1.Foo[g].S_num<<endl;
		cout<<N1.Foo[g].E_num<<endl;
		int jk=0;
	
		while(jk<N1.Foo[g].B1.size())
		{
			//cout<<N1.Foo[g].B1[jk].recipe_name<<endl;
	
			int kp=0;
			cout<<N1.Foo[g].B1[jk].recipe_name<<endl;
			while(kp<N1.Foo[g].B1[jk].ingr.size())
			{
	

				cout<<N1.Foo[g].B1[jk].ingr[kp].name<<" "<<N1.Foo[g].B1[jk].ingr[kp].quantity<<" "<<N1.Foo[g].B1[jk].ingr[kp].unit<<endl;
				kp++;
			}
			
			jk++;
		}
		g++;
	}*/
	inFile.close();
	//File_write();
	File_write(N1);
}
