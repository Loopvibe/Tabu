#ifndef TABUMAINWINDOW_H
#define TABUMAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class TabuMainWindow; }
QT_END_NAMESPACE

/*!
 * \brief Класс главного окна.
 */
class TabuMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /*!
     * \brief Конструктор.
     * \param _parent - родитеский виджет.
     */
    TabuMainWindow(QWidget *_parent = nullptr);

    /*!
     * \brief Дструктор.
     */
    ~TabuMainWindow();

private slots:
    /*!
     * \brief Обрабатывает возвращения пользователя в меню.
     */
    void backToMenuSlot();

    /*!
     * \brief Обрабатывает нажатие на кнопку "Старт".
     */
    void onStartButtonClickedSlot();

    /*!
     * \brief Обрабатывает нажатие на кнопку "Выход".
     */
    void onExitButtonClickedSlot();

    /*!
     * \brief Обрабатывает нажатие на кнопку "Правила".
     */
    void onRulesButtonClickedSlot();

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
    Ui::TabuMainWindow *m_ui;
};
#endif // TABUMAINWINDOW_H
