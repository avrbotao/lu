
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

/*
 *
 *		  /\		 ___________________________________________________
 *		 /  \		|													|
 *		/ OO \		|	tohuman.c	human readable value abbreviation	|
 *		\ \/ /		|	(c) 2000-2015			alexandre v. r. botao	|
 *		 \  /		|___________________________________________________|
 *		  \/
 *
 */

# include	"tohuman.h"

/*\	__	__	__	__	__	__	__	__	__	__	__	__	__	__	__	__	__	__	__
\*/

char * itohuman (x, si) int64_t x ; int si ; {

	static	char	kmg [64] ;
	static	char	kc = 'K' , mc = 'M' , gc = 'G' , sc = ' ' ;
	static	char	tc = 'T' , pc = 'P' , ec = 'E' ;
			double	bval, kval, mval, gval ;
			double	tval, pval, eval ;

	bval = x ;

		if ( bval < 1000 ) {
			sprintf (kmg, "%3d", (int) bval) ; SETKMG(sc) ;
			return kmg ;
		}

	kval = bval / ( si ? 1000.0 : 1024.0 ) ;

		if ( kval < 10.0 ) {
			sprintf (kmg, "%11.9f", kval) ; SETKMG(kc) ;
			return kmg ;
		}

			if ( kval < 1000.0 ) {
				sprintf (kmg, "%13.9f", kval) ; SETKMG(kc) ;
				return kmg ;
			}

	mval = bval / ( si ? 1000000.0 : 1048576.0 ) ;

	if ( mval < 10.0 ) {
		sprintf (kmg, "%11.9f", mval) ; SETKMG(mc) ;
		return kmg ;
	}

	if ( mval < 1000.0 ) {
		sprintf (kmg, "%13.9f", mval) ; SETKMG(mc) ;
		return kmg ;
	}

	gval = bval / ( si ? 1000000000.0 : 1073741824.0 ) ;

	if ( gval < 10.0 ) {
		sprintf (kmg, "%11.9f", gval) ; SETKMG(gc) ;
		return kmg ;
	}

	if ( gval < 1000.0 ) {
		sprintf (kmg, "%13.9f", gval) ; SETKMG(gc) ;
		return kmg ;
	}

	tval = bval / ( si ? 1000000000000.0 : 1099511627776.0 ) ;

	if ( tval < 10.0 ) {
		sprintf (kmg, "%11.9f", tval) ; SETKMG(tc) ;
		return kmg ;
	}

	if ( tval < 1000.0 ) {
		sprintf (kmg, "%13.9f", tval) ; SETKMG(tc) ;
		return kmg ;
	}

	pval = bval / ( si ? 1000000000000000.0 : 1125899906842624.0 ) ;

	if ( pval < 10.0 ) {
		sprintf (kmg, "%11.9f", pval) ; SETKMG(pc) ;
		return kmg ;
	}

	if ( pval < 1000.0 ) {
		sprintf (kmg, "%13.9f", pval) ; SETKMG(pc) ;
		return kmg ;
	}

	eval = bval / ( si ? 1000000000000000000.0 : 1152921504606846976.0 ) ;

	if ( eval < 10.0 ) {
		sprintf (kmg, "%11.9f", eval) ; SETKMG(ec) ;
		return kmg ;
	}

	if ( eval < 1000.0 ) {
		sprintf (kmg, "%13.9f", eval) ; SETKMG(ec) ;
		return kmg ;
	}

	return "????" ;
}

/*\___________________________________________________________________________
\*/

/*		 _______________________________________________________________
 *		|																|
 *		|  date....   version   history ..............................	|
 *		|			 		   											|
 *		|  yy mm dd   v.v rls   ......................................	|
 *		|_______________________________________________________________|
 *		|																|
 *		|  + ...														|
 *		|_______________________________________________________________|
 */

/*
 * vi:nu tabstop=4
 */
