/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
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
static const char *tags[] = { "", "", "▶", "", "" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
  /* class | instance | title | tags mask | isfloating |  monitor | scratch key | float x,y,w,h | floatborderpx */
	{ "Gimp",     NULL,     NULL,       0,        1,          -1,                   50,50,500,500,        5 },
	//{ NULL,  "Navigator",   NULL,     1 << 0,   0,          -1,                   50,50,500,500,        5 },
	{ "Brave-browser", NULL,   NULL,    1 << 0,   0,          -1,                   50,50,500,500,        5 },
	{ NULL,  "qutebrowser", NULL,       1 << 0,   0,          -1,                   50,50,500,500,        5 },
	{ "Steam",    NULL,     NULL,       1 << 4,   0,          -1,                   50,50,500,500,        5 },
	{ NULL,       NULL,     "Steam",    1 << 4,   0,          -1,                   50,50,500,500,        5 },
	{ "Bottles",  NULL,     NULL,       1 << 4,   0,          -1,                   50,50,500,500,        5 },
	{ "Zathura",  NULL,     NULL,       1 << 3,   0,          -1,                   50,50,500,500,        5 },
	{ "mpv",      NULL,     NULL,       1 << 2,   0,          -1,                   50,50,500,500,        5 },
	{ "Emacs",    NULL,     NULL,       1 << 1,   0,          -1,                   50,50,500,500,        5 },
	{ NULL,       NULL,   "scratchpad", 0,        1,          -1,        50,20,1200,400,     5 ,'s'},
	{ "fm",       NULL,    NULL,        0,        1,          -1,        50,20,1200,600,  5,   'f' },
	{ "cmus",     NULL,    NULL,        0,        1,          -1,        50,20,1200,600, 5, 'c' },
	{ "Vimiv",    NULL,    NULL,        0,        1,          -1,        50,20,1200,600, 5, 'v' },
	{ NULL,     "chromium",    NULL,    0,        1,          -1,        50,20,1250,700, 5,  'w' },
	{ NULL,     "Navigator",    NULL,   0,        1,          -1,        50,20,1250,700,  5,  'd' },
};

/* layout(s) */
static const float mfact     = 0.60; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
  { "()",    bstack },
	{ "()",    monocle },
	{ "><>",    NULL },    /* no layout function means floating behavior */
};

/* key definitions */
#define MODKEY Mod3Mask
#define ALTKEY Mod1Mask

#define TAGKEYS(KEY,TAG)												\
	{1, {{MODKEY, KEY}},								view,           {.ui = 1 << TAG} },	\
	{1, {{MODKEY|ControlMask, KEY}},					toggleview,     {.ui = 1 << TAG} }, \
	{1, {{MODKEY|ShiftMask, KEY}},						tag,            {.ui = 1 << TAG} }, \
	{1, {{MODKEY|ControlMask|ShiftMask, KEY}},			toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", bg, "-nf", fg2, "-sb", bg2, "-sf", option, NULL };
static const char *termcmd[]  = { "st", NULL };
static const char *volup[]    = { "volume.sh", "up", NULL };
static const char *voldw[]    = { "volume.sh", "down", NULL };
static const char *browser[]    = { "brave", NULL };
static const char *rgb_on[]   = { "xset", "led", "on", NULL };
static const char *rgb_off[]  = { "xset", "led", "off", NULL };

/*First arg only serves to match against key in rules*/
static const char *scratchpadcmd[] = {"s", "st", "-A", "0.6", "-t", "scratchpad", NULL};
static const char *filemanager[] = {"f", "st", "-c", "fm", "ranger", NULL};
static const char *cmus[] = {"c", "st", "-c", "cmus", "cmus", NULL};
static const char *vimiv[] = {"v", "vimvi", "/hom/aevim/.web/projects/frontend-mentor/", NULL};
static const char *dev_ch[] = {"w", "chromium", "http://127.0.0.1:8080", NULL};
static const char *dev_fx[] = {"d", "firefox", "http://127.0.0.1:8080", NULL};

#include "movestack.c"
static Keychord keychords[] = {
	/* Keys        function        argument */
	{1, {{MODKEY, XK_p}},							spawn,          {.v = dmenucmd } },
	{1, {{ALTKEY, XK_p}},							spawn,          {.v = dmenucmd } },
	{1, {{MODKEY, XK_t}},			        spawn,          {.v = termcmd } },
	{1, {{ALTKEY, XK_t}},			        spawn,          {.v = termcmd } },
	{1, {{MODKEY, XK_w}},			        spawn,          {.v = browser } },
	{1, {{ALTKEY, XK_i}},			        spawn,          {.v = volup } },
	{1, {{ALTKEY, XK_o}},			        spawn,          {.v = voldw } },
	{1, {{MODKEY, XK_b}},							togglebar,      {0} },
	{1, {{MODKEY, XK_j}},							focusstack,     {.i = +1 } },
	{1, {{MODKEY, XK_k}},							focusstack,     {.i = -1 } },
  {1, {{MODKEY|ShiftMask, XK_j}},   movestack,      {.i = +1 } },
  {1, {{MODKEY|ShiftMask, XK_k}},   movestack,      {.i = -1 } },
	{1, {{MODKEY, XK_i}},							incnmaster,     {.i = +1 } },
	{2, {{MODKEY, XK_s}, {0, XK_u}},  togglescratch,  {.v = scratchpadcmd } },
	{2, {{MODKEY, XK_s}, {0, XK_m}},  togglescratch,  {.v = cmus } },
	{2, {{MODKEY, XK_s}, {0, XK_f}},  togglescratch,  {.v = filemanager } },
	{2, {{MODKEY, XK_s}, {0, XK_v}},  togglescratch,  {.v = vimiv } },
	{1, {{MODKEY, XK_d}},							incnmaster,     {.i = -1 } },
	{1, {{MODKEY, XK_h}},							setmfact,       {.f = -0.05} },
	{1, {{MODKEY, XK_l}},							setmfact,       {.f = +0.05} },
	{1, {{MODKEY, XK_Return}},				zoom,           {0} },
	{1, {{MODKEY, XK_Tab}},						view,           {0} },
	{1, {{MODKEY|ShiftMask, XK_c}},		killclient,     {0} },
	{1, {{MODKEY, XK_space}},				  setlayout,      {0} },
	{1, {{MODKEY|ShiftMask, XK_space}},				togglefloating, {0} },
	{1, {{MODKEY, XK_0}},							view,           {.ui = ~0 } },
	{1, {{MODKEY|ShiftMask, XK_0}},					tag,            {.ui = ~0 } },
	{1, {{MODKEY, XK_comma}},						focusmon,       {.i = -1 } },
	{1, {{MODKEY, XK_period}},						focusmon,       {.i = +1 } },
	{1, {{MODKEY|ShiftMask, XK_comma}},				tagmon,         {.i = -1 } },
	{1, {{MODKEY|ShiftMask, XK_period}},			tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	{1, {{MODKEY|ShiftMask, XK_q}},					quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

