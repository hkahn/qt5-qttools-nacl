/****************************************************************************
**
** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the Qt Designer of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "qaxwidgetplugin.h"
#include "qaxwidgetextrainfo.h"
#include "qdesigneraxwidget.h"
#include "qaxwidgetpropertysheet.h"
#include "qaxwidgettaskmenu.h"

#include <QtDesigner/QDesignerFormEditorInterface>
#include <QtDesigner/QDesignerFormWindowInterface>

#include <QtCore/qplugin.h>
#include <QtWidgets/QIcon>
#include <ActiveQt/QAxWidget>

QT_BEGIN_NAMESPACE

QAxWidgetPlugin::QAxWidgetPlugin(QObject *parent) :
    QObject(parent),
    m_core(0)
{
}

QString QAxWidgetPlugin::name() const
{
    return QStringLiteral("QAxWidget");
}

QString QAxWidgetPlugin::group() const
{
    return QStringLiteral("Containers");
}

QString QAxWidgetPlugin::toolTip() const
{
    return tr("ActiveX control");
}

QString QAxWidgetPlugin::whatsThis() const
{
    return tr("ActiveX control widget");
}

QString QAxWidgetPlugin::includeFile() const
{
    return QStringLiteral("qaxwidget.h");
}

QIcon QAxWidgetPlugin::icon() const
{
    return QIcon(QDesignerAxWidget::widgetIcon());
}

bool QAxWidgetPlugin::isContainer() const
{
    return false;
}

QWidget *QAxWidgetPlugin::createWidget(QWidget *parent)
{
    // Construction from Widget box or on a form?
    const bool isFormEditor = parent != 0 && QDesignerFormWindowInterface::findFormWindow(parent) != 0;
    QDesignerAxWidget *rc = new QDesignerAxPluginWidget(parent);
    if (!isFormEditor)
        rc->setDrawFlags(QDesignerAxWidget::DrawFrame|QDesignerAxWidget::DrawControl);
    return rc;
}

bool QAxWidgetPlugin::isInitialized() const
{
    return m_core != 0;
}

void QAxWidgetPlugin::initialize(QDesignerFormEditorInterface *core)
{
    if (m_core != 0)
        return;

    m_core = core;

    QExtensionManager *mgr = core->extensionManager();
    ActiveXPropertySheetFactory::registerExtension(mgr);
    ActiveXTaskMenuFactory::registerExtension(mgr, Q_TYPEID(QDesignerTaskMenuExtension));
    QAxWidgetExtraInfoFactory *extraInfoFactory = new QAxWidgetExtraInfoFactory(core, mgr);
    mgr->registerExtensions(extraInfoFactory, Q_TYPEID(QDesignerExtraInfoExtension));
}

QString QAxWidgetPlugin::domXml() const
{
    return QStringLiteral("\
<ui language=\"c++\">\
    <widget class=\"QAxWidget\" name=\"axWidget\">\
        <property name=\"geometry\">\
            <rect>\
                <x>0</x>\
                <y>0</y>\
                <width>80</width>\
                <height>70</height>\
            </rect>\
        </property>\
    </widget>\
</ui>");
}

Q_EXPORT_PLUGIN(QAxWidgetPlugin)

QT_END_NAMESPACE
