#include "custombutton.h"

CustomButton::CustomButton()
{
    code_bar_image = "img/reds.png";

    info_and_image_layout = new QHBoxLayout();
    info_center_layout = new QHBoxLayout();
    info_bottom_layout = new QHBoxLayout();
    quantity_layout = new  QHBoxLayout();
    info_top_layout = new QHBoxLayout();
    image_layout = new QHBoxLayout();
    main_layout = new QHBoxLayout();

    info = new QVBoxLayout();

    info_bar_code_img = new QLabel();
    info_description = new QLabel();
    info_quantity = new QLabel();
    info_code = new QLabel();
    name = new QLabel();
    img = new QLabel();

    space = new QSpacerItem(450,10);

    QString Style1="QLabel{margin-left: 0;margin-right: auto; padding:0; }";

    info_description->setStyleSheet(Style1);
    info_code->setStyleSheet(Style1);
    info_code->setAlignment(Qt::AlignLeft);
    info_code->setMargin(0);

    image_layout->addWidget(img);

    info_bar_code_img->setPixmap(QPixmap(code_bar_image).scaled(43,18));
    info_bar_code_img->setAlignment(Qt::AlignLeft);

    info_center_layout->setSpacing(0);
    info_center_layout->addWidget(info_bar_code_img);
    info_center_layout->addWidget(info_code);

    info_bottom_layout->addWidget(info_description);

    info_top_layout->addWidget(name);

    info->addLayout(info_top_layout);
    info->addLayout(info_center_layout);
    info->addLayout(info_bottom_layout);

    quantity_layout->addSpacerItem(space);
    quantity_layout->addWidget(info_quantity);

    info_and_image_layout->addLayout(image_layout);
    info_and_image_layout->addLayout(info);
    info_and_image_layout->setAlignment(Qt::AlignLeft);

    main_layout->addLayout(info_and_image_layout);
    main_layout->addLayout(quantity_layout);

    this->setLayout(main_layout);
    this->setMinimumSize(QSize(400,90));


}

CustomButton::CustomButton(QString ImgPath , QString Name , QString Code , QString Description, int Quantity )
    :CustomButton::CustomButton()
{
    setImage(ImgPath);
    setDescription_Info(Name,Code,Description);
    setQuantity(Quantity);
}


void CustomButton::setImage(QString image_path)
{
       AvatarImg = image_path;

       QPixmap target = QPixmap(QSize(66,66));
        target.fill(Qt::transparent);

       QPixmap pixmap(image_path);
       QPixmap scaled = pixmap.scaled(66, 66, Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);
       QBrush brush(scaled);
        brush.setStyle(Qt::TexturePattern);
        brush.setColor(QColor(255,255,255,28));
       QPainter painter(&target);
        painter.setRenderHint(QPainter::Antialiasing,true);
        painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
        painter.setBrush(brush);
        painter.drawRoundedRect(0, 0,66, 66, 100, 100);

       img->setPixmap(QPixmap::fromImage( target.toImage()));

       img->setStyleSheet("QLabel{border-radius: 33px;}");
}

void CustomButton::setDescription_Info(QString name,QString code, QString description)
{
    info_code->setText(code);
    info_code->setFont(QFont("Times",9,QFont::Cursive));

    info_description->setText(description);
    info_description->setFont(QFont("Times",9,QFont::Cursive));

    this->name->setText(name);
    this->name->setFont(QFont("Times",13,QFont::Bold));
}

void CustomButton::setQuantity(int quantity = 0)
{
    info_quantity->setNum(quantity);
}

QString CustomButton::getName()
{
    return name->text();
}

QString CustomButton::getDescription()
{
    return info_description->text();
}

QString CustomButton::getCode()
{
    return info_code->text();
}

QString CustomButton::getQuantity()
{
    return info_quantity->text();
}

QString CustomButton::getImgPath()
{
    return AvatarImg;
}
