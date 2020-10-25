resource 
Label
{
	cvarvisibility coop_ui_vt 14 ==
	
	title "$$c#038$$"
	name "coopGBSModLevelsTitle"
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
	cvarvisibility coop_ui_vt 14 ==
	title "1. USS Atlantic - Holodeck"
	name 	"gbsmodmap_coop_gbs1"
	rect	275 114 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap coop_gbs1\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/mapshots/coop_gbs1.tga;globalwidgetcommand coop_startserverName title \"THE COLONISTS\""
	hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 14 ==
	title "2. USS Atlantic - Bar"
	name 	"gbsmodmap_coop_gbs2"
	rect	275 135 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top
	
	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap coop_gbs2\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/mapshots/coop_gbs2.tga;globalwidgetcommand coop_startserverName title \"THE COLONISTS\""
	hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 14 ==
	title "3. USS Atlantic - Engineering"
	name 	"gbsmodmap_coop_gbs3"
	rect	275 156 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top
	
	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap coop_gbs3\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/mapshots/coop_gbs3.tga;globalwidgetcommand coop_startserverName title \"THE COLONISTS\""
	hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 14 ==
	title "4. USS Atlantic - Sickbay"
	name 	"gbsmodmap_coop_gbs4"
	rect	275 177 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top
	
	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap coop_gbs4\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/mapshots/coop_gbs4.tga;globalwidgetcommand coop_startserverName title \"THE COLONISTS\""
	hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 14 ==
	title "5. USS Atlantic - Transporter"
	name 	"gbsmodmap_coop_gbs5"
	rect	275 198 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top
	
	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap coop_gbs5\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/mapshots/coop_gbs5.tga;globalwidgetcommand coop_startserverName title \"THE COLONISTS\""
	hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 14 ==
	title "6. USS Atlantic - Shuttlebay"
	name 	"gbsmodmap_coop_gbs6"
	rect	275 219 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top
	
	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap coop_gbs6\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/mapshots/coop_gbs6.tga;globalwidgetcommand coop_startserverName title \"THE COLONISTS\""
	hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 14 ==
	title "7. Antioch System - Klingon Base"
	name 	"gbsmodmap_coop_gbs7"
	rect	275 240 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top
	
	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap coop_gbs7\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/mapshots/coop_gbs7.tga;globalwidgetcommand coop_startserverName title \"THE COLONISTS\""
	hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 14 ==
	title "8. Warbird - Bridge"
	name 	"gbsmodmap_coop_gbs8"
	rect	275 261 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top
	
	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap coop_gbs8\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/mapshots/coop_gbs8.tga;globalwidgetcommand coop_startserverName title \"THE COLONISTS\""
	hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 14 ==
	title "9. Romulan Planet - Surface"
	name 	"gbsmodmap_coop_gbs9"
	rect	275 282 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top
	
	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap coop_gbs9\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/mapshots/coop_gbs9.tga;globalwidgetcommand coop_startserverName title \"THE COLONISTS\""
	hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 14 ==
	title "10. Romulan Planet - Underground"
	name 	"gbsmodmap_coop_gbs10"
	rect	275 303 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top
	
	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap coop_gbs10\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/mapshots/coop_gbs10.tga;globalwidgetcommand coop_startserverName title \"THE COLONISTS\""
	hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 14 ==
	title "11. End Cinematic / Credits"
	name 	"gbsmodmap_coop_gbs11"
	rect	275 324 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top
	
	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap coop_gbs11\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/mapshots/coop_gbs11.tga;globalwidgetcommand coop_startserverName title \"THE COLONISTS\""
	hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 14 ==
	title "12. Credits and Secret Map"
	name 	"gbsmodmap_coop_gbsCredits"
	rect	275 345 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top
	
	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap coop_gbsCredits\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/mapshots/coop_gbsCredits.tga;globalwidgetcommand coop_startserverName title \"THE COLONISTS\""
	hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}

end.

