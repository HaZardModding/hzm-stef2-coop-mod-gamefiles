resource 
Label
{
	cvarvisibility coop_ui_vt 20 ==
	
	title "$$c#041$$"
	name "coopHzmTestLvlStartSvTitle"
	rect		274 89 330 24
	fgcolor 1.000 0.000 0.000 0.800
	bgcolor 0.12 0.15 0.25 1.00
	
	borderstyle "3D_BORDER"
	
	horizontaljustify left
	verticaljustify top
	font 	serpentinemedium-10
	
	hovercommand "globalwidgetcommand tooltip_coop_startserver title \"\""
    hoverexitcommand "globalwidgetcommand tooltip_coop_startserver title \"\""
}
resource
Button
{
	title "Next"
	name 	"coopHzmTestLvlStartSvButtonNext0"
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
	hovercommand "globalwidgetcommand coop_settings_tooltip title \"Show more HaZardModding Test Maps\""
	hoverexitcommand "globalwidgetcommand coop_settings_tooltip title \"\""
	
	cvarvisibility coop_ui_vt 20 ==
}

resource
Button
{
	cvarvisibility coop_ui_vt 20 ==
	title "Coop NoScript Example"
	name 	"coopHzmTestLvlStartSv0"
	rect	275 114 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap coop_noscript_example\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 20 ==
	title "Prefab Animation"
	name 	"coopHzmTestLvlStartSv1"
	rect	275 135 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap prf_animate\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 20 ==
	title "Prefab Bind"
	name 	"coopHzmTestLvlStartSv2"
	rect	275 156 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap prf_bind\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 20 ==
	title "Prefab Callvolume"
	name 	"coopHzmTestLvlStartSv3"
	rect	275 177 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap prf_callvolume\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 20 ==
	title "Prefab Cinematic"
	name 	"coopHzmTestLvlStartSv4"
	rect	275 198 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap prf_cinematic\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 20 ==
	title "Prefab Destructible"
	name 	"coopHzmTestLvlStartSv5"
	rect	275 219 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap prf_destructible\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 20 ==
	title "Prefab Destructible Vanish"
	name 	"coopHzmTestLvlStartSv6"
	rect	275 240 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap prf_destructiblevanish\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 20 ==
	title "Prefab Dialog"
	name 	"coopHzmTestLvlStartSv7"
	rect	275 261 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap prf_dialog\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 20 ==
	title "Prefab Doors"
	name 	"coopHzmTestLvlStartSv8"
	rect	275 282 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap prf_doors\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 20 ==
	title "Prefab Everyone"
	name 	"coopHzmTestLvlStartSv9"
	rect	275 303 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap prf_everyone\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 20 ==
	title "Prefab Forcefield"
	name 	"coopHzmTestLvlStartSv10"
	rect	275 324 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap prf_forcefield\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 20 ==
	title "Prefab Heal"
	name 	"coopHzmTestLvlStartSv11"
	rect	275 345 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap prf_heal\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 20 ==
	title "Prefab Bioscanner"
	name 	"coopHzmTestLvlStartSv12"
	rect	275 366 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap prf_bioscanner\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource 
Label
{
	cvarvisibility coop_ui_vt 21 ==
	
	title "$$c#041$$"
	name "coopHzmTestLvlStartSvTitle2"
	rect		274 89 330 24
	fgcolor 1.000 0.000 0.000 0.800
	bgcolor 0.12 0.15 0.25 1.00
	
	borderstyle "3D_BORDER"
	
	horizontaljustify left
	verticaljustify top
	font 	serpentinemedium-10
	
	hovercommand "globalwidgetcommand tooltip_coop_startserver title \"Test levels from HaZardModding...\""
    hoverexitcommand "globalwidgetcommand tooltip_coop_startserver title \"\""
}
resource
Button
{
	title "Next"
	name 	"coopHzmTestLvlStartSvButtonNext1"
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
	hovercommand "globalwidgetcommand coop_settings_tooltip title \"Show more HaZardModding Test Maps\""
	hoverexitcommand "globalwidgetcommand coop_settings_tooltip title \"\""
	
	cvarvisibility coop_ui_vt 21 ==
}
resource
Button
{
	cvarvisibility coop_ui_vt 21 ==
	title "Prefab Hud"
	name 	"coopHzmTestLvlStartSv13"
	rect	275 114 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap prf_hud\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 21 ==
	title "Prefab Hurt"
	name 	"coopHzmTestLvlStartSv14"
	rect	275 135 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap prf_hurt\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 21 ==
	title "Prefab Immobilize"
	name 	"coopHzmTestLvlStartSv15"
	rect	275 156 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap prf_immobilize\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 21 ==
	title "Prefab Lock"
	name 	"coopHzmTestLvlStartSv16"
	rect	275 177 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap prf_lock\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 21 ==
	title "Prefab Load Map"
	name 	"coopHzmTestLvlStartSv17"
	rect	275 198 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap prf_map\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 21 ==
	title "Prefab Objective"
	name 	"coopHzmTestLvlStartSv18"
	rect	275 219 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap prf_objective\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 21 ==
	title "Prefab Puzzle"
	name 	"coopHzmTestLvlStartSv19"
	rect	275 240 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap prf_puzzle\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 21 ==
	title "Prefab Remove"
	name 	"coopHzmTestLvlStartSv20"
	rect	275 261 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap prf_remove\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 21 ==
	title "Prefab Respawn"
	name 	"coopHzmTestLvlStartSv21"
	rect	275 282 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap prf_respawn\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 21 ==
	title "Prefab Savegame"
	name 	"coopHzmTestLvlStartSv22"
	rect	275 303 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap prf_savegame\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 21 ==
	title "Prefab Selection Move"
	name 	"coopHzmTestLvlStartSv23"
	rect	275 324 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap prf_selectionmove\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 21 ==
	title "Prefab Rotating Doors"
	name 	"coopHzmTestLvlStartSv24"
	rect	275 345 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap prf_doorsRotating\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 21 ==
	title "Prefab Walkto"
	name 	"coopHzmTestLvlStartSv25"
	rect	275 366 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap prf_walkto\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Label
{
	cvarvisibility coop_ui_vt 22 ==
	
	title "$$c#041$$"
	name "coopHzmTestLvlStartSvTitle4"
	rect		274 89 330 24
	fgcolor 1.000 0.000 0.000 0.800
	bgcolor 0.12 0.15 0.25 1.00
	
	borderstyle "3D_BORDER"
	
	horizontaljustify left
	verticaljustify top
	font 	serpentinemedium-10
	
	hovercommand "globalwidgetcommand tooltip_coop_startserver title \"Test levels from HaZardModding...\""
    hoverexitcommand "globalwidgetcommand tooltip_coop_startserver title \"\""
}
resource
Button
{
	title "Next"
	name 	"coopHzmTestLvlStartSvButtonNext2"
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
	hovercommand "globalwidgetcommand coop_settings_tooltip title \"Show more HaZardModding Test Maps\""
	hoverexitcommand "globalwidgetcommand coop_settings_tooltip title \"\""
	
	cvarvisibility coop_ui_vt 22 ==
}
resource
Button
{
	cvarvisibility coop_ui_vt 22 ==
	title "Prefab Weapon"
	name 	"coopHzmTestLvlStartSv27"
	rect	275 114 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap prf_weapon\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 22 ==
	title "Prefab Cinematic 2"
	name 	"coopHzmTestLvlStartSv28"
	rect	275 135 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap prf_cinematic2\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 22 ==
	title "Prefab Fallschirmspringer"
	name 	"coopHzmTestLvlStartSv29"
	rect	275 156 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap prf_fallschirmspringer\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 22 ==
	title "Prefab Multi Options Menu (MOM)"
	name 	"coopHzmTestLvlStartSv30"
	rect	275 177 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap prf_multioptions\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 22 ==
	title "Prefab Borg Work"
	name 	"coopHzmTestLvlStartSv31"
	rect	275 198 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap prf_borgWork\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 22 ==
	title "Prefab Group Death Thread"
	name 	"coopHzmTestLvlStartSv32"
	rect	275 219 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap prf_groupdeath\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 22 ==
	title "Prefab Teammate"
	name 	"coopHzmTestLvlStartSv33"
	rect	275 240 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap prf_teammate\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 22 ==
	title "Prefab Lead Player"
	name 	"coopHzmTestLvlStartSv34"
	rect	275 261 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap prf_leadplayer\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 22 ==
	title "Prefab Bat'leth Teammate"
	name 	"coopHzmTestLvlStartSv35"
	rect	275 282 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap prf_batlethteammate\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 22 ==
	title "Prefab Triggerish"
	name 	"coopHzmTestLvlStartSv36"
	rect	275 303 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap prf_triggerish\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 22 ==
	title "Prefab Mission Resource Managment"
	name 	"coopHzmTestLvlStartSv37"
	rect	275 324 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap prf_mrm\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 22 ==
	title "Prefab Circle Menu"
	name 	"coopHzmTestLvlStartSv38"
	rect	275 345 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap prf_circle\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 22 ==
	title "Prefab Statistics and Health Bar"
	name 	"coopHzmTestLvlStartSv39"
	rect	275 366 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap prf_statbar\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	title "Next"
	name 	"coopHzmTestLvlStartSvButtonNext3"
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
	hovercommand "globalwidgetcommand coop_settings_tooltip title \"Show more HaZardModding Test Maps\""
	hoverexitcommand "globalwidgetcommand coop_settings_tooltip title \"\""
	
	cvarvisibility coop_ui_vt 23 ==
}
resource
Button
{
	cvarvisibility coop_ui_vt 23 ==
	title "Prefab Ranks"
	name 	"coopHzmTestLvlStartSv40"
	rect	275 114 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap prf_ranks\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 23 ==
	title "Prefab Symbols, Icons, Sprites"
	name 	"coopHzmTestLvlStartSv41"
	rect	275 135 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap prf_symbols\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"Chrissstrahl\""
	hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
end.