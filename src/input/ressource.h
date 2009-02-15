/*****************************************************************************
 * ressource.h
 *****************************************************************************
 * Copyright (C) 2008 Laurent Aimar
 * $Id$
 *
 * Authors: Laurent Aimar < fenrir _AT_ videolan _DOT_ org >
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
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

#if defined(__PLUGIN__) || defined(__BUILTIN__) || !defined(__LIBVLC__)
# error This header file can only be included from LibVLC.
#endif

#ifndef _INPUT_RESSOURCE_H
#define _INPUT_RESSOURCE_H 1

#include <vlc_common.h>

/**
 * This function creates an empty input_ressource_t.
 */
input_ressource_t *input_ressource_New( void );

/**
 * This function set the associated input.
 */
void input_ressource_SetInput( input_ressource_t *, input_thread_t * );

/**
 * This function handles sout request.
 */
sout_instance_t *input_ressource_RequestSout( input_ressource_t *, sout_instance_t *, const char *psz_sout );

/**
 * This function handles aout request.
 */
aout_instance_t *input_ressource_RequestAout( input_ressource_t *, aout_instance_t * );

/**
 * This function return the current aout if any.
 *
 * You must call vlc_object_release on the value returned (if non NULL).
 */
aout_instance_t *input_ressource_HoldAout( input_ressource_t *p_ressource );

/**
 * This function handles vout request.
 */
vout_thread_t *input_ressource_RequestVout( input_ressource_t *, vout_thread_t *, video_format_t *, bool b_recycle );

/**
 * This function return one of the current vout if any.
 *
 * You must call vlc_object_release on the value returned (if non NULL).
 */
vout_thread_t *input_ressource_HoldVout( input_ressource_t * );

/**
 * This function return all current vouts if any.
 *
 * You must call vlc_object_release on all values returned (if non NULL).
 */
void input_ressource_HoldVouts( input_ressource_t *, vout_thread_t ***, int * );

#endif
