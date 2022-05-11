#ifndef RIVERLISTSQL_H
#define RIVERLISTSQL_H

#include <QtSql>

class riverListSQL: public QSqlQueryModel
{
    Q_OBJECT

    Q_PROPERTY(QSqlQueryModel* riverModel READ getModel CONSTANT)
    Q_PROPERTY(bool IsConnectionOpen READ isConnectionOpen CONSTANT)

public:
    explicit riverListSQL(QObject *parent);
    void refresh();
    QHash<int, QByteArray> roleNames() const override;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const override;

    /*Q_INVOKABLE void add(const QString& nameSt, const int numberSt, const int countSt);  // макрос указывает, что к методу можно обратиться из QML
    Q_INVOKABLE void del(const int index);
    Q_INVOKABLE void edit(const QString& nameSt, const int numberSt, const int countSt, const int index);*/

    Q_INVOKABLE void add(const QString& nameRiv, const QString& lenghtRiv, const QString& flowRiv, const QString& runoffRiv, const QString& areaRiv);
    Q_INVOKABLE void del(const int index);
    Q_INVOKABLE void edit(const QString& nameRiv, const QString& lenghtRiv, const QString& flowRiv, const QString& runoffRiv, const QString& areaRiv, const int index);
    //Q_INVOKABLE QString count(const QString& textSelArea);



signals:

public slots:

private:
    const static char* SQL_SELECT;
    QSqlDatabase db;
    QSqlQueryModel *getModel();
    bool _isConnectionOpen;
    bool isConnectionOpen();
};

#endif // RIVERLISTSQL_H
