#include "riverlistsql.h"
#include "QObject"

riverListSQL::riverListSQL(QObject *parent) :
    QSqlQueryModel(parent)
{
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setDatabaseName("Rivers");
    db.setPort(5432);
    db.setPassword("123");
    db.setUserName("postgres");

    QSqlQuery query(db);

     _isConnectionOpen = true;

    if(!db.open())
    {
        qDebug() << db.lastError().text();
        _isConnectionOpen = false;
    }

    refresh();
}

QSqlQueryModel* riverListSQL::getModel(){
    return this;
}
bool riverListSQL::isConnectionOpen(){
    return _isConnectionOpen;
}
QHash<int, QByteArray> riverListSQL::roleNames() const
{
    QHash<int, QByteArray> roles;

    roles[Qt::UserRole + 2] = "NameOfRiver";
    roles[Qt::UserRole + 3] = "LenghtOfRiver";
    roles[Qt::UserRole + 4] = "FlowOfRiver";
    roles[Qt::UserRole + 5] = "RunoffOfRiver";
    roles[Qt::UserRole + 6] = "AreaOfRiver";
    roles[Qt::UserRole + 1] = "Id_river";

    return roles;
}

QVariant riverListSQL::data(const QModelIndex &index, int role) const
{
    QVariant value = QSqlQueryModel::data(index, role);
    if(role < Qt::UserRole-1)
    {
        value = QSqlQueryModel::data(index, role);
    }
    else
    {
        int columnIdx = role - Qt::UserRole - 1;
        QModelIndex modelIndex = this->index(index.row(), columnIdx);
        value = QSqlQueryModel::data(modelIndex, Qt::DisplayRole);
    }
    return value;
}

const char* riverListSQL::SQL_SELECT =
        "SELECT *"
        "FROM rivers";

void riverListSQL::refresh()
{
    this->setQuery(riverListSQL::SQL_SELECT,db);
    qDebug() << db.lastError().text();
}

void riverListSQL::add(const QString& nameRiv, const QString& lenghtRiv, const QString& flowRiv, const QString& runoffRiv, const QString& areaRiv){

    QSqlQuery query(db);
    QString strQuery= QString("INSERT INTO rivers (Name,Lenght,Flow,Runoff,Area) VALUES ('%1', '%2', '%3', '%4', '%5')")
            .arg(nameRiv)
            .arg(lenghtRiv)
            .arg(flowRiv)
            .arg(runoffRiv)
            .arg(areaRiv);
    bool a = query.exec(strQuery);
    qDebug() << a;

    refresh();
}

void riverListSQL::edit(const QString& nameRiv, const QString& lenghtRiv, const QString& flowRiv, const QString& runoffRiv, const QString& areaRiv, const int Id_river){

    QSqlQuery query(db);
    QString strQuery= QString("UPDATE rivers SET Name = '%1',Lenght = '%2',Flow = '%3',Runoff = '%4', Area = '%5'  WHERE Id = %6")
            .arg(nameRiv)
            .arg(lenghtRiv)
            .arg(flowRiv)
            .arg(runoffRiv)
            .arg(areaRiv)
            .arg(Id_river);
    bool a = query.exec(strQuery);
    qDebug() << a;

    refresh();
}

void riverListSQL::del(const int Id_river){

    QSqlQuery query(db);
    QString strQuery= QString("DELETE FROM rivers WHERE Id = %1")
            .arg(Id_river);
    bool a = query.exec(strQuery);
    qDebug() << a;

    refresh();
}
