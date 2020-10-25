resource 
Label
{
	cvarvisibility coop_ui_vt 15 ==
	
	title "$$c#039$$"
	name "coopRotecModLevelsTitle"
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
	cvarvisibility coop_ui_vt 15 ==
	title "1. USS Odyssey-A"
	rect	275 114 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap coop_rotec1\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/mapshots/coop_rotec1.tga;globalwidgetcommand coop_startserverName title \"Luke Sutton\""
	hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 15 ==
	title "2. Attrexia - Landing"
	name 	"coopRotec2"
	rect	275 135 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap coop_rotec2\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/mapshots/coop_rotec2.tga;globalwidgetcommand coop_startserverName title \"Luke Sutton\""
	hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 15 ==
	title "3. Attrexia - Installation"
	name 	"coopRotec3"
	rect	275 156 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap coop_rotec3\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/mapshots/coop_rotec3.tga;globalwidgetcommand coop_startserverName title \"Luke Sutton\""
	hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 15 ==
	title "4. Attrexia - Central"
	name 	"coopRotec4"
	rect	275 177 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top
	
	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap coop_rotec4\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/mapshots/coop_rotec4.tga;globalwidgetcommand coop_startserverName title \"Luke Sutton\""
	hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 15 ==
	title "5. Attrexia - Central"
	name 	"coopRotec5"
	rect	275 198 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top
	
	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap coop_rotec5\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/mapshots/coop_rotec5.tga;globalwidgetcommand coop_startserverName title \"Luke Sutton\""
	hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 15 ==
	title "6. Attrexia - Departure"
	name 	"coopRotec6"
	rect	275 219 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top
	
	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap coop_rotec6\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/mapshots/coop_rotec6.tga;globalwidgetcommand coop_startserverName title \"Luke Sutton\""
	hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 15 ==
	title "7. USS Odyssey-A - Back again"
	rect	275 240 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap coop_rotec7\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/mapshots/coop_rotec7.tga;globalwidgetcommand coop_startserverName title \"Luke Sutton\""
	hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 15 ==
	title "8. USS Odyssey-A - Relaxation"
	rect	275 261 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap coop_rotec8\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/mapshots/coop_rotec8.tga;globalwidgetcommand coop_startserverName title \"Luke Sutton\""
	hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}


end.

