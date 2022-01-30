#include "webinfo.h"
#include <QRegExp>


WebInfo::WebInfo(const QString &host)
{
    if (host == "Choose host")
    {
       m_weather = "Please, choose hostname (see comobobox above)";
    }
    else {
        if (host == "mail.ru")
        m_hstCnv = hostConvArr[0];
        if (host == "yandex.ru")
        m_hstCnv = hostConvArr[1];

        QRegExp reg { m_hstCnv.weatherRegExpStr };
        if (reg.indexIn(m_hstCnv.weatherRegExpStr) == -1)
        {
           m_weather = "Wheather info for " + m_hstCnv.hostName +
            " not found.";
           return;
        }

        m_weather = reg.cap();
    }

}

const QString WebInfo::getWeather() const
{
    return m_weather;
}

const QString WebInfo::getCurrency() const
{
    return m_currency;
}


