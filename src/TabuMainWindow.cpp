#include "TabuMainWindow.h"
#include "ui_TabuMainWindow.h"

#include "TabuRulesDialog.h"

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

void TabuMainWindow::backToMenuSlot()
{
    m_ui->fButtons->setHidden(false);
}

void TabuMainWindow::onStartButtonClickedSlot()
{
    m_ui->prepeareGameWidget->setHidden(false);
    m_ui->fButtons->setHidden(true);
}

void TabuMainWindow::onExitButtonClickedSlot()
{
    QMainWindow::close();
}

void TabuMainWindow::onRulesButtonClickedSlot()
{
    TabuRulesDialog *rulesDialog = new TabuRulesDialog(this);
    rulesDialog->setWindowTitle("Rules");
    rulesDialog->exec();

    delete rulesDialog;
    rulesDialog = NULL;
}

void TabuMainWindow::prepeareUi()
{
    setWindowTitle("Tabu");
    m_ui->prepeareGameWidget->setHidden(true);
}

void TabuMainWindow::prepeareConections()
{
    connect(m_ui->pbExit, SIGNAL(clicked()),
            this, SLOT(onExitButtonClickedSlot()));

    connect(m_ui->pbRules, SIGNAL(clicked()),
            this, SLOT(onRulesButtonClickedSlot()));

    connect(m_ui->pbStart, SIGNAL(clicked()),
            this, SLOT(onStartButtonClickedSlot()));

    connect(m_ui->prepeareGameWidget, SIGNAL(menuSignal()),
            this, SLOT(backToMenuSlot()));


}

