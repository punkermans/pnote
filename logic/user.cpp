#include "user.h"
#include "../initialize.h"
#include <tr1/unordered_map>
#include <QFileDialog>
#include <QtSql>

using namespace std;

User::User()
{
}

void User::setUser(QString Id, QString previousId, QString FirstName, QString LastName, QString phone, QString otherContact, QString notes, std::tr1::unordered_map<int, userCar> userCar)
{
    this->id = Id;
    this->previousId = previousId;
    this->firstName = FirstName;
    this->lastName = LastName;
    this->phone = phone;
    this->otherContact = otherContact;
    this->userCarsHash = userCar;
    this->notes = notes;
}

void User::setUser(QString Id, QString previousId, QString FirstName, QString LastName, QString phone, QString otherContact, QString notes)
{
    this->id = Id;
    this->firstName = FirstName;
    this->lastName = LastName;
    this->phone = phone;
    this->previousId = previousId;
    this->otherContact = otherContact;
    this->notes = notes;
}


void User::insertUser()
{
    QSqlQuery query ;
    QString queryStr;
    std::tr1::unordered_map<QString, User> usersHash = initialize::Instance()->getUsersHash();


    queryStr = "INSERT INTO pnote.user (ID, First_Name, Last_Name, Contact_Number, Other_Contact, notes) VALUES ('"
                    + this->id + "', '"
                    + this->firstName + "', '"
                    + this->lastName + "', '"
                    + this->phone + "', '"
                    + this->otherContact + "', '"
                    + this->notes +"');";
    qDebug() << queryStr;
    query.exec(queryStr);
    usersHash.insert(std::make_pair(this->id, *this));
    initialize::Instance()->setUsersHash(usersHash);
}

User getUserbyId(QString userId)
{
    std::tr1::unordered_map<QString, User> usersHash = initialize::Instance()->getUsersHash();
    return usersHash[userId];
}
