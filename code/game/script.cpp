//-----------------------------------------------------------------------------
//
//  $Logfile:: /red_code/game/script.cpp                                     $
// $Revision:: 4                                                              $
//   $Author:: Sketcher                                                       $
//     $Date:: 12/20/00 2:46p                                                 $
//
// Copyright (C) 1997 by Ritual Entertainment, Inc.
// All rights reserved.
//
// This source is may not be distributed and/or modified without
// expressly written permission by Ritual Entertainment, Inc.
//
// $Log:: /red_code/game/script.cpp                                          $
// 
// 4     12/20/00 2:46p Sketcher
// Removed AtComma() since it proved to be useless
// 
// 3     12/05/00 1:41p Sketcher
// Fixed a weak-lame-"$" conflict with scripts and my new define/include code
// 
// 2     12/04/00 10:21a Sketcher
// Added Additional functionality to the StateMachine - Can use $include and
// $define
//
// 4     1/10/00 5:30p Markd
// Replaced TagMalloc and TagFree with Malloc and Free
//
// 3     12/13/99 10:46a Markd
// incremental merge fix
//
// 2     12/13/99 10:16a Markd
// incremental checkin for bad files
//
// 1     9/10/99 10:54a Jimdose
//
// 1     9/08/99 3:16p Aldie
//
// 5     8/17/99 5:08p Markd
// Changed all FS_ReadFile's to FS_ReadFileEx's in game code
//
// DESCRIPTION:
// C++ implementaion of tokenizing text interpretation.  Class accepts filename
// to load or pointer to preloaded text data.  Standard tokenizing operations
// such as skip white-space, get string, get integer, get float, get token,
// and skip line are implemented.
//
// Note: all '//', '#', and ';' are treated as comments.  Probably should
// make this behaviour toggleable.
//

#include "g_local.h"
#include "script.h"

#define TOKENCOMMENT      (';')
#define TOKENCOMMENT2     ('#')
#define TOKENEOL          ('\n')
#define TOKENNULL         ('\0')
#define TOKENSPACE        (' ')
#define TOKENSPECIAL	     ('$')

CLASS_DECLARATION( Class, Script, NULL )
	{
		{ NULL, NULL }
	};

Script::~Script()
	{
	Close();
	}

Script::Script()
	{
	buffer			= NULL;
	script_p			= NULL;
	end_p				= NULL;
	line				= 0;
	releaseBuffer	= false;
	tokenready		= false;
	memset( token, 0, sizeof( token ) );
	}

void Script::Close
	(
	void
	)

	{
	if ( releaseBuffer && buffer )
		{
		gi.Free( ( void * )buffer );
		}

	buffer			= NULL;
	script_p			= NULL;
	end_p				= NULL;
	line				= 0;
	releaseBuffer	= false;
	tokenready		= false;
	memset( token, 0, sizeof( token ) );

	//Loop Through the macro container and delete (del33t -hehe) them all
	for( int i = 1; i <= macrolist.NumObjects(); i++)
		{
		if (macrolist.ObjectAt( i ) )
			{
			delete macrolist.ObjectAt( i );
			macrolist.ObjectAt( i ) = 0;
			}
		
		}

	}

/*
==============
=
= Filename
=
==============
*/

const char *Script::Filename
	(
	void
	)

	{
	return filename.c_str();
	}

/*
==============
=
= GetLineNumber
=
==============
*/

int Script::GetLineNumber
	(
	void
	)

	{
	return line;
	}

/*
==============
=
= Reset
=
==============
*/

void Script::Reset
	(
	void
	)

	{
	script_p = buffer;
	line = 1;
	tokenready = false;
	}

/*
==============
=
= MarkPosition
=
==============
*/

void Script::MarkPosition
	(
	scriptmarker_t *mark
	)

	{
	assert( mark );

	mark->tokenready = tokenready;
	mark->offset     = script_p - buffer;
	mark->line		  = line;
	strcpy( mark->token, token );
	}

/*
==============
=
= RestorePosition
=
==============
*/

void Script::RestorePosition
	(
	scriptmarker_t *mark
	)

	{
	assert( mark );

	tokenready	= mark->tokenready;
	script_p		= buffer + mark->offset;
	line			= mark->line;
	strcpy( token, mark->token );

   assert( script_p <= end_p );
   if ( script_p > end_p )
      {
      script_p = end_p;
      }
	}

/*
==============
=
= SkipToEOL
=
==============
*/

qboolean Script::SkipToEOL
	(
	void
	)

	{
	if ( script_p >= end_p )
		{
		return true;
		}

	while( *script_p != TOKENEOL )
		{
		if ( script_p >= end_p )
			{
			return true;
			}
		script_p++;
		}
	return false;
	}

/*
==============
=
= CheckOverflow
=
==============
*/

void Script::CheckOverflow
	(
	void
	)

	{
	if ( script_p >= end_p )
		{
		gi.Error( ERR_DROP, "End of token file reached prematurely reading %s\n", filename.c_str() );
		}
	}

/*
==============
=
= SkipWhiteSpace
=
==============
*/

void Script::SkipWhiteSpace
	(
	qboolean crossline
	)

	{
	//
	// skip space
	//
	CheckOverflow();

	while( *script_p <= TOKENSPACE )
		{
		if ( *script_p++ == TOKENEOL )
			{
			if ( !crossline )
				{
				gi.Error( ERR_DROP, "Line %i is incomplete in file %s\n", line, filename.c_str() );
				}

			line++;
			}
		CheckOverflow();
		}
	}

qboolean Script::AtComment
	(
	void
	)

	{
	if ( script_p >= end_p )
		{
		return false;
		}

	if ( *script_p == TOKENCOMMENT )
		{
		return true;
		}

	if ( *script_p == TOKENCOMMENT2 )
		{
		return true;
		}

	// Two or more character comment specifiers
	if ( ( script_p + 1 ) >= end_p )
		{
		return false;
		}

	if ( ( *script_p == '/' ) && ( *( script_p + 1 ) == '/' ) )
		{
		return true;
		}

	return false;
	}

/*
==============
=
= SkipNonToken
=
==============
*/

void Script::SkipNonToken
	(
	qboolean crossline
	)

	{
	//
	// skip space and comments
	//
	SkipWhiteSpace( crossline );
	while( AtComment() )
		{
		SkipToEOL();
		SkipWhiteSpace( crossline );
		}
	}

/*
=============================================================================
=
= Token section
=
=============================================================================
*/

/*
==============
=
= TokenAvailable
=
==============
*/

qboolean Script::TokenAvailable
	(
	qboolean crossline
	)

	{
	if ( script_p >= end_p )
		{
		return false;
		}

	while ( 1 )
		{
		while ( *script_p <= TOKENSPACE )
			{
			if ( *script_p == TOKENEOL )
				{
				if ( crossline==false )
					{
					return( false );
					}
				line++;
				}

			script_p++;
			if ( script_p >= end_p )
				{
				return false;
				}
			}

		if ( AtComment() )
			{
			qboolean done;

			done = SkipToEOL();
			if ( done )
				{
				return false;
				}
			}
		else
			{
			break;
			}
		}

	return true;
	}

/*
==============
=
= CommentAvailable
=
==============
*/

qboolean Script::CommentAvailable
	(
	qboolean crossline
	)

	{
	const char *searchptr;

	searchptr = script_p;

	if ( searchptr >= end_p )
		{
		return false;
		}

	while ( *searchptr <= TOKENSPACE )
		{
		if ( ( *searchptr == TOKENEOL ) && ( !crossline ) )
			{
			return false;
			}
		searchptr++;
		if ( searchptr >= end_p )
			{
			return false;
			}
		}

	return true;
	}


/*
==============
=
= UnGet
=
= Signals that the current token was not used, and should be reported
= for the next GetToken.  Note that

GetToken (true);
UnGetToken ();
GetToken (false);

= could cross a line boundary.
=
==============
*/

void Script::UnGetToken
	(
	void
	)

	{
	tokenready = true;
	}

/*
==============
=
= Get
=
==============
*/
qboolean Script::AtString
	(
	qboolean crossline
	)

	{
	//
	// skip space
	//
	SkipNonToken( crossline );

	return ( *script_p == '"' );
	}

qboolean Script::AtOpenParen
	(
	qboolean crossline 
	)

	{
	//
	// skip space
	//
	SkipNonToken( crossline );
	
	return ( *script_p == '(' );	
	}

qboolean Script::AtCloseParen
	(
	qboolean crossline 
	)

	{
	//
	// skip space
	//
	SkipNonToken( crossline );
	
	return ( *script_p == ')' );	
	}

/*
==============
=
= Get
=
==============
*/

const char *Script::GetToken
	(
	qboolean crossline
	)

	{
	
	str		 token_p = token;
	qboolean	 is_Macro = false;

	// is a token already waiting?
	if ( tokenready )
		{
		tokenready = false;
		return token;
		}

	is_Macro = isMacro();

	token_p = GrabNextToken(crossline);

	if(is_Macro && token_p != "$include")
		{
		
		//Check to see if we need to add any definitions
		while (token_p == "$define" || token_p == "$Define" )
			{
			AddMacroDefinition(crossline);
			is_Macro = isMacro();
			token_p = GrabNextToken(crossline);			
			}
			
			//Check to see if we need return any defines strings
			if( is_Macro && token_p != "$include" && token_p[token_p.length() - 1] == '$')
				{
				return GetMacroString(token_p);
				}		

		}
	
	
	return token;
	}

/*
==============
=
= GrabNextToken
=
==============
*/
const char *Script::GrabNextToken
	(
	qboolean crossline
	)

	{
	char *token_p;

	//
	// skip space
	//
	SkipNonToken( crossline );
	
	//
	// copy token
	//
	if ( *script_p == '"' )
		{
		return GetString( crossline );
		}
	
	token_p = token;
	while( *script_p > TOKENSPACE && !AtComment() )
		{
		if ( ( *script_p == '\\' ) && ( script_p < end_p - 1 ) )
			{
			script_p++;
			switch( *script_p )
				{
				case 'n' :	*token_p++ = '\n'; break;
				case 'r' :	*token_p++ = '\n'; break;
				case '\'' : *token_p++ = '\''; break;
				case '\"' : *token_p++ = '\"'; break;
				case '\\' : *token_p++ = '\\'; break;
				default:		*token_p++ = *script_p; break;
				}
			script_p++;
			}
		else
			{
			*token_p++ = *script_p++;
			}

		if ( token_p == &token[ MAXTOKEN ] )
			{
			gi.Error( ERR_DROP, "Token too large on line %i in file %s\n", line, filename.c_str() );
			}

		if ( script_p == end_p )
			{
			break;
			}
		}


	*token_p = 0;

	return token;
	}

/*
==============
=
= AddMacroDefinition
=
==============
*/
void Script::AddMacroDefinition
	(
	qboolean crossline
	)

	{
	macro      *theMacro;
	
	//Create a new macro structure.  This new macro will be deleted in the script close()
	theMacro = new macro;

	//Grab the macro name
	theMacro->macroName = '$';
	theMacro->macroName.append(GrabNextToken(crossline));
	theMacro->macroName.append('$'); //<-- Adding closing ($) to keep formatting consistant

	//Grab the macro string
	theMacro->macroText = GrabNextToken(crossline);

	macrolist.AddObject( theMacro );

	}

/*
==============
=
= GetMacroString
=
==============
*/
const char *Script::GetMacroString
	(
	const char *theMacroName
	)

	{
   
	macro *theMacro =0; //Initialize this puppy
		
	for( int i = 1; i <= macrolist.NumObjects(); i++)
		{
		theMacro = macrolist.ObjectAt( i );

		if(!theMacro->macroName.cmp(theMacro->macroName.c_str(), theMacroName))
			{
			return theMacro->macroText;
			}

		}

	//Crap in a hat -- We didn't find what we were looking for -- We need to bitch.
	gi.Error( ERR_DROP, "No Macro Text found for %s in file %s\n", *theMacroName, filename.c_str() );
	return 0;
	
	}

/*
==============
=
= isMacro
=
==============
*/
qboolean Script::isMacro
	(
	void
	)

	{
	
	SkipNonToken( true );
	if ( *script_p == TOKENSPECIAL )
		{
		return true;
		}

	return false;
	}

/*
==============
=
= GetLine
=
==============
*/

const char *Script::GetLine
	(
	qboolean crossline
	)

	{
	const char	*start;
	int			size;

	// is a token already waiting?
	if ( tokenready )
		{
		tokenready = false;
		return token;
		}

	//
	// skip space
	//
	SkipNonToken( crossline );

	//
	// copy token
	//
   start = script_p;
   SkipToEOL();
   size = script_p - start;
   if ( size < MAXTOKEN - 1 )
		{
		memcpy( token, start, size );
		token[ size ] = '\0';
		}
	else
		{
		gi.Error( ERR_DROP, "Token too large on line %i in file %s\n", line, filename.c_str() );
		}

	return token;
	}

/*
==============
=
= GetRaw
=
==============
*/

const char *Script::GetRaw
	(
	void
	)

	{
	const char	*start;
	int			size;

	//
	// skip white space
	//
	SkipWhiteSpace( true );

	//
	// copy token
	//
	start = script_p;
	SkipToEOL();
	size = script_p - start;
	if ( size < MAXTOKEN - 1 )
		{
		memset( token, 0, sizeof( token ) );
		memcpy( token, start, size );
		}
	else
		{
		gi.Error( ERR_DROP, "Token too large on line %i in file %s\n", line, filename.c_str() );
		}

	return token;
	}

/*
==============
=
= GetString
=
==============
*/

const char *Script::GetString
	(
	qboolean crossline
	)

	{
	int startline;
	char *token_p;

	// is a token already waiting?
	if ( tokenready )
		{
		tokenready = false;
		return token;
		}

	//
	// skip space
	//
	SkipNonToken( crossline );

	if ( *script_p != '"' )
		{
		gi.Error( ERR_DROP, "Expecting string on line %i in file %s\n", line, filename.c_str() );
		}

	script_p++;

	startline = line;
	token_p = token;
	while( *script_p != '"' )
		{
		if ( *script_p == TOKENEOL )
			{
			gi.Error( ERR_DROP, "Line %i is incomplete while reading string in file %s\n", line, filename.c_str() );
			}

		if ( ( *script_p == '\\' ) && ( script_p < end_p - 1 ) )
			{
			script_p++;
			switch( *script_p )
				{
				case 'n' :	*token_p++ = '\n'; break;
				case 'r' :	*token_p++ = '\n'; break;
				case '\'' : *token_p++ = '\''; break;
				case '\"' : *token_p++ = '\"'; break;
				case '\\' : *token_p++ = '\\'; break;
				default:		*token_p++ = *script_p; break;
				}
			script_p++;
			}
		else
			{
			*token_p++ = *script_p++;
			}

		if ( script_p >= end_p )
			{
			gi.Error( ERR_DROP, "End of token file reached prematurely while reading string on\n"
				"line %d in file %s\n", startline, filename.c_str() );
			}

		if ( token_p == &token[ MAXTOKEN ] )
			{
			gi.Error( ERR_DROP, "String too large on line %i in file %s\n", line, filename.c_str() );
			}
		}

	*token_p = 0;

	// skip last quote
	script_p++;

	return token;
	}


/*
==============
=
= GetSpecific
=
==============
*/

qboolean Script::GetSpecific
	(
	const char *string
	)

	{
	do
		{
		if ( !TokenAvailable( true ) )
			{
			return false;
			}
		GetToken( true );
		}
	while( strcmp( token, string ) );

	return true;
	}

/*
==============
=
= GetInteger
=
==============
*/

int Script::GetInteger
	(
	qboolean crossline
	)

	{
	GetToken( crossline );
	return atoi( token );
	}

/*
==============
=
= GetDouble
=
==============
*/

double Script::GetDouble
	(
	qboolean crossline
	)

	{
	GetToken( crossline );
	return atof( token );
	}

/*
==============
=
= GetFloat
=
==============
*/

float Script::GetFloat
	(
	qboolean crossline
	)

	{
	return ( float )GetDouble( crossline );
	}

/*
==============
=
= GetVector
=
==============
*/

Vector Script::GetVector
	(
	qboolean crossline
	)

	{
	return Vector( GetFloat( crossline ), GetFloat( crossline ), GetFloat( crossline ) );
	}

/*
===================
=
= LinesInFile
=
===================
*/
int Script::LinesInFile
	(
	void
	)

	{
	qboolean		temp_tokenready;
	const char	*temp_script_p;
	int			temp_line;
	char			temp_token[ MAXTOKEN ];
	int			numentries;

	temp_tokenready = tokenready;
	temp_script_p	= script_p;
	temp_line		= line;
	strcpy( temp_token, token );

	numentries = 0;

	Reset();
	while( TokenAvailable( true ) )
		{
		GetLine( true );
		numentries++;
		}

	tokenready	= temp_tokenready;
	script_p	= temp_script_p;
	line		= temp_line;
	strcpy( token, temp_token );

	return numentries;
	}

/*
==============
=
= Parse
=
==============
*/

void Script::Parse
	(
	const char *data,
	int length,
	const char *name
	)

	{
	Close();

	buffer = data;
	Reset();
	end_p = script_p + length;
	this->length = length;
	filename = name;
	}

/*
==============
=
= Load
=
==============
*/

void Script::LoadFile
	(
	const char *name
	)

	{
	int			length;
	byte        *buffer;
	byte        *tempbuf;
	const char  *const_buffer;

	Close();

   length = gi.FS_ReadFile( name, ( void ** )&tempbuf, qtrue );
	if ( length < 0 )
		{
		error( "LoadFile", "Couldn't load %s\n", name );
		}
   // create our own space
   buffer = ( byte * )gi.Malloc( length );
   // copy the file over to our space
   memcpy( buffer, tempbuf, length );
   // free the file
   gi.FS_FreeFile( tempbuf );

   const_buffer = ( char * )buffer;

	Parse( const_buffer, length, name );
	releaseBuffer = true;
	}

const char *Script::Token
	(
	void
	)

	{
	return token;
	}