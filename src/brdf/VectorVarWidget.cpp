/*
Copyright Disney Enterprises, Inc. All rights reserved.

This license governs use of the accompanying software. If you use the software, you
accept this license. If you do not accept the license, do not use the software.

1. Definitions
The terms "reproduce," "reproduction," "derivative works," and "distribution" have
the same meaning here as under U.S. copyright law. A "contribution" is the original
software, or any additions or changes to the software. A "contributor" is any person
that distributes its contribution under this license. "Licensed patents" are a
contributor's patent claims that read directly on its contribution.

2. Grant of Rights
(A) Copyright Grant- Subject to the terms of this license, including the license
conditions and limitations in section 3, each contributor grants you a non-exclusive,
worldwide, royalty-free copyright license to reproduce its contribution, prepare
derivative works of its contribution, and distribute its contribution or any derivative
works that you create.
(B) Patent Grant- Subject to the terms of this license, including the license
conditions and limitations in section 3, each contributor grants you a non-exclusive,
worldwide, royalty-free license under its licensed patents to make, have made,
use, sell, offer for sale, import, and/or otherwise dispose of its contribution in the
software or derivative works of the contribution in the software.

3. Conditions and Limitations
(A) No Trademark License- This license does not grant you rights to use any
contributors' name, logo, or trademarks.
(B) If you bring a patent claim against any contributor over patents that you claim
are infringed by the software, your patent license from such contributor to the
software ends automatically.
(C) If you distribute any portion of the software, you must retain all copyright,
patent, trademark, and attribution notices that are present in the software.
(D) If you distribute any portion of the software in source code form, you may do
so only under this license by including a complete copy of this license with your
distribution. If you distribute any portion of the software in compiled or object code
form, you may only do so under a license that complies with this license.
(E) The software is licensed "as-is." You bear the risk of using it. The contributors
give no express warranties, guarantees or conditions. You may have additional
consumer rights under your local laws which this license cannot change.
To the extent permitted under your local laws, the contributors exclude the
implied warranties of merchantability, fitness for a particular purpose and non-
infringement.
*/

// File added by Joey Chen.

#include <string>
#include <QHBoxLayout>
#include <QLabel>
#include <QDoubleValidator>
#include "VectorVarWidget.h"

Vec3VarWidget::Vec3VarWidget(QString name, float x, float y, float z)
{
    QHBoxLayout *layout = new QHBoxLayout;

    // Keep the same style as the color widget
    QLabel* label = new QLabel( name );
    QFont font = label->font();
    font.setBold( true );
    label->setFont( font );
    layout->addWidget( label );

    QDoubleValidator* validator = new QDoubleValidator();
    x_field = new QLineEdit("0");
    x_field->setValidator(validator);
    layout->addWidget(x_field);
    connect(x_field, SIGNAL(textChanged(const QString&)), this, SLOT(setXValue(const QString&)));

    y_field = new QLineEdit("0");
    y_field->setValidator(validator);
    layout->addWidget(y_field);
    connect(y_field, SIGNAL(textEdited(const QString&)), this, SLOT(setYValue(const QString&)));

    z_field = new QLineEdit("0");
    z_field->setValidator(validator);
    layout->addWidget(z_field);
    connect(z_field, SIGNAL(textEdited(const QString&)), this, SLOT(setZValue(const QString&)));

    setContentsMargins( 0, 0, 0, 0 );
    layout->setMargin( 1 );
    setSizePolicy( QSizePolicy::Preferred, QSizePolicy::Fixed );

    setLayout(layout);

    value = defaultValue = QVector3D(x, y, z);
    setToDefault();
}

Vec3VarWidget::~Vec3VarWidget()
{
}

void Vec3VarWidget::setXValue(const QString& text)
{
    value.setX(std::stof(text.toStdString()));
    emit(valueChanged());
}

void Vec3VarWidget::setYValue(const QString& text)
{
    value.setY(std::stof(text.toStdString()));
    emit(valueChanged());
}

void Vec3VarWidget::setZValue(const QString& text)
{
    value.setZ(std::stof(text.toStdString()));
    emit(valueChanged());
}

void Vec3VarWidget::setToDefault()
{
    x_field->setText(std::to_string(defaultValue.x()).c_str());
    y_field->setText(std::to_string(defaultValue.y()).c_str());
    z_field->setText(std::to_string(defaultValue.z()).c_str());
    emit(valueChanged());
}

Vec4VarWidget::Vec4VarWidget(QString name, float x, float y, float z, float w)
{
    QHBoxLayout *layout = new QHBoxLayout;

    // Keep the same style as the color widget
    QLabel* label = new QLabel( name );
    QFont font = label->font();
    font.setBold( true );
    label->setFont( font );
    layout->addWidget( label );

    QDoubleValidator* validator = new QDoubleValidator();
    x_field = new QLineEdit("0");
    x_field->setValidator(validator);
    layout->addWidget(x_field);
    connect(x_field, SIGNAL(textEdited(const QString&)), this, SLOT(setValue(const QString&)));

    y_field = new QLineEdit("0");
    y_field->setValidator(validator);
    layout->addWidget(y_field);
    connect(y_field, SIGNAL(textEdited(const QString&)), this, SLOT(setValue(const QString&)));

    z_field = new QLineEdit("0");
    z_field->setValidator(validator);
    layout->addWidget(z_field);
    connect(z_field, SIGNAL(textEdited(const QString&)), this, SLOT(setValue(const QString&)));

    w_field = new QLineEdit("0");
    w_field->setValidator(validator);
    layout->addWidget(w_field);
    connect(w_field, SIGNAL(textEdited(const QString&)), this, SLOT(setValue(const QString&)));

    setContentsMargins( 0, 0, 0, 0 );
    layout->setMargin( 1 );
    setSizePolicy( QSizePolicy::Preferred, QSizePolicy::Fixed );

    setLayout(layout);

    value = defaultValue = QVector4D(x, y, z, w);
    setToDefault();
}

Vec4VarWidget::~Vec4VarWidget()
{
}

void Vec4VarWidget::setXValue(const QString& text)
{
    value.setX(std::stof(text.toStdString()));
    emit(valueChanged());
}

void Vec4VarWidget::setYValue(const QString& text)
{
    value.setY(std::stof(text.toStdString()));
    emit(valueChanged());
}

void Vec4VarWidget::setZValue(const QString& text)
{
    value.setZ(std::stof(text.toStdString()));
    emit(valueChanged());
}

void Vec4VarWidget::setWValue(const QString& text)
{
    value.setW(std::stof(text.toStdString()));
    emit(valueChanged());
}


void Vec4VarWidget::setToDefault()
{
    x_field->setText(std::to_string(defaultValue.x()).c_str());
    y_field->setText(std::to_string(defaultValue.y()).c_str());
    z_field->setText(std::to_string(defaultValue.z()).c_str());
    w_field->setText(std::to_string(defaultValue.w()).c_str());
    emit(valueChanged());
}
