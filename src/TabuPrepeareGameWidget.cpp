#include "TabuPrepeareGameWidget.h"
#include "ui_TabuPrepeareGameWidget.h"

#include <QFileDialog>
#include <QDebug>

TabuPrepeareGameWidget::TabuPrepeareGameWidget(QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::TabuPrepeareGameWidget)
{
    m_ui->setupUi(this);

    prepeareUi();
    prepeareConections();
}

TabuPrepeareGameWidget::~TabuPrepeareGameWidget()
{
    delete m_ui;
}

void TabuPrepeareGameWidget::onMenuButtonClickedSlot()
{
    setHidden(true);
    emit menuSignal();
}

void TabuPrepeareGameWidget::onChooseFileButtonClickedSlot()
{
    QFileDialog *gialog = new QFileDialog(this);
    if(gialog->exec()){

    }
}

void TabuPrepeareGameWidget::prepeareUi()
{

}

void TabuPrepeareGameWidget::prepeareConections()
{
    connect(m_ui->pbMenu, SIGNAL(clicked()),
            this, SLOT(onMenuButtonClickedSlot()));

    connect(m_ui->pbChooseFile, SIGNAL(clicked()),
            this, SLOT(onChooseFileButtonClickedSlot()));
}
