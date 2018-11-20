#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
#include<string.h>
#include<cstdlib>
#include<stdlib.h>
#include <gtkmm.h>
#include<memory>
#include"pro.h"
using namespace std;





Menuwindow::Menuwindow():box(Gtk::ORIENTATION_VERTICAL)
,case1("Modify Recipes"),case2("Create Meal Plan",2),case3("Choose Old Shopping list"),case4("Exit",3)
{
    set_size_request(400,200);
    set_title("Preppy Meal");
    add(box);
    Gtk::Label label=Gtk::Label();
    label.set_text("Pick a option");
    label.set_padding(10,10);
    box.pack_start(label);
    box.pack_start(case1);
    box.pack_start(case2);
    box.pack_start(case3);
    box.pack_start(case4);
    show_all_children();
    
    
    case1.signal_clicked().connect(sigc::mem_fun(*this, &Menuwindow::case1_clicked));
    box.pack_start(case1);
    
}
Menuwindow::~Menuwindow()
{
}


void Menuwindow::case1_clicked() {
    hide ();
    Modify_window w;
    Gtk::Main::run(w);
}

Modify_window::Modify_window():box(Gtk::ORIENTATION_VERTICAL), nationality_button("Enter") {
    set_size_request(400,200);
    set_title("Modify a recipe");
    add(box);
    
    nationality_label.set_text ("Enter a nationality: ");
    box.pack_start (nationality_label);
    
    nationality_entry.set_max_length (50);
    nationality_entry.set_text("Enter nationality");
    nationality_entry.select_region(0, nationality_entry.get_text_length());
    box.pack_start(nationality_entry);
    
    nationality_button.signal_clicked().connect(sigc::mem_fun(*this, &Modify_window::Nationality));
    box.pack_start(nationality_button);
    
     show_all_children();
    
}


void Modify_window::Nationality() {}
Modify_window::~Modify_window(){}
