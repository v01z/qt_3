#ifndef WEBINFO_H
#define WEBINFO_H

#include <QString>
#include <QFile>

//const QString

struct HostConvention {
    QString hostName;
 //   QString localFilePath;
    QString weatherURL;
    QString weatherRegExpStr;
    QString currencyURL;
    QString currencyRegExpStr;
};

class WebInfo
{
private:
    HostConvention m_hstCnv{};
    QString m_weather{};
    QString m_currency{};
public:
    WebInfo(const QString&);
    const QString getWeather() const;
    const QString getCurrency() const;

    //Функции призваны уменьшить число строк кода в конструкторе,
    //а также избегнуть дополнительных геттеров и сеттеров
    friend void gettingWeather(WebInfo&);
    friend void gettingCurrency(WebInfo&);

};


const HostConvention hostConvArr[] =
{
   { "mail.ru",
//     "https://trk.mail.ru/c/qtcyh9",
     //Same as above link:
     "https://pogoda.mail.ru/prognoz/moskva/",
//     "mrc__share_title\" content=[^>]+>", //works
     "mrc__share_title\" content=\"([^>]+)/>", //works
//     "https://news.mail.ru/currency.html",
     "https://news.mail.ru/currency/src/CBRF/charcode/USD/",
//     "RUB\",\"items\":\[\{\"rate\":\"(.+)\",\"link\":\"h"
//     "RUB\",\"items\":\[\{\"rate\":\"(\d\d).(\d\d)(.+)(\d\d).(\d\d)\",\"link\":\"h"
"RUB\",\"items\":\[\{\"rate\":\"(\d\d).(\d\d)(...)(\d\d).(\d\d)(...)EUR"
    },

    { "yandex.ru",
      "https://yandex.ru/pogoda/",
      //"nowcastAlert\":\"[\p{Cyrillic}|[:alnum:]],\"icon\":\"bkn_sn_n",
//      "nowcastAlert\":\"(.+),\"icon\":\"bkn_sn_n",
      //"nowcastAlert\":\"(.+),\"icon\":\"bkn_sn_n" //works on regex101.com
      "nowcastAlert\":\"(.+),\"icon\":",
      "",
      ""
    }
};

//void removeHtmlFile(QFile&);

#endif // WEBINFO_H
