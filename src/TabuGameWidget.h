#ifndef TABUGAMEWIDGET_H
#define TABUGAMEWIDGET_H

#include <QWidget>

#include <QMap>

namespace Ui {
class TabuGameWidget;
}

/*!
 * \brief Класс виджета игры.
 */
class TabuGameWidget : public QWidget
{
    Q_OBJECT

public:
    /*!
     * \brief Конструктор.
     * \param _teams - Команды.
     * \param _gameTime - время раунда.
     * \param _banWords - Словарь слов.
     * \param _parent - родительский виджет.
     */
    explicit TabuGameWidget(const QList<QString> &_teams,
                            int _gameTime,
                            const QMap<QString, QStringList> &_words,
                            QWidget *_parent = nullptr);

    /*!
     * \brief Дструктор.
     */
    ~TabuGameWidget();

    /*!
     * \brief Задает список команд. (Для начала игры)
     * \param _teams - список команд.
     */
    void setTeams(const QList<QString> &_teams);

private:
    /*!
     * \brief Подготавливает интерфейс к показу.
     */
    void prepeareUi();

    /*!
     * \brief Подготавливает сигнальнослотовые соединения.
     */
    void prepeareConections();

private:
    //! Словарь команд (ключ - название команды, значение - очки).
    QMap<QString, int> m_teams;
    //! Время раунда.
    int m_gameTime;
    //! Словарь слов(значение - игроване слово, ключ список запреток).
    QMap<QString, QStringList> m_words;

    //! Графический интерфейс.
    Ui::TabuGameWidget *m_ui;
};

#endif // TABUGAMEWIDGET_H
