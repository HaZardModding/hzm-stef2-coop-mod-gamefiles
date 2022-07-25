resource 
Label
{
	cvarvisibility coop_ui_vt 20 ==
	
	title "$$c#041$$"
	name "coopHzmTestLevelsTitle"
	rect		274 89 330 24
	fgcolor 1.000 0.000 0.000 0.800
	bgcolor 0.12 0.15 0.25 1.00
	
	borderstyle "3D_BORDER"
	
	horizontaljustify left
	verticaljustify top
	font 	serpentinemedium-10
	
	hovercommand "globalwidgetcommand tooltip_callvote title \"\""
    hoverexitcommand "globalwidgetcommand tooltip_callvote title \"\""
}

resource
Button
{
	title "$$next$$"
	name 	"coopHzmTestLevelsButtonNext0"
	rect	543 90 60 22
	font serpentinemedium-10
	fgcolor			0.937 0.643 0.129 1.000
	bgcolor			0.125 0.157 0.251 1.000
	hoverbgcolor	0.278 0.365 0.510 1.000
	hoverfgcolor	1.000 1.000 1.000 1.000
	borderstyle "3D_BORDER"
	hovershader menu/generic/button-hover
	pressedshader menu/generic/button-press
    clicksound sound/misc/menu/click.wav
	stuffcommand "seta coop_ui_vt 21\n"
    verticaljustify top	
	cvarvisibility coop_ui_vt 20 ==
}

resource
Button
{
	cvarvisibility coop_ui_vt 20 ==
	title "Coop NoScript Example"
	name 	"coopHzmTestLevels0"
	rect	275 114 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map coop_noscript_example;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 20 ==
	title "Prefab Animation"
	name 	"coopHzmTestLevels1"
	rect	275 135 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map prf_animate;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 20 ==
	title "Prefab Bind"
	name 	"coopHzmTestLevels2"
	rect	275 156 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map prf_bind;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 20 ==
	title "Prefab Callvolume"
	name 	"coopHzmTestLevels3"
	rect	275 177 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map prf_callvolume;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 20 ==
	title "Prefab Cinematic"
	name 	"coopHzmTestLevels4"
	rect	275 198 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map prf_cinematic;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 20 ==
	title "Prefab Destructible"
	name 	"coopHzmTestLevels5"
	rect	275 219 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map prf_destructible;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 20 ==
	title "Prefab Destructible Vanish"
	name 	"coopHzmTestLevels6"
	rect	275 240 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map prf_destructiblevanish;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 20 ==
	title "Prefab Dialog"
	name 	"coopHzmTestLevels7"
	rect	275 261 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map prf_dialog;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 20 ==
	title "Prefab Doors"
	name 	"coopHzmTestLevels8"
	rect	275 282 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map prf_doors;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 20 ==
	title "Prefab Everyone"
	name 	"coopHzmTestLevels9"
	rect	275 303 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map prf_everyone;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 20 ==
	title "Prefab Forcefield"
	name 	"coopHzmTestLevels10"
	rect	275 324 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map prf_forcefield;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 20 ==
	title "Prefab Heal"
	name 	"coopHzmTestLevels11"
	rect	275 345 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map prf_heal;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 20 ==
	title "Prefab Bioscanner"
	name 	"coopHzmTestLevels12"
	rect	275 366 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map prf_bioscanner;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource 
Label
{
	cvarvisibility coop_ui_vt 21 ==
	
	title "$$c#041$$"
	name "coopHzmTestLevelsTitle2"
	rect		274 89 330 24
	fgcolor 1.000 0.000 0.000 0.800
	bgcolor 0.12 0.15 0.25 1.00
	
	borderstyle "3D_BORDER"
	
	horizontaljustify left
	verticaljustify top
	font 	serpentinemedium-10
	
	hovercommand "globalwidgetcommand tooltip_callvote title \"Test levels from HaZardModding...\""
    hoverexitcommand "globalwidgetcommand tooltip_callvote title \"\""
}
resource
Button
{
	title "$$next$$"
	name 	"coopHzmTestLevelsButtonNext1"
	rect	543 90 60 22
	font serpentinemedium-10
	fgcolor			0.937 0.643 0.129 1.000
	bgcolor			0.125 0.157 0.251 1.000
	hoverbgcolor	0.278 0.365 0.510 1.000
	hoverfgcolor	1.000 1.000 1.000 1.000
	borderstyle "3D_BORDER"
	hovershader menu/generic/button-hover
	pressedshader menu/generic/button-press
    clicksound sound/misc/menu/click.wav
	stuffcommand "seta coop_ui_vt 22\n"
    verticaljustify top
	
	cvarvisibility coop_ui_vt 21 ==
}
resource
Button
{
	cvarvisibility coop_ui_vt 21 ==
	title "Prefab Hud"
	name 	"coopHzmTestLevels13"
	rect	275 114 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map prf_hud;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 21 ==
	title "Prefab Hurt"
	name 	"coopHzmTestLevels14"
	rect	275 135 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map prf_hurt;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 21 ==
	title "Prefab Immobilize"
	name 	"coopHzmTestLevels15"
	rect	275 156 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map prf_immobilize;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 21 ==
	title "Prefab Lock"
	name 	"coopHzmTestLevels16"
	rect	275 177 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map prf_lock;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 21 ==
	title "Prefab Load Map"
	name 	"coopHzmTestLevels17"
	rect	275 198 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map prf_map;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 21 ==
	title "Prefab Objective"
	name 	"coopHzmTestLevels18"
	rect	275 219 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map prf_objective;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 21 ==
	title "Prefab Puzzle"
	name 	"coopHzmTestLevels19"
	rect	275 240 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map prf_puzzle;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 21 ==
	title "Prefab Remove"
	name 	"coopHzmTestLevels20"
	rect	275 261 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map prf_remove;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 21 ==
	title "Prefab Respawn"
	name 	"coopHzmTestLevels21"
	rect	275 282 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map prf_respawn;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 21 ==
	title "Prefab Savegame"
	name 	"coopHzmTestLevels22"
	rect	275 303 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map prf_savegame;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 21 ==
	title "Prefab Selection Move"
	name 	"coopHzmTestLevels23"
	rect	275 324 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map prf_selectionmove;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 21 ==
	title "Prefab Rotating Doors"
	name 	"coopHzmTestLevels24"
	rect	275 345 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map prf_doorsRotating;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 21 ==
	title "Prefab Walkto"
	name 	"coopHzmTestLevels25"
	rect	275 366 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map prf_walkto;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Label
{
	cvarvisibility coop_ui_vt 22 ==
	
	title "$$c#041$$"
	name "coopHzmTestLevelsTitle4"
	rect		274 89 330 24
	fgcolor 1.000 0.000 0.000 0.800
	bgcolor 0.12 0.15 0.25 1.00
	
	borderstyle "3D_BORDER"
	
	horizontaljustify left
	verticaljustify top
	font 	serpentinemedium-10
	
	hovercommand "globalwidgetcommand tooltip_callvote title \"Test levels from HaZardModding...\""
    hoverexitcommand "globalwidgetcommand tooltip_callvote title \"\""
}
resource
Button
{
	title "$$next$$"
	name 	"coopHzmTestLevelsButtonNext2"
	rect	543 90 60 22
	font serpentinemedium-10
	fgcolor			0.937 0.643 0.129 1.000
	bgcolor			0.125 0.157 0.251 1.000
	hoverbgcolor	0.278 0.365 0.510 1.000
	hoverfgcolor	1.000 1.000 1.000 1.000
	borderstyle "3D_BORDER"
	hovershader menu/generic/button-hover
	pressedshader menu/generic/button-press
    clicksound sound/misc/menu/click.wav
	stuffcommand "seta coop_ui_vt 20\n"
    verticaljustify top
	
	cvarvisibility coop_ui_vt 22 ==
}
resource
Button
{
	cvarvisibility coop_ui_vt 22 ==
	title "Prefab Weapon"
	name 	"coopHzmTestLevels27"
	rect	275 114 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map prf_weapon;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 22 ==
	title "Prefab Cinematic 2"
	name 	"coopHzmTestLevels28"
	rect	275 135 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map prf_cinematic2;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 22 ==
	title "Prefab Fallschirmspringer"
	name 	"coopHzmTestLevels29"
	rect	275 156 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map prf_fallschirmspringer;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 22 ==
	title "Prefab Multi Options Menu (MOM)"
	name 	"coopHzmTestLevels30"
	rect	275 177 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map prf_multioptions;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 22 ==
	title "Prefab Borg Work"
	name 	"coopHzmTestLevels31"
	rect	275 198 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map prf_borgWork;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 22 ==
	title "Prefab Rotating Doors"
	name 	"coopHzmTestLevels32"
	rect	275 219 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map prf_doorsRotating;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 22 ==
	title "Prefab Group Death Thread"
	name 	"coopHzmTestLevels33"
	rect	275 240 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map prf_groupdeath;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 22 ==
	title "Prefab Teammate"
	name 	"coopHzmTestLevels34"
	rect	275 261 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map prf_teammate;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 22 ==
	title "Prefab Lead Player"
	name 	"coopHzmTestLevels35"
	rect	275 282 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map prf_leadplayer;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 22 ==
	title "Prefab Bat'leth Teammate"
	name 	"coopHzmTestLevels35"
	rect	275 303 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map prf_batlethteammate;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 22 ==
	title "Prefab Triggerish"
	name 	"coopHzmTestLevels36"
	rect	275 324 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map prf_triggerish;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 22 ==
	title "Prefab Mission Resource Managment"
	name 	"coopHzmTestLevels37"
	rect	275 345 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map prf_mrm;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
end.

