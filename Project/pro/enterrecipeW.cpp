#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
#include<string.h>
#include<cstdlib>
#include<stdlib.h>
#include<gtkmm.h>
#include<memory>
#include"pro.h"



//ENTERRECIPE_WINDOW CONSTRUCTOR DECONSTRUCTOR AND FUNCTIONS USED IN OPTION 2 MAnual

EnterRecipe_window::~EnterRecipe_window()
{
        hide();
}

//used in option 2(create manual shopping list)

EnterRecipe_window::EnterRecipe_window(Mealplan m, File N1, string NationalityName, string meal_type) :box(Gtk::ORIENTATION_VERTICAL), enter("Enter"), cancel("Cancel", 3)
{
        set_title("Enter Recipe");
        this->cancel_=false;//signal to other Modify2_window that user canceled a recipe write
        set_size_request(300, 300);
        int e = 0;
        string Nation;
        transform(NationalityName.begin(),NationalityName.end(),NationalityName.begin(),::toupper);//allowing user to enter nationality in any case
        while (e < N1.Nationality.size())
        {
                Nation=N1.Nationality[e].nationality;
                transform(Nation.begin(),Nation.end(),Nation.begin(),::toupper);

                if(Nation.compare(NationalityName) == 0)
                {
                        hold_index = e;
                }
                e++;
        }
        e = 0;
        string recipe_names = " ";


//this will display the recipes in catagory that the user clicked
         if (meal_type.compare("Breakfast") == 0)
        {
                while (e < N1.Nationality[hold_index].breakfast.size())
                {
                        recipe_names = recipe_names + N1.Nationality[hold_index].breakfast[e].recipe_name;
                        recipe_names = recipe_names + "\n";
                        e++;


                }
        }
        else if (meal_type.compare("Lunch") == 0)
        {
                while (e < N1.Nationality[hold_index].lunch.size())
                {
                        recipe_names = recipe_names + N1.Nationality[hold_index].lunch[e].recipe_name;
                        recipe_names = recipe_names + "\n";
                        e++;
                }
        }
        else if (meal_type.compare("Dinner") == 0)
        {
                while (e < N1.Nationality[hold_index].dinner.size())
                {
                        recipe_names = recipe_names + N1.Nationality[hold_index].dinner[e].recipe_name;
                        recipe_names = recipe_names + "\n";
                        e++;
                }
        }
        else if (meal_type.compare("Snack") == 0)
        {
                while (e < N1.Nationality[hold_index].snack.size())
                {
                        recipe_names = recipe_names + N1.Nationality[hold_index].snack[e].recipe_name;
                        recipe_names = recipe_names + "\n";
                        e++;
                }
        }
        else if (meal_type.compare("Dessert") == 0)
        {
                while (e < N1.Nationality[hold_index].dessert.size())
                {
                   
                        recipe_names = recipe_names + N1.Nationality[hold_index].dessert[e].recipe_name;
                        recipe_names = recipe_names + "\n";
                        e++;
                }
        }
        add(box);


        recipe_name_label.set_text(recipe_names);
        entry.set_text("Enter Recipe Name:");
        entry.set_text("Flan");//this is just here so i can test the code
        box.pack_start(recipe_name_label);
        box.pack_start(entry);
        box.pack_start(enter);
        box.pack_start(cancel);
        show_all_children();
        enter.signal_clicked().connect(sigc::mem_fun(*this, &EnterRecipe_window::enter_clicked));
        cancel.signal_clicked().connect(sigc::mem_fun(*this, &EnterRecipe_window::cancel_clicked));
}
//used in option 2(create manual shopping list)
void EnterRecipe_window::enter_clicked()
{
        this->recipe = entry.get_text();
        hide();
}
//used in option 2(create manual shopping list)
void EnterRecipe_window::cancel_clicked()
{
        hide();
        this->  cancel_=true;

}
