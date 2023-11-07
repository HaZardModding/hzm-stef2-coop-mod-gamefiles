resource
Label
{
title "EF2"
name "Default"
rect 40 455 25 24
fgcolor 1.00 1.00 1.00 1.00
bgcolor 1.00 1.00 1.00 0.00
borderstyle "RAISED"
font serpentinelight-10
}

resource
Label
{
name "Default"
rect 60 455 40 24
fgcolor 1.00 1.00 1.00 1.00
bgcolor 1.00 1.00 1.00 0.00
borderstyle "RAISED"
linkcvar "shortversion"
font serpentinelight-10
}

resource
Label
{
title "$$c#005$$"
name "Default"
rect 100 455 210 24
fgcolor 1.00 1.00 1.00 1.00
bgcolor 0.00 1.00 0.00 0.0
borderstyle "RAISED"
font serpentinelight-10
}

resource
Label
{
name "Default"
rect 304 455 40 24
fgcolor 0.00 1.00 1.00 1.00
bgcolor 0.00 1.00 0.00 0
borderstyle "RAISED"
font serpentinelight-10
linkcvar "coop_ver"
}

////////////////////////////
// adds troubleshooting button
////////////////////////////

resource
widget
{
	rect 	 371 339 256 32
	fgcolor 1.00 1.00 0.00 1.00
	bgcolor 0.00 0.00 0.00 0.00
	borderstyle "none"
	
	shader menu/main/secrets
	shadercolor 1.00 0.10 0.60 1.00
	hovershadercolor 1.00 0.10 0.60 1.00
	armedshadercolor 1.00 0.10 0.60 1.00
	selectedshadercolor 1.00 0.10 0.60 1.00
}

resource
Button
{
	title "TROUBLESHOOTING"
	name 	"Default"
	rect 	 424 341 123 26
	font serpentinemedium-8
	fgcolor 		1.000 1.000 1.000 1.000
	bgcolor 		0.000 0.000 0.000 0.000

	hovershader menu/generic/button-hover
	pressedshader menu/generic/button-press

	stuffcommand "pushmenu coop_ts\n"

    hovercommand "globalwidgetcommand tooltip_main title \"Might help you to fix issues with the game.\""
    hoverexitcommand "globalwidgetcommand tooltip_main title \"\""
    
    clicksound sound/misc/menu/click.wav
}

////////////////////////////
// This fires up the setup menu if required
////////////////////////////
resource
Label
{
	cvarvisibility coop_ver 60018 !=
	title "$$c#001$$"
	name "coopVersionCheckerTitle"
	rect 120 90 400 46
	//fgcolor 0 0.8 0.9 1.00
	fgcolor 1 1 1 1.00
	bgcolor 1.00 0 0 0.40
	font serpentinemedium-24
	horizontaljustify center
	verticaljustify top
	borderstyle "none"
}
resource
widget
{
	cvarvisibility coop_ver 60018 !=
	name "coopVersionCheckerImage"
	rect 230 140 40 52
	bgcolor 0 1 0 0.40
	horizontaljustify center
	verticaljustify top
	borderstyle "none"
}
resource
widget
{
	cvarvisibility coop_ver 60018 !=
	name "coopVersionCheckerImage1"
	rect 230 142 20 20
	bgcolor 0 1 0 0
	shader textures/menu/arrow_left
}
resource
widget
{
	cvarvisibility coop_ver 60018 !=
	name "coopVersionCheckerImage2"
	rect 230 170 20 20
	bgcolor 0 1 0 0
	shader textures/menu/arrow_left
}
resource
Label
{
	cvarvisibility coop_ver 60018 !=
	title "$$c#002$$"
	name "coopVersionCheckerShadow"
	rect 272 142 250 52
	fgcolor 0 0 0 1
	bgcolor 0 1 0 0
	font serpentinemedium-14
	horizontaljustify center
	verticaljustify top
	borderstyle "none"
}
resource
Label
{
	cvarvisibility coop_ver 60018 !=
	title "$$c#002$$"
	name "coopVersionChecker"
	rect 270 140 250 52
	fgcolor 1 1 1 1
	bgcolor 0 1 0 0.40
	font serpentinemedium-14
	horizontaljustify center
	verticaljustify top
	borderstyle "none"
}
resource
Label
{
	cvarvisibility coop_ver 60018 !=
	title "$$c#003$$"
	name "coopVersionCheckerButtonShadow"
	rect 122 142 100 52
	fgcolor 0 0 0 1
	bgcolor 1.00 0 0 0
	font serpentinemedium-14
	horizontaljustify center
	verticaljustify top
	borderstyle "none"
}
resource
Button
{
	cvarvisibility coop_ver 60018 !=
	title "$$c#003$$"
	name "coopVersionCheckerButton"
	rect 120 140 100 52
	//fgcolor 0.12 0.15 0.25 1.00
	//bgcolor 0.00 1.00 1.00 0.40
	//fgcolor 0.4 0.5 0.7 1.00
	bgcolor 1.00 0 0 0.40
	hoverfgcolor 1 0 0 1
	hoverbgcolor 0 0 0 0.70
	hoverbordercolor 1 1 1 1
	borderstyle "BORDER_OUTLINE"

	//font serpentinemedium-12
	font serpentinemedium-14
	horizontaljustify center
	verticaljustify top
	hovercommand "globalwidgetcommand tooltip_main title \"$$c#007$$\""
	hoverexitcommand "globalwidgetcommand tooltip_main title \"\""
	stuffcommand "pushmenu coop_setup\n"

	ordernumber 12

	hoversound sound/misc/menu/hover.wav
	clicksound sound/misc/menu/click.wav
}
////////////////////////
resource
Button
{
	title	"Reset Video"
	name 	"Default"
	rect 	 0 453 36 28
	font serpentinelight-8
	fgcolor			0.937 0.643 0.129 1.000
	bgcolor			0.125 0.157 0.251 1.000
	hoverbgcolor	0.278 0.365 0.510 1.000
	hoverfgcolor	1.000 1.000 1.000 1.000
	borderstyle "3D_BORDER"
	hovershader menu/generic/button-hover
	pressedshader menu/generic/button-press
	stuffcommand "r_mode 3;r_fullscreen 0;vid_restart\n"
    verticaljustify top
	hovercommand "globalwidgetcommand coop_settings_tooltip title \"\""
	hoverexitcommand "globalwidgetcommand coop_settings_tooltip title \"\""
}

end.

