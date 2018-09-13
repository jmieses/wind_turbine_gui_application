#ifndef READ_H
#define READ_H


#include <iostream>
#include <string>
#include <fstream>
#include <qvector>
#include <qfile.h>
#include <algorithm>

class Read
{
private:
    QFile readFile;
    bool check_file_open;

protected:

    QVector<double> data1, data2;
    QVector<QString> date_time;
    QString file;

public:


    Read();
    Read(QString file);
    //Read(const Read&);

    QVector<QString> * ReadStoreDateTimeData();

    void ReadStoreData();
    void ReadPrintData();

    void setData1(const QVector<double>& data);
    void setData2(const QVector<double>& data);
    void setDateTime(const QVector<QString>& data);

    const QString getFileName() const;
    const QVector<double>& getData1() const;
    const QVector<double>& getData2() const;
    const QVector<QString>& getDateTime() const;
    const int getStringIndex(QString, QString) const;

    /*Rule of three implementation: copy constructor, overloaded assignment operator, destructor*/

    // copy constructor
    Read(const Read&);

    // overloaded assignment operator
    Read& operator=(const Read);

    // destructor
    ~Read();
};

#endif // READ_H
