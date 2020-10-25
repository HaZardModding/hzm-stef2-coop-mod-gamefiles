//=======================================
//Forward Declarations
//=======================================
class BitVector;

/* Bit Vector
This class is to used to manage flags.  I'm hoping that, once it's running well, we can rework all of the flags
systems in the game.dll to use this class to keep things easy to maintain and uniform
*/

#ifndef __BIT_VECTOR_H__
#define __BIT_VECTOR_H__

class BitVector 
   {
	public:
		BitVector( unsigned int lastIndex );
		~BitVector();

		void SetFlag( unsigned int index );
		bool GetFlag( unsigned int index );
		void ClearFlag( unsigned int index );

	private:
		unsigned int *_bytes;
		unsigned int _numBytes;
	};

BitVector::BitVector ( unsigned int lastIndex )
   {
	_numBytes = (lastIndex / 32 ) + 1;
	_bytes = new unsigned int[numBytes];

	}

BitVector::~BitVector()
   {
	delete[] _bytes;
	}

inline void SetFlag( unsigned int index )
   {
	int byte = index / 32;
	int offset = index % 32;

	_bytes[byte] |= ( 1<<offset );

	}

inline void ClearFlag( unsigned int index )
	{
	int byte = index / 32;
	int offset = index % 32;

	_bytes[byte] &= ~( 1<<offset );
	}

inline bool GetFlag( unsigned int index )
	{
	int byte = index / 32;
	int offset = index % 32;

	return ( _bytes[byte] & ( 1 << offset ) );
	}

#endif // __BIT_VECTOR_H__