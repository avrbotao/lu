
/*
 *          |          _                     _______________________
 *          |\       _/ \_                  |                       |
 *          | \_    /_    \_                |    Alexandre Botao    |
 *          \   \__/  \__   \               |     www.botao.org     |
 *           \_    \__/  \_  \              |    55-11-8244-UNIX    |
 *             \_   _/     \ |              |  alexandre@botao.org  |
 *               \_/        \|              |_______________________|
 *                           |
 */

/*		 _______________________________________________________________
 *		|																|
 *		|	tohuman.h						 (c) 2000 Alexandre Botao	|
 *		|_______________________________________________________________|
 */

/*______________________________________________________________________
 |                                                                      |
 |  This code is free software: you can redistribute it and/or modify   |
 |  it under the terms of the GNU General Public License as published   |
 |  by the Free Software Foundation, either version 3 of the License,   |
 |  or (at your option) any later version.                              |
 |                                                                      |
 |  This code is distributed in the hope that it will be useful,        |
 |  but WITHOUT ANY WARRANTY; without even the implied warranty of      |
 |  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.                |
 |  See the GNU General Public License for more details.                |
 |                                                                      |
 |  You should have received a copy of the GNU General Public License   |
 |  along with this code.  If not, see <http://www.gnu.org/licenses/>,  |
 |  or write to the Free Software Foundation, Inc.,                     |
 |  59 Temple Place, Suite 330, Boston, MA  02111-1307  USA.            |
 |______________________________________________________________________|
 */

# ifndef _TOHUMAN_H

# define _TOHUMAN_H

/*\	__	__	__	__	__	__	__	__	__	__	__	__	__	__	__	__	__	__
\*/

# include	<sys/types.h>

# ifdef AIX71
typedef		uint_t          rid_t ;		/* role ID */
# endif /* AIX71 */

# include	<math.h>
# include	<ctype.h>
# include	<errno.h>
# include	<stdio.h>
# include	<stdlib.h>
# include	<string.h>
# include	<unistd.h>

/*\	__	__	__	__	__	__	__	__	__	__	__	__	__	__	__	__	__	__
\*/

/*
 *	from gnu readline and rsa md5 plus alternate configure
 *
 #  include	"abx/params.h"
 */

#ifndef _PARAMS_H_

#define _PARAMS_H_

# if !defined (PARAMS)
#	if defined (__STDC__) || defined (__GNUC__) || defined (__cplusplus)
#		define PARAMS(protos) protos
#	else
#		if defined (PROTOTYPES)
#			define PARAMS(protos) protos
#		else
#			define PARAMS(protos) ()
#		endif
#	endif
# endif

#endif  /* _PARAMS_H_ */

/*\	__	__	__	__	__	__	__	__	__	__	__	__	__	__	__	__	__	__
\*/

# define	SETKMG(X)	kmg[3] = ( si ? tolower((int)X) : X ) ; kmg[4] = '\0' ;

/*\	__	__	__	__	__	__	__	__	__	__	__	__	__	__	__	__	__	__
\*/

char *		itohuman		PARAMS ( ( int64_t , int )					) ;

/*\	__	__	__	__	__	__	__	__	__	__	__	__	__	__	__	__	__	__
\*/

# endif /* _TOHUMAN_H */

/*
 * vi:nu tabstop=4
 */
