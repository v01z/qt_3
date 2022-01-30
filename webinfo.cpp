#include "webinfo.h"
#include <QRegularExpression>
#include <QProcess>
//#include <QFile>
#include <QTextStream>
#include <QDebug> //debug


WebInfo::WebInfo(const QString &host)
{
    if (host == "Choose host")
    {
       m_weather = "Please, choose hostname (see combobox above)";
    }
    else {
        if (host == hostConvArr[0].hostName)
            m_hstCnv = hostConvArr[0];

        if (host == hostConvArr[1].hostName)
            m_hstCnv = hostConvArr[1];

        QFile htmlFile { "index.html" };
        removeHtmlFile(htmlFile);
    /*
        if (htmlFile.exists())
            htmlFile.remove();
*/

        //Реализация http-клиента, подозреваю, выходит за рамки текущего ДЗ,
        //поэтому для получения index.html решил задействовать утилиту wget
        QProcess::execute("wget", QStringList() << m_hstCnv.weatherURL);

        if (htmlFile.open(QFile::ReadOnly |
                QFile::ExistingOnly))
            {
            QTextStream stream(&htmlFile);
//            QString tempStr { htmlFile.readAll()}; //debug


            QRegularExpression reg { m_hstCnv.weatherRegExpStr };
            QRegularExpressionMatch match { reg.match(stream.readAll()) };
//            if (reg.indexIn(stream.readAll(), 0) == -1)
            //if (!reg.hasMatch(stream.readAll()))
            if (!match.hasMatch())
            {
               m_weather = "Weather info from " + m_hstCnv.hostName +
                " not found.";
             //   m_weather = tempStr; //debug
               return;
            }

            m_weather = match.captured(1);
            if (m_hstCnv.hostName == hostConvArr[0].hostName)
                {
                    //&deg; - мусор
                    m_weather.replace("&deg;","");

                }
            }
        else
            {
            m_weather = "Can't open index.html.";
            }
    }

}

const HostConvention WebInfo::getHstCnv() const
{
    return m_hstCnv;
}

const QString WebInfo::getWeather() const
{
    return m_weather;
}

const QString WebInfo::getCurrency() const
{
    return m_currency;
}

void WebInfo::setHstCnv(const HostConvention &ihstCnv)
{
    m_hstCnv = ihstCnv;
}

void WebInfo::setWeather(const QString &iweather)
{
    m_weather = iweather;
}

void WebInfo::setCurrency(const QString &icurrency)
{
    m_currency = icurrency;
}

void removeHtmlFile(QFile &file)
{
    if (file.exists())
          file.remove();
}


