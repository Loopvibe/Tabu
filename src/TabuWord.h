#ifndef TABUWORD_H
#define TABUWORD_H

#include <QStringList>

/*!
 * \brief Класс слова.
 */
class TabuWord
{
public:
    /*!
     * \brief Конструктор.
     * \param _word - Загаданное слово.
     */
    TabuWord(const QString &_word);

    /*!
     * \brief Получает загаданное слово.
     * \return
     */
    QString word() const;

    /*!
     * \brief Добавляет ТАБУ слово.
     * \param _word - ТАБУ слово.
     */
    void appendBanWord(const QString _word);

    /*!
     * \brief Получает список ТАБУ слов.
     * \return Список ТАБУ слов.
     */
    QStringList banWords() const;

    /*!
     * \brief Устанавливает список ТАБУ слов.
     * \param _words - список ТАБУ слов.
     */
    void setBanWords(const QStringList _words);

private:
    //! Загаданное слово.
    QString m_word;
    //! ТАБУ слова.
    QStringList m_banWords;
};

#endif // TABUWORD_H
