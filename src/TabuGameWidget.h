#ifndef TABUGAMEWIDGET_H
#define TABUGAMEWIDGET_H

#include <QWidget>
#include <QMap>

class TabuWord;

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
     * \param _parent - родительский виджет.
     */
    explicit TabuGameWidget(QWidget *parent = nullptr);

    /*!
     * \brief Устанавливает данные.
     * \param _teams - Команды.
     * \param _gameTime - время раунда.
     * \param _words - Словарь слов.
     * \param _winScore - Очки для победы.
     */
    void setData(const QStringList &_teams,
                 int _gameTime,
                 const QList<TabuWord *> &_words,
                 int _winScore);

    /*!
     * \brief Дструктор.
     */
    ~TabuGameWidget();

signals:
    /*!
     * \brief Сигнал о выходе в меню.
     */
    void menuSignal();

private slots:
    /*!
     * \brief Обрабатывает нажатие на кнопку "Выход".
     */
    void onExitButtonClickedSlot();

    /*!
     * \brief Обрабатывает нажатие на кнопку "Продолжить".
     */
    void onGoButtonClickedSlot();

    /*!
     * \brief Обрабатывает нажатие на кнопку "Отгадано".
     */
    void onDoneButtonClickedSlot();

    /*!
     * \brief Обрабатывает нажатие на кнопку "ТАБУ".
     */
    void onTabuButtonClickedSlot();

    /*!
     * \brief Обрабатывает нажатие на кнопку "Пропуск".
     */
    void onSkipButtonClickedSlot();

private:
    /*!
     * \brief Подготавливает интерфейс к показу.
     */
    void prepeareUi();

    /*!
     * \brief Подготавливает сигнальнослотовые соединения.
     */
    void prepeareConections();

    /*!
     * \brief Задает список команд. (Для начала игры)
     * \param _teams - список команд.
     */
    void setTeams(const QStringList &_teams);

    /*!
     * \brief Задает словарь слов.
     * \param _words - словарь слов.
     */
    void setWords(const QList<TabuWord *> &_words);

    /*!
     * \brief Очищает данные виджета.
     */
    void clearData();

private:
    //! Словарь команд (ключ - название команды, значение - очки).
    QMap<QString, int> m_teams;
    //! Время раунда.
    int m_gameTime;
    //! Словарь слов(значение - игроване слово, ключ список запреток).
    QList<TabuWord*> m_words;
    //! Очки для победы.
    int m_winScore;

    //! Графический интерфейс.
    Ui::TabuGameWidget *m_ui;
};

#endif // TABUGAMEWIDGET_H
