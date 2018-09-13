#include "read.h"
#include <qdebug.h>

QVector<QString> files {"a170503.csv","a170504.csv","a170505.csv","a170506.csv"};
Read::Read()
{
}

Read::Read(QString new_file){

    file = new_file;
    readFile.setFileName(new_file);
    check_file_open = readFile.open(QFile::ReadOnly);
    if (!check_file_open){
        qDebug() << "read: File could not be opened \n";
    }
}


void Read::ReadStoreData(){
    // check that file is opened
    // read date, time, and data from file separated by ','
    qDebug() << "files size: " << files.size() << endl;

    for(int i = 0; i < files.size() ; i++){
    readFile.setFileName(":/files/test/" + files.at(i));
    check_file_open = readFile.open(QFile::ReadOnly);
        if (check_file_open){
        double temp1, temp2;
        QString date, time, str_dummy;
        QStringList dummy_list;
        // getline(istream& is, const string&) -> change to equivalent method with different parameters for QT
        //getline(QString::toStdString(readFile.readLine()), str_dummy); // get rid of first line

        QTextStream in(&readFile);
        str_dummy = in.readLine();


        while (!in.atEnd()){
            str_dummy = in.readLine();

            dummy_list = str_dummy.split(",");

            // check if the list is not empty, then
            // store the data into respected variables;
            if(dummy_list.size() > 0){
            date = dummy_list.at(0);
            time = dummy_list.at(1);
            temp1 = dummy_list.at(2).toDouble();
            temp2 = dummy_list.at(3).toDouble();
            }
            date_time.push_back(date + ',' + time);
            data1.push_back(temp1);
            data2.push_back(temp2);
        }

    }
    else {
        std::cout << "File could not be open" << std::endl;
    }
    readFile.close();
    }
    qDebug() << "data1 size: " << data1.size() << endl;
}

void Read::setData1(const QVector<double> &data)
{
    data1.append(data);
}

void Read::setData2(const QVector<double> &data)
{
    data2.append(data);
}

void Read::setDateTime(const QVector<QString> &data)
{
    date_time.append(data);
}


const QString Read::getFileName() const{
    return file;
}

const QVector<double>& Read::getData1() const{
    return data1;
}

const QVector<double>& Read::getData2() const{
    return data2;
}

const QVector<QString>& Read::getDateTime() const{
    return date_time;
}

const int Read::getStringIndex(QString date, QString time) const {
    // get the index that represent the date and time
    /*QVector<QString>::const_iterator date_it = std::find(date_time.cbegin(), date_time.cend(), date + ',' + time);
    return std::distance(date_time.cbegin(), date_it);*/
    int i = 0;
    while (('\n' + date + ',' + time) != date_time.at(i)){
        i++;
        if (i > date_time.size()) break;
    }
    return i;
}

// Rule of three definition

// copy constructor
Read::Read(const Read& r){

    // resize the vector containers data1, data2, date_time
    // so the iterator does not go out  of range
    if (!this->data1.empty()){

        size_t n = r.data1.size();
        this->data1.resize(n);
        this->data2.resize(n);
        this->date_time.resize(n);
    }

    std::cout << "Read Copy constructor called " << std::endl;
    if (!this->data1.empty()){
        std::copy(r.file.begin(), r.file.end() - 1, this->file.begin());
        std::copy(r.data1.begin(), r.data1.end() - 1, this->data1.begin());
        std::copy(r.data2.begin(), r.data2.end() - 1, this->data2.begin());
        std::copy(r.date_time.begin(), r.date_time.end() - 1, this->date_time.begin());
    }
    system("pause");
}

// overloaded assignment operator
Read& Read::operator=(const Read r){
    // check if the two objects have the same data.
    // if same data return this object.
    if (this == &r){
        return *this;
    }
    std::copy(r.file.begin(), r.file.end(), this->file.begin());
    std::copy(r.data1.begin(), r.data1.end(), this->data1.begin());
    std::copy(r.data2.begin(), r.data2.end(), this->data2.begin());
    std::copy(r.date_time.begin(), r.date_time.end(), this->date_time.begin());

    return *this;
}

Read::~Read()
{
    readFile.close();
}
