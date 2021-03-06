/*ex89.c*/
#include "d4all.h"

#ifdef __TURBOC__
   extern unsigned _stklen = 10000;
#endif

void main()
{
   CODE4  cb ;
   DATA4  *data ;
   EXPR4 *expr ;
   char *result ;

   code4init( &cb ) ;
   data = d4open( &cb, "DATA" ) ;

   d4go( data, 1L ) ;
   /* "FNAME" and "LNAME" are Character field names of data file "DATA.DBF"*/

   expr = expr4parse( data, "FNAME+\' \'+LNAME") ;
   expr4vary( expr, &result ) ;
   printf( "FNAME and LNAME for Record One: %s\n", result ) ;

   expr4free( expr ) ;
   d4close( data ) ;
   code4initUndo( &cb ) ;
}
