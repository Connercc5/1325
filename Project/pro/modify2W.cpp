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

//ASK USER TO CHOOSE NATIONALITY
Modify2_window::Modify2_window(File N1, int day, int time) :box(Gtk::ORIENTATION_VERTICAL),cancel("Cancel"), brea("Breakfast"), lunc("Lunch"),dinn("Dinner"),snac("Snack"),dess("Dessert") {
        set_size_request(400, 200);
        set_title("Create Shopping List");
        add(box);
        this->day = day;
        this->time = time;
        this->N1 =N1;
        this->error=0;
        y = 0;

        string nations = " ";
        while (y < N1.Nationality.size())
        {

                nations += N1.Nationality[y].nationality;
                nations += "\n";
                y++;
        }
        nationality_names_title_label.set_text("Nationalities:");
        nationality_names_label.set_text(nations);
        nations = " ";
        nationality_label.set_text("Enter a nationality: ");
        box.pack_start(nationality_names_title_label);
        box.pack_start(nationality_names_label);
        box.pack_start(nationality_label);
        label.set_text(m.daysList[day].name);

        nationality_entry.set_max_length(50);
        //nationality_entry.set_text("Enter nationality");
        nationality_entry.set_text("Mexican");//just using this to test program
        nationality_entry.select_region(0, nationality_entry.get_text_length());
        box.pack_start(nationality_entry);
        time_label.set_text(tim[time]+" Recipe");

        box.pack_start(label);

        box.pack_start(time_label);
        box.pack_start(brea);
        box.pack_start(lunc);
        box.pack_start(dinn);
        box.pack_start(snac);
        box.pack_start(dess);
        box.pack_start(cancel);
        box.pack_start(cancel);

         brea.signal_clicked().connect(sigc::bind<Glib::ustring>(sigc::mem_fun(*this, &Modify2_window::enter_clicked), "Breakfast"));
         lunc.signal_clicked().connect(sigc::bind<Glib::ustring>(sigc::mem_fun(*this, &Modify2_window::enter_clicked), "Lunch"));
         dinn.signal_clicked().connect(sigc::bind<Glib::ustring>(sigc::mem_fun(*this, &Modify2_window::enter_clicked), "Dinner"));
         snac.signal_clicked().connect(sigc::bind<Glib::ustring>(sigc::mem_fun(*this, &Modify2_window::enter_clicked), "Snack"));
         dess.signal_clicked().connect(sigc::bind<Glib::ustring>(sigc::mem_fun(*this, &Modify2_window::enter_clicked), "Dessert"));
         cancel.signal_clicked().connect(sigc::mem_fun(*this, &Modify2_window::cancel_clicked));

        show_all_children();

}

Modify2_window::~Modify2_window() 
{
        hide();
}
void Modify2_window::enter_clicked(string type)
{

        if (entry_ans.compare("DONE") != 0)
        {
                //Mealplan m; //SETTING UP WINDOW FOR MANUAL OPTION
                this->  entry_ans=nationality_entry.get_text();
                //string input = nationality_entry.get_text();
                hide();

                bool NationalityFound=false;
                int e=0;
                while(e<N1.Nationality.size())
                {
        
                        string Nation=N1.Nationality[e].nationality;
                        transform(Nation.begin(),Nation.end(),Nation.begin(),::toupper);//make text upper case so user can enter recipe name in any case
                        string entry= entry_ans;
                        transform(entry.begin(),entry.end(),entry.begin(),::toupper);//make text upper case so user can enter recipe name in any case
                        if(Nation.compare(entry)==0)
                        {
                        
                                NationalityFound=true;
                
                        }       
                        e++;    
                }
                
                
                if(NationalityFound==false)
                {
                        Gtk::MessageDialog dialog(*this,"Not Found",false,Gtk::MESSAGE_INFO);
                        dialog.set_secondary_text("You currently do not have this nationality");
                        dialog.run();
                        error=1;
                }       
      
                else    
                        Send2_ER(m,type);//this function will go to the EnterRecipe Window
                
                
                
                if((day==6)&&(time==4))//THIS IS FOR GETTING THE LABELS FOR THE FINAL SHOPPING LIST WINDOW
                //if((day==0)&&(time==4))//this is here because i am testing code
                {
                        ShoppingList s (Chosen_recipes);
                        Chosen_recipes.clear();
                        List_window f (s.Rep_names,s.List,0);             
                        Gtk::Main::run(f);


                }

        }
}

void Modify2_window::cancel_clicked()
{
        hide();
        entry_ans = "DONE";
}

void Modify2_window::Send2_ER(Mealplan m, string meal_type)
{
        //hide();
        int y = 0;
        int h = 0;
        EnterRecipe_window e(m, N1, entry_ans, meal_type);
        Gtk::Main::run(e);
        string rep_name = e.recipe;//rep_name now holds the input from the entry in EnterRecipe window

     string entryR,FileR;//use this for case error
        bool found=false;
        entryR=rep_name;
        transform(entryR.begin(),entryR.end(),entryR.begin(),::toupper);
        if(e.cancel_==true)//they click cancel in ER(EnterRecipe window)
        {
                error=1;
                return;
        }

        if (meal_type.compare("Breakfast") == 0)//if user clicked breakfast
                while (h < N1.Nationality[e.hold_index].breakfast.size())
                {

                        FileR=N1.Nationality[e.hold_index].breakfast[h].recipe_name;
                        transform(FileR.begin(),FileR.end(),FileR.begin(),::toupper);//make text upper case so user can enter recipe name in any case
                        if (FileR.compare(entryR) == 0)
                        {
                                this->temp_hold = N1.Nationality[e.hold_index].breakfast[h];
                                found=true;
                        }
                        h++;
                }
        else if (meal_type.compare("Lunch") == 0)//if user clicked lunch
                while (h < N1.Nationality[e.hold_index].lunch.size())
                {
                        FileR=N1.Nationality[e.hold_index].lunch[h].recipe_name;
                        transform(FileR.begin(),FileR.end(),FileR.begin(),::toupper);
                        if (FileR.compare(entryR) == 0)
                        {
                                this->temp_hold = N1.Nationality[e.hold_index].lunch[h];
                                found=true;

                  }
                        h++;
                }
        else if (meal_type.compare("Dinner") == 0)//if user clicked dinner
                while (h < N1.Nationality[e.hold_index].dinner.size())
                {
                        FileR=N1.Nationality[e.hold_index].dinner[h].recipe_name;
                        transform(FileR.begin(),FileR.end(),FileR.begin(),::toupper);
                        if (FileR.compare(entryR) == 0)
                        {
                                this->temp_hold = N1.Nationality[e.hold_index].dinner[h];
                                found=true;

                        }
                        h++;
                }
        else if (meal_type.compare("Snack") == 0)//if user clicked snack
        {
                while (h < N1.Nationality[e.hold_index].snack.size())
                {
                        FileR=N1.Nationality[e.hold_index].snack[h].recipe_name;
                        transform(FileR.begin(),FileR.end(),FileR.begin(),::toupper);
                        if (FileR.compare(entryR) == 0)
                        {
                                this->temp_hold = N1.Nationality[e.hold_index].snack[h];
                                found=true;

                        }
                        h++;
                }
        }
        else if (meal_type.compare("Dessert") == 0)
  {
                while (h < N1.Nationality[e.hold_index].dessert.size())
                {

                        FileR=N1.Nationality[e.hold_index].dessert[h].recipe_name;
                        transform(FileR.begin(),FileR.end(),FileR.begin(),::toupper);
                        if (FileR.compare(entryR) == 0)
                        {
                                this->temp_hold = N1.Nationality[e.hold_index].dessert[h];
                                found=true;

                        }
                        h++;
                }
        }
        if(found==false)//recipe not found
        {
                warning();
                return;
        }
        // there is a bug here it is only add on 1 recipe
        Chosen_recipes.push_back(temp_hold);
        }


void Modify2_window:: warning()
{
        Gtk::MessageDialog dialog(*this,"Not Found",false,Gtk::MESSAGE_INFO);
        dialog.set_secondary_text("Recipe was not found");
        dialog.run();
        error=1;

}

