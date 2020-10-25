#ifndef __SHRAPNELBOMB_H__
#define __SHRAPNELBOMB_H__

#include "weapon.h"
#include "weaputils.h"

class ShrapnelBomb : public Projectile
   {
	private:
		str			shrapnelModel;
		int			shrapnelCount;

	public:
		CLASS_PROTOTYPE( ShrapnelBomb );

		      ShrapnelBomb();
		void  SetShrapnelModel ( Event *ev );
		void  SetShrapnelCount ( Event *ev );

		//Override
		void  Explode			  ( Event *ev );

		virtual void Archive ( Archiver &arc );

	};

inline void ShrapnelBomb::Archive ( Archiver &arc )
   {
	Projectile::Archive( arc );
	arc.ArchiveInteger( &shrapnelCount );
	arc.ArchiveString( &shrapnelModel );
	}
        

#endif //__SHRAPNELBOMB_H__