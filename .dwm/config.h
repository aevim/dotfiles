/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int focusonwheel       = 0;
static const char *fonts[]          = { "FiraCode Nerd Font:size=10" };
static const char dmenufont[]       = "FiraCode Nerd Font:size=10";
static const char bg[]              = "#0f111b";
static const char bg2[]             = "#1b1c36";
static const char fg[]              = "#ecf0c1";
static const char fg2[]             = "#ce6f8f";
static const char option[]          = "#5ccc96";
static const char *colors[][3]      = {
   /*               fg         bg         border   */
   [SchemeNorm] = { fg,        bg,       bg2 },
   [SchemeSel]  = { fg2,       bg2,      option },
};

/* tagging */
static const char *tags[] = { "", "", "", "龎", "", "" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor    float x,y,w,h         floatborderpx*/
	{ "Gimp",     NULL,       NULL,       0,            1,           -1,        50,50,500,500,        5 },
	{ "Brave-browser", NULL,NULL,       1 << 0,   0,          -1,                   50,50,500,500,        5 },
	{ NULL,  "qutebrowser", NULL,       1 << 0,   0,          -1,                   50,50,500,500,        5 },
	{ NULL,       NULL,     "st",       1 << 5,   0,          -1,                   50,50,500,500,        5 },
	{ "Steam",    NULL,     NULL,       1 << 4,   0,          -1,                   50,50,500,500,        5 },
	{ NULL,       NULL,     "Steam",    1 << 4,   0,          -1,                   50,50,500,500,        5 },
	{ "Bottles",  NULL,     NULL,       1 << 4,   0,          -1,                   50,50,500,500,        5 },
	{ "Zathura",  NULL,     NULL,       1 << 3,   0,          -1,                   50,50,500,500,        5 },
	{ "mpv",      NULL,     NULL,       1 << 2,   0,          -1,                   50,50,500,500,        5 },
	{ NULL,  "Navigator",   NULL,       1 << 1,   0,          -1,                   50,50,500,500,        5 },
	{ "Emacs",    NULL,     NULL,       1 << 0,   0,          -1,                   50,50,500,500,        5 },
	{ "dev-e",    NULL,     NULL,       1 << 0,   0,          -1,                   50,50,500,500,        5 },
	{ NULL,       NULL,   "scratchpad",   0,            1,           -1,   's',  60,20,1200,400, 5 },
	{ "fm",       NULL,    NULL,        0,        1,          -1,           'f',        60,20,1200,600,       5, },
	{ "cmus",     NULL,    NULL,        0,        1,          -1,              'c',     60,20,1200,600,       5,  },
	{ "Vimiv",    NULL,    NULL,        0,        1,          -1,          'v',         60,20,1200,600,       5,  },
	{ "trayer",   NULL,    NULL,        0,        1,          -1,            'o',       60,20,1200,600,       5,  },
	{ "wikiman",  NULL,    NULL,        0,        1,          -1,            'i',       60,20,1200,600,       5,  },
	{ NULL,     "chromium",    NULL,    0,        1,          -1,              'w',     50,20,1250,700,       5,  },
	{ NULL,     "librewolf",    NULL,   0,        1,          -1,           'd',        50,20,1250,700,       5,  },


};

/* layout(s) */
static const float mfact     = 0.65; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "TTT",      bstack },
	{ "[M]",      monocle },
	{ "><>",      NULL },    /* no layout function means floating behavior */
};

/* key definitions */
#define MODKEY Mod3Mask
#define SUPER Mod4Mask
#define TAGKEYS(KEY,TAG)												\
	&((Keychord){1, {{MODKEY, KEY}},								view,           {.ui = 1 << TAG} }), \
		&((Keychord){1, {{MODKEY|ControlMask, KEY}},					toggleview,     {.ui = 1 << TAG} }), \
		&((Keychord){1, {{MODKEY|ShiftMask, KEY}},						tag,            {.ui = 1 << TAG} }), \
		&((Keychord){1, {{MODKEY|ControlMask|ShiftMask, KEY}},			toggletag,      {.ui = 1 << TAG} }),

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", bg, "-nf", fg, "-sb", option, "-sf", fg2, NULL };
static const char *termcmd[]  = { "st", NULL };
static const char *pymor[]  = { "pymor", "-p", "20", "l", "3", NULL };
static const char *pymorStop[]  = { "pymor", "-c", NULL };
static const char *emacs[]         = {"emacsclient","-c", "-a", "'emacs'", NULL};

// to control the volume
static const char *volup[]         = { "volume.sh", "up", NULL };
static const char *voldw[]         = { "volume.sh", "down", NULL };

static const char *browser[]       = { "firefox", NULL };

static const char *filemanager[]   = {"f", "st", "-c", "fm",  "sfm", NULL};
static const char *cmus[]          = {"c", "st", "-c", "cmus", "cmus", NULL};
static const char *trayer[]        = {
  "o", 
  "trayer", 
  "--transparent", "true", 
  "--alpha", "200", 
  "--tint", "0x282828", 
  "--widthtype", "request", 
  "--heighttype", "request",
  "--padding", "4",
  "--distance", "12",
  NULL
};

static const char *wikiman[]       = {"i", "st", "-c", "wikiman", "wikiman", NULL};
static const char *vimiv[]         = {"v", "vimvi", "/home/aevim/.web/projects/", NULL};
static const char *dev_ch[]        = {"w", "chromium", "http://127.0.0.1:8080", NULL};
static const char *dev_fx[]        = {"d", "librewolf", "http://127.0.0.1:8080", NULL};

// dunst
static const char *closePopUp[]    = { "dunstctl", "close-all", NULL};

// to ligh the keyboard rgb
static const char *rgb_on[]        = { "xset", "led", "on", NULL };
static const char *rgb_off[]       = { "xset", "led", "off", NULL };

// cmus-remote
static const char *cmus_play[]     = { "cmus-remote", "-p", NULL };
static const char *cmus_stop[]     = { "cmus-remote", "-u", NULL };
static const char *cmus_next[]     = { "cmus-remote", "-n", NULL };
static const char *cmus_prev[]     = { "cmus-remote", "-r", NULL };

/*First arg only serves to match against key in rules*/
static const char *scratchpadcmd[] = {"s", "st", "-t", "scratchpad", NULL}; 

#include "movestack.c"
static Keychord *keychords[] = {
	/* Keys        function        argument */
	// scratchpads
	&((Keychord){2, {{MODKEY, XK_s}, {0, XK_u}},					togglescratch,          {.v = scratchpadcmd } }),
	&((Keychord){1, {{MODKEY, XK_p}},							spawn,          {.v = dmenucmd } }),
	&((Keychord){1, {{MODKEY, XK_e}},							spawn,          {.v = dmenucmd } }),
	&((Keychord){1, {{MODKEY, XK_t}},			spawn,          {.v = termcmd } }),
	&((Keychord){2, {{SUPER, XK_p}, {0, XK_s}},			spawn,          {.v = pymor } }),
	&((Keychord){2, {{SUPER, XK_p}, {0, XK_o}},			spawn,          {.v = pymorStop } }),
	&((Keychord){1, {{MODKEY|ShiftMask, XK_j}},      			movestack,      {.i = +1 } }),
	&((Keychord){2, {{MODKEY|ShiftMask, XK_k}},      			movestack,      {.i = -1 } }),
	&((Keychord){1, {{MODKEY, XK_e}},			        spawn,          {.v = emacs } }),
	&((Keychord){1, {{MODKEY, XK_w}},			        spawn,          {.v = browser } }),
	&((Keychord){2, {{MODKEY, XK_d}, {0, XK_f}},  spawn,          {.v = dev_fx } }),
	&((Keychord){2, {{MODKEY, XK_d}, {0, XK_c}},  spawn,          {.v = dev_ch } }),
	&((Keychord){2, {{SUPER, XK_l}, {0, XK_o}},  spawn,          {.v = rgb_on } }),
	&((Keychord){2, {{SUPER, XK_l}, {0, XK_f}},  spawn,          {.v = rgb_off } }),
	&((Keychord){2, {{SUPER, XK_m}, 
        {ShiftMask, XK_p}},         spawn,          {.v = cmus_play } }),
	&((Keychord){2, {{SUPER, XK_m}, {0, XK_o}},  spawn,          {.v = cmus_stop } }),
	&((Keychord){2, {{SUPER, XK_m}, {0, XK_n}},  spawn,          {.v = cmus_next } }),
	&((Keychord){2, {{SUPER, XK_m}, {0, XK_p}},  spawn,          {.v = cmus_prev } }),
	&((Keychord){1, {{SUPER, XK_i}},			        spawn,          {.v = volup } }),
	&((Keychord){1, {{SUPER, XK_o}},			        spawn,          {.v = voldw } }),
	&((Keychord){1, {{SUPER, XK_h}},			        spawn,          {.v = closePopUp } }),

	&((Keychord){1, {{MODKEY, XK_b}},							togglebar,      {0} }),
	&((Keychord){1, {{MODKEY, XK_j}},							focusstack,     {.i = +1 } }),
	&((Keychord){1, {{MODKEY, XK_k}},							focusstack,     {.i = -1 } }),
	&((Keychord){1, {{MODKEY, XK_i}},							incnmaster,     {.i = +1 } }),
	&((Keychord){1, {{MODKEY, XK_d}},							incnmaster,     {.i = -1 } }),
	&((Keychord){1, {{MODKEY, XK_h}},							setmfact,       {.f = -0.05} }),
	&((Keychord){1, {{MODKEY, XK_l}},							setmfact,       {.f = +0.05} }),
	&((Keychord){1, {{MODKEY, XK_Return}},						zoom,           {0} }),
	&((Keychord){1, {{MODKEY, XK_Tab}},							view,           {0} }),
	&((Keychord){1, {{MODKEY|ShiftMask, XK_c}},					killclient,     {0} }),
	&((Keychord){1, {{MODKEY, XK_space}},						setlayout,      {0} }),
	&((Keychord){1, {{MODKEY|ShiftMask, XK_space}},				togglefloating, {0} }),
	&((Keychord){1, {{MODKEY, XK_0}},							view,           {.ui = ~0 } }),
	&((Keychord){1, {{MODKEY|ShiftMask, XK_0}},					tag,            {.ui = ~0 } }),
	&((Keychord){1, {{MODKEY, XK_comma}},						focusmon,       {.i = -1 } }),
	&((Keychord){1, {{MODKEY, XK_period}},						focusmon,       {.i = +1 } }),
	&((Keychord){1, {{MODKEY|ShiftMask, XK_comma}},				tagmon,         {.i = -1 } }),
	&((Keychord){1, {{MODKEY|ShiftMask, XK_period}},			tagmon,         {.i = +1 } }),
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_q,                      5)
	&((Keychord){1, {{MODKEY|ShiftMask, XK_q}},					quit,           {0} }),
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

