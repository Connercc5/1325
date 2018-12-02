#ifndef REP_S
#define REP_S
#include<iostream>
using namespace std;
#include<string>
#include <vector>
#include"ingredient.h"
#include <gtkmm.h>
#include <gtkmm/window.h>
//#include"mealplan.h"

class Recipe
{
	public:
		string recipe_name;
		vector<ingredient> ingr;
		int num_of_ingredients;
		explicit Recipe(string recipe_name ,vector <ingredient> ingr,int num_of_ingredients);
		Recipe();

};
class ShoppingList:public Recipe
{
	public:
	string List;
	string Rep_names;
	ShoppingList(vector <Recipe> Chosen_reps);
};



#endif
