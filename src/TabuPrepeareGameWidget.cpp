#include "TabuPrepeareGameWidget.h"
#include "ui_TabuPrepeareGameWidget.h"

#include "TabuAddTeamWidget.h"
#include "TabuWord.h"

#include <QFileDialog>
#include <QModelIndex>
#include <QMessageBox>


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

QStringList TabuPrepeareGameWidget::teams()
{
    QStringList teams;

    for (int i = 0; i < m_ui->fComands->children().count(); i++){
        if(m_ui->fComands->children().at(i)->isWidgetType()){
            QString team = static_cast<TabuAddTeamWidget*>
                    (m_ui->fComands->children().at(i))->team();

            if (!team.isEmpty()){
                teams.append(team);
            }
        }
    }

    return teams;
}

QList<TabuWord *> TabuPrepeareGameWidget::words()
{
    QList<TabuWord *> words;

    QFile file;
    for(int i = 0; i < m_ui->lvGamePacks->selectedItems().count(); i++){
        QString path(m_path + m_ui->lvGamePacks->selectedItems().at(i)->text());
        file.setFileName(path);
        if (!file.open(QIODevice::ReadOnly)){
            continue;
        }

        QString data;
        data = file.readAll();

        //parsingData(data, words);

        QStringList stringWords = data.split(QString("\r\n"));

        for(int i = 0; i < stringWords.count(); i++){
            QStringList stringWord = stringWords.at(i).split(QString(":"));

            TabuWord * word = new TabuWord(stringWord.at(0));
            word->setBanWords(stringWords.at(1).split(QString(",")));

            words.append(word);
        }
    }

    return words;
}

int TabuPrepeareGameWidget::roundTime()
{
    return m_ui->sbTimer->value();
}

int TabuPrepeareGameWidget::winScore()
{
    return m_ui->sbWinScore->value();
}

void TabuPrepeareGameWidget::onStartButtonClickedSlot()
{    
    if(teams().count() <= 1){
        QMessageBox *message = new QMessageBox(this);
        message->setText(QString("Для игры требуется 2 и более команды"));
        message->exec();
        return;
    }

    if(m_ui->lvGamePacks->selectedItems().count() == 0){
        QMessageBox *message = new QMessageBox(this);
        message->setText(QString("Выберите темы для игры"));
        message->exec();
        return;
    }
    emit startGameSignal();

    setHidden(true);
}

void TabuPrepeareGameWidget::onMenuButtonClickedSlot()
{
    setHidden(true);
    emit menuSignal();
}

void TabuPrepeareGameWidget::onChooseFileButtonClickedSlot()
{
    QFileDialog *dialog = new QFileDialog(this);
    dialog->setFileMode(QFileDialog::Directory);

    QDir dir;
    QStringList gamePacks;

    if(dialog->exec()){
        m_path = dialog->selectedFiles().at(0) + "/";
        dir.setPath(m_path);
        gamePacks = dir.entryList(QDir::Files);
        m_ui->lvGamePacks->clear();
    }

    for(int i = 0; i < gamePacks.count(); i++){
        if(gamePacks.at(i).contains(QString("txt"))){
            m_ui->lvGamePacks->addItem(gamePacks.at(i));
        }
    }
}

void TabuPrepeareGameWidget::parsingData(const QString &_data,
                                         QMap<QString, QStringList> &_words)
{
    QStringList words = _data.split(QString("\r\n"));

    for(int i = 0; i < words.count(); i++){
        QStringList word = words.at(i).split(QString(":"));
        _words.insert(word.at(0), word.at(1).split(QString(",")));
    }
}

void TabuPrepeareGameWidget::prepeareUi()
{
    m_ui->lvGamePacks->setSelectionMode(QAbstractItemView::MultiSelection);
    m_ui->sbTimer->setMinimum(30);
    m_ui->sbTimer->setMaximum(120);
    m_ui->sbTimer->setValue(60);
    m_ui->sbWinScore->setMinimum(15);
}

void TabuPrepeareGameWidget::prepeareConections()
{
    connect(m_ui->pbStart, SIGNAL(clicked()),
            SLOT(onStartButtonClickedSlot()));

    connect(m_ui->pbMenu, SIGNAL(clicked()),
            SLOT(onMenuButtonClickedSlot()));

    connect(m_ui->pbChooseFile, SIGNAL(clicked()),
            SLOT(onChooseFileButtonClickedSlot()));
}
