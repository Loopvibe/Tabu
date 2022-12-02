#include "TabuAddComandWidget.h"
#include "ui_TabuAddComandWidget.h"

TabuAddComandWidget::TabuAddComandWidget(QWidget *_parent) :
    QWidget(_parent),
    m_ui(new Ui::TabuAddComandWidget)
{
    m_ui->setupUi(this);

    prepeareUi();
    prepeareConections();
}

TabuAddComandWidget::~TabuAddComandWidget()
{
    delete m_ui;
}

void TabuAddComandWidget::onAddButtonClickedSlot()
{
    if(parentWidget()->children().count() < 7){
        TabuAddComandWidget *newComand = new TabuAddComandWidget(parentWidget());
        newComand->parentWidget()->layout()->addWidget(newComand);
        newComand->show();
    }
}

void TabuAddComandWidget::onDeleteButtonClickedSlot()
{
    if(parentWidget()->children().count() > 2){
        parentWidget()->layout()->removeWidget(this);
        delete this;
    }
}

void TabuAddComandWidget::prepeareUi()
{

}

void TabuAddComandWidget::prepeareConections()
{
    connect(m_ui->pbDelete, SIGNAL(clicked()),
            this, SLOT(onDeleteButtonClickedSlot()));

    connect(m_ui->pbAdd, SIGNAL(clicked()),
            this, SLOT(onAddButtonClickedSlot()));
}
