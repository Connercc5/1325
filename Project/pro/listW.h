#ifndef LIST_W
#define LIST_W
#include <gtkmm.h>
#include<vector>
#include<string>
#include<iostream>
using namespace std;

//#include"nationalities.h"


class List_window:public Gtk::Window
{
        public:
        List_window(string Rep_names,string List);
        virtual~List_window();
        protected:
        Gtk::Label Rep_name_label;
        Gtk::Label List_label;
        Gtk::Box box;
        Gtk::Button ok;
        Gtk::ScrolledWindow scrolled_window;


        void ok_clicked();      
};
#endif
