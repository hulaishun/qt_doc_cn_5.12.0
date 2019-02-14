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

    void OnKeyClicked(const QModelIndex& index);

private:
    void InitAllControl();
    void ClearListView();

private:
    Ui::CEn2CnKeyForm *ui;
};

#endif // EN2CNKEYFORM_H
