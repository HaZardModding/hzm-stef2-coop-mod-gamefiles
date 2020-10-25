// r_dialog.h
// pmack
// feb 2000

#ifndef __DIALOGTEXT_H__
#define __DIALOGTEXT_H__

#include "g_local.h"

#define MAX_TEXT_ENTRY_FILES	8
#define MAX_DIALOG_TEXT_LENGTH  4096

//======================================
//======================================

class DialogEntry;

class DialogEntry : public Class
{
	private:
		str			name;
		str			text;
		//char			*name;
		//char			*text;
		DialogEntry	*next;

	public:
		CLASS_PROTOTYPE( DialogEntry );

					DialogEntry();
					~DialogEntry();
		void		SetName(const char *);
		const char *	GetName();
		void		SetText(const char *);
		const char *	GetText();

		DialogEntry	*GetNext();
		void		SetNext(DialogEntry *);
};

inline DialogEntry * DialogEntry::GetNext()
	{
	return next;
	}

inline void DialogEntry::SetNext(DialogEntry *newNext)
	{
	next = newNext;
	}

inline void DialogEntry::SetName(const char *newName)
	{
	/* if(name)
		free(name);

	name = (char *)malloc(strlen(newName) + 1);

	if(name)
		{
		strcpy(name, newName);
		} */

	name = newName;
	}

inline const char * DialogEntry::GetName()
	{
	return name.c_str();
	}

inline void DialogEntry::SetText( const char *newText )
	{
	/* if(text)
		free(text);

	text = (char *)malloc(strlen(newText) + 1);
	if(text)
	{
		strcpy(text, newText);
	} */

	text = newText;
	}

inline const char * DialogEntry::GetText()
	{
	return text.c_str();
	}

//======================================
//======================================

class DialogText : public Listener
{
	private:
		DialogEntry		*dialogEntries;
		float				m_fadetime;
		float				m_fadespeed;
		float				m_fadeinspeed;
		int				m_position;
		int				m_size;

	public:
		CLASS_PROTOTYPE( DialogText );

					DialogText();
		virtual	~DialogText();

		void		FadeTime (Event *);
		void		FadeOutSpeed (Event *);
		void		FadeInSpeed (Event *);
		void		SetPosition (Event *);
		void		ClearText (Event *);
		void		ResetDialog (Event *);
		void		SetSize (Event *);
		void		LoadFile (Event *);

		virtual void		LoadEntries (const char *);
		virtual void		ClearEntries (void);
		DialogEntry			*GetDialogEntry( const char *dialog_name );
		virtual void		PrintDialogText (const char *, float);
		virtual void		ParseEntryFile (char *, char *);
};

extern DialogText		dialogText;

#endif