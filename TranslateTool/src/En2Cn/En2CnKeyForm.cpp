#include "En2CnKeyForm.h"
#include "ui_En2CnKeyForm.h"

#include <QtWidgets/qfiledialog.h>
#include <QtCore/qfile.h>
#include <QtCore/qtextstream.h>

#include "En2CnManager.h"
#include "En2CnTableModel.h"
#include "En2CnKeyFile.h"

CEn2CnKeyForm::CEn2CnKeyForm(QWidget *parent) :
QWidget(parent),
ui(new Ui::CEn2CnKeyForm)
{
    ui->setupUi(this);

    InitAllControl();
}

CEn2CnKeyForm::~CEn2CnKeyForm()
{
    delete ui;
}

void CEn2CnKeyForm::InitAllControl()
{
    connect(ui->pbtnLoadKey, &QPushButton::clicked, this, &CEn2CnKeyForm::OnLoadKeyClicked);
    connect(ui->pbtnAddKey, &QPushButton::clicked, this, &CEn2CnKeyForm::OnAddKeyClicked);
    connect(ui->pbtnEditKey, &QPushButton::clicked, this, &CEn2CnKeyForm::OnEditKeyClicked);
    connect(ui->pbtnDelKey, &QPushButton::clicked, this, &CEn2CnKeyForm::OnDelKeyClicked);
    connect(ui->pbtnImportKey, &QPushButton::clicked, this, &CEn2CnKeyForm::OnImportKeyClicked);
    connect(ui->pbtnExportKey, &QPushButton::clicked, this, &CEn2CnKeyForm::OnExportKeyClicked);
	connect(ui->pbtnTranslateFile, &QPushButton::clicked, this, &CEn2CnKeyForm::OnTranslateFileClicked);
    connect(ui->tableViewKey, &QTableView::clicked, this, &CEn2CnKeyForm::OnKeyClicked);

    ui->tableViewKey->setModel(gEn2CnMgr->GetKeyModel());
    ui->tableViewKey->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableViewKey->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui->tableViewKey->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}

void CEn2CnKeyForm::ClearListView()
{
    gEn2CnMgr->GetKeyModel()->ClearData();
}

void CEn2CnKeyForm::OnLoadKeyClicked()
{
    gEn2CnMgr->GetKeyModel()->ClearData();

    QString strFile = QFileDialog::getOpenFileName(this, QString("打开文件"));

    gEn2CnMgr->GetKeyFile()->ReadFromFile(strFile);

    QList<CEn2CnKeyInfo> listKeyinfo = gEn2CnMgr->GetKeyFile()->GetKeyList();
    for(int i=0; i < listKeyinfo.count(); ++i)
    {
        gEn2CnMgr->GetKeyModel()->AddKeyInfo(listKeyinfo.at(i));
    }
}

void CEn2CnKeyForm::OnAddKeyClicked()
{
    QString strEnText = ui->plainTextEditEn->toPlainText().trimmed();
    if(strEnText.isEmpty())
    {
        ui->plainTextEditEn->setFocus();
        return;
    }

    QString strCnText = ui->plainTextEditCn->toPlainText().trimmed();
    if(strCnText.isEmpty())
    {
        ui->plainTextEditCn->setFocus();
        return;
    }

    int iMaxKeyId = gEn2CnMgr->GetMaxKeyId();
    iMaxKeyId++;

    CEn2CnKeyInfo keyinfo(iMaxKeyId, strEnText, strCnText);
    gEn2CnMgr->AddKeyInfo(keyinfo);
    gEn2CnMgr->GetKeyModel()->AddKeyInfo(keyinfo);
	ui->tableViewKey->scrollToBottom();
}

void CEn2CnKeyForm::OnEditKeyClicked()
{
    QString strEnText = ui->plainTextEditEn->toPlainText().trimmed();
    if(strEnText.isEmpty())
    {
        ui->plainTextEditEn->setFocus();
        return;
    }

    QString strCnText = ui->plainTextEditCn->toPlainText().trimmed();
    if(strCnText.isEmpty())
    {
        ui->plainTextEditCn->setFocus();
        return;
    }

    gEn2CnMgr->UpdateKeyInfo(strEnText, strCnText);

    QModelIndex index = ui->tableViewKey->currentIndex();
    gEn2CnMgr->GetKeyModel()->UpdateKeyInfo(index, strEnText, strCnText);
}

void CEn2CnKeyForm::OnDelKeyClicked()
{
    QString strEnText = ui->plainTextEditEn->toPlainText().trimmed();
    if(strEnText.isEmpty())
    {
        ui->plainTextEditEn->setFocus();
        return;
    }

    gEn2CnMgr->DelKeyInfo(strEnText);
    QModelIndex index = ui->tableViewKey->currentIndex();
    gEn2CnMgr->GetKeyModel()->DelKeyInfo(index);
}

void CEn2CnKeyForm::OnImportKeyClicked()
{

}

void CEn2CnKeyForm::OnExportKeyClicked()
{

}

void CEn2CnKeyForm::OnKeyClicked(const QModelIndex& index)
{
    if(!index.isValid())
    {
        return;
    }

    QString strEnText = gEn2CnMgr->GetKeyModel()->data(index, CEn2CnTableModel::KeyEnNameRole).toString();
    ui->plainTextEditEn->setPlainText(strEnText);

    QString strCnText = gEn2CnMgr->GetKeyModel()->data(index, CEn2CnTableModel::KeyCnNameRole).toString();
    ui->plainTextEditCn->setPlainText(strCnText);
}

void CEn2CnKeyForm::OnTranslateFileClicked()
{
	QString strFile = QFileDialog::getOpenFileName(this, QStringLiteral("打开文件"), QCoreApplication::applicationFilePath(), QStringLiteral("英文文档 (*.html *.htm);;所有文档 (*.*)"));
	if (strFile.isEmpty())
	{
		return;
	}

	QFile oldFile(strFile);
	if (!oldFile.open(QIODevice::ReadWrite|QIODevice::Text))
	{
		return;
	}
	QTextStream instream(&oldFile);
	instream.setCodec("UTF-8");
	QString strOldData = instream.readAll();
	oldFile.close();

	foreach (CEn2CnKeyInfo keyinfo, gEn2CnMgr->GetKeyModel()->GetDataList())
	{
		strOldData.replace(keyinfo.GetEnKey().toUtf8(), keyinfo.GetCnKey().toUtf8());
	}

	QFile newFile(strFile);
	if (!newFile.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text))
	{
		return;
	}
	QTextStream outstream(&newFile);
	outstream.setCodec("UTF-8");
	outstream << strOldData;
	newFile.close();
	
}
