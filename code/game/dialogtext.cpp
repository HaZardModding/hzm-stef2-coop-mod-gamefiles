//-----------------------------------------------------------------------------
//
//  $Logfile:: /red_code/game/dialogtext.cpp                                  $
// $Revision:: 1                                                              $
//   $Author:: Steven                                                         $
//     $Date:: 4/24/01 7:32a                                                  $
//
// Copyright (C) 2001 by Ritual Entertainment, Inc.
// All rights reserved.
//
// This source is may not be distributed and/or modified without
// expressly written permission by Ritual Entertainment, Inc.
//
// $Log:: /red_code/game/dialogtext.cpp                                            $
// 
// 1     4/24/01 7:32a Steven
// Added dialog text.
//
// DESCRIPTION:

#include "dialogtext.h"

//==========================
// DialogText
//==========================

Event EV_DT_Fadetime
	( 
	"dt_fadetime",
	EV_DEFAULT,
   "f",
   "time",
   "Time before fading, in seconds. (default 5)"
	);
Event EV_DT_Fadeoutspeed
	( 
	"dt_fadeoutspeed",
	EV_DEFAULT,
   "f",
   "time",
   "Time for fadeout, in seconds. (default 1)"
	);
Event EV_DT_Fadeinspeed
	( 
	"dt_fadeinspeed",
	EV_DEFAULT,
   "f",
   "time",
   "Time for fadein, in seconds. (default 1)"
	);
Event EV_DT_Position
	( 
	"dt_position",
	EV_DEFAULT,
   "i",
   "position_number",
   "Set position the window appears at. Clockwise from topleft, 1-9. center:10"
	);
Event EV_DT_Clear
	( 
	"dt_clear",
	EV_DEFAULT,
   NULL,
   NULL,
   "Clears the dialog text contents"
	);
Event EV_DT_ResetDialog
	( 
	"dt_resetdialog",
	EV_DEFAULT,
   NULL,
   NULL,
   "Clears text and removes dialog"
	);
Event EV_DT_Size
	( 
	"dt_size",
	EV_DEFAULT,
   "i",
   "size_number",
   "Large: 1, Small: 2"
	);
Event EV_DT_LoadFile
	(
	"dt_loadfile",
	EV_DEFAULT,
	"s",
	"filename",
	"Load a dialog file"
	);
	
DialogText dialogText;

CLASS_DECLARATION (Listener, DialogText, NULL)
	{
		{ &EV_DT_Fadetime,		FadeTime },
		{ &EV_DT_Fadeoutspeed,	FadeOutSpeed },
		{ &EV_DT_Fadeinspeed,	FadeInSpeed },
		{ &EV_DT_Position,		SetPosition },
		{ &EV_DT_Clear,			ClearText },
		{ &EV_DT_ResetDialog,	ResetDialog },
		{ &EV_DT_Size,				SetSize },
		{ &EV_DT_LoadFile,		LoadFile },
		{ NULL, NULL }
	};

DialogText::DialogText()
	{
	dialogEntries = NULL;
	m_fadetime = 1;
	m_fadespeed = 5;
	m_position = 1;
	m_size = 1;
	}

DialogText::~DialogText()
	{
	if ( dialogEntries != NULL )
		ClearEntries();
	}

void DialogText::FadeTime( Event *ev )
	{
	if( ev->NumArgs() >= 1 )
		m_fadetime = ev->GetFloat( 1 );
	else
		warning ( "FadeTime", "Fadetime needs an argument!" );
	
	if ( m_fadetime < 0 )
		{
		warning ( "FadeTime", "Invalid fadetime passed to DialogText!" );
		m_fadetime = 5.0;
		}

	gi.WidgetPrintf( "DialogText", "*fadetime %f", m_fadetime );
}

void DialogText::FadeOutSpeed( Event *ev )
	{
	if( ev->NumArgs() >= 1 )
		m_fadespeed = ev->GetFloat( 1 );
	else
		warning ( "FadeOutSpeed", "FadeOutSpeed needs an argument!" );

	if ( m_fadespeed < 0 )
		{
		warning ( "FadeOutSpeed", "Invalid fadeout speed passed to DialogText!" );
		m_fadespeed = 1.0;
		}

	gi.WidgetPrintf( "DialogText", "*fadespeed %f", m_fadespeed );
}

void DialogText::FadeInSpeed( Event *ev )
	{
	if( ev->NumArgs() >= 1 )
		m_fadeinspeed = ev->GetFloat( 1 );
	else
		warning( "FadeInSpeed", "FadeInSpeed needs an argument!" );

	if( m_fadeinspeed < 0 )
		{
		warning( "FadeInSpeed", "Invalid fadeinspeed passed to DialogText!" );
		m_fadeinspeed = 1.0;
		}

	gi.WidgetPrintf( "DialogText", "*fadeinspeed %f", m_fadeinspeed );
}

void DialogText::SetPosition( Event *ev )
	{
	if ( ev->NumArgs() >= 1 )
		m_position = ev->GetInteger( 1 );
	else
		warning( "SetPosition", "SetPosition needs an argument!" );

	if ( m_position < 1 || m_position > 10 )
		{
		warning ( "Position", "Invalid position passed to DialogText!" );
		m_position = 1;
		}

	gi.WidgetPrintf( "DialogText", "*position %d", m_position );
}

void DialogText::ClearText( Event *ev )
	{
	gi.WidgetPrintf( "DialogText", "*cleartext" );
	}

void DialogText::ResetDialog( Event *ev )
	{
	gi.WidgetPrintf( "DialogText", "*resetdialog" );
	gi.WidgetPrintf( "DialogText", "*cleartext" );
	}

void DialogText::SetSize( Event *ev )
	{
	if( ev->NumArgs() >= 1 )
		m_size = ev->GetInteger( 1 );
	else
		warning( "SetSize", "SetSize needs an argument!" );

	if ( m_size < 1 || m_size > 2 )
		{
		warning( "SetSize", "Invalid size passed to DialogText!" );
		m_position = 1;
		}

	gi.WidgetPrintf( "DialogText", "*size %d", m_position );
	}

void DialogText::LoadFile( Event *ev )
	{
	if ( ev->NumArgs() >= 1 )
		{
		LoadEntries( ev->GetString( 1 ) );
		}
	else
		{
		warning( "LoadFile", "Loadfile needs a filename!" );
		}
	}

void DialogText::LoadEntries( const char *filename )
	{
	char	fixed_filename[MAX_OSPATH];
	char	dialog_filename[MAX_OSPATH];
	char	*data;
	int	i;

	COM_FileName( filename, fixed_filename );

	// Trim out spawnpoint information & movie name

	for ( i = 0 ; i < MAX_OSPATH ; i++ )
		{
		if ( fixed_filename[ i ] == '$' || fixed_filename[ i ] == '#' || fixed_filename[ i ] == '\0' )
			{
			fixed_filename[ i ] = '\0';
			break;
			}
		}

	// Try to read in all versions of this dialog file

	for( i = -1 ; i < 10 ; i++ )
		{
		if ( i < 0 )
			sprintf( dialog_filename, "dialog/%s", fixed_filename );
		else
			sprintf( dialog_filename, "dialog/%s%d", fixed_filename, i );

		COM_DefaultExtension( dialog_filename, MAX_OSPATH, ".dlg" );

		if ( gi.FS_ReadFile( dialog_filename, (void **)&data, qtrue ) != -1 )
			{
			ParseEntryFile( dialog_filename, data );
			gi.FS_FreeFile( data );
			}
		}
	}

void DialogText::ClearEntries( void )
	{
	DialogEntry		*entry, *next;

	entry = dialogEntries;

	while( entry )
		{
		next = entry->GetNext();
		delete entry;
		entry = next;
		}

	dialogEntries = NULL;
	}

void DialogText::PrintDialogText( const char *dialog_name, float dialog_length )
	{
	DialogEntry		*entry;

	entry = dialogEntries;

	while( entry )
		{
		if( !strcmp( entry->GetName(), dialog_name ) )
			break;

		entry = entry->GetNext();
		}

	if ( entry )		// found a match
		{
		gi.WidgetPrintf( "DialogText", "*time %f", dialog_length );
		gi.WidgetPrintf( "DialogText", "%s\n", entry->GetText() );
		}
	else
		{
		warning( "PrintDialogText", "couldn't find dialog text matching %s", dialog_name );
		}
	}

DialogEntry	*DialogText::GetDialogEntry( const char *dialog_name )
	{
	DialogEntry	*entry;

	entry = dialogEntries;

	while( entry )
		{
		if( strcmp( entry->GetName(), dialog_name ) == 0 )
			return entry;

		entry = entry->GetNext();
		}

	return NULL;
	}

void DialogText::ParseEntryFile( char *filename, char *data )
	{
	const char		*ptr, *token;
	char				entryText[MAX_DIALOG_TEXT_LENGTH];
	DialogEntry		*entry;
	qboolean			using_old_entry;

	ptr = data;

	token = COM_GetToken( &ptr, qtrue );

	if ( strcmp( token, "DIALOG" ) )
		error( "ParseEntryFile", "File %s is not a DIALOG file", filename );

	while( *ptr != '\0' )
		{
		token = COM_GetToken( &ptr, qtrue );

		if ( token[0] == '\0' )
			break;

		using_old_entry = qtrue;

		entry = GetDialogEntry( token );

		if ( !entry )
			{
			using_old_entry = qfalse;
			entry = new DialogEntry();
			entry->SetName( token );
			}

		token = (char *)COM_GetToken( &ptr, qtrue );

		if ( token[0] == '\0' )
			error( "ParseEntryFile", "text entry named (%s) has no text entry", entry->GetName() );

		strcpy( entryText, token );

		do
			{
			strcat( entryText, " " );
			token = COM_GetToken( &ptr, qfalse );

			if ( strlen( entryText ) + strlen( token ) >= MAX_DIALOG_TEXT_LENGTH )
				{
				gi.WDPrintf( "Dialog text too long for entry %s\n", entry->GetName() );
				return;
				}

			strcat( entryText, token );
			} while( token[0] != '\0' );

		entry->SetText( entryText );

		if ( !using_old_entry )
			{
			entry->SetNext( dialogEntries );
			dialogEntries = entry;
			}

		if ( ptr == NULL )
			break;
		}

	gi.DPrintf( "Parsed Dialog text file %s\n", filename );
	}

//============================
// DialogEntry
//============================

CLASS_DECLARATION (Class, DialogEntry, NULL)
	{
		{ NULL, NULL }
	};

DialogEntry::DialogEntry ()
	{
	//name = NULL;
	//text = NULL;
	next = NULL;
	}

DialogEntry::~DialogEntry()
	{
	/* if ( name )
		free( name );
	if ( text )
		free( text ); */
	}
