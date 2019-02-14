#ifndef CN2CNKEYFORM_H
#define CN2CNKEYFORM_H

#include <QWidget>

namespace Ui {
class CCn2CnKeyForm;
}

class CCn2CnKeyForm : public QWidget
{
Q_OBJECT

public:
explicit CCn2CnKeyForm(QWidget *parent = nullptr);
~CCn2CnKeyForm();

private:
Ui::CCn2CnKeyForm *ui;
};

#endif // CN2CNKEYFORM_H
