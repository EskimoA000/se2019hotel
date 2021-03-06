﻿#ifndef RECORDS_H
#define RECORDS_H

#include "../share/objects.h"
#include "../share/pipe.h"

#include <QObject>
#include <QVector>

class Records : public QObject
{
    Q_OBJECT
public:
    explicit Records(QObject *parent = nullptr);

    QVector<QString> getDetailedBill(int roomId);
    QVector<QString> getSimpleBills(int roomId);
    QVector<Billing> getReportForm();

signals:

public slots:

private:
    Pipe *pipe;

    QString calcDurationStr(long long duration);
};

#endif // RECORDS_H
