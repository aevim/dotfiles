/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const int gappx     = 5;                 /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int systraypinning = 0; /* 0: sloppy systray follows selected monitor,
    >0: pin systray to monitor X */
static const unsigned int systrayonleft = 0; /* 0: systray in the right corner, >0: systray
     on left of status text */
static const unsigned int systrayspacing = 2; /* systray spacing */
static const int systraypinningfailfirst = 1; /* 1: if pinning fails, display systray on the
    first monitor, False: display systray on the las
    t monitor*/
static const int showsystray        = 1;     /* 0 means no systray */
static const int showbar            = 1;     /* 0 means no bar */
static const int topbar             = 1;     /* 0 means bottom bar */
static const int focusonwheel       = 0;
static const char *fonts[]          = { "VictorMono:size=12" };
static const char dmenufont[]       = "VictorMono:size=12";
static const char bg[]              = "#282828";
static const char bg2[]             = "#504945";
static const char fg[]              = "#ebdbb2";
static const char fg2[]             = "#d5c4a1";
static const char option[]          = "#fe8019";
static const char *colors[][3]      = {
   /*               fg         bg         border   */
   [SchemeNorm] = { fg,        bg,       bg2 },
   [SchemeSel]  = { fg2,       bg2,      option },
};

/* tagging */
static const char *tags[] = { "", "", "▶", "", "" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
  /* class | instance | title | tags mask | isfloating |  monitor | scratch key | float x,y,w,h | floatborderpx */
	{ "Gimp",     NULL,     NULL,       0,        1,          -1,                   50,50,500,500,        5 },
	{ NULL,  "Navigator",   NULL,       1 << 0,   0,          -1,                   50,50,500,500,        5 },
	{ "Brave-browser", NULL,   NULL,       1 << 0,   0,       -1,                   50,50,500,500,        5 },
	{ NULL,  "qutebrowser", NULL,       1 << 0,   0,          -1,                   50,50,500,500,        5 },
	{ "Steam",    NULL,     NULL,       1 << 4,   0,          -1,                   50,50,500,500,        5 },
	{ "Zathura",  NULL,     NULL,       1 << 3,   0,          -1,                   50,50,500,500,        5 },
	{ "mpv",      NULL,     NULL,       1 << 2,   0,          -1,                   50,50,500,500,        5 },
	{ "Emacs",    NULL,     NULL,       1 << 1,   0,          -1,                   50,50,500,500,        5 },
  { NULL,       NULL,   "scratchpad", 0,        1,          -1,         's',      250,20,900,300,       5 },
  { NULL,       NULL,   "fm",         0,        1,          -1,         'f',      50,20,1200,600,       5 },
};

/* layout(s) */
static const float mfact     = 0.65; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
  { "TTT",    bstack },
	{ "",      monocle },
	{ "><>",    NULL },    /* no layout function means floating behavior */
};

/* key definitions */
#define MODKEY Mod3Mask
#define ALTKEY Mod1Mask
#define SUPERKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ ALTKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },
#define STACKKEYS(MOD,ACTION) \
	{ MOD, XK_j,     ACTION##stack, {.i = INC(+1) } }, \
	{ MOD, XK_k,     ACTION##stack, {.i = INC(-1) } }, \
	{ MOD, XK_grave, ACTION##stack, {.i = PREVSEL } }, \
	{ MOD, XK_q,     ACTION##stack, {.i = 0 } }, \
	{ MOD, XK_a,     ACTION##stack, {.i = 1 } }, \
	{ MOD, XK_z,     ACTION##stack, {.i = 2 } }, \
	{ MOD, XK_x,     ACTION##stack, {.i = -1 } },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", bg, "-nf", fg2, "-sb", bg2, "-sf", option, NULL };
static const char *termcmd[]  = { "st", NULL };
static const char *volup[]    = { "volume.sh", "up", NULL };
static const char *voldw[]    = { "volume.sh", "down", NULL };
static const char *emacs[]    = { "emacsclient", "-c", "-a", "'emacs'", NULL };
static const char *rgb_on[]   = { "xset", "led", "on", NULL };
static const char *rgb_off[]  = { "xset", "led", "off", NULL };

/*First arg only serves to match against key in rules*/
static const char *scratchpadcmd[] = {"s", "st", "-t", "scratchpad", NULL};
static const char *filemanager[] = {"f", "st", "-t", "fm", "ranger", NULL};

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_r,      spawn,          {.v = dmenucmd } },
	{ ALTKEY,                       XK_r,      spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_t,      spawn,          {.v = termcmd } },
	{ ALTKEY,                       XK_t,      spawn,          {.v = termcmd } },
	{ ALTKEY,                       XK_i,      spawn,          {.v = volup } },
	{ ALTKEY,                       XK_o,      spawn,          {.v = voldw } },
	{ MODKEY,                       XK_e,      spawn,          {.v = emacs } },
  { ALTKEY,                       XK_u,      togglescratch,  {.v = scratchpadcmd } },
  { ALTKEY,                       XK_m,      togglescratch,  {.v = filemanager } },
	{ 0,                            XK_Prior,  spawn,          {.v = rgb_on } },
	{ 0,                            XK_Next,   spawn,          {.v = rgb_off } },
	{ MODKEY|ShiftMask,             XK_b,      togglebar,      {0} },
  STACKKEYS(MODKEY,                          focus)
	STACKKEYS(MODKEY|ShiftMask,                push)
	{ ALTKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ ALTKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_b,      view,           {0} },
	{ MODKEY,                       XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_8,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_9,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_0,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_f,      setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_minus,  setgaps,        {.i = -5 } },
	{ MODKEY,                       XK_equal,  setgaps,        {.i = +5 } },
	{ MODKEY|ShiftMask,             XK_equal,  setgaps,        {.i = 0  } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
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
};

