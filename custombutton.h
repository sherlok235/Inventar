#ifndef CUSTOMBUTTON_H
#define CUSTOMBUTTON_H

#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSpacerItem>
#include <QPainter>
#include <QPixmap>
#include <QLabel>
#include <QPainterPath>

class CustomButton : public QPushButton
{
private:
    QHBoxLayout * main_layout,* image_layout, * quantity_layout,* info_top_layout,* info_center_layout,
    * info_bottom_layout,*info_and_image_layout;
    QVBoxLayout * info;
    QLabel * img,* name,* info_bar_code_img,* info_description,* info_code, * info_quantity;
    QSpacerItem * space;
    QString  code_bar_image;
public:
    CustomButton();
    CustomButton(QString ImgPath,QString Name,QString Code,QString Description , int Quantity);
    void setImage(QString path);
    void setDescription_Info(QString name ,QString code,QString description);
    void setQuantity(int quantity);

};

#endif // CUSTOMBUTTON_H
