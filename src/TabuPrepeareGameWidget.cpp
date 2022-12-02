#include "TabuPrepeareGameWidget.h"
#include "ui_TabuPrepeareGameWidget.h"

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

void TabuPrepeareGameWidget::prepeareUi()
{

}

void TabuPrepeareGameWidget::prepeareConections()
{
    connect(m_ui->pbMenu, SIGNAL(clicked()),
            this, SLOT(onMenuButtonClickedSlot()));
}
