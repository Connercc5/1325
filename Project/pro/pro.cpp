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


}
Menuwindow::~Menuwindow()
{
	hide();
}
