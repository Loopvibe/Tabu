#ifndef TABUPREPEAREGAMEWIDGET_H
#define TABUPREPEAREGAMEWIDGET_H

#include <QWidget>

namespace Ui {
class TabuPrepeareGameWidget;
}

/*!
 * \brief Класс виджета с настройками предстоящей игры.
 */
class TabuPrepeareGameWidget : public QWidget
{
    Q_OBJECT

public:
    /*!
     * \brief Конструктор.
     * \param _parent - родительский виджет.
     */
    explicit TabuPrepeareGameWidget(QWidget *parent = nullptr);

    /*!
     * \brief Дструктор.
     */
    ~TabuPrepeareGameWidget();

signals:
    /*!
     * \brief Отправляет сигнал при нажакти кнопки меню.
     */
    void menuSignal();

private slots:
    /*!
     * \brief Обрабатывает нажатие на кнопку "Меню".
     */
    void onMenuButtonClickedSlot();

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
    Ui::TabuPrepeareGameWidget *m_ui;
};

#endif // TABUPREPEAREGAMEWIDGET_H
