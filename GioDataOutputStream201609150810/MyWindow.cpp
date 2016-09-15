#include <glibmm.h>
#include "MyWindow.h"
#include <stdio.h>
#include <stdlib.h>
MyWindow::MyWindow(char* runPath)
{
	memset(m_filePath, '\0', 1024);
	strcpy_s(m_filePath, 1024, runPath);
	strcat_s(m_filePath, 1024, "\\entry.log");
	try {
		m_file = Gio::File::create_for_path(m_filePath);
		//m_foStream = m_file->create_file(); // 新規作成
		//m_foStream = m_file->replace(); // 上書き
		m_foStream = m_file->append_to(); // 追記
		m_doStream = Gio::DataOutputStream::create(m_foStream);
	} catch(...) {
		exit(EXIT_FAILURE);
	}
	m_entry.set_text(Glib::locale_to_utf8("Gtk::Entry テキストボックス"));
	m_entry.signal_activate().connect(sigc::mem_fun( *this, &MyWindow::on_activate ) );
	add( m_entry );
	show_all_children();
}
MyWindow::~MyWindow(void)
{
	m_doStream->close();
	m_foStream->close();
}
void MyWindow::on_activate()
{
	if (NULL == m_doStream) {
		Gtk::MessageDialog( m_entry.get_text() ).run();
	} else {
		m_doStream->put_string(m_entry.get_text());
		m_doStream->put_string("\n");
	}
}