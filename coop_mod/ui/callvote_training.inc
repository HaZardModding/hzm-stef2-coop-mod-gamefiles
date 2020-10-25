resource 
Label
{
	cvarvisibility coop_ui_vt 6 ==
	
	title "$$c#035$$"
	name "trainingAndSecertLevelsTitle"
	rect		274 89 330 24
	fgcolor 0.500 1.000 0.000 0.800
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
	cvarvisibility coop_ui_vt 6 ==
	title "$$TrainingLevel1Desc$$"
	name 	"trainingAndSecert0"
	rect	275 114 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map ent-training1;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/mapshots/ent-training1.tga;globalwidgetcommand coopName title \"Ritual Entertainment\""
    hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 6 ==
	title "$$TrainingLevel2Desc$$"
	name 	"trainingAndSecert1"
	rect	275 135 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top
	
	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map ent-training2;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/mapshots/ent-training2.tga;globalwidgetcommand coopName title \"Ritual Entertainment\""
    hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 6 ==
	title "$$TrainingLevel3Desc$$"
	name 	"trainingAndSecert2"
	rect	275 156 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top
	
	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map ent-training3;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/mapshots/ent-training3.tga;globalwidgetcommand coopName title \"Ritual Entertainment\""
    hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 6 ==
	title "$$TrainingLevel4Desc$$"
	name 	"trainingAndSecert3"
	rect	275 177 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top
	
	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map ent-training4;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/mapshots/ent-training4.tga;globalwidgetcommand coopName title \"Ritual Entertainment\""
    hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}

resource
Button
{
	cvarvisibility coop_ui_vt 6 ==
	title "$$Secret1$$"
	name 	"trainingAndSecert5"
	rect	275 219 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top
	
	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map secret1;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/mapshots/secret1.tga;globalwidgetcommand coopName title \"Ritual Entertainment\""
    hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 6 ==
	title "$$Secret2$$"
	name 	"trainingAndSecert6"
	rect	275 240 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top
	
	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map secret2;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/mapshots/secret2.tga;globalwidgetcommand coopName title \"Ritual Entertainment\""
    hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 6 ==
	title "$$Secret3$$"
	name 	"trainingAndSecert7"
	rect	275 261 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top
	
	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map secret3;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/mapshots/secret3.tga;globalwidgetcommand coopName title \"Ritual Entertainment\""
    hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 6 ==
	title "$$Minigame$$"
	name 	"trainingAndSecert8"
	rect	275 282 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top
	
	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map ef2_minigame2;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/mapshots/ef2_minigame2.tga;globalwidgetcommand coopName title \"Ritual Entertainment\""
    hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 6 ==
	title "$$Zoo1$$"
	name 	"trainingAndSecert9"
	rect	275 303 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top
	
	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map zoo1;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/mapshots/zoo1.tga;globalwidgetcommand coopName title \"Ritual Entertainment\""
    hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_vt 6 ==
	title "$$Zoo2$$"
	name 	"trainingAndSecert10"
	rect	275 324 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top
	
	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote map testmorph;popmenu 1;popmenu 0\n"
	hovercommand "globalwidgetcommand coopShot shader sysimg/mapshots/testmorph.tga;globalwidgetcommand coopName title \"Ritual Entertainment\""
    hoverexitcommand "globalwidgetcommand coopShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coopName title \"\""
}


end.

