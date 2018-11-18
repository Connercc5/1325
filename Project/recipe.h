#ifndef REP_S
#define REP_S
#include<iostream>
using namespace std;
#include<string>
#include <vector>
#include"ingredient.h"

class Recipe
{
	public:
		string recipe_name;
		vector<ingredient> ingr;
		int num_of_ingredients;
//		virtual void add_recipe();/*have not made functions in the .cpp file yet, so these functions are comment out until then.*/
//		virtual void modify_recipe();
//		virtual void delete_recipe(); 
		explicit Recipe(string recipe_name ,vector <ingredient> ingr,int num_of_ingredients); 


};
class Shoppinglist:public Recipe
{

        char*filename[20];//past.txt
/*past.txt is the file that holds the filenames of old shopping list*/

};



//I ended up not using these I just used a recipe vector instead
/*class Breakfest:public Recipe
{
//	using Recipe::Recipe(string recipe_name ,vector <ingredient> ingr,int num_of_ingredients); 
	using Recipe::Recipe; 
};
class Lunch:public Recipe
{

	//using Recipe::Recipe(char recipe_name ,vector <ingredient> ingr); 
	using Recipe::Recipe; 

};
class Dinner:public Recipe
{
	//using Recipe::Recipe(char recipe_name ,vector <ingredient> ingr); 
	using Recipe::Recipe; 


};
class Snack:public Recipe
{

	//using Recipe::Recipe(char recipe_name ,vector <ingredient> ingr); 
	using Recipe::Recipe; 
};
class Dessert:public Recipe
{

	using Recipe::Recipe; 

};
*/
/*
class Shoppinglist:public Recipe
{

	char*filename[20];//past.txt


};
*/
#endif
