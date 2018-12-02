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


//used in option 2(create shopping list)
List_window::~List_window(){hide();}
//used in option 2(create manual shopping list)
List_window::List_window(string Rep_names,string List):box(Gtk::ORIENTATION_VERTICAL),ok("Ok")
{
// Setting up message dialog
        set_title("List");
        Gtk::Entry entry=Gtk::Entry();
        set_size_request(400,500);
        Gtk::Label lab= Gtk::Label();
        entry.set_text("Ex: file.txt or List.txt... etc");
        lab.set_text("Enter a file name:");
        Gtk::MessageDialog dialog(*this,"Save List",false,Gtk::MESSAGE_INFO);
        dialog.set_secondary_text("All files are saved in savedList folder!\nWhat name would you like to save this list under?");
        dialog.get_content_area()->pack_start(lab);
        dialog.get_content_area()->pack_start(entry);
        box.pack_start(scrolled_window);
        scrolled_window.set_border_width(10);
        scrolled_window.set_policy(Gtk::POLICY_AUTOMATIC,Gtk::POLICY_ALWAYS);
        dialog.set_size_request(400,200);
        entry.show();
        lab.show();
        dialog.run();
//END: Message dialog set up
        string s= entry.get_text();
        //write the recipe names and list of ingredients to a file.
        string path = "./savedList/"+s;
        ofstream outfile (path);
        outfile <<Rep_names<<"\n"<<List<<endl;
        outfile.close();
        set_size_request(600,500);
        Rep_name_label.set_text(Rep_names);
        List_label.set_text(List);
        add(box);
        box.pack_start(Rep_name_label);
        box.pack_start(ok);
        box.pack_start(List_label);

        ok.signal_clicked().connect(sigc::mem_fun(*this, &List_window::ok_clicked));
        show_all_children();

}
List_window::List_window(string Rep_names,string List,int random):box(Gtk::ORIENTATION_VERTICAL),ok("Ok")
{
// Setting up message dialog
        set_title("Random List");
        Gtk::Entry entry=Gtk::Entry();
        set_size_request(400,500);
        Gtk::Label lab= Gtk::Label();
        entry.set_text("Ex: file.txt or List.txt... etc");
        lab.set_text("Enter a file name:");
        Gtk::MessageDialog dialog(*this,"Save Random List",false,Gtk::MESSAGE_INFO);
        dialog.set_secondary_text("All files are saved in savedList folder!\nWhat name would you like to save this list under?");
        dialog.get_content_area()->pack_start(lab);
        dialog.get_content_area()->pack_start(entry);
        box.pack_start(scrolled_window);
        scrolled_window.set_border_width(10);
        scrolled_window.set_policy(Gtk::POLICY_AUTOMATIC,Gtk::POLICY_ALWAYS);
        dialog.set_size_request(400,200);
        entry.show();
        lab.show();
        dialog.run();
//END: Message dialog set up
        string s= entry.get_text();
        //write the recipe names and list of ingredients to a file.
        string path = "./savedList/"+s;
        ofstream outfile (path);
        outfile <<Rep_names<<"\n"<<List<<endl;
        outfile.close();
        set_size_request(600,500);
        Rep_name_label.set_text(Rep_names);
        List_label.set_text(List);
        add(box);
        box.pack_start(Rep_name_label);
        box.pack_start(ok);
        box.pack_start(List_label);

        ok.signal_clicked().connect(sigc::mem_fun(*this, &List_window::ok_clicked));
        show_all_children();

}
//used in option 2(create manual shopping list)
void List_window::ok_clicked()
{
        hide();
        Menuwindow d;
        Gtk::Main::run(d);
}


