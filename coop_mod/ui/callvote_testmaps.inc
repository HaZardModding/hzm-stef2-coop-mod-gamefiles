resource 
Label
{
	cvarvisibility coop_ui_vt 20 ==
	
	title "$$c#041$$"
	name "coopHzmTestLvlCallvoteTitle"
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
	name 	"coopHzmTestLvlCallvoteButtonNext0"
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
	name 	"coopHzmTestLvlCallvote0"
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
	name 	"coopHzmTestLvlCallvote1"
	rect	275 135 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map coop_test-animate;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 20 ==
	title "Prefab Bind"
	name 	"coopHzmTestLvlCallvote2"
	rect	275 156 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map coop_test-bind;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 20 ==
	title "Prefab Callvolume"
	name 	"coopHzmTestLvlCallvote3"
	rect	275 177 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map coop_test-callvolume;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 20 ==
	title "Prefab Cinematic"
	name 	"coopHzmTestLvlCallvote4"
	rect	275 198 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map coop_test-cinematic;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 20 ==
	title "Prefab Destructible"
	name 	"coopHzmTestLvlCallvote5"
	rect	275 219 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map coop_test-destructible;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 20 ==
	title "Prefab Destructible Vanish"
	name 	"coopHzmTestLvlCallvote6"
	rect	275 240 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map coop_test-destructiblevanish;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 20 ==
	title "Prefab Dialog"
	name 	"coopHzmTestLvlCallvote7"
	rect	275 261 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map coop_test-dialog;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 20 ==
	title "Prefab Doors"
	name 	"coopHzmTestLvlCallvote8"
	rect	275 282 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map coop_test-doors;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 20 ==
	title "Prefab Everyone"
	name 	"coopHzmTestLvlCallvote9"
	rect	275 303 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map coop_test-everyone;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 20 ==
	title "Prefab Forcefield"
	name 	"coopHzmTestLvlCallvote10"
	rect	275 324 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map coop_test-forcefield;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 20 ==
	title "Prefab Heal"
	name 	"coopHzmTestLvlCallvote11"
	rect	275 345 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map coop_test-heal;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 20 ==
	title "Prefab Bioscanner"
	name 	"coopHzmTestLvlCallvote12"
	rect	275 366 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map coop_test-bioscanner;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource 
Label
{
	cvarvisibility coop_ui_vt 21 ==
	
	title "$$c#041$$"
	name "coopHzmTestLvlCallvoteTitle2"
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
	name 	"coopHzmTestLvlCallvoteButtonNext1"
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
	name 	"coopHzmTestLvlCallvote13"
	rect	275 114 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map coop_test-hud;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 21 ==
	title "Prefab Hurt"
	name 	"coopHzmTestLvlCallvote14"
	rect	275 135 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map coop_test-hurt;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 21 ==
	title "Prefab Immobilize"
	name 	"coopHzmTestLvlCallvote15"
	rect	275 156 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map coop_test-immobilize;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 21 ==
	title "Prefab Lock"
	name 	"coopHzmTestLvlCallvote16"
	rect	275 177 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map coop_test-lock;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 21 ==
	title "Prefab Load Map"
	name 	"coopHzmTestLvlCallvote17"
	rect	275 198 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map coop_test-map;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 21 ==
	title "Prefab Objective"
	name 	"coopHzmTestLvlCallvote18"
	rect	275 219 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map coop_test-objective;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 21 ==
	title "Prefab Puzzle"
	name 	"coopHzmTestLvlCallvote19"
	rect	275 240 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map coop_test-puzzle;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 21 ==
	title "Prefab Remove"
	name 	"coopHzmTestLvlCallvote20"
	rect	275 261 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map coop_test-remove;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 21 ==
	title "Prefab Respawn"
	name 	"coopHzmTestLvlCallvote21"
	rect	275 282 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map coop_test-respawn;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 21 ==
	title "Prefab Savegame"
	name 	"coopHzmTestLvlCallvote22"
	rect	275 303 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map coop_test-savegame;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 21 ==
	title "Prefab Selection Move"
	name 	"coopHzmTestLvlCallvote23"
	rect	275 324 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map coop_test-selectionmove;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 21 ==
	title "Prefab Rotating Doors"
	name 	"coopHzmTestLvlCallvote24"
	rect	275 345 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map coop_test-doorsRotating;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 21 ==
	title "Prefab Walkto"
	name 	"coopHzmTestLvlCallvote25"
	rect	275 366 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map coop_test-walkto;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Label
{
	cvarvisibility coop_ui_vt 22 ==
	
	title "$$c#041$$"
	name "coopHzmTestLvlCallvoteTitle3"
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
	name 	"coopHzmTestLvlCallvoteButtonNext2"
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
	stuffcommand "seta coop_ui_vt 23\n"
    verticaljustify top
	
	cvarvisibility coop_ui_vt 22 ==
}
resource
Button
{
	cvarvisibility coop_ui_vt 22 ==
	title "Prefab Weapon"
	name 	"coopHzmTestLvlCallvote27"
	rect	275 114 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map coop_test-weapon;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 22 ==
	title "Prefab Cinematic 2"
	name 	"coopHzmTestLvlCallvote28"
	rect	275 135 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map coop_test-cinematic2;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 22 ==
	title "Prefab Fallschirmspringer"
	name 	"coopHzmTestLvlCallvote29"
	rect	275 156 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map coop_test-fallschirmspringer;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 22 ==
	title "Prefab Multi Options Menu (MOM)"
	name 	"coopHzmTestLvlCallvote30"
	rect	275 177 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map coop_test-multioptions;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 22 ==
	title "Prefab Borg Work"
	name 	"coopHzmTestLvlCallvote31"
	rect	275 198 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map coop_test-borgWork;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 22 ==
	title "Prefab Group Death Thread"
	name 	"coopHzmTestLvlCallvote32"
	rect	275 219 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map coop_test-groupdeath;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 22 ==
	title "Prefab Teammate"
	name 	"coopHzmTestLvlCallvote33"
	rect	275 240 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map coop_test-teammate;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 22 ==
	title "Prefab Lead Player"
	name 	"coopHzmTestLvlCallvote34"
	rect	275 261 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map coop_test-leadplayer;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 22 ==
	title "Prefab Bat'leth Teammate"
	name 	"coopHzmTestLvlCallvote35"
	rect	275 282 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map coop_test-batlethteammate;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 22 ==
	title "Prefab Triggerish"
	name 	"coopHzmTestLvlCallvote36"
	rect	275 303 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map coop_test-triggerish;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 22 ==
	title "Prefab Mission Resource Managment"
	name 	"coopHzmTestLvlCallvote37"
	rect	275 324 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map coop_test-mrm;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 22 ==
	title "Prefab Circle Menu"
	name 	"coopHzmTestLvlCallvote38"
	rect	275 345 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map coop_test-circle;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 22 ==
	title "Prefab Statistics and Health Bar"
	name 	"coopHzmTestLvlCallvote39"
	rect	275 366 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map coop_test-statbar;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource 
Label
{
	cvarvisibility coop_ui_vt 23 ==
	
	title "$$c#041$$"
	name "coopHzmTestLvlCallvoteTitle4"
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
	name 	"coopHzmTestLvlCallvoteButtonNext3"
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
	
	cvarvisibility coop_ui_vt 23 ==
}
resource
Button
{
	cvarvisibility coop_ui_vt 23 ==
	title "Prefab Ranks"
	name 	"coopHzmTestLvlCallvote40"
	rect	275 114 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map coop_test-ranks;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 23 ==
	title "Prefab Symbols, Icons, Sprites"
	name 	"coopHzmTestLvlCallvote41"
	rect	275 135 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map coop_test-symbols;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 23 ==
	title "Prefab Continuous Use"
	name 	"coopHzmTestLvlCallvote42"
	rect	275 156 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map coop_test-continuoususe;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 23 ==
	title "Prefab Forcefield Scan"
	name 	"coopHzmTestLvlCallvote43"
	rect	275 177 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map coop_test-ffscan;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 23 ==
	title "Prefab Bridge Commander"
	name 	"coopHzmTestLvlCallvote44"
	rect	275 198 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map coop_test-bCommander;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 23 ==
	title "Prefab Point And Click"
	name 	"coopHzmTestLvlCallvote45"
	rect	275 219 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map coop_test-pointAndClick;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
end.