#include "TabuWord.h"

TabuWord::TabuWord(const QString &_word) :
    m_word(_word),
    m_banWords(QStringList())
{
}

QString TabuWord::word() const
{
    return m_word;
}

void TabuWord::appendBanWord(const QString _word)
{
    m_banWords.append(_word);
}

QStringList TabuWord::banWords() const
{
    return m_banWords;
}

void TabuWord::setBanWords(const QStringList _words)
{
    m_banWords.clear();
    m_banWords = _words;
}
