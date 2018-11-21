#include<algorithm>
#include<stdlib.h>
//#include"ingredient.h"
#include"recipe.h"
using namespace std;
Recipe::Recipe(string recipe_name, vector <ingredient> ingr, int num_of_ingredients)
{
        this->recipe_name = recipe_name;
        this->ingr = ingr;
        this->num_of_ingredients = num_of_ingredients;
}

