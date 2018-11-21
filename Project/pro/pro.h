#ifndef MEAL_P
#define MEAL_P
#include <gtkmm.h>
#include<vector>
#include<string>
#include<iostream>
using namespace std;
//SLOWLY INTEGRATING IN ALL OF OUR CLASS
#include"file.h"
#include"nationalities.h"
#include"recipe.h"
#include"ingredient.h"
#include"days.h"
#include"mealplan.h"



class Menuwindow: public Gtk::Window
{ //START:FUNCTIONS THAT ARE USED FOR FILE INTERACTIONS

        static void File_write(File N1);
        static void get_blank(char*token);
        static string get_underscore(string s);
        static void File_read(File N1);
        static File N1;
 //END:FUNCTIONS THAT ARE USED FOR FILE INTERACTIONS*/

public:
   // static  File N1;
    Menuwindow();
    virtual ~Menuwindow();
protected:
    void case1_clicked();
    void case2_clicked();
    void case3_clicked();
    void case4_clicked();


    Gtk::Button case1;
    Gtk::Button case2;
    Gtk::Button case3;
    Gtk::Button case4;
    Gtk::Box box;
//private:
 //START:FUNCTIONS THAT ARE USED FOR FILE INTERACTIONS
/*        
        static void File_write(File N1);
        static void get_blank(char*token);
        static string get_underscore(string s);
        static void File_read(File N1);
        static File file;
 *///END:FUNCTIONS THAT ARE USED FOR FILE INTERACTIONS*/


};


class Modify_window: public Gtk::Window{
public:
    Modify_window ();
    virtual ~Modify_window();


protected:

    void Nationality ();
    void back_button_clicked();

    Gtk::Label nationality_label;
    Gtk::Entry nationality_entry;
    Gtk::Button nationality_button;
    Gtk::Button back_button;
    Gtk::Box box;

};


class Recipe_Info {
public:
    string food_type, recipe_name, recipe;
    Recipe_Info (string food_type_p, string recipe_name_p, string recipe_p);
};

class Database {

};
#endif

