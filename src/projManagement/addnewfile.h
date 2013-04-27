/* ============================================================
 *
 * This file is a part of WHC IDE Project
 * http://http://whcomputing.wikispaces.com/
 *
 * Date        :
 * Description :
 *
 * Copyright (C) 2012 by Veaceslav Munteanu <slavuttici at gmail dot com>
 *
 * This program is free software; you can redistribute it
 * and/or modify it under the terms of the GNU General
 * Public License as published by the Free Software Foundation;
 * either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * ============================================================ */

#ifndef ADDNEWFILE_H
#define ADDNEWFILE_H
#include "ide.h"
#include "projManagement/overwritefile.h"
#include <QDialog>
#include <QComboBox>
#include <QDialogButtonBox>
#include <QDomNodeList>

#ifdef WIN32
#define sep "\\"
#elif __linux__
#define sep "/"
#endif


class Ide;
class ProjectTreeItem;
class AddNewFile : public QDialog
{
  Q_OBJECT

public:
    AddNewFile(QDomDocument* proj, Ide* parent,QModelIndex selected);
    ~AddNewFile();

private slots:

    /**
     * @brief slotAddNewFile -add selected fiels to .whc
     */
    void slotAddNewFile();
    void slotWriteNewFile();
private:

    QDomNodeList lst;
    QDomDocument* projectXml;
    Ide* parent;
    ProjectTreeItem* tasksItem;
    /**
     * Gui elements
     */
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QComboBox *comboBox;
    QPushButton *pushButton;
    /**
     * Instance of the overwrite diablog
     */
    OverwriteFile *overwriteDialog;
};
#endif // ADDNEWFILE_H
