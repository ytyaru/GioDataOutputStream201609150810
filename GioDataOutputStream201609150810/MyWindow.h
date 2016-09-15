#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <gtkmm.h>
#include <giomm.h>
class MyWindow : public Gtk::Window
{
public:
	explicit MyWindow(char* runPath);
	virtual ~MyWindow(void);
private:
	void on_activate();
	Gtk::Entry m_entry;
	Glib::RefPtr<Gio::File> m_file;
	Glib::RefPtr<Gio::FileOutputStream> m_foStream;
	Glib::RefPtr<Gio::DataOutputStream> m_doStream;
	char m_filePath[1024];
};
