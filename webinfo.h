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
    const HostConvention getHstCnv() const;
    const QString getWeather() const;
    const QString getCurrency() const;
    void setHstCnv(const HostConvention&);
    void setWeather(const QString&);
    void setCurrency(const QString&);

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
     ""
    },

    { "yandex.ru",
      "https://yandex.ru/pogoda/",
      //"nowcastAlert\":\"[\p{Cyrillic}|[:alnum:]],\"icon\":\"bkn_sn_n",
      "nowcastAlert\":\"(\\w{1,}),\"icon\":\"bkn_sn_n",
      "",
      ""
    }
};

void removeHtmlFile(QFile&);

#endif // WEBINFO_H
