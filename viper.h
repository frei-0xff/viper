#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <time.h>
#include <openssl/des.h>

#define DEBUG		0
#define DEFAULTPWLENGTH	8
#define MAXPASSWDLENGTH 16
#define MAXENCPWDLENGTH 13
#define CHARSET_FILE 	"charset.ini"
#define TIMECHECK	1000000
#define FIN_IDENT	"--viper_final--"
#define SCREENWIDTH	80
#define SCREENHEIGTH	24

struct crack_input
{
	char ci_user[80];			// username
	char ci_pass[MAXENCPWDLENGTH+1];	// encrypted password
	char ci_cset[255];			// characterset to use
	char ci_rf;				// runtime limit
	int  ci_pwl;    			// password max length
	int  ci_pws;				// password min length
	int  ci_ui;				// console update interval
	char ci_dnum[255];			// status for each digit
	char ci_pf[255];			// progressfile name
	int  ci_vo;				// verbose output
};
	
extern struct  crack_input lsf_out;
extern struct  tm start_time, last_time;		// time structs
extern char    checkpass[17];				// cleartext passphrase
extern char    message[8][81];				// result message
extern char    time_done[17];				// passed time
extern char    time_togo[17];				// calculated time to run
extern time_t  read_time;				// actual time
extern FILE *  fp_pf;					// progressfile
extern int     ret;                                    // function return codes

int help();
int crack();
int convert(double, char *);
void the_res(struct crack_input, char *, struct tm);
