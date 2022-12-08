#ifndef TABUADDTEAMWIDGET_H
#define TABUADDTEAMWIDGET_H

#include <QWidget>

namespace Ui {
class TabuAddTeamWidget;
}

/*!
 * \brief Класс виджета добавляющий команду.
 */
class TabuAddTeamWidget : public QWidget
{
    Q_OBJECT

public:
    /*!
     * \brief Конструктор.
     * \param _parent - родительский виджет.
     */
    explicit TabuAddTeamWidget(QWidget *_parent = nullptr);

    /*!
     * \brief Дструктор.
     */
    ~TabuAddTeamWidget();

    /*!
     * \brief Получает название команды.
     * \return Название команды
     */
    QString team();

private slots:
    /*!
     * \brief Обрабатывает нажатие на кнопку "+".
     */
    void onAddButtonClickedSlot();

    /*!
     * \brief Обрабатывает нажатие на кнопку "-".
     */
    void onDeleteButtonClickedSlot();

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
    //! Графический интерфейс.
    Ui::TabuAddTeamWidget *m_ui;
};

#endif // TABUADDTEAMWIDGET_H
