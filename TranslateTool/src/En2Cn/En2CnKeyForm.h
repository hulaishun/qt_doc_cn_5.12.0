#ifndef EN2CNKEYFORM_H
#define EN2CNKEYFORM_H

#include <QWidget>

namespace Ui {
class CEn2CnKeyForm;
}

class CEn2CnKeyForm : public QWidget
{
Q_OBJECT

public:
    explicit CEn2CnKeyForm(QWidget *parent = nullptr);
    ~CEn2CnKeyForm();

private slots:
    void OnLoadKeyClicked();
    void OnAddKeyClicked();
    void OnEditKeyClicked();
    void OnDelKeyClicked();
    void OnImportKeyClicked();
    void OnExportKeyClicked();
	void OnTranslateFileClicked();
	void OnTranslatePathClicked();
	void OnTranslateAllPathClicked();

    void OnKeyClicked(const QModelIndex& index);

private:
    void InitAllControl();
    void ClearListView();
	void TranslatePath(const QString& strPath);
	void TranslateFile(const QString& strFile);

private:
    Ui::CEn2CnKeyForm *ui;
};

#endif // EN2CNKEYFORM_H
