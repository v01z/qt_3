#include "webinfo.h"
#include <QRegExp>
#include <QProcess>
#include <QFile>
#include <QTextStream>
#include <QDebug>


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

        QFile htmlFile { "index.html" };
        if (htmlFile.exists())
            htmlFile.remove();

        //unix only!
        QProcess::execute("wget", QStringList() << "mail.ru");

        if (htmlFile.open(QFile::ReadOnly |
                QFile::ExistingOnly))
            {
            QTextStream stream(&htmlFile);


            QRegExp reg { m_hstCnv.weatherRegExpStr };
//            if (reg.indexIn(stream.readAll(), 0) == -1)
            if (!reg.exactMatch(stream.readAll()))
            {
               m_weather = "Weather info for " + m_hstCnv.hostName +
                " not found.";
               return;
            }

            m_weather = reg.cap(1);
            }
        else
            {
            m_weather = "Can't open index.html.";
            }
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


