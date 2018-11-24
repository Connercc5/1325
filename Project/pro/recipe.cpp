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

Recipe::Recipe(){}
ShoppingList::ShoppingList(vector <Recipe> Chosen_reps)
{
	vector<ingredient> tempList;
	ingredient I;
	int h=0;
	int k=0;
	while (h<Chosen_reps.size())
	{
		Rep_names+=Chosen_reps[h].recipe_name;
		Rep_names+=", ";

//Trying to combine of the ingredients
		int ingre=0;
		while (ingre <Chosen_reps[h].ingr.size())
		{
			if(ingre==0)
			{	
				I=Chosen_reps[h].ingr[ingre];
				tempList.push_back(I);
			}
			else
			{
				int g=0;
				while(g<tempList.size())
				{
					if(tempList[g].name.compare(Chosen_reps[h].ingr[ingre].name)==0)
					{
						tempList[g].quantity+=Chosen_reps[h].ingr[ingre].quantity;
				
						k=10;
					}
				
					if(k==0)
					{
						I=Chosen_reps[h].ingr[ingre];
						tempList.push_back(I);
					}	
					g++;
				}	
			}	
			ingre++;
		}
		h++;
	}
	h=0;
	while (h<tempList.size())
	{
		List+=tempList[h].quantity;
		List+=" ";
		List+=tempList[h].unit;
		List+=" ";
		List+=tempList[h].name;
		List+="\n";
		h++;
	}	

}
