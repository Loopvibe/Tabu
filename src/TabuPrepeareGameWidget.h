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
    void onStartButtonClickedSlot();

    /*!
     * \brief Обрабатывает нажатие на кнопку "Меню".
     */
    void onMenuButtonClickedSlot();

    /*!
     * \brief Обрабатывает нажатие на кнопку "Выбрать папку".
     */
    void onChooseFileButtonClickedSlot();

private:
    /*!
     * \brief Получает список команд.
     * \return Список команд.
     */
    QList<QString> teams();

    /*!
     * \brief Получает слова для игры.
     * \return Слова.
     */
    QMap<QString, QStringList> words();

    /*!
     * \brief Парсит данные в словарь.
     * \param _data - Данные.
     * \param _words[in, out] - Словарь.
     */
    void parsingData(const QString &_data,
                     QMap<QString, QStringList> &_words);

    /*!
     * \brief Подготавливает интерфейс к показу.
     */
    void prepeareUi();

    /*!
     * \brief Подготавливает сигнальнослотовые соединения.
     */
    void prepeareConections();


private:
    //! Путь к файлам тем игры.
    QString m_path;
    //! Графический интерфейс.
    Ui::TabuPrepeareGameWidget *m_ui;

};

#endif // TABUPREPEAREGAMEWIDGET_H
