#ifndef MODIFY2_W
#define MODIFY2_W
#include <gtkmm.h>
#include<vector>
#include<string>
#include<iostream>
#include"mealplan.h"
#include"file.h"
#include"recipe.h"
using namespace std;

//used in option 2
class Modify2_window : public Gtk::Window {//Used for create shopping option
        static int y;
        static vector <Recipe> Chosen_recipes;
        public:
        string tim[5] = { "Breakfast","Lunch","Dinner","Snack","Dessert" };
        Modify2_window(File N1, int day, int time);
        virtual ~Modify2_window();
        string entry_ans;
        int day;
        int time;
        int error=0;
        File N1;
        string meal_type;
        string input;
        Recipe temp_hold;
        vector<Recipe> get_chosen();
        Mealplan m;
        protected:
        void enter_clicked(string type);
        void warning();//entered something that was not an option
        Gtk::Label label;
        Gtk::Label time_label;
        Gtk::Button cancel;
        Gtk::Button brea;
        Gtk::Button lunc;
        Gtk::Button dinn;
        Gtk::Button snac;
        Gtk::Button dess;
        void Send2_ER(Mealplan m,string meal_type);
        void cancel_clicked();
        Gtk::Label nationality_names_title_label;
        Gtk::Label nationality_names_label;
        Gtk::Label nationality_label;
        Gtk::Entry nationality_entry;
        Gtk::Button enter_button;
        Gtk::Button back_button;
        Gtk::Box box;
};
#endif
