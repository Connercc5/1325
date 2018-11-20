#ifndef MEAL_P
#define MEAL_P
#include <gtkmm.h>
#include<vector>
#include<string>
#include<iostream>
using namespace std;

class Menuwindow: public Gtk::Window
{

public:
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
private:

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

