
/*________________________________________________________________________
*/

# include "lu.h"

/*________________________________________________________________________
*/

int				allflag		= 0 ;
int				errorflag	= 0 ;
int				helpflag	= 0 ;
int				humanflag	= 0 ;
int				indentflag	= 0 ;
int				mountflag	= 0 ;
int				siflag		= 0 ;
int				totalflag	= 0 ;
int				verboseflag	= 0 ;
int				versionflag	= 0 ;

int				grd			= 0 ;
int				lastone		= 0 ;

int				limdepth	= 1 ;

int64_t			lucount		= 0 ;
int64_t			topcount	= 0 ;

int64_t			dircount		= 0 ;
int64_t			filecount		= 0 ;
int64_t			othercount		= 0 ;

int64_t			dirbytes		= 0 ;
int64_t			filebytes		= 0 ;
int64_t			otherbytes		= 0 ;

int64_t			totdircount		= 0 ;
int64_t			totfilecount	= 0 ;
int64_t			totothercount	= 0 ;

int64_t			totdirbytes		= 0 ;
int64_t			totfilebytes	= 0 ;
int64_t			tototherbytes	= 0 ;

int64_t			tottopbytes		= 0 ;

int64_t			dnrcount	= 0 ;
int64_t			nscount		= 0 ;

dev_t			mountdev ;

/*________________________________________________________________________
*/

void filefall (name, deep) char * name ; int deep ; {

# define	VSIZ	5 /* 4 ? */
# define	VLEN	3

	static		char			vlast [VSIZ] = "\\--" ;
	static		char			veach [VSIZ] = "+--" ;
	static		char			vstik [VSIZ] = "|  " ;
	static		char			vspac [VSIZ] = "   " ;
	static		char			vbuf  [4096] = { '\0' } ;
				char *			vpref ;

	*(vbuf+(deep*VLEN)) = '\0' ;

	if (*vbuf)
		printf ("%s", vbuf) ;

	if ( lastone ) {
		strcat (vbuf, vspac) ; vpref = vlast ;
	} else {
		strcat (vbuf, vstik) ; vpref = veach ;
	}

	printf ("%s", deep ? vpref : vspac ) ;

	printf ("%s\n", name) ;
}

/*________________________________________________________________________
*/

void showsize ( size )
				int64_t			size		;
{
	if ( humanflag ) {
		printf ( "%s " , itohuman ( size , siflag ) ) ;
	} else {
		printf ( "%15ld " , (long)size ) ;
	}
}

/*________________________________________________________________________
*/

void shownode ( stemsize , depth , leaf , pathbuff )
				int64_t			stemsize	;
				int				depth		;
				char *			leaf		;
				char			pathbuff [] ;
{
	register	int				rd			;

	if ( humanflag ) {
		printf ( "%s " , itohuman ( stemsize , siflag ) ) ;
	} else {
		printf ( "%15ld " , (long)stemsize ) ;
	}
	if ( indentflag ) {
		for ( rd = 0 ; rd < depth ; ++rd ) {
			printf ("   ") ;
		}
		printf ( "%s\n" , leaf ) ;
	} else {
		printf ( "%s\n" , pathbuff ) ;
	}
}
/*________________________________________________________________________
*/

off_t lu (stem, leaf) char * stem , * leaf ; {

	static		int				depth		= 0 ;
	register	int				rd			;
				int64_t			itemsize	;
				int64_t			stemsize	= 0 ;
				struct STAT		stabuf		;
				struct dirent *	dep			;
				DIR *			dip			;
				char *			np			;
				char			pathbuff [ PATHSIZE ] ;

	if ( stem == NULL ) {
		strcpy ( pathbuff , leaf ) ;
		++topcount ;
		dircount = filecount = othercount = 0 ;
		dirbytes = filebytes = otherbytes = 0 ;
		if ( versionflag ) {
			printf ("%s %s\n", lu_program_string, lu_version_string) ;
			exit (0) ;
		}
	} else {
		for ( rd = 0 ; stem[rd] != '\0' ; ++rd )
			;
		--rd ;
		sprintf ( pathbuff , stem[rd] == '/' ? "%s%s" : "%s/%s" , stem , leaf ) ;
	}
	
	++lucount ;

	if ( ( rd = LSTAT ( pathbuff , &stabuf ) ) != 0 ) {
		if ( verboseflag > 2 ) {
			fprintf ( stderr , "* lstat(%s)=<%d>\n" , pathbuff , rd ) ;
		}
		++nscount ; return -1 ;
	} else {
		if ( mountflag ) {
			if ( stem == NULL ) {
				mountdev = stabuf.st_dev ;
			} else {
				if ( mountdev != stabuf.st_dev ) {
					return -1 ;
				}
			}
		}
	}

	itemsize = (int64_t) stabuf.st_size ;

	switch ( stabuf.st_mode & S_IFMT ) {

		case S_IFDIR :

			++dircount ; ++totdircount ;
			dirbytes += itemsize ; totdirbytes += itemsize ;

			if ( ( dip = opendir ( pathbuff ) ) == NULL ) {
				++dnrcount ;
				if ( verboseflag > 2 ) {
					fprintf ( stderr , "* opendir(%s)=<fail>\n" , pathbuff ) ;
				}
			} else {
				stemsize = itemsize ;
				while ( ( dep = readdir (dip) ) != NULL ) {
					np = dep->d_name ;
					if ( *np == '.' ) {
						if ( *(np+1) == '\0' ) {
							continue ;
						} else if ( *(np+1) == '.' && *(np+2) == '\0' ) {
							continue ;
						}
					}
					++depth ;
					if ( ( itemsize = lu ( pathbuff , np ) ) > 0 ) {
						stemsize += itemsize ;
					}
					--depth ;
				}
				closedir (dip) ;
				if ( depth <= limdepth ) {
					shownode ( stemsize , depth , leaf , pathbuff ) ;
				}
			}

		break ;

		case S_IFREG :

			++filecount ; ++totfilecount ;
			filebytes += itemsize ; totfilebytes += itemsize ;

			stemsize = itemsize ;

			if ( allflag ) {
				shownode ( stemsize , depth , leaf , pathbuff ) ;
			}

		break ;

		default :

			++othercount ; ++totothercount ;
			otherbytes += itemsize ; tototherbytes += itemsize ;

			stemsize = itemsize ;

			if ( allflag ) {
				shownode ( stemsize , depth , leaf , pathbuff ) ;
			}

		break ;
	}

	if ( stem == NULL ) {
		if ( totalflag ) {
			tottopbytes += stemsize ;
		}
		if ( verboseflag > 0 ) {
			printf ( "%15ld bytes in %15ld directories\n" , (long)dirbytes   , (long)dircount   ) ;
			printf ( "%15ld bytes in %15ld files\n"       , (long)filebytes  , (long)filecount  ) ;
			printf ( "%15ld bytes in %15ld other\n"       , (long)otherbytes , (long)othercount ) ;
		}
		if ( verboseflag > 1 ) {
			printf ( "%15ld lstat failures\n" , (long)nscount ) ;
			printf ( "%15ld unreadable directories\n" , (long)dnrcount ) ;
		}
		if ( verboseflag > 3 ) {
			printf ( "%15ld lu() calls\n" , (long)lucount ) ;
		}
	}

	return stemsize ;
}

/*________________________________________________________________________
*/

void usage ( name ) char * name ; {
	fprintf ( stderr , "* use : %s [options]\n" , name ) ;
	fprintf ( stderr , " -a   : show all objects\n" ) ;
	fprintf ( stderr , " -h   : human readable sizes\n" ) ;
	fprintf ( stderr , " -i   : human readable SI sizes\n" ) ;
	fprintf ( stderr , " -l N : limit level summary\n" ) ;
	fprintf ( stderr , " -m   : do not cross mount points\n" ) ;
	fprintf ( stderr , " -t   : indent\n" ) ;
	fprintf ( stderr , " -T   : total\n" ) ;
	fprintf ( stderr , " -V   : version\n" ) ;
	fprintf ( stderr , " -v   : verbose\n" ) ;
	exit ( errorflag ) ;
}

/*________________________________________________________________________
*/

int main (argc, argv) int argc ; char * argv [ ] ; {
	char * name = argv [ 0 ] ;

	if ( --argc ) {
		while ( *++argv ) {
			if ( **argv == '-' ) {
				if ( 0 == strcmp ( *argv , "-?" ) ) {
					++helpflag ;
				} else if ( 0 == strcmp ( *argv , "-a" ) ) {
					++allflag ;
				} else if ( 0 == strcmp ( *argv , "-h" ) ) {
					++humanflag ;
				} else if ( 0 == strcmp ( *argv , "-i" ) ) {
					++siflag ;
				} else if ( 0 == strcmp ( *argv , "-l" ) ) {
					limdepth = atoi ( *++argv ) ;
				} else if ( 0 == strcmp ( *argv , "-m" ) ) {
					++mountflag ;
				} else if ( 0 == strcmp ( *argv , "-t" ) ) {
					++indentflag ;
				} else if ( 0 == strcmp ( *argv , "-T" ) ) {
					++totalflag ;
				} else if ( 0 == strcmp ( *argv , "-V" ) ) {
					++versionflag ;
				} else if ( 0 == strcmp ( *argv , "-v" ) ) {
					++verboseflag ;
				} else {
					++errorflag ;
				}
			} else {
				lu ( NULL , *argv ) ;
			}
		}
		if ( helpflag || errorflag ) {
			usage ( name ) ;
		}
		if ( topcount == 0 ) {
			lu ( NULL , "." ) ;
		} else {
			if ( totalflag ) {
				if ( verboseflag > 0 ) {
					printf ( "%15ld bytes in %ld trees\n"     , (long)tottopbytes   , (long)topcount      ) ;
				} else {
					printf ( "%15ld total\n"                   , (long)tottopbytes ) ;
				}
			}
			if ( verboseflag > 0 ) {
				printf ( "%15ld bytes in %15ld directories\n" , (long)totdirbytes   , (long)totdircount   ) ;
				printf ( "%15ld bytes in %15ld files\n"       , (long)totfilebytes  , (long)totfilecount  ) ;
				printf ( "%15ld bytes in %15ld other\n"       , (long)tototherbytes , (long)totothercount ) ;
			}
		}
	} else {
		lu ( NULL , "." ) ;
	}

	return grd ;
} 

/*________________________________________________________________________
*/

/*
 * vi:nu ts=4
 */
