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
       return;
    }

    else if (host == hostConvArr[0].hostName)
        m_hstCnv = hostConvArr[0];

    else if (host == hostConvArr[1].hostName)
        m_hstCnv = hostConvArr[1];

    constructorHelper(*this);


}

const QString WebInfo::getWeather() const
{
    return m_weather;
}

const QString WebInfo::getCurrency() const
{
    return m_currency;
}

void removeHtmlFile(QFile &file)
{
    if (file.exists())
          file.remove();
}

void constructorHelper(WebInfo &webInfo)
{
        QFile htmlFile { "index.html" };
        removeHtmlFile(htmlFile);
    /*
        if (htmlFile.exists())
            htmlFile.remove();
*/

        //Реализация http-клиента, подозреваю, выходит за рамки текущего ДЗ,
        //поэтому для получения index.html решил задействовать утилиту wget
        QProcess::execute("wget", QStringList() << webInfo.m_hstCnv.weatherURL);

        if (htmlFile.open(QFile::ReadOnly |
                QFile::ExistingOnly))
            {
            QTextStream stream(&htmlFile);
//            QString tempStr { htmlFile.readAll()}; //debug


            QRegularExpression reg { webInfo.m_hstCnv.weatherRegExpStr };
            QRegularExpressionMatch match { reg.match(stream.readAll()) };
//            if (reg.indexIn(stream.readAll(), 0) == -1)
            //if (!reg.hasMatch(stream.readAll()))
            if (!match.hasMatch())
            {
               webInfo.m_weather = "Weather info from " + webInfo.m_hstCnv.hostName +
                " not found.";
             //   m_weather = tempStr; //debug
               return;
            }

            webInfo.m_weather = match.captured(1);
            if (webInfo.m_hstCnv.hostName == hostConvArr[0].hostName)
                {
                    //&deg; - мусор
                    webInfo.m_weather.replace("&deg;","");

                }
            }
        else
            {
            webInfo.m_weather = "Can't open index.html.";
            }

}


