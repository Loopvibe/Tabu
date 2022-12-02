#include "TabuRulesDialog.h"
#include "ui_TabuRulesDialog.h"

TabuRulesDialog::TabuRulesDialog(QWidget *_parent) :
    QDialog(_parent),
    m_ui(new Ui::TabuRulesDialog)
{
    m_ui->setupUi(this);
}

TabuRulesDialog::~TabuRulesDialog()
{
    delete m_ui;
}
