#ifndef WEBINFO_H
#define WEBINFO_H

#include <QString>

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

};


const HostConvention hostConvArr[] =
{
   { "mail.ru",
     "https://trk.mail.ru/c/qtcyh9",
     "mrc__share_title\" content=[^>]+>",
     "https://news.mail.ru/currency.html",
     ""
    },

    { "yandex.ru",
      "",
      "",
      "",
      ""
    }
};

#endif // WEBINFO_H
