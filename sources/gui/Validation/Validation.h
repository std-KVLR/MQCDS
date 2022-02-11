#ifndef VALIDATION_H
#define VALIDATION_H


#include <QTextEdit>
#include <QIntValidator>
#include <QRegExp>
#include <QRegExpValidator>


namespace validation
{

    class Validator
    {
        const QString ipRange = "(?:[0-1]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])";
        static constexpr uint16_t minPortValue = 0;
        static constexpr uint16_t maxPortValue = 65535;

        QIntValidator portValidator;
        QRegExpValidator ipAddressValidator;
    public:
        Validator()
            :portValidator(minPortValue, maxPortValue, nullptr),
            ipAddressValidator(QRegExp("^" + ipRange + "\\." + ipRange + "\\." + ipRange + "\\." + ipRange + "$"), nullptr){}
        bool validateIP(QString& str)
        {
           int pos = 0;
           return ipAddressValidator.validate(str, pos) == QValidator::Acceptable;
        }
        bool validatePort(QString& str)
        {
            int pos = 0;
            return portValidator.validate(str, pos) == QValidator::Acceptable;
        }
    };
}



#endif // VALIDATION_H
