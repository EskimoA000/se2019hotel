#include "pipe.h"

#include <QDebug>
#include <QSqlQuery>
#include <QVariant>

Pipe::Pipe():
  db(QSqlDatabase::addDatabase("QODBC3"))
{
  db.setDatabaseName("SE");
  db.open();
  qDebug() << db.isOpen();
}

Pipe::~Pipe()
{
  db.close();
}

void Pipe::addUser(const User &user)
{
  QSqlQuery query(db);
  query.prepare("INSERT INTO usr VALUES(:id, :pswd);");
  query.bindValue(":id", QVariant(user.id));
  query.bindValue(":pswd", QVariant(user.pswd));
  query.exec();
  qDebug() << "add user";
}

void Pipe::delUser(const User &user)
{
  QSqlQuery query(db);
  query.prepare("DELETE FROM usr WHERE usr.id = :id;");
  query.bindValue(":id", QVariant(user.id));
  query.exec();
  qDebug() << "delete user";
}

void Pipe::addRoom(const Room &room)
{
  // ************ TODO ***************
  QSqlQuery query(db);
  query.prepare("INSERT INTO room VALUES()");
  query.exec();
  qDebug() << "add Room";
}

void Pipe::delRoom(const Room &room)
{

}
