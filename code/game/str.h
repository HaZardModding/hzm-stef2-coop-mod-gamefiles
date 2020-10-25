//-----------------------------------------------------------------------------
//
//  $Logfile:: /EF2/game/str.h                                               $
// $Revision:: 6                                                              $
//   $Author:: Steven                                                         $
//     $Date:: 8/30/01 5:36p                                                  $
//
// Copyright (C) 1997 by Ritual Entertainment, Inc.
// All rights reserved.
//
// This source is may not be distributed and/or modified without
// expressly written permission by Ritual Entertainment, Inc.
//
// $Log:: /EF2/game/str.h                                                    $
// 
// 6     8/30/01 5:36p Steven
// Lots of fixes to strings.
// 
// 5     1/16/01 2:12p Steven
// Script C merge.
//
// 15    7/25/00 11:32p Aldie
// Made some changes to the memory system and fixed a memory allocation bug in
// Z_TagMalloc.  Also changed a lot of classes to subclass from Class.
//
// 14    6/14/00 3:57p Markd
// fixed bug
//
// 13    6/14/00 3:50p Markd
// Cleaned up more Intel Compiler warnings
//
// 12    6/14/00 11:18a Markd
// cleaned up code using Intel compiler
//
// 11    5/25/00 4:29p Markd
// made archive a friend class of strings
//
// 10    3/22/00 3:23p Jimdose
// moved len from str to strdata
//
// 9     3/21/00 2:44p Jimdose
// fixed a bug where assigning the string to itself would corrupt the object
//
// 8     3/17/00 3:44p Markd
// added float, int and unsigned constructors
//
// 7     10/28/99 12:17p Morbid
// Fixed various const-ness issues with the compare functions
//
// 6     10/06/99 10:01a Markd
// Fixed compiler warnings
//
// 5     10/05/99 2:03p Markd
// Added warning about files being in multiple projects
//
// 4     9/29/99 4:38p Morbid
// Added snprintf
//
// 3     9/24/99 1:55p Morbid
// Strings from Uber
//
// 2     9/24/99 11:03a Morbid
// Added CapLength ()
//
// 1     9/10/99 10:55a Jimdose
//
// 1     9/08/99 3:16p Aldie
//
// DESCRIPTION:
// Simple, DLL portable string class
//
// WARNING: This file is shared between game, cgame and possibly the user interface.
// It is instanced in each one of these directories because of the way that SourceSafe works.
//

#ifndef __STR_H__
#define __STR_H__

#include <assert.h>
#include <string.h>
#include <stdio.h>

#ifdef _WIN32
#pragma warning(disable : 4710)     // function 'blah' not inlined
#endif

#define STRING_PREALLOC_SIZE 32

void TestStringClass ();

#if 1
class __declspec( dllexport ) str
#else
class str : public Class
#endif
	{
	protected:

		char *data;
		char buffer[ STRING_PREALLOC_SIZE ];
      int alloced;
      int len;

      void              EnsureAlloced ( int, bool keepold = true );

  	public:
								~str();
								str();
								str( const char *text );
								str( const str& string );
								str( const str string, int start, int end );
								str( const char ch );
                        str( const int num );
								str( const float num );
								str( const unsigned num );


					int		length( void ) const;
		const		char *	c_str( void ) const;

					void		append( const char *text );
					void		append( const str& text );

					char		operator[]( int index ) const;
					char&		operator[]( int index );

					void		operator=( const str& text );
					void		operator=( const char *text );

		friend	str		operator+( const str& a, const str& b );
		friend	str		operator+( const str& a, const char *b );
		friend	str		operator+( const char *a, const str& b );

      friend	str		operator+( const str& a, const float b );
      friend	str		operator+( const str& a, const int b );
      friend	str		operator+( const str& a, const unsigned b );
      friend	str		operator+( const str& a, const bool b );
      friend	str		operator+( const str& a, const char b );

					str&		operator+=( const str& a );
					str&		operator+=( const char *a );
					str&		operator+=( const float a );
					str&		operator+=( const char a );
					str&		operator+=( const int a );
					str&		operator+=( const unsigned a );
					str&		operator+=( const bool a );

		friend	bool		operator==(	const str& a, const str& b );
		friend	bool		operator==(	const str& a, const char *b );
		friend	bool		operator==(	const char *a, const str& b );

		friend	bool		operator!=(	const str& a, const str& b );
		friend	bool		operator!=(	const str& a, const char *b );
		friend	bool		operator!=(	const char *a, const str& b );

                        operator const char * () const;

               int      icmpn( const char *text, int n ) const;
               int      icmpn( const str& text, int n ) const;
               int      icmp( const char *text ) const;
               int      icmp( const str& text ) const;
               int      cmpn( const char *text, int n ) const;
               int      cmpn( const str& text, int n ) const;
					int      cmp( const char *text ) const;
               int      cmp( const str& text ) const;

               void     tolower( void );
               void     toupper( void );

      static   char     *tolower( char *s1 );
      static   char     *toupper( char *s1 );

      static   int      icmpn( const char *s1, const char *s2, int n );
      static   int      icmp( const char *s1, const char *s2 );
      static   int      cmpn( const char *s1, const char *s2, int n );
      static   int      cmp( const char *s1, const char *s2 );

      static   void     snprintf ( char *dst, int size, const char *fmt, ... );

      static   bool	   isNumeric( const char *str );
               bool	   isNumeric( void ) const;

               void     CapLength ( int );

               void     BackSlashesToSlashes ();
   };


inline char str::operator[]( int index ) const
	{
   assert ( data );

   if ( !data )
      return 0;

	// don't include the '/0' in the test, because technically, it's out of bounds
	assert( ( index >= 0 ) && ( index < len ) );

	// In release mode, give them a null character
	// don't include the '/0' in the test, because technically, it's out of bounds
	if ( ( index < 0 ) || ( index >= len ) )
		{
		return 0;
		}

	return data[ index ];
	}

inline int str::length( void ) const
	{
   return len;
	}

inline str::~str()
	{
	if ( data != buffer )
		delete [] data;
	}

inline str::str()
	{
	data = buffer;
	alloced = STRING_PREALLOC_SIZE;
	data[ 0 ] = 0;
	len = 0;
	}

inline str::str
	(
	const char *text
   )

	{
   int length;

	assert( text );

	data = buffer;
	alloced = STRING_PREALLOC_SIZE;
	data[ 0 ] = 0;
	len = 0;

	if ( text )
		{
      length = strlen( text );
		EnsureAlloced ( length + 1 );
		strcpy( data, text );
      len = length;
		}
	}

inline str::str
	(
	const str& text
   )

	{
	data = buffer;
	alloced = STRING_PREALLOC_SIZE;
	data[ 0 ] = 0;
	len = 0;

	EnsureAlloced ( text.length() + 1);
	strcpy( data, text.c_str() );
   len = text.length();
   }

inline str::str
	(
	const str text,
	int start,
	int end
   )

	{
	int i;
   int length;

	data = buffer;
	alloced = STRING_PREALLOC_SIZE;
	data[ 0 ] = 0;
	len = 0;

	if ( end > text.length() )
		{
		end = text.length();
		}

	if ( start > text.length() )
		{
		start = text.length();
		}

	length = end - start;
	if ( length < 0 )
		{
		length = 0;
		}

   EnsureAlloced ( length + 1 );

	for( i = 0; i < length; i++ )
		{
		data[ i ] = text[ start + i ];
		}

	data[ length ] = 0;
   len = length;
	}

inline str::str
   (
   const char ch
   )

   {
	data = buffer;
	alloced = STRING_PREALLOC_SIZE;

   EnsureAlloced ( 2 );

   data[ 0 ] = ch;
   data[ 1 ] = 0;
   len = 1;
   }

inline str::str
   (
   const float num
   )

   {
   char text[ 32 ];
   int length;

	data = buffer;
	alloced = STRING_PREALLOC_SIZE;

   sprintf( text, "%.3f", num );
   length = strlen( text );
   EnsureAlloced( length + 1 );
   strcpy( data, text );
   len = length;
   }

inline str::str
   (
   const int num
   )

   {
   char text[ 32 ];
   int length;

	data = buffer;
	alloced = STRING_PREALLOC_SIZE;

   sprintf( text, "%d", num );
   length = strlen( text );
   EnsureAlloced( length + 1 );
   strcpy( data, text );
   len = length;
   }

inline str::str
   (
   const unsigned num
   )

   {
   char text[ 32 ];
   int length;

	data = buffer;
	alloced = STRING_PREALLOC_SIZE;

   sprintf( text, "%u", num );
   length = strlen( text );
   EnsureAlloced( length + 1 );
   strcpy( data, text );
   len = length;
   }

inline const char *str::c_str( void ) const
	{
	assert( data );

	return data;
	}

inline void str::append
	(
	const char *text
	)

	{
   int new_length;

	assert( text );

	if ( text )
		{
		new_length = length();
		new_length += strlen( text );
		EnsureAlloced( new_length + 1 );

      strcat( data, text );
      len = new_length;
		}
	}

inline void str::append
	(
	const str& text
	)

	{
   int new_length;

   new_length = length();
   new_length += text.length();
   EnsureAlloced ( new_length + 1 );

   strcat ( data, text.c_str () );
   len = new_length;
	}


inline char& str::operator[]
	(
	int index
	)

	{
	// Used for result for invalid indices
	static char dummy = 0;
   assert ( data );

   if ( !data )
      return dummy;

	// don't include the '/0' in the test, because technically, it's out of bounds
	assert( ( index >= 0 ) && ( index < len ) );

	// In release mode, let them change a safe variable
	// don't include the '/0' in the test, because technically, it's out of bounds
	if ( ( index < 0 ) || ( index >= len ) )
		{
		return dummy;
		}

	return data[ index ];
	}

inline void str::operator=
	(
	const str& text
	)

	{
   EnsureAlloced ( text.length() + 1, false );
	strcpy( data, text.c_str() );
   len = text.length();
   }

inline void str::operator=
	(
	const char *text
	)

	{
   int length;

	assert( text );

	if ( !text )
		{
		// safe behaviour if NULL
		EnsureAlloced ( 1, false );
      data[0] = 0;
      len = 0;
      return;
		}

   if ( text == data )
      return; // Copying same thing.  Punt.

   // Now we need to check if we're aliasing..

   if ( text >= data && text <= data + len )
      {
      // Great, we're aliasing.  We're copying from inside ourselves.
      // This means that I don't have to ensure that anything is alloced,
      // though I'll assert just in case.
      int diff = text - data;
      int i;

      assert ( strlen ( text ) < (unsigned) len );

      for ( i = 0; text[i]; i++ )
         {
         data[i] = text[i];
         }

      data[i] = 0;

      len -= diff;

      return;
      }

	length = strlen( text );
   EnsureAlloced ( length + 1, false );
	strcpy( data, text );
   len = length;
	}

inline str operator+
	(
	const str& a,
	const str& b
	)

	{
	str result( a );

	result.append( b );

	return result;
	}

inline str operator+
	(
	const str& a,
	const char *b
	)

	{
	str result( a );

	result.append( b );

	return result;
	}

inline str operator+
	(
	const char *a,
	const str& b
	)

	{
	str result( a );

	result.append( b );

	return result;
	}

inline str operator+
   (
   const str& a,
   const bool b
   )

   {
	str result( a );

   result.append( b ? "true" : "false" );

	return result;
   }

inline str operator+
	(
   const str& a,
	const char b
	)

	{
   char text[ 2 ];

   text[ 0 ] = b;
   text[ 1 ] = 0;

	return a + text;
	}

inline str& str::operator+=
	(
	const str& a
	)

	{
	append( a );
	return *this;
	}

inline str& str::operator+=
	(
	const char *a
	)

	{
	append( a );
	return *this;
	}

inline str& str::operator+=
	(
	const char a
	)

	{
   char text[ 2 ];

   text[ 0 ] = a;
   text[ 1 ] = 0;
	append( text );

   return *this;
	}

inline str& str::operator+=
	(
	const bool a
	)

	{
   append( a ? "true" : "false" );
	return *this;
	}

inline bool operator==
	(
	const str& a,
	const str& b
	)

	{
	return ( !strcmp( a.c_str(), b.c_str() ) );
	}

inline bool operator==
	(
	const str& a,
	const char *b
	)

	{
	assert( b );
	if ( !b )
		{
		return false;
		}
	return ( !strcmp( a.c_str(), b ) );
	}

inline bool operator==
	(
	const char *a,
	const str& b
	)

	{
	assert( a );
	if ( !a )
		{
		return false;
		}
	return ( !strcmp( a, b.c_str() ) );
	}

inline bool operator!=
	(
	const str& a,
	const str& b
	)

	{
	return !( a == b );
	}

inline bool operator!=
	(
	const str& a,
	const char *b
	)

	{
	return !( a == b );
	}

inline bool operator!=
	(
	const char *a,
	const str& b
	)

	{
	return !( a == b );
	}

inline int str::icmpn
   (
   const char *text,
   int n
   ) const

   {
	assert( data );
	assert( text );

   return str::icmpn( data, text, n );
   }

inline int str::icmpn
   (
   const str& text,
   int n
   ) const

   {
	assert( data );
	assert( text.data );

   return str::icmpn( data, text.data, n );
   }

inline int str::icmp
   (
   const char *text
   ) const

   {
	assert( data );
	assert( text );

   return str::icmp( data, text );
   }

inline int str::icmp
   (
   const str& text
   ) const

   {
	assert( c_str () );
	assert( text.c_str () );

   return str::icmp( c_str () , text.c_str () );
   }

inline int str::cmp
   (
   const char *text
   ) const

   {
	assert( data );
	assert( text );

   return str::cmp( data, text );
   }

inline int str::cmp
   (
   const str& text
   ) const

   {
	assert( c_str () );
	assert( text.c_str () );

   return str::cmp( c_str () , text.c_str () );
   }

inline int str::cmpn
   (
   const char *text,
   int n
   ) const

   {
	assert( c_str () );
	assert( text );

   return str::cmpn( c_str () , text, n );
   }

inline int str::cmpn
   (
   const str& text,
   int n
   ) const

   {
	assert( c_str () );
	assert( text.c_str ()  );

   return str::cmpn( c_str () , text.c_str () , n );
   }

inline void str::tolower
   (
   void
   )

   {
   assert( data );

   str::tolower( data );
   }

inline void str::toupper
   (
   void
   )

   {
   assert( data );

   str::toupper( data );
   }

inline bool str::isNumeric
   (
   void
   ) const

   {
   assert( data );
   return str::isNumeric( data );
   }

inline str::operator const char *
   (
   void
   ) const

   {
   return c_str ();
   }

#endif