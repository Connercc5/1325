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
//I AM USING THIS CONSTRUCTOR TO CREATE THE TEXT FOR THE LABELS ON THE SHOPPING LIST WINDOW
ShoppingList::ShoppingList(vector <Recipe> Chosen_reps)
{
	vector<ingredient> tempList;
	ingredient I;
	int h=0;
	int k=0;
	while (h<Chosen_reps.size())
	{
		if(Rep_names.compare(Chosen_reps[h].recipe_name)!=0)
		{
			if(h>0)
				Rep_names+=", ";
			Rep_names+=Chosen_reps[h].recipe_name;
		}

//Trying to combine of the ingredients
		int ingre=0;
		tempList.clear();
		while (ingre <Chosen_reps[h].ingr.size())
		{
			cout<<Chosen_reps[h].ingr.size()<<endl;
		//IM PRETTY SURE THAT THE BUG IN THE SHOPPING WINDOW INGREDIENT COMBINATION IS HERE	
			if(ingre==0)
			{	
				I=Chosen_reps[h].ingr[ingre];
				tempList.push_back(I);
				cout<<tempList.size()<<endl;
			}
			else
			{

				int g=0;
				while(g<tempList.size())
				{
					cout<<tempList[g].name<<endl;
					if(tempList[g].name.compare(Chosen_reps[h].ingr[ingre].name)==0)
					{
						tempList[g].quantity+=Chosen_reps[h].ingr[ingre].quantity;
				
						
						
						//k=10;
					}
					else
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
		List+=to_string(tempList[h].quantity);
		List+=" ";
		List+=tempList[h].unit;
		List+=" ";
		List+=tempList[h].name;
		List+="\n";
		h++;
	}	

}
