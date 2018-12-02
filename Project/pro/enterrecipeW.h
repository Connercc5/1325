#ifndef ENTERRECIPE_W
#define ENTERRECIPE_W
#include <gtkmm.h>
#include<vector>
#include<string>
#include<iostream>
#include"mealplan.h"
#include"file.h"
using namespace std;



//used in option 2
class EnterRecipe_window :public Gtk::Window//ER
{
public:
        EnterRecipe_window(Mealplan m, File N1, string NationalityName,string meal_type);
        virtual ~EnterRecipe_window();
        string recipe;
        int hold_index;
        bool cancel_=false;
protected:
        Gtk::Label recipe_name_label;
        Gtk::Entry entry;
        Gtk::Button enter;
        Gtk::Button cancel;
        Gtk::Box box;
        void cancel_clicked();
        void enter_clicked();


};
#endif
