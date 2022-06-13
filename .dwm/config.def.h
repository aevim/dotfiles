/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft = 0;   	/* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;     /* 0 means no systray */
static const int showbar            = 1;     /* 0 means no bar */
static const int topbar             = 1;     /* 0 means bottom bar */
/*  Display modes of the tab bar: never shown, always shown, shown only in  */
/*  monocle mode in the presence of several windows.                        */
/*  Modes after showtab_nmodes are disabled.                                */
enum showtab_modes { showtab_never, showtab_auto, showtab_nmodes, showtab_always};
static const int showtab     = showtab_auto;        /* Default tab bar show mode */
static const int toptab        = True;               /* False means bottom tab bar */
static const char *fonts[]          = { "Monoid Nerd Font Mono:size=12" };
static const char dmenufont[]       = "Monoid Nerd Font Mono:size=12";
static const char bg[]       = "#282a36";
static const char bg2[]      = "#44475a";
static const char fg[]       = "#f8f8f2";
static const char fg2[]      = "#8be9fd";
static const char option[]   = "#ff79c6";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { fg,        bg,       option },
	[SchemeSel]  = { fg2,       bg2,      bg2  },
};

static const char *const autostart[] = {
  "hsetroot", "-solid", "#282a36", NULL,
  "xrandr", "--output", "VGA-1", "--gamma", "1.0:0.88:0.90", "--brightness", "0.95", NULL,
  "dunst", NULL,
  "unclutter", NULL,
  "run_xidlehook", NULL,
  "safeeyes", NULL,
  "xcape", "-e", "Control_L=Escape", NULL,
	NULL /* terminate */
};

/* tagging */
static const char *tags[] = { "a", "s", "d", "f", "h", "j", "k", "l" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
  /* class      instance    title       tags mask     isfloating   monitor    float x,y,w,h         floatborderpx*/
  { "Gimp",     NULL,       NULL,       0,            1,           -1,        50,50,500,500,        5 },
  { "firefox",  NULL,       NULL,       1 << 1,       0,           -1,        50,50,500,500,        5 },
  { "qutebrowser",  NULL,       NULL,       1 << 1,       0,           -1,        50,50,500,500,        5 },
  { "Steam",    NULL,       NULL,       1 << 7,       1,           -1,        100,50,1200,640,        5 },
  { "Com.github.tchx84.Flatseal",    NULL,       NULL,       0,       1,           -1,        50,50,800,600,        5 },
	{ NULL,       NULL,   "scratchpad",   0,            1,           -1,        80,10,1200,300,        5, 's' },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[Ꙫ]",      monocle },
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
};

/* key definitions */
#define MODKEY Mod3Mask
#define MODKEY2 Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY2,                      KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },
#define STACKKEYS(MOD,ACTION) \
	{ MOD, XK_n,     ACTION##stack, {.i = INC(+1) } }, \
	{ MOD, XK_p,     ACTION##stack, {.i = INC(-1) } }, \
	{ MOD, XK_b,     ACTION##stack, {.i = PREVSEL } }, \
	{ MOD, XK_q,     ACTION##stack, {.i = 0 } }, \
	{ MOD, XK_e,     ACTION##stack, {.i = 1 } }, \
	{ MOD, XK_z,     ACTION##stack, {.i = 2 } }, \
	{ MOD, XK_x,     ACTION##stack, {.i = -1 } },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", bg, "-nf", fg, "-sb", bg2, "-sf", fg2, NULL };
static const char *termcmd[]  = { "st", "-A 100", NULL };
/*First arg only serves to match against key in rules*/
static const char *scratchpadcmd[] = {"s", "st", "-t", "scratchpad", NULL}; 
static const char *volup[] = {"volume.sh", "up", NULL}; 
static const char *voldown[] = {"volume.sh", "down", NULL}; 
static const char *closepop[] = {"dunstctl", "close-all", NULL}; 
static const char *pymor[] = {"pymor", "-p", "20", "-l", "3", NULL}; 

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_r,      spawn,          {.v = dmenucmd } },
	{ MODKEY2,                      XK_r,      spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_t,      spawn,          {.v = termcmd } },
	{ MODKEY2,                      XK_t,      spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_u,      togglescratch,  {.v = scratchpadcmd } },
	{ MODKEY|ShiftMask,             XK_u,      spawn,          {.v = volup } },
	{ MODKEY|ShiftMask,             XK_d,      spawn,          {.v = voldown } },
	{ MODKEY|ShiftMask,             XK_p,      spawn,          {.v = pymor } },
	{ MODKEY|ShiftMask,             XK_c,      spawn,          {.v = closepop } },
	{ MODKEY|ShiftMask,             XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_w,      tabmode,        {-1} },
  STACKKEYS(MODKEY,                          focus)
  STACKKEYS(MODKEY|ShiftMask,                push)
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_m,      incnmaster,     {.i = -1 } },
	{ MODKEY|ControlMask,           XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY|ControlMask,           XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_space,  view,           {0} },
	{ MODKEY,                       XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_1,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_2,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_3,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_9,      setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY|ShiftMask,             XK_f,      togglefullscr,  {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_a,                      0)
	TAGKEYS(                        XK_s,                      1)
	TAGKEYS(                        XK_d,                      2)
	TAGKEYS(                        XK_f,                      3)
	TAGKEYS(                        XK_h,                      4)
	TAGKEYS(                        XK_j,                      5)
	TAGKEYS(                        XK_k,                      6)
	TAGKEYS(                        XK_l,                      7)
  { MODKEY|ShiftMask,             XK_BackSpace, quit,        {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
	{ ClkTagBar,            0,              Button1,        focuswin,       {0} },
};

