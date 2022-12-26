#include "TabuGameWidget.h"
#include "ui_TabuGameWidget.h"

TabuGameWidget::TabuGameWidget(QWidget *_parent) :
    QWidget(_parent),
    m_teams(QMap<QString, int>()),
    m_gameTime(0),
    m_words(QList<TabuWord*>()),
    m_winScore(0),
    m_ui(new Ui::TabuGameWidget)
{
    m_ui->setupUi(this);

    prepeareUi();
    prepeareConections();
}

void TabuGameWidget::setData(const QStringList &_teams,
                             int _gameTime,
                             const QList<TabuWord *> &_words,
                             int _winScore)
{
    clearData();

    m_gameTime = _gameTime;
    m_winScore = _winScore;
    setTeams(_teams);
    setWords(_words);

    m_ui->twTeams->setColumnCount(2);
    m_ui->twTeams->setRowCount(m_teams.count());
    m_ui->twTeams->verticalHeader()->setHidden(true);
    m_ui->twTeams->setHorizontalHeaderLabels(QStringList()
                                             << "Название команды"
                                             << "Очки");
    m_ui->twTeams->setColumnWidth(0, 300);

    for(int i = 0; i < m_teams.count(); i++){
        QTableWidgetItem *item =
                new QTableWidgetItem(m_teams.keys().at(i));
        m_ui->twTeams->setItem(i, 0, item);

        QTableWidgetItem *itemScore =
                new QTableWidgetItem(QString::number(m_teams.values().at(i)));
        m_ui->twTeams->setItem(i, 1, itemScore);
    }
    m_ui->twTeams->setCurrentIndex(m_ui->twTeams->model()->index(0,0));
}

TabuGameWidget::~TabuGameWidget()
{
    qDeleteAll(m_words);

    delete m_ui;
}

void TabuGameWidget::onExitButtonClickedSlot()
{
    clearData();
    setHidden(true);

    emit menuSignal();
}

void TabuGameWidget::onGoButtonClickedSlot()
{

}

void TabuGameWidget::onDoneButtonClickedSlot()
{

}

void TabuGameWidget::onTabuButtonClickedSlot()
{

}

void TabuGameWidget::onSkipButtonClickedSlot()
{

}

void TabuGameWidget::prepeareUi()
{
    m_ui->frmGame->setHidden(true);
}

void TabuGameWidget::prepeareConections()
{
    connect(m_ui->pbExit, SIGNAL(clicked()),
            SLOT(onExitButtonClickedSlot()));
    connect(m_ui->pbGo, SIGNAL(clicked()),
            SLOT(onGoButtonClickedSlot()));
    connect(m_ui->pbDone, SIGNAL(clicked()),
            SLOT(onDoneButtonClickedSlot()));
    connect(m_ui->pbTabu, SIGNAL(clicked()),
            SLOT(onTabuButtonClickedSlot()));
    connect(m_ui->pbSkip, SIGNAL(clicked()),
            SLOT(onSkipButtonClickedSlot()));
}

void TabuGameWidget::setTeams(const QStringList &_teams)
{
    for(int i = 0; i < _teams.count(); i++){
        m_teams.insert(_teams.at(i), 0);
    }
}

void TabuGameWidget::setWords(const QList<TabuWord*> &_words)
{
    m_words = _words;
}

void TabuGameWidget::clearData()
{
    m_gameTime = 0;
    m_winScore = 0;

    m_teams.clear();
    m_ui->twTeams->clear();

    qDeleteAll(m_words);

}
