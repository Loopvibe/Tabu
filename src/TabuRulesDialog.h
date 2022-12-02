#ifndef TABURULESDIALOG_H
#define TABURULESDIALOG_H

#include <QDialog>

namespace Ui {
class TabuRulesDialog;
}

/*!
 * \brief Класс окна с правилами игры.
 */
class TabuRulesDialog : public QDialog
{
    Q_OBJECT

public:
    /*!
     * \brief Конструктор.
     * \param _parent - родительский виджет.
     */
    explicit TabuRulesDialog(QWidget *_parent = nullptr);

    /*!
     * \brief Дструктор.
     */
    ~TabuRulesDialog();

private:
    //! Графический интерфейс.
    Ui::TabuRulesDialog *m_ui;
};

#endif // TABURULESDIALOG_H
