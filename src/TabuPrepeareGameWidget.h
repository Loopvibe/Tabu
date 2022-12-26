#ifndef TABUPREPEAREGAMEWIDGET_H
#define TABUPREPEAREGAMEWIDGET_H

#include <QWidget>

class TabuWord;

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

    /*!
     * \brief Получает список команд.
     * \return Список команд.
     */
    QStringList teams();

    /*!
     * \brief Получает слова для игры.
     * \return Слова.
     */
    QList<TabuWord*> words();

    /*!
     * \brief Получает время раунда.
     * \return Время раунда.
     */
    int roundTime();

    /*!
     * \brief Получает количество очков для победы.
     * \return Кол-во очков для победы.
     */
    int winScore();

signals:
    /*!
     * \brief Сигнал при нажакти кнопки меню.
     */
    void menuSignal();

    /*!
     * \brief Сигнал для старта игры.
     */
    void startGameSignal();

private slots:
    /*!
     * \brief Обрабатывает нажатие на кнопку "Старт".
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
