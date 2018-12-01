#include<algorithm>
#include<stdlib.h>
//#include"ingredient.h"
#include"recipe.h"
#include"mealplan.h"
#include"days.h"
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
	Recipe b;
	Recipe l;
	Recipe d;
	Recipe s;
	Recipe e;
	vector<string>Rep;
	string rep;
	Mealplan m;

		
	int x=0;
	u=0;	

	while (h<=Chosen_reps.size())
	{
		if(k==0)
		{
			if(x==0)
			{
				b=Chosen_reps[h];
			}	
			else if(x==1)
				l=Chosen_reps[h];
			else if(x==2)
				d=Chosen_reps[h];
			else if(x==3)
				s=Chosen_reps[h];
			else if(x==4)
				e=Chosen_reps[h];
			else if(x==5)
			{	
				m.daysList[u].breakfast=b;
				m.daysList[u].lunch=l;
				m.daysList[u].dinner=d;
				m.daysList[u].snack=s;
				m.daysList[u].dessert=e;
				cout<<m.daysList.size()<<endl;
				x=-1;
				if(h==Chosen_reps.size())
					k=10;

				u++;	
				h--;
			}
			x++;
		}

		h++;
	}	
		k=0;

u=0;
Rep_names="";
	while(u<7)
	//while(u<1)//using this to test code
	{
		Rep_names+=m.daysList[u].name;
		Rep_names+=": ";
		Rep_names+=m.daysList[u].breakfast.recipe_name;
		Rep_names+=", ";
		Rep_names+=m.daysList[u].lunch.recipe_name;
		Rep_names+=", ";
		Rep_names+=m.daysList[u].dinner.recipe_name;
		Rep_names+=", ";
		Rep_names+=m.daysList[u].snack.recipe_name;
		Rep_names+=", ";
		Rep_names+=m.daysList[u].dessert.recipe_name;
		Rep_names+="\n";
		u++;
	}
u=0;
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
					if(tempList[g].name.compare(Chosen_reps[h].ingr[ingre].name)==0)
					{
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
