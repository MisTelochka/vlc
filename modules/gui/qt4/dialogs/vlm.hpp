/*****************************************************************************
 * vlm.hpp : VLM Management
 ****************************************************************************
 * Copyright ( C ) 2006 the VideoLAN team
 * $Id$
 *
 * Authors: Jean-François Massol <jf.massol@gmail.com>
 *          Jean-Baptiste Kempf <jb@videolan.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * ( at your option ) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/

#ifndef _VLM_DIALOG_H_
#define _VLM_DIALOG_H_

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include <vlc_common.h>

#ifdef ENABLE_VLM

#include <vlc_vlm.h>

#include "ui/vlm.h"
#include "util/qvlcframe.hpp"
#include <QDateTime>

enum{
    QVLM_Broadcast,
    QVLM_Schedule,
    QVLM_VOD
};

enum{
    ControlBroadcastPlay,
    ControlBroadcastPause,
    ControlBroadcastStop,
    ControlBroadcastSeek
};

class QComboBox;
class QVBoxLayout;
class QStackedWidget;
class QLabel;
class QGridLayout;
class QLineEdit;
class QCheckBox;
class QToolButton;
class QGroupBox;
class QPushButton;
class QHBoxLayout;
class QDateTimeEdit;
class QSpinBox;
class VLMAWidget;
class VLMWrapper;


class VLMDialog : public QVLCDialog
{
    Q_OBJECT;
public:
    static VLMDialog * getInstance( intf_thread_t *p_intf )
    {
        if( !instance)
             instance = new VLMDialog( (QWidget *)p_intf->p_sys->p_mi, p_intf );
        return instance;
    };
    virtual ~VLMDialog();

    VLMWrapper *vlmWrapper;
    vlm_t *p_vlm;
private:
    VLMDialog( QWidget *, intf_thread_t * );
    static VLMDialog *instance;
    Ui::Vlm ui;

    QList<VLMAWidget *> vlmItems;
    int currentIndex;

    QVBoxLayout *vlmItemLayout;
    QWidget *vlmItemWidget;

    QComboBox *mediatype;
    QDateTimeEdit *time, *date, *repeatTime;
    QSpinBox *scherepeatnumber, *repeatDays;
    bool isNameGenuine( QString );
    void mediasPopulator();
public slots:
    void removeVLMItem( VLMAWidget * );
    void startModifyVLMItem( VLMAWidget * );
private slots:
    void addVLMItem();
    void clearWidgets();
    void saveModifications();
    void showScheduleWidget( int );
    void selectVLMItem( int );
    void selectInput();
    void selectOutput();
    bool exportVLMConf();
    bool importVLMConf();
};

class VLMWrapper
{
public:
    VLMWrapper( vlm_t * );
    virtual ~VLMWrapper();

    static void AddBroadcast( const QString, const QString, const QString,
                       bool b_enabled = true,
                       bool b_loop = false );
    static void EditBroadcast( const QString, const QString, const QString,
                       bool b_enabled = true,
                       bool b_loop = false );
    static void EditSchedule( const QString, const QString, const QString,
                       QDateTime _schetime, QDateTime _schedate,
                       int _scherepeatnumber, int _repeatDays,
                       bool b_enabled = true, QString mux = "" );
    static void AddVod( const QString, const QString, const QString,
                       bool b_enabled = true, QString mux = "" );
    static void EditVod( const QString, const QString, const QString,
                       bool b_enabled = true, QString mux = "" );
    static void AddSchedule( const QString, const QString, const QString,
                       QDateTime _schetime, QDateTime _schedate,
                       int _scherepeatnumber, int _repeatDays,
                       bool b_enabled = true, QString mux = "" );

    static void ControlBroadcast( const QString, int, unsigned int seek = 0 );
    static void EnableItem( const QString, bool );

    /* We don't have yet the accessors in the core, so the following is commented */
    //unsigned int NbMedia() { if( p_vlm ) return p_vlm->i_media; return 0; }
   /* vlm_media_t *GetMedia( int i )
    { if( p_vlm ) return p_vlm->media[i]; return NULL; }*/

private:
    static vlm_t *p_vlm;
};

class VLMAWidget : public QGroupBox
{
    Q_OBJECT
    friend class VLMDialog;
public:
    VLMAWidget( QString name, QString input, QString output,
            bool _enable, VLMDialog *parent, int _type = QVLM_Broadcast );
    virtual void update() = 0;
protected:
    QLabel *nameLabel;
    QString name;
    QString input;
    QString output;
    bool b_enabled;
    int type;
    VLMDialog *parent;
    QGridLayout *objLayout;
private slots:
    virtual void modify();
    virtual void del();
    virtual void toggleEnabled( bool );
};

class VLMBroadcast : public VLMAWidget
{
    Q_OBJECT
    friend class VLMDialog;
public:
    VLMBroadcast( QString name, QString input, QString output,
            bool _enable, bool _loop, VLMDialog *parent );
    void update();
private:
    bool b_looped;
    bool b_playing;
    QToolButton *loopButton, *playButton;
private slots:
    void stop();
    void togglePlayPause();
    void toggleLoop();
};

class VLMVod : public VLMAWidget
{
    Q_OBJECT
    friend class VLMDialog;
public:
    VLMVod( QString name, QString input, QString output,
            bool _enable, QString _mux, VLMDialog *parent );
    void update();
private:
    QString mux;
    QLabel *muxLabel;
};

class VLMSchedule : public VLMAWidget
{
    Q_OBJECT
    friend class VLMDialog;
public:
    VLMSchedule( QString name, QString input, QString output,
            QDateTime schetime, QDateTime schedate, int repeatnumber,
            int repeatdays, bool enabled, VLMDialog *parent );
    void update();
private:
    QDateTime schetime;
    QDateTime schedate;
    int rNumber;
    int rDays;
};

#endif

#endif

