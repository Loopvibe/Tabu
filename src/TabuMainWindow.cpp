#include "TabuMainWindow.h"
#include "ui_TabuMainWindow.h"

TabuMainWindow::TabuMainWindow(QWidget *_parent)
    : QMainWindow(_parent),
      m_ui(new Ui::TabuMainWindow)
{
    m_ui->setupUi(this);

    prepeareUi();
    prepeareConections();
}

TabuMainWindow::~TabuMainWindow()
{
    delete m_ui;
}

void TabuMainWindow::prepeareUi()
{
    setWindowTitle("Tabu");
}

void TabuMainWindow::prepeareConections()
{

}

