/*
 * CDDL HEADER START
 *
 * The contents of this file are subject to the terms of the
 * Common Development and Distribution License, Version 1.0 only
 * (the "License").  You may not use this file except in compliance
 * with the License.
 *
 * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE
 * or http://www.opensolaris.org/os/licensing.
 * See the License for the specific language governing permissions
 * and limitations under the License.
 *
 * When distributing Covered Code, include this CDDL HEADER in each
 * file and include the License file at usr/src/OPENSOLARIS.LICENSE.
 * If applicable, add the following below this CDDL HEADER, with the
 * fields enclosed by brackets "[]" replaced with your own identifying
 * information: Portions Copyright [yyyy] [name of copyright owner]
 *
 * CDDL HEADER END
 */
/*
 * Copyright 2003 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

/*	Copyright (c) 1984, 1986, 1987, 1988, 1989 AT&T	*/
/*	  All Rights Reserved  	*/


/*	from OpenSolaris "tdef.h	1.11	05/06/08 SMI"	*/

/*
 * Portions Copyright (c) 2005 Gunnar Ritter, Freiburg i. Br., Germany
 *
 * Sccsid @(#)tdef.h	1.43 (gritter) 9/11/05
 */

/*
 * University Copyright- Copyright (c) 1982, 1986, 1988
 * The Regents of the University of California
 * All Rights Reserved
 *
 * University Acknowledgment- Portions of this document are derived from
 * software developed by the University of California, Berkeley, and its
 * contributors.
 */

/* starting values for typesetting parameters: */

#define	PS	10	/* default point size */
#define	FT	1	/* default font position */
#define ULFONT	2	/* default underline font */
#define	BDFONT	3	/* default emboldening font */
#define	BIFONT	4	/* default bold italic font */
#define	LL	(unsigned) 65*INCH/10	/* line length; 39picas=6.5in */
#define	VS	((12*INCH)/72)	/* initial vert space */

#ifdef	NROFF
#	define	EM	t.Em
#	define	HOR	t.Adj
#	define	VERT	t.Vert
#	define	INCH	240	/* increments per inch */
#	define	SPS	INCH/10	/* space size */
#	define	SES	SPS	/* sentence space size */
#	define	SS	INCH/10	/* " */
#	define	TRAILER	0
#	define	PO	0 /* page offset */
#	define	ASCII	1
#	define	PTID	1
#	define	LG	0
#	define	DTAB	0	/* set at 8 Ems at init time */
#	define	ICS	2*SPS
#endif
#ifndef NROFF	/* TROFF */
	/* Inch is set by ptinit() when troff started. */
	/* all derived values set then too
	*/
#	define	INCH	Inch	/* troff resolution -- number of goobies/inch  */
#	define	POINT	(INCH/72)	/* goobies per point (1/72 inch) */
#	define	HOR	Hor	/* horizontal resolution in goobies */
#	define	VERT	Vert	/* vertical resolution in goobies */
#	define	SPS	(EM/3)	/* space size  */
#	define	SES	SPS	/* sentence space size */
#	define	SS	12	/* space size in 36ths of an em */
#	define	PO	(INCH)	/* page offset 1 inch */
/* #	define	EM	(POINT * pts) */
#define	EM	(((long) INCH * u2pts(pts) + 36) / 72)	/* don't lose significance */
#define	EMPTS(pts)	(((long) INCH * u2pts(pts) + 36) / 72)
#	define	ASCII	0
#	define	PTID	1
#	define	LG	1
#	define	DTAB	(INCH/2)
#	define	ICS	3*SPS
#endif

/* These "characters" are used to encode various internal functions
 * Some make use of the fact that most ascii characters between
 * 0 and 040 don't have any graphic or other function.
 * The few that do have a purpose (e.g., \n, \b, \t, ...
 * are avoided by the ad hoc choices here.
 * See ifilt[] in n1.c for others -- 1, 2, 3, 5, 6, 7, 010, 011, 012 
 */

#define	LEADER	001
#define	IMP	004	/* impossible char; glues things together */
#define	TAB	011
#define	RPT	014	/* next character is to be repeated many times */
#define	CHARHT	015	/* size field sets character height */
#define	SLANT	016	/* size field sets amount of slant */
#define	DRAWFCN	017	/* next several chars describe arb drawing fcn */
			/* line: 'l' dx dy char */
			/* circle: 'c' r */
			/* ellipse: 'e' rx ry */
			/* arc: 'a' dx dy r */
			/* wiggly line '~' x y x y ... */
#define	DRAWLINE	'l'
#define	DRAWCIRCLE	'c'	/* circle */
#define	DRAWELLIPSE	'e'
#define	DRAWARC		'a'	/* arbitrary arc */
#define	DRAWSPLINE	'~'	/* quadratic B spline */

#define	LEFT	020	/* \{ */
#define	RIGHT	021	/* \} */
#define	FILLER	022	/* \& and similar purposes */
#define	XON	023	/* \X'...' starts here */
#define	OHC	024	/* optional hyphenation character \% */
#define	CONT	025	/* \c character */
#define	PRESC	026	/* printable escape */
#define	UNPAD	027	/* unpaddable blank */
#define	STRETCH	037	/* stretchable but unbreakable blank */
#define	XPAR	030	/* transparent mode indicator */
#define	FLSS	031
#define	WORDSP	032	/* paddable word space */
#define	ESC	033
#define	XOFF	034	/* \X'...' ends here */

#define	iscontrol(n)	(n==035 || n==036)	/* used to test the next two */
#define	HX	035	/* next character is value of \x'...' */
#define	FONTPOS	036	/* position of font \f(XX encoded in top */

#define	HYPHEN	c_hyphen
#define	EMDASH	c_emdash	/* \(em */
#define	RULE	c_rule		/* \(ru */
#define	MINUS	c_minus		/* minus sign on current font */
#define	LIG_FI	c_fi		/* \(ff */
#define	LIG_FL	c_fl		/* \(fl */
#define	LIG_FF	c_ff		/* \(ff */
#define	LIG_FFI	c_ffi		/* \(Fi */
#define	LIG_FFL	c_ffl		/* \(Fl */
#define	ACUTE	c_acute		/* acute accent \(aa */
#define	GRAVE	c_grave		/* grave accent \(ga */
#define	UNDERLINE c_under	/* \(ul */
#define	ROOTEN	c_rooten	/* root en \(rn */
#define	BOXRULE	c_boxrule	/* box rule \(br */
#define	LEFTHAND c_lefthand	/* left hand for word overflow */
#define	DAGGER	c_dagger	/* dagger for footnotes */

/* array sizes, and similar limits: */

#define	NFONT	10	/* maximum number of fonts (including specials, !afm) */
#define	EXTRAFONT 500	/* extra space for swapping a font */
extern	int	NN;	/* number registers */
#define	NNAMES	15	 /* predefined reg names */
#define	NIF	15	/* if-else nesting */
#define	NS	128	/* name buffer */
#define	NTM	256	/* tm buffer */
#define	NEV	3	/* environments */
#define	EVLSZ	10	/* size of ev stack */
#define	DSIZE	512	/* disk sector size in chars */

extern	int	NM;	/* requests + macros */
#define	DELTA	1024	/* delta core bytes */
#define	NHYP	10	/* max hyphens per word */
#define	NTAB	40	/* tab stops */
#define	NSO	5	/* "so" depth */
extern	int	NMF;	/* size of space for -m flags */
#define	WDSIZE	540	/* word buffer size */
#define	LNSIZE	680	/* line buffer size */
#define	NDI	5	/* number of diversions */
extern	int	NCHARS;	/* maximum size of troff character set */
#define	NTRTAB	NCHARS	/* number of items in trtab[] */
#define	NWIDCACHE NCHARS	/* number of items in widcache */
#define	NTRAP	20	/* number of traps */
#define	NPN	20	/* numbers in "-o" */
#define	FBUFSZ	256	/* field buf size words */
#define	OBUFSZ	4096	/* bytes */
#define	IBUFSZ	4096	/* bytes */
#define	NC	1024	/* cbuf size words */
#define	NOV	10	/* number of overstrike chars */
#define	NPP	10	/* pads per field */

/*
	Internal character representation:
	Internally, every character is carried around as
	a 64 bit cookie, called a "tchar" (typedef long long).
	Bits are numbered 63..0 from left to right.
	If bit 15 is 1, the character is motion, with
		if bit 16 it's vertical motion
		if bit 17 it's negative motion
	If bit 15 is 0, the character is a real character.
		if bit 63	zero motion
		bits 62..40	size
		bits 39..32	font
ifndef EUC
		bit 8		absolute char number in 7..0
	This implies at most 256-32 characters in a single font,
	which is going to be a problem somewhere
else
		bits 14,13	identifier for the colunm of print of character.
		bits 12,11	multibyte position identifier
	Currently, this applies only to nroff.
endif EUC
*/

/* in the following, "LL" should really be a tchar, but ... */

#define	MOT	(01LL<<15)	/* motion character indicator */
#define	VMOT	(01LL<<16)	/* vert motion bit */
#define	NMOT	(01LL<<17)	/* negative motion indicator*/
#define	BMBITS	077777LL	/* basic absolute motion bits */
#define	XMBITS	0x7FFC0000LL	/* extended absolute motion bits */
#define	XMSHIFT	3		/* extended absolute motion shift */
#define	MAXMOT	0x0FFFFFFFLL	/* bad way to write this!!! */

#define	ismot(n)	((n) & MOT)
#define	isvmot(n)	((n) & VMOT)	/* must have tested MOT previously */
#define	isnmot(n)	((n) & NMOT)	/* ditto */
#define	absmot(n)	(unsigned long)(BMBITS&(n) | ((n)&XMBITS)>>XMSHIFT)
#define	sabsmot(n)	((n)&BMBITS | ((n)&~BMBITS)<<XMSHIFT)

#define	ZBIT		(01ULL << 63) 	/* zero width char */
#define	iszbit(n)	((n) & ZBIT)
#define	BLBIT		(01ULL << 31)	/* optional break-line char */
#define	isblbit(n)	((n) & BLBIT)
#define	ABSCHAR		0400	/* absolute char number in this font */

#define	SMASK		(037777777LL << 40)
#define	FMASK		(0377LL << 32)
#define	SFMASK		(SMASK|FMASK)	/* size and font in a tchar */
#define	sbits(n)	(unsigned)(((n) >> 40) & 037777777)
#define	fbits(n)	(((n) >> 32) & 0377)
#define	sfbits(n)	(unsigned)(037777777777UL & (((n) & SFMASK) >> 32))
#define	cbits(n)	(unsigned)(0177777 & (n))	/* isolate bottom 16 bits  */
#define	absbits(n)	(cbits(n) & ~ABSCHAR)

#define	setsbits(n,s)	n = (n & ~SMASK) | (tchar)(s) << 40
#define	setfbits(n,f)	n = (n & ~FMASK) | (tchar)(f) << 32
#define	setsfbits(n,sf)	n = (n & ~SFMASK) | (tchar)(sf) << 32
#define	setcbits(n,c)	n = (n & ~077777LL | (c))	/* set character bits */

#define	BYTEMASK	0377
#define	BYTE	8

#define	ischar(n)	(((n) & ~BYTEMASK) == 0)

#ifdef EUC
#ifdef NROFF
#define CSMASK	0x6000	/* colunm of print identifier */
#define MBMASK	0x1c00	/* bits identifying position in a multibyte char */
#define MBMASK1	0x1800
#define FIRSTOFMB	0x1000
#define MIDDLEOFMB	0x0800
#define LASTOFMB	0x0400
#define BYTE_CHR	0x0000
#define	cs(n)	(((n) & CSMASK) >> 13)	/* colum of print of character */
#define	setcsbits(n,c)	n = ((n & ~CSMASK) | ((c) << 13))
#define CHMASK	(BYTEMASK | CSMASK | MBMASK)
#define ZWDELIM1	ZBIT | FIRSTOFMB | ' '	/* non-ASCII word delimiter 1 */
#define ZWDELIM2	ZBIT | MIDDLEOFMB | ' '	/* non-ASCII word delimiter 2 */
#define ZWDELIM(c)	((c) == 0) ? ' ' : ((c) == 1) ? ZWDELIM1 : ZWDELIM2
#endif /* NROFF */
#endif /* EUC */

#define	ZONE	5	/* 5 hrs for EST */
#define	TABMASK	0x3FFFFFFF
#define	RTAB	(unsigned) 0x80000000
#define	CTAB	0x40000000

#define	TABBIT	02		/* bits in gchtab */
#define	LDRBIT	04
#define	FCBIT	010

#define	PAIR(A,B)	(A|(B<<BYTE))

#ifndef EUC
#define	oput(c)	if ((*obufp++ = (c)), obufp >= &obuf[OBUFSZ]) flusho(); else
#else
#ifdef notdef
#ifndef NROFF
#define	oput(c)	if ((*obufp++ = (c)), obufp >= &obuf[OBUFSZ]) flusho(); else
#endif /* NROFF */
#endif
#define	oput(c)	if ((*obufp++ = cbits(c) & BYTEMASK), obufp >= &obuf[OBUFSZ]) flusho(); else
#endif /* EUC */

/*
 * "temp file" parameters.  macros and strings
 * are stored in an array of linked blocks,
 * which may be in memory and an array called
 * corebuf[], if INCORE is set during
 * compilation, or otherwise in a file called trtmp$$.

 * The numerology is delicate if filep is 16 bits:
	#define BLK 128
	#define NBLIST 512
 * i.e., the product is 16 bits long.

 * If filep is an unsigned long (and if your
 * compiler will let you say that) then NBLIST
 * can be a lot bigger.  Of course that makes
 * the file or core image a lot bigger too,
 * and means you don't detect missing diversion
 * terminations as quickly... .
 * It also means that you may have trouble running
 * on non-swapping systems, since the core image
 * will be over 1Mb.

 * Note: As of 8/14/05, NBLIST has gone, and filep is
 * grown dynamically as needed. XBLIST is an just an
 * uninteresting relict to pass a special value.

 * BLK must be a power of 2
 */

typedef unsigned int filep;	/* this is good for 32 bit machines */

#define	BLK	128	/* alloc block in tchars */

#define	XBLIST	077777777

/* Other things are stored in the temp file or corebuf:
 *	a single block for .rd input, at offset RD_OFFSET
 *	NEV copies of the environment block, at offset ENV_OFFSET

 * The existing implementation assumes very strongly that
 * these are respectively NBLIST*BLK and 0.

 */

#define	RD_OFFSET	(NBLIST * BLK)
#define ENV_OFFSET	0
#define	ENV_BLK		((NEV * sizeof(env) / sizeof(tchar) + BLK-1) / BLK)
				/* rounded up to even BLK */

typedef	long long	tchar;

#define	atoi()		((int) atoi0())

extern	int	Inch, Hor, Vert, Unitwidth;

/* BSD systems have a function devname(); avoid a collision */
#define	devname	troff_devname

/* these characters are used as various signals or values
 * in miscellaneous places.
 * values are set in specnames in t10.c
 */

extern int	c_hyphen;
extern int	c_emdash;
extern int	c_rule;
extern int	c_minus;
extern int	c_fi;
extern int	c_fl;
extern int	c_ff;
extern int	c_ffi;
extern int	c_ffl;
extern int	c_acute;
extern int	c_grave;
extern int	c_under;
extern int	c_rooten;
extern int	c_boxrule;
extern int	c_lefthand;
extern int	c_dagger;

/*
 * <widec.h> includes <stdio.h> which defines
 * stderr. So undef it if it is already defined.
 */
#ifdef stderr
#	undef stderr
#endif
extern int	stderr;	/* this is NOT the stdio value! */

#ifdef	DEBUG
extern	int	debug;	/*debug flag*/
#define	DB_MAC	01	/*print out macro calls*/
#define	DB_ALLC	02	/*print out message from alloc()*/
#define	DB_GETC	04	/*print out message from getch()*/
#define	DB_LOOP	010	/*print out message before "Eileen's loop" fix*/
#endif	/* DEBUG */

struct	d {	/* diversion */
	filep	op;
	int	dnl;
	int	dimac;
	int	ditrap;
	int	ditf;
	int	alss;
	int	blss;
	int	nls;
	int	mkline;
	int	maxl;
	int	hnl;
	int	curd;
};

struct	s {	/* stack frame */
	int	nargs;
	struct s *pframe;
	filep	pip;
	int	pnchar;
	tchar	prchar;
	int	ppendt;
	tchar	pch;
	int	lastpbp;
	int	mname;
};

extern struct contab {
	unsigned int	rq;
	struct	contab *link;
	void	(*f)(int);
	unsigned mx;
} *contab;
extern const struct contab initcontab[];

extern struct numtab {
	int	r;		/* name */
	short	fmt;
	int	inc;
	int	val;
	struct	numtab *link;
} *numtab;
extern const struct numtab initnumtab[];

#define	PN	0
#define	NL	1
#define	YR	2
#define	HP	3
#define	CT	4
#define	DN	5
#define	MO	6
#define	DY	7
#define	DW	8
#define	LN	9
#define	DL	10
#define	ST	11
#define	SB	12
#define	CD	13
#define	PID	14

/* the infamous environment block */

#define	ics	env._ics
#define	sps	env._sps
#define	ses	env._ses
#define	spacesz	env._spacesz
#define	lss	env._lss
#define	lss1	env._lss1
#define	ll	env._ll
#define	ll1	env._ll1
#define	lt	env._lt
#define	lt1	env._lt1
#define	ic	env._ic
#define	icf	env._icf
#define	chbits	env._chbits
#define	spbits	env._spbits
#define	nmbits	env._nmbits
#define	apts	env._apts
#define	apts1	env._apts1
#define	pts	env._pts
#define	pts1	env._pts1
#define	font	env._font
#define	font1	env._font1
#define	ls	env._ls
#define	ls1	env._ls1
#define	ad	env._ad
#define	nms	env._nms
#define	ndf	env._ndf
#define	fi	env._fi
#define	cc	env._cc
#define	c2	env._c2
#define	ohc	env._ohc
#define	tdelim	env._tdelim
#define	hyf	env._hyf
#define	hyoff	env._hyoff
#define	un1	env._un1
#define	tabc	env._tabc
#define	dotc	env._dotc
#define	adsp	env._adsp
#define	adrem	env._adrem
#define	lastl	env._lastl
#define	nel	env._nel
#define	admod	env._admod
#define	wordp	env._wordp
#define	spflg	env._spflg
#define	linep	env._linep
#define	wdend	env._wdend
#define	wdstart	env._wdstart
#define	wne	env._wne
#define	ne	env._ne
#define	nc	env._nc
#define	nb	env._nb
#define	lnmod	env._lnmod
#define	nwd	env._nwd
#define	nn	env._nn
#define	ni	env._ni
#define	ul	env._ul
#define	cu	env._cu
#define	ce	env._ce
#define	in	env._in
#define	in1	env._in1
#define	un	env._un
#define	wch	env._wch
#define	pendt	env._pendt
#define	pendw	env._pendw
#define	pendnf	env._pendnf
#define	spread	env._spread
#define	it	env._it
#define	itmac	env._itmac
#define	lnsize	env._lnsize
#define	hyptr	env._hyptr
#define	tabtab	env._tabtab
#define	line	env._line
#define	word	env._word

extern struct env {
	int	_ics;
	int	_sps;
	int	_ses;
	int	_spacesz;
	int	_lss;
	int	_lss1;
	int	_ll;
	int	_ll1;
	int	_lt;
	int	_lt1;
	tchar	_ic;
	int	_icf;
	tchar	_chbits;
	tchar	_spbits;
	tchar	_nmbits;
	int	_apts;
	int	_apts1;
	int	_pts;
	int	_pts1;
	int	_font;
	int	_font1;
	int	_ls;
	int	_ls1;
	int	_ad;
	int	_nms;
	int	_ndf;
	int	_fi;
	int	_cc;
	int	_c2;
	int	_ohc;
	int	_tdelim;
	int	_hyf;
	int	_hyoff;
	int	_un1;
	int	_tabc;
	int	_dotc;
	int	_adsp;
	int	_adrem;
	int	_lastl;
	int	_nel;
	int	_admod;
	tchar	*_wordp;
	int	_spflg;
	tchar	*_linep;
	tchar	*_wdend;
	tchar	*_wdstart;
	int	_wne;
	int	_ne;
	int	_nc;
	int	_nb;
	int	_lnmod;
	int	_nwd;
	int	_nn;
	int	_ni;
	int	_ul;
	int	_cu;
	int	_ce;
	int	_in;
	int	_in1;
	int	_un;
	int	_wch;
	int	_pendt;
	tchar	*_pendw;
	int	_pendnf;
	int	_spread;
	int	_it;
	int	_itmac;
	int	_lnsize;
	tchar	*_hyptr[NHYP];
	int	_tabtab[NTAB];
	tchar	_line[LNSIZE];
	tchar	_word[WDSIZE];
} env, initenv;

/* n1.c */
int tryfile(char *, char *, int);
void catch(int);
void kcatch(int);
void init0(void);
void init1(char);
void init2(void);
void cvtime(void);
int ctoi(register char *);
void mesg(int);
void errprint(const char *, ...);
void fdprintf(int, char *, ...);
char *roff_sprintf(char *, char *, ...);
int control(register int, register int);
int getrq(void);
tchar getch(void);
void setxon(void);
tchar getch0(void);
void pushback(register tchar *);
void cpushback(register char *);
tchar *growpbbuf(void);
int nextfile(void);
int popf(void);
void flushi(void);
int getach(void);
void casenx(void);
int getname(void);
void caseso(void);
void caself(void);
void casecf(void);
void casesy(void);
void getpn(register char *);
void setrpt(void);
void casedb(void);
void casexflag(void);
/* n2.c */
int pchar(register tchar);
void pchar1(register tchar);
void outascii(tchar);
void oputs(register char *);
void flusho(void);
void done(int);
void done1(int);
void done2(int);
void done3(int);
void edone(int);
void casepi(void);
/* n3.c */
void *growcontab(void);
void *growblist(void);
void caseig(void);
void casern(void);
void maddhash(register struct contab *);
void munhash(register struct contab *);
void mrehash(void);
void caserm(void);
void caseas(void);
void caseds(void);
void caseam(void);
void casede(void);
int findmn(register int);
void clrmn(register int);
filep finds(register int);
int skip(void);
int copyb(void);
void copys(void);
filep alloc(void);
void ffree(filep);
void wbt(tchar);
void wbf(register tchar);
void wbfl(void);
tchar rbf(void);
tchar rbf0(register filep);
filep incoff(register filep);
tchar popi(void);
int pushi(filep, int);
char *setbrk(int);
int getsn(void);
int setstr(void);
void collect(void);
void seta(void);
void caseda(void);
void casedi(void);
void casedt(void);
void casetl(void);
void casepc(void);
void casechop(void);
void casepm(void);
void stackdump(void);
char *macname(int);
int maybemore(int, int);
/* n4.c */
void *grownumtab(void);
void setn(void);
int wrc(tchar);
void setn1(int, int, tchar);
void nrehash(void);
void nunhash(register struct numtab *);
int findr(register int);
int usedr(register int);
int fnumb(register int, register int (*)(tchar));
int decml(register int, register int (*)(tchar));
int roman(int, int (*)(tchar));
int roman0(int, int (*)(tchar), char *, char *);
int abc(int, int (*)(tchar));
int abc0(int, int (*)(tchar));
long atoi0(void);
long ckph(void);
long atoi1(register tchar);
void caserr(void);
void casenr(void);
void caseaf(void);
void setaf(void);
int vnumb(int *);
int hnumb(int *);
int inumb(int *);
int quant(int, int);
/* n5.c */
void save_tty(void);
void casead(void);
void casena(void);
void casefi(void);
void casenf(void);
void casers(void);
void casens(void);
int chget(int);
void casecc(void);
void casec2(void);
void casehc(void);
void casetc(void);
void caselc(void);
void casehy(void);
void casenh(void);
int max(int, int);
int min(int, int);
void casece(void);
void casein(void);
void casell(void);
void caselt(void);
void caseti(void);
void casels(void);
void casepo(void);
void casepl(void);
void casewh(void);
void casech(void);
int findn(int);
void casepn(void);
void casebp(void);
void casetm(int);
void casesp(int);
void casert(void);
void caseem(void);
void casefl(void);
void caseev(void);
void caseevc(void);
void caseel(void);
void caseie(void);
void caseif(int);
void casereturn(void);
void eatblk(int);
int cmpstr(tchar);
void caserd(void);
int rdtty(void);
void caseec(void);
void caseeo(void);
void caseta(void);
void casene(void);
void casetr(void);
void casecu(void);
void caseul(void);
void caseuf(void);
void caseit(void);
void casemc(void);
void casemk(void);
void casesv(void);
void caseos(void);
void casenm(void);
void getnm(int *, int);
void casenn(void);
void caseab(void);
void restore_tty(void);
void set_tty(void);
void echo_off(void);
void echo_on(void);
/* n7.c */
int collectmb(tchar);
void tbreak(void);
void donum(void);
void text(void);
void nofill(void);
void callsp(void);
void ckul(void);
void storeline(register tchar, int);
void newline(int);
int findn1(int);
void chkpn(void);
int findt(int);
int findt1(void);
void eject(struct s *);
int movword(void);
void horiz(int);
void setnel(void);
int getword(int);
void storeword(register tchar, register int);
/* n8.c */
void hyphen(tchar *);
int punct(tchar);
int alph(tchar);
void caseht(void);
void casehw(void);
int exword(void);
int suffix(void);
int maplow(register int, int);
int vowel(int);
tchar *chkvow(tchar *);
void digram(void);
int dilook(int, int, const char [26][13]);
void casehylang(void);
/* n9.c */
tchar setz(void);
void setline(void);
int eat(register int);
void setov(void);
void setbra(void);
void setvline(void);
void setdraw(void);
void casefc(void);
tchar setfield(int);
void localize(void);
void caselc_ctype(void);
void morechars(int);
