#include "TabuAddTeamWidget.h"
#include "ui_TabuAddTeamWidget.h"

TabuAddTeamWidget::TabuAddTeamWidget(QWidget *_parent) :
    QWidget(_parent),
    m_ui(new Ui::TabuAddTeamWidget)
{
    m_ui->setupUi(this);

    prepeareUi();
    prepeareConections();
}

TabuAddTeamWidget::~TabuAddTeamWidget()
{
    delete m_ui;
}

QString TabuAddTeamWidget::team()
{
    return m_ui->leComand->text();
}

void TabuAddTeamWidget::onAddButtonClickedSlot()
{
    if(parentWidget()->children().count() < 7){
        TabuAddTeamWidget *newTeam = new TabuAddTeamWidget(parentWidget());
        newTeam->parentWidget()->layout()->addWidget(newTeam);
        newTeam->show();
    }
}

void TabuAddTeamWidget::onDeleteButtonClickedSlot()
{
    if(parentWidget()->children().count() > 2){
        parentWidget()->layout()->removeWidget(this);
        delete this;
    }
}

void TabuAddTeamWidget::prepeareUi()
{

}

void TabuAddTeamWidget::prepeareConections()
{
    connect(m_ui->pbDelete, SIGNAL(clicked()),
            this, SLOT(onDeleteButtonClickedSlot()));

    connect(m_ui->pbAdd, SIGNAL(clicked()),
            this, SLOT(onAddButtonClickedSlot()));
}
