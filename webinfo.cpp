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

    gettingWeather(*this);


}

const QString WebInfo::getWeather() const
{
    return m_weather;
}

const QString WebInfo::getCurrency() const
{
    return m_currency;
}

void gettingWeather(WebInfo &webInfo)
{
        QFile htmlFile { "index.html" };
        if (htmlFile.exists())
             htmlFile.remove();

        //Реализация http-клиента, подозреваю, выходит за рамки текущего ДЗ,
        //поэтому для получения index.html решил задействовать утилиту wget
        QProcess::execute("wget", QStringList() << webInfo.m_hstCnv.weatherURL);

        if (htmlFile.open(QFile::ReadOnly |
                QFile::ExistingOnly))
            {
            QTextStream stream(&htmlFile);


            QRegularExpression reg { webInfo.m_hstCnv.weatherRegExpStr };
            QRegularExpressionMatch match { reg.match(stream.readAll()) };

            if (!match.hasMatch())
            {
               webInfo.m_weather = "Weather info from " + webInfo.m_hstCnv.hostName +
                " not found.";

               return;
            }

            if (webInfo.m_hstCnv.hostName == hostConvArr[0].hostName)
                {
                    webInfo.m_weather = "Погода:\n" + match.captured(1);

                    //&deg; - мусор
                    webInfo.m_weather.replace("&deg;","");
                    webInfo.m_weather.append(".\n\n");

                }
            else if (webInfo.m_hstCnv.hostName == hostConvArr[1].hostName)
                {
                    webInfo.m_weather = match.captured(1);

                    //Жалко, нельзя воспользоваться предыдущим объектом
                    //регулярки (reg) - нет перегруженного оператора
                    //присваивания, где rvalue был бы QString.
                    QRegularExpression innerReg
                     { "(.+)\",\"fact(.+)temp\":(.+),\"feels_like\":(.+)" };
                    match = innerReg.match(webInfo.m_weather);
                    if(match.hasMatch())
                    {
                        webInfo.m_weather = "Погода:\n" + match.captured(1) +
                            ". Температура " + match.captured(3) +
                                ". Чувствуется как " + match.captured(4) +
                                    ".\n\n";

                    }


                }


            }
        else
            {
            webInfo.m_weather = "Can't open index.html.";
            }

}

void gettingCurrency(WebInfo &webInfo)
{

    QFile htmlFile { "index.html" };
    if (htmlFile.exists())
         htmlFile.remove();

}


