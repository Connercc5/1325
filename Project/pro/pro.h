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
#endif
