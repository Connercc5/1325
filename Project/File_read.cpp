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
	char rope[500];
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
	inFile >> rope;
	double amount=0;                
	while(!inFile.eof())
        {
		token=strtok(rope,"\n");
		BlankC(token);
		string Nation(token);
		F1.nationality=Nation;
	//	cout<<"Nationality: "<<Nation<<" "<<endl;
		while(fi<5)
		{
			inFile >> rope;
			token=strtok(rope,"#");
			string t_name(token);
			token=strtok(NULL,"\n");
			int Num=atoi(token);
			//cout<<"TIME: "<<t_name<<"NUM: "<<Num<<endl;
			while(s<Num)
			{
				inFile >> rope;
				token=strtok(rope,":");

				BlankC(token);
				string Rep_name(token);						
				token=strtok(NULL,"\n");
				int Rep_num=atoi(token);
				//cout<<"RECIPE NAME:"<<Rep_name<<" RECIPE INGERDENT NUMBER: "<<Rep_num<<endl;
				inFile >> rope;

				token=strtok(rope,"_");
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
					F1.B1.push_back(Recipe(Rep_name,G,Rep_num));
				else if(fi==1)
					F1.L1.push_back(Recipe(Rep_name,G,Rep_num));
				else if(fi==2)
					F1.D1.push_back(Recipe(Rep_name,G,Rep_num));
				else if(fi==3)
					F1.S1.push_back(Recipe(Rep_name,G,Rep_num));
				else if(fi==4)
					F1.E1.push_back(Recipe(Rep_name,G,Rep_num));
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

	cout<<N1.Foo.size()<<endl;
	g=0;
	while(g<N1.Foo.size())
	{
		cout<<N1.Foo[g].nationality<<endl;
		int jk=0;
	
		while(jk<N1.Foo[g].L1.size())
		{
			cout<<N1.Foo[g].L1[jk].recipe_name<<endl;
	
			int kp=0;
			while(kp<N1.Foo[g].L1[jk].ingr.size())
			{
	
				cout<<N1.Foo[g].L1[jk].ingr[kp].name<<" "<<N1.Foo[g].L1[jk].ingr[kp].quantity<<" "<<N1.Foo[g].L1[jk].ingr[kp].unit<<endl;
				kp++;
			}
			
			jk++;
		}
		g++;
	}
inFile.close();
}
