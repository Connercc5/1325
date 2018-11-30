#include<algorithm>
#include<stdlib.h>
//#include"ingredient.h"
#include"recipe.h"
#include"mealplan.h"
using namespace std;
Recipe::Recipe(string recipe_name, vector <ingredient> ingr, int num_of_ingredients)
{
        this->recipe_name = recipe_name;
        this->ingr = ingr;
        this->num_of_ingredients = num_of_ingredients;
}

Recipe::Recipe(){}
//I AM USING THIS CONSTRUCTOR TO CREATE THE TEXT FOR THE LABELS ON THE SHOPPING LIST WINDOW
//ShoppingList::ShoppingList(vector <Recipe> Chosen_reps,Mealplan m)
ShoppingList::ShoppingList(vector <Recipe> Chosen_reps)
{
	vector<ingredient> tempList;
	ingredient I;
	int h=0;
	int k=0;
	int r=0;
	int u=0;
	int j=0;
	int g=0;
	vector<string>Rep;
	string rep;
	Mealplan m;
	while (h<Chosen_reps.size())
	{
		
		//m.dayList.push_back(day);
		
		
		k=0;
		u=0;
		if(h==0)
		{	Rep.push_back(Chosen_reps[h].recipe_name);
		
		}
		else
		{
			cout<<Rep.size()<<endl;
			while(u<Rep.size())
			{
			
			cout<<Rep[u]<<Chosen_reps[h].recipe_name<<endl;
			if(Rep[u].compare(Chosen_reps[h].recipe_name)==0)
			{


				k=10;

			}

			u++;
		}
		}
		if(k==0)
		{
				if(r>0)		
					Rep_names+=", ";
				Rep_names+=Chosen_reps[h].recipe_name;
			Rep.push_back(Chosen_reps[h].recipe_name);
			j++;
	
				r=9;	
		}
	h++;
	}
	//Trying to combine all of the ingredients from all of the recipes
	h=0;
	while(h<Chosen_reps.size())
	{
		int ingre=0;
		while (ingre <Chosen_reps[h].ingr.size())
		{
		//IM PRETTY SURE THAT THE BUG IN THE SHOPPING WINDOW INGREDIENT COMBINATION IS HERE	
			if(ingre==0&& h==0)
			{	
				I=Chosen_reps[h].ingr[ingre];
				tempList.push_back(I);
			}
			else
			{

				 g=0;
				 k=0;
				while(g<tempList.size())
				{
					cout<<tempList.size()<<endl;
					cout<<tempList[g].name<<"Chosen: "<<Chosen_reps[h].ingr[ingre].name<<endl;
					if(tempList[g].name.compare(Chosen_reps[h].ingr[ingre].name)==0)
					{
						
						cout<<"Hi"<<endl;
						tempList[g].quantity+=Chosen_reps[h].ingr[ingre].quantity;
						k=10;
						break;
					}
					g++;
				}
				if(k==0)
					{
					ingredient ID=Chosen_reps[h].ingr[ingre];
						tempList.push_back(ID);
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
		if(tempList[h].unit.compare("NONE")!=0)
		{
			List+=tempList[h].unit;
			List+=" ";
		}
		List+=tempList[h].name;
		List+="\n";
		h++;
	}	

}
