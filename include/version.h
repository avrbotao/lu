/*
 *	version.h
 */

# ifndef _VERSION_H_

# define _VERSION_H_

extern const char * lu_program_string ;
extern const char * lu_version_string ;
extern const char * lu_release_string ;
extern const char * lu_relogio_string ;
extern const char * lu_summary_string ;
extern const char * lu_taglist_string ;
extern const char * lu_license_string ;
extern const char * lu_creator_string ;
extern const char * lu_contact_string ;
extern const char * lu_builder_string ;
extern const char * lu_compile_string ;

	/*  legacy  */

# define	SWNAME		lu_program_string
# define	SWVERS		lu_version_string
# define	SWDATE		lu_release_string
# define	SWTIME		lu_relogio_string
# define	SWDESC		lu_summary_string
# define	SWTAGS		lu_taglist_string
# define	SWCOPY		lu_license_string
# define	SWAUTH		lu_creator_string
# define	SWMAIL		lu_contact_string
# define	SWBLDR		lu_builder_string
# define	SWCOMP		lu_compile_string

# define	SWFORG		" " /* deprecated */

# endif /* _VERSION_H_ */

/*
 * vi:nu ts=8
 */
