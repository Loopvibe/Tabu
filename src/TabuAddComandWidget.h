#ifndef TABUADDCOMANDWIDGET_H
#define TABUADDCOMANDWIDGET_H

#include <QWidget>

namespace Ui {
class TabuAddComandWidget;
}

/*!
 * \brief Класс виджета добавляющий команду.
 */
class TabuAddComandWidget : public QWidget
{
    Q_OBJECT

public:
    /*!
     * \brief Конструктор.
     * \param _parent - родительский виджет.
     */
    explicit TabuAddComandWidget(QWidget *_parent = nullptr);

    /*!
     * \brief Дструктор.
     */
    ~TabuAddComandWidget();

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
    Ui::TabuAddComandWidget *m_ui;
};

#endif // TABUADDCOMANDWIDGET_H
