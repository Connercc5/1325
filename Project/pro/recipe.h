#ifndef REP_S
#define REP_S
#include<iostream>
using namespace std;
#include<string>
#include <vector>
#include"ingredient.h"
#include <gtkmm.h>
#include <gtkmm/window.h>

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
		Recipe();

};
class ShoppingList:public Recipe
{
	public:
  	string filename;//past.txt
	string List;
	string Rep_names;
	ShoppingList(vector <Recipe> Chosen_reps);

/*past.txt is the file that holds the filenames of old shopping list*/

};



#endif
