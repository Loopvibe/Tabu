#include "TabuGameWidget.h"
#include "ui_TabuGameWidget.h"

TabuGameWidget::TabuGameWidget(const QList<QString> &_teams,
                               int _gameTime,
                               const QMap<QString, QStringList> &_words,
                               QWidget *_parent) :
    QWidget(_parent),
    m_gameTime(_gameTime),
    m_words(_words),
    m_ui(new Ui::TabuGameWidget)
{
    m_ui->setupUi(this);

    setTeams(_teams);

    prepeareUi();
    prepeareConections();
}

TabuGameWidget::~TabuGameWidget()
{
    delete m_ui;
}

void TabuGameWidget::prepeareUi()
{

}

void TabuGameWidget::prepeareConections()
{

}

void TabuGameWidget::setTeams(const QList<QString> &_teams)
{
    for(int i = 0; i < _teams.count(); i++){
        m_teams.insert(_teams.at(i), 0);
    }
}
