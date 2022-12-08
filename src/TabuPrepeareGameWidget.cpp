#include "TabuPrepeareGameWidget.h"
#include "ui_TabuPrepeareGameWidget.h"

#include "TabuAddTeamWidget.h"

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

void TabuPrepeareGameWidget::onStartButtonClickedSlot()
{
    words();
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

QList<QString> TabuPrepeareGameWidget::teams()
{
    QList<QString> teams;

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

QMap<QString, QStringList> TabuPrepeareGameWidget::words()
{
    QMap<QString, QStringList> words;

    QFile file;
    for(int i = 0; i < m_ui->lvGamePacks->selectedItems().count(); i++){
        QString path(m_path + m_ui->lvGamePacks->selectedItems().at(i)->text());
        file.setFileName(path);
        if (!file.open(QIODevice::ReadOnly)){
            continue;
        }

        QString data;
        data = file.readAll();

        parsingData(data, words);
    }

    return words;
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
}

void TabuPrepeareGameWidget::prepeareConections()
{
    connect(m_ui->pbStart, SIGNAL(clicked()),
            this, SLOT(onStartButtonClickedSlot()));

    connect(m_ui->pbMenu, SIGNAL(clicked()),
            this, SLOT(onMenuButtonClickedSlot()));

    connect(m_ui->pbChooseFile, SIGNAL(clicked()),
            this, SLOT(onChooseFileButtonClickedSlot()));
}
