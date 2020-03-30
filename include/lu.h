
/*________________________________________________________________________
*/

# include "config.h"

# include "version.h"

# define	_XOPEN_SOURCE	500

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <dirent.h>

# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>

# include "tohuman.h"

/*________________________________________________________________________
*/

# ifdef HPUX
#	define	STAT		stat64
#	define	LSTAT		lstat64
# else
#	define	STAT		stat
#	define	LSTAT		lstat
# endif

# define	PATHSIZE	8192

/*________________________________________________________________________
** vi:nu ts=8
*/

