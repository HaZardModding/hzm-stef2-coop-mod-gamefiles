//-----------------------------------------------------------------------------
//
//  $Logfile:: /red_code/game/compiler.h                                      $
// $Revision:: 1                                                              $
//     $Date:: 1/16/01 2:13p                                                  $
//
// Copyright (C) 1999 by Ritual Entertainment, Inc.
// All rights reserved.
//
// This source is may not be distributed and/or modified without
// expressly written permission by Ritual Entertainment, Inc.
//
// $Log:: /red_code/game/compiler.h                                           $
// 
// 1     1/16/01 2:13p Steven
// Script C merge.
// 
// 8     4/05/00 3:56p Jimdose
// Fakk2 merge
// 
// 6     4/04/00 2:33p Jimdose
// added support for passing parameters into threads
// 
// 5     3/31/00 3:45p Jimdose
// fixed the order of some opcode
// 
//
// DESCRIPTION:
// 
//
// Form of for statement with a counter:
//
//       a = 0;
//    start:               << patch4
//       if ( !( a < 10 ) )
//          {
//          goto end;      << patch1
//          }
//       else
//          {
//          goto process;  << patch3
//          }
//    
//    increment:           << patch2
//       a = a + 1;
//       goto start;       << goto patch4
//    
//    process:
//       statements;
//       goto increment;   << goto patch2
//    
//    end:
//    
// Form of for statement without a counter:
//
//       a = 0;
//    start:               << patch2
//       if ( !( a < 10 ) )
//          {
//          goto end;      << patch1
//          }
//    
//    process:
//       statements;
//       goto increment;   << goto patch2
//    
//    end:
//

#ifndef __COMPILER_H__
#define __COMPILER_H__

#include "program.h"
#include "lexer.h"

#define	MAX_ERRORS		10

typedef struct
   {
	int				code;		               // first statement
	char				*file;	               // source file with definition
	int				file_line;
	int				parm_ofs[ MAX_PARMS ];  // allways contiguous, right?
   } function_t;

typedef struct
   {
	char		*name;
	char		*opname;
	float		priority;
	bool     right_associative;
	def_t		*type_a;
   def_t		*type_b;
   def_t		*type_c;
   } opcode_t;

extern	opcode_t	pr_opcodes[ 99 ];		      // sized by initialization

enum 
   {
	OP_DONE,

   OP_UINC_F,
   OP_UDEC_F,

	OP_MUL_F,
	OP_MUL_V,
	OP_MUL_FV,
	OP_MUL_VF,
	OP_DIV_F,
	OP_ADD_F,
	OP_ADD_V,
   OP_ADD_S,
   OP_ADD_FS,
   OP_ADD_SF,
	OP_SUB_F,
	OP_SUB_V,
	
	OP_EQ_F,
	OP_EQ_V,
	OP_EQ_S,
	OP_EQ_E,
	OP_EQ_FNC,
	
	OP_NE_F,
	OP_NE_V,
	OP_NE_S,
	OP_NE_E,
	OP_NE_FNC,
	
	OP_LE,
	OP_GE,
	OP_LT,
	OP_GT,

	OP_STORE_F,
	OP_STORE_V,
	OP_STORE_S,
	OP_STORE_ENT,
	OP_STORE_FNC,

   OP_STORE_FTOS,

   OP_UMUL_F,
   OP_UDIV_F,
   OP_UADD_F,
   OP_USUB_F,
   OP_UAND_F,
   OP_UOR_F,

	OP_RETURN,
	OP_NOT_F,
	OP_NOT_V,
	OP_NOT_S,
	OP_NOT_ENT,
	OP_NOT_FNC,
	OP_IF,
	OP_IFNOT,

	OP_CALL,
	OP_OCALL,
   OP_THREAD,

   OP_PUSH_F,
   OP_PUSH_V,
   OP_PUSH_S,
	OP_PUSH_ENT,
	OP_PUSH_FNC,
   OP_PUSH_FTOS,

   OP_GOTO,
	OP_AND,
	OP_OR,
	
	OP_BITAND,
	OP_BITOR
   };

class Compiler
   {
   public :
      def_t		   *pr_scope;		      // the function being parsed, or NULL
      
      Program     &program;
      Lexer       lex;

      bool        callthread;

      int         filenumber;

                  Compiler( Program &prg );

      def_t       *Statement( opcode_t *op, def_t *var_a, def_t *var_b );
      def_t	      *ParseImmediate( void );
      def_t       *ParseFunctionCall( def_t *func );
      def_t       *ParseObjectCall( def_t *func, def_t *object );
      def_t	      *ParseValue( void );
      def_t       *Term( void );
      def_t       *Expression( int priority );
      void        ParseStatement( void );
      function_t  ParseImmediateStatements( type_t *type, char parm_names[ MAX_PARMS ][ MAX_NAME ], int numparms );
      type_t      *ParseFunction( type_t *returntype, char parm_names[ MAX_PARMS ][ MAX_NAME ], int *numparms );
      void        ParseFunctionDef( type_t *type, const char *name );
      void        ParseVariableDef( type_t *type, const char *name );
      void        ParseDefs( void );
      bool        CompileFile( char *text, const char *filename, int filenum );
   };

#endif
