showcommand "scale ui_customresolution 1;scale ui_customresapplay 1\n"

resource
Button
{
	title "$$Controls$$"
	name "Default"
	rect 44 57 138 28
	fgcolor 0.12 0.15 0.25 1.00
	bgcolor 1.00 1.00 1.00 0.00

	borderstyle "none"

	font serpentinemedium-12
	horizontaljustify center
	verticaljustify top

	hovershader menu/generic/button-hover
	pressedshader menu/generic/button-press
	hovercommand "globalwidgetcommand tooltip_video title \"$$ChangeKeyboardSettings$$\""
	hoverexitcommand "globalwidgetcommand tooltip_video title \"\""

	stuffcommand "transitionmenu controls 0"

	hoversound sound/misc/menu/hover.wav
	clicksound sound/misc/menu/click.wav
	}

resource
Button
{
	title "$$Video$$"
	name "Default"
	rect 182 57 138 28
	//fgcolor 0.12 0.15 0.25 1.00
	fgcolor 1.00 1.00 1.00 1.00
	bgcolor 1.00 1.00 1.00 0.00
	borderstyle "none"
	font serpentinemedium-12
	horizontaljustify center
	verticaljustify top
	//hovershader menu/generic/button-hover
	//pressedshader menu/generic/button-press
	//hovercommand "globalwidgetcommand tooltip_video title \"$$ChangeVideoSettings$$\""
	//hoverexitcommand "globalwidgetcommand tooltip_video title \"\""
	//stuffcommand "transitionmenu  video 0"
	//hoversound sound/misc/menu/hover.wav
	//clicksound sound/misc/menu/click.wav
}

resource
Button
{
	title "$$Audio$$"
	name "Default"
	rect 320 57 138 28
	fgcolor 0.12 0.15 0.25 1.00
	bgcolor 1.00 1.00 1.00 0.00
	borderstyle "none"
	font serpentinemedium-12
	horizontaljustify center
	verticaljustify top
	hovershader menu/generic/button-hover
	pressedshader menu/generic/button-press
	hovercommand "globalwidgetcommand tooltip_video title \"$$ChangeAudioSettings$$\""
	hoverexitcommand "globalwidgetcommand tooltip_video title \"\""
	stuffcommand "transitionmenu  audio 0"
	hoversound sound/misc/menu/hover.wav
	clicksound sound/misc/menu/click.wav
}

resource
Button
{
	title "$$GameOptions$$"
	name "Default"
	rect 458 57 138 28
	fgcolor 0.12 0.15 0.25 1.00
	bgcolor 1.00 1.00 1.00 0.00
	borderstyle "none"
	font serpentinemedium-12
	horizontaljustify center
	verticaljustify top
	hovershader menu/generic/button-hover
	pressedshader menu/generic/button-press
	hovercommand "globalwidgetcommand tooltip_video title \"$$ChangeGameSettings$$\""
	hoverexitcommand "globalwidgetcommand tooltip_video title \"\""
	stuffcommand "transitionmenu  gameoptions 0"
	hoversound sound/misc/menu/hover.wav
	clicksound sound/misc/menu/click.wav
}

resource
Label
{
    name "tooltip_video"
    rect 49 403 320 30
    fgcolor 1 1 1 1
    bgcolor 0 0 0 0
    font tahoma-8
    verticaljustify top
    horizontaljustify left
}

resource
widget
{
	rect 	 371 399 256 32
	fgcolor 1.00 1.00 0.00 1.00
	bgcolor 0.00 0.00 0.00 0.00
	borderstyle "none"
	shader menu/main/credits
}

resource
Button
{
	title "$$Apply$$"
	name 	"Default"
	rect 	 424 401 123 32
	font serpentinemedium-12
	fgcolor 		1.000 1.000 1.000 1.000
	bgcolor 		0.000 0.000 0.000 0.000
	
	horizontaljustify center
	verticaljustify top

	hovershader menu/generic/button-hover
	pressedshader menu/generic/button-press

	//borderstyle "BORDER_OUTLINE"
	//borderwidth 1
	//bordercolor 0.12 0.15 0.25 1.00

    stuffcommand "ui_checkrestart"
    
    hovercommand "globalwidgetcommand tooltip_video title \"$$ApplyCurrentChangesToVideo$$\""
    hoverexitcommand "globalwidgetcommand tooltip_video title \"\""
    
    clicksound sound/misc/menu/click.wav
	cvarvisibility ui_customresapplay 0 ==
}

resource
Button
{
	disable
	title "$$Apply$$"
	name 	"Default"
	rect 	 424 401 123 32
	font serpentinemedium-12
	fgcolor 		1.000 1.000 1.000 1.000
	bgcolor 		1.000 0.000 0.000 0.000
	
	horizontaljustify center
	verticaljustify top

	hovershader menu/generic/button-hover
	pressedshader menu/generic/button-press

	//borderstyle "BORDER_OUTLINE"
	//borderwidth 1
	//bordercolor 0.12 0.15 0.25 1.00

    stuffcommand "exec coop_mod/cfg/changeres.cfg"
    
    hovercommand "globalwidgetcommand tooltip_video title \"$$ApplyCurrentChangesToVideo$$\""
    hoverexitcommand "globalwidgetcommand tooltip_video title \"\""
    
    clicksound sound/misc/menu/click.wav
	cvarvisibility ui_customresapplay 1 ==
}

resource
Button
{
    title "$$MainMenu$$"
    name "Default"
    rect 435 428 96 42
    fgcolor 0.12 0.15 0.25 1.00
    bgcolor 1.00 1.00 1.00 0.00
    borderstyle "None"
    stuffcommand "popmenu 0"
    font serpentinemedium-12
    hovershader menu/generic/button-hover
    pressedshader menu/generic/button-press
    hovercommand "globalwidgetcommand tooltip_video title \"$$ReturnToMainMenu$$\""
    hoverexitcommand "globalwidgetcommand tooltip_video title \"\""
    
    clicksound sound/misc/menu/back1.wav
	verticaljustify top
}

///////////////////////////////////////////////////////////////// GAMMA
///////////////////////////////////////////////////////////////// GAMMA
///////////////////////////////////////////////////////////////// GAMMA
resource 
Label
{
    title "$$GammaCorrections$$"
	name "VideoBackground"
	rect 34 278 572 34
	fgcolor 1.000 1.000 1.000 1.000
	bgcolor 0.278 0.365 0.510 1.000
	font serpentinemedium-10
	borderstyle "3D_BORDER"
	verticaljustify topq
}

resource
Widget
{
	name "VideoBackground2"
	rect 34 312 572 54
	fgcolor 1 1 1 1
	bgcolor 0.000 0.000 0.000 0.75
	borderstyle "OUTLINE_BORDER"
	borderwidth 1
	bordercolor 0.278 0.365 0.510 1.000
}
resource 
Label
{
	title "$$Brightness$$"
	name	"Default"
	rect 36 314 120 36
	fgcolor 1.00 1.00 1.00 1.00
	bgcolor 0.122 0.157 0.251 1.000
	borderstyle "3D_BORDER"
	font serpentinemedium-10
	horizontaljustify right
	hovercommand "globalwidgetcommand tooltip_video title \"$$SetBrightness$$\""
	hoverexitcommand "globalwidgetcommand tooltip_video title \"\""
	verticaljustify top
}
resource
Slider
{
	name "Default"
	rect 156 314 130 36
	fgcolor 0.953 0.667 0.271 1.000
	bgcolor 0.000 0.000 0.000 0.750
	borderstyle "OUTLINE_BORDER"
	bordercolor 0.122 0.157 0.251 1.000
	linkcvar "r_gamma"
	slidertype float
	setrange 0.5 3
	stepsize 0.1
	hovercommand "globalwidgetcommand tooltip_video title \"$$SetBrightness$$\""
	hoverexitcommand "globalwidgetcommand tooltip_video title \"\""
	clicksound sound/misc/menu/click.wav
}



resource 
widget
{
	name	"Default"
	rect 288 314 316 48
	fgcolor 1.00 1.00 1.00 1.00
	bgcolor 0.00 0.00 0.00 0.00
	shader "sysimg/menu/calibration.tga"
}
//Brightness
resource 
Label
{
	name	"Default"
	title "$$AllShadesShouldBeDistinct$$"
	rect 288 314 316 34
	fgcolor 1.00 1.00 1.00 1.00
	bgcolor 0.00 0.00 0.00 0.00
	font serpentinelight-10
	horizontaljustify left
	verticaljustify top
	textshadowcolor 0 0 0 1
	hovertextshadowcolor 0 0 0 1
}

///////////////////////////////////////////////////////////////// ADVANCED BUTTON
///////////////////////////////////////////////////////////////// ADVANCED BUTTON
///////////////////////////////////////////////////////////////// ADVANCED BUTTON
///////////////////////////////////////////////////////////////// ADVANCED BUTTON
resource
Button
{
	title "$$Advanced$$"
	name "Default"
	rect 420 370 128 36
	fgcolor 1.00 1.00 1.00 1.00
	bgcolor 0.00 0.00 0.00 0.00
	borderstyle "NONE"
	stuffcommand "showmenu promptadvancedvideo\n"
	//shader "textures/menu/B_apply"
	//hovershader "textures/menu/B_apply_selected"
	//clicksound sound/misc/menu/select.wav
	ordernumber 1
	font serpentinemedium-10
	hovershader menu/generic/button-hover
	pressedshader menu/generic/button-press
	hovercommand "globalwidgetcommand tooltip_video title \"$$AdvancedVideoSettings$$\""
	hoverexitcommand "globalwidgetcommand tooltip_video title \"\""
	clicksound sound/misc/menu/click.wav
	verticaljustify top
}

///////////////////////////////////////////////////////////////// VIDEO SETTINGS WIDGET
///////////////////////////////////////////////////////////////// VIDEO SETTINGS WIDGET
///////////////////////////////////////////////////////////////// VIDEO SETTINGS WIDGET
///////////////////////////////////////////////////////////////// VIDEO SETTINGS WIDGET
resource 
Label
{
    title "$$VideoSettings$$"
	name "VideoBackground"
	rect 34 87 572 34
	fgcolor 1.000 1.000 1.000 1.000
	bgcolor 0.278 0.365 0.510 1.000
	font serpentinemedium-10
	borderstyle "3D_BORDER"
	verticaljustify top
}

resource
Widget
{
	name "VideoBackground"
	rect 34 121 572 154
	fgcolor 1 1 1 1
	bgcolor 0.000 0.000 0.000 0.75
	borderstyle "OUTLINE_BORDER"
	borderwidth 1
	bordercolor 0.278 0.365 0.510 1.000
}

///////////////////////////////////////////////////////////////// VIDEO SETTINGS res change restart warning
///////////////////////////////////////////////////////////////// VIDEO SETTINGS res change restart warning
///////////////////////////////////////////////////////////////// VIDEO SETTINGS res change restart warning
///////////////////////////////////////////////////////////////// VIDEO SETTINGS res change restart warning

resource 
Label
{
	disable
    title "$$c#107$$"
	name "videoCustomResWarning"
	rect 34 368 340 30
	fgcolor 0 0 0 1
	bgcolor 0.8 0 0.8 0.8
	font serpentinemedium-10
	borderstyle "OUTLINE_BORDER"
	verticaljustify top
}

///////////////////////////////////////////////////////////////// VIDEO SETTINGS video-mode
///////////////////////////////////////////////////////////////// VIDEO SETTINGS video-mode
///////////////////////////////////////////////////////////////// VIDEO SETTINGS video-mode
///////////////////////////////////////////////////////////////// VIDEO SETTINGS video-mode
resource
Label
{
    title "$$VideoMode$$"
    name "Default"
    rect 36 122 140 36
    fgcolor 1.00 1.00 1.00 1.00
    bgcolor 0.122 0.157 0.251 1.000
    borderstyle "3D_BORDER"
    font serpentinemedium-10
    horizontaljustify right
    hovercommand "globalwidgetcommand videoResActualSwitchBoxMode bgcolor 0 1 0.5 0.5;globalwidgetcommand tooltip_video title \"$$SetVideoResolution$$\""
    hoverexitcommand "globalwidgetcommand videoResActualSwitchBoxMode bgcolor 0.00 0.00 0.00 0.85;globalwidgetcommand tooltip_video title \"\""
	verticaljustify top
}

resource
SwitchBox
{
    name "videoCostumResSwitchBox"
	rect 178 122 130 36
    fgcolor 0.953 0.667 0.271 1.000
    bgcolor 0.000 0.000 0.000 0.750
    borderstyle "OUTLINE_BORDER"
    bordercolor 0.122 0.157 0.251 1.000
	verticaljustify top
    
    linkcvar "ui_customresolution"
	
	option "$$c#160$$"  "seta ui_customresolution 3;exec coop_mod/cfg/menu_video_customreschange.cfg;seta ui_videotest \"seta userFov 80.00;seta r_mode 3\"" 0
//GENERATED IN BLACKBOX MAP SCRIPT
option "640x480"		"seta ui_customresolution 3;exec coop_mod/cfg/menu_video_customreschange.cfg;seta ui_videotest \"seta userFov 80;seta r_mode 3\"" 3
option "800x600"		"seta ui_customresolution 4;exec coop_mod/cfg/menu_video_customreschange.cfg;seta ui_videotest \"seta userFov 80;seta r_mode 4\"" 4
option "856x480"		"seta ui_customresolution 5;exec coop_mod/cfg/menu_video_customreschange.cfg;seta ui_videotest \"seta userFov 96.6;seta r_mode 11\"" 5
option "960x720"		"seta ui_customresolution 6;exec coop_mod/cfg/menu_video_customreschange.cfg;seta ui_videotest \"seta userFov 80;seta r_mode 5\"" 6
option "1024x768"		"seta ui_customresolution 7;exec coop_mod/cfg/menu_video_customreschange.cfg;seta ui_videotest \"seta userFov 80;seta r_mode 6\"" 7
option "1152x864"		"seta ui_customresolution 8;exec coop_mod/cfg/menu_video_customreschange.cfg;seta ui_videotest \"seta userFov 80;seta r_mode 7\"" 8
option "1280x720"		"seta ui_customresolution 9;exec coop_mod/cfg/menu_video_customreschange.cfg;seta ui_videotest \"seta userFov 96.42;seta r_mode -1;set r_customHeight 720;set r_customwidth 1280\"" 9
option "1280x800"		"seta ui_customresolution 10;exec coop_mod/cfg/menu_video_customreschange.cfg;seta ui_videotest \"seta userFov 90.4;seta r_mode -1;set r_customHeight 800;set r_customwidth 1280\"" 10
option "1280x1024"		"seta ui_customresolution 11;exec coop_mod/cfg/menu_video_customreschange.cfg;seta ui_videotest \"seta userFov 76.38;seta r_mode 8\"" 11
option "1360x768"		"seta ui_customresolution 12;exec coop_mod/cfg/menu_video_customreschange.cfg;seta ui_videotest \"seta userFov 96.2;seta r_mode -1;set r_customHeight 768;set r_customwidth 1360\"" 12
option "1366x768"		"seta ui_customresolution 13;exec coop_mod/cfg/menu_video_customreschange.cfg;seta ui_videotest \"seta userFov 96.45;seta r_mode -1;set r_customHeight 768;set r_customwidth 1366\"" 13
option "1440x900"		"seta ui_customresolution 14;exec coop_mod/cfg/menu_video_customreschange.cfg;seta ui_videotest \"seta userFov 90.4;seta r_mode -1;set r_customHeight 900;set r_customwidth 1440\"" 14
option "1536x864"		"seta ui_customresolution 15;exec coop_mod/cfg/menu_video_customreschange.cfg;seta ui_videotest \"seta userFov 90.4;seta r_mode -1;set r_customHeight 864;set r_customwidth 1536\"" 15
option "1600x900"		"seta ui_customresolution 16;exec coop_mod/cfg/menu_video_customreschange.cfg;seta ui_videotest \"seta userFov 96.42;seta r_mode -1;set r_customHeight 900;set r_customwidth 1600\"" 16
option "1600x1200"		"seta ui_customresolution 17;exec coop_mod/cfg/menu_video_customreschange.cfg;seta ui_videotest \"seta userFov 80;seta r_mode 9\"" 17
option "1680x1050"		"seta ui_customresolution 18;exec coop_mod/cfg/menu_video_customreschange.cfg;seta ui_videotest \"seta userFov 90.4;seta r_mode -1;set r_customHeight 1050;set r_customwidth 1680\"" 18
option "1920x1080"		"seta ui_customresolution 19;exec coop_mod/cfg/menu_video_customreschange.cfg;seta ui_videotest \"seta userFov 96.42;seta r_mode -1;set r_customHeight 1080;set r_customwidth 1920\"" 19
option "1920x1200"		"seta ui_customresolution 20;exec coop_mod/cfg/menu_video_customreschange.cfg;seta ui_videotest \"seta userFov 90.4;seta r_mode -1;set r_customHeight 1200;set r_customwidth 1920\"" 20
option "2048x1152"		"seta ui_customresolution 21;exec coop_mod/cfg/menu_video_customreschange.cfg;seta ui_videotest \"seta userFov 106.26;seta r_mode -1;set r_customHeight 1152;set r_customwidth 2048\"" 21
option "2048x1536"		"seta ui_customresolution 22;exec coop_mod/cfg/menu_video_customreschange.cfg;seta ui_videotest \"seta userFov 80;seta r_mode 10\"" 22
option "2560x1080"		"seta ui_customresolution 23;exec coop_mod/cfg/menu_video_customreschange.cfg;seta ui_videotest \"seta userFov 112.33;seta r_mode -1;set r_customHeight 1080;set r_customwidth 2560\"" 23
option "2560x1440"		"seta ui_customresolution 24;exec coop_mod/cfg/menu_video_customreschange.cfg;seta ui_videotest \"seta userFov 96.42;seta r_mode -1;set r_customHeight 1440;set r_customwidth 2560\"" 24
option "2560x1600"		"seta ui_customresolution 25;exec coop_mod/cfg/menu_video_customreschange.cfg;seta ui_videotest \"seta userFov 90.4;seta r_mode -1;set r_customHeight 1600;set r_customwidth 2560\"" 25
option "2880x1200"		"seta ui_customresolution 26;exec coop_mod/cfg/menu_video_customreschange.cfg;seta ui_videotest \"seta userFov 112.98;seta r_mode -1;set r_customHeight 1200;set r_customwidth 2880\"" 26
option "3200x1800"		"seta ui_customresolution 27;exec coop_mod/cfg/menu_video_customreschange.cfg;seta ui_videotest \"seta userFov 96.42;seta r_mode -1;set r_customHeight 1800;set r_customwidth 3200\"" 27
option "3440x1440"		"seta ui_customresolution 28;exec coop_mod/cfg/menu_video_customreschange.cfg;seta ui_videotest \"seta userFov 112.74;seta r_mode -1;set r_customHeight 1440;set r_customwidth 3440\"" 28
option "3840x1080"		"seta ui_customresolution 29;exec coop_mod/cfg/menu_video_customreschange.cfg;seta ui_videotest \"seta userFov 112.74;seta r_mode -1;set r_customHeight 1080;set r_customwidth 3840\"" 29
option "3840x1600"		"seta ui_customresolution 30;exec coop_mod/cfg/menu_video_customreschange.cfg;seta ui_videotest \"seta userFov 112.98;seta r_mode -1;set r_customHeight 1600;set r_customwidth 3840\"" 30
option "3840x2160"		"seta ui_customresolution 31;exec coop_mod/cfg/menu_video_customreschange.cfg;seta ui_videotest \"seta userFov 96.42;seta r_mode -1;set r_customHeight 2160;set r_customwidth 3840\"" 31
option "3840x2400"		"seta ui_customresolution 32;exec coop_mod/cfg/menu_video_customreschange.cfg;seta ui_videotest \"seta userFov 90.4;seta r_mode -1;set r_customHeight 2400;set r_customwidth 3840\"" 32
option "4096x2304"		"seta ui_customresolution 33;exec coop_mod/cfg/menu_video_customreschange.cfg;seta ui_videotest \"seta userFov 96.42;seta r_mode -1;set r_customHeight 2304;set r_customwidth 4096\"" 33
option "4320x1800"		"seta ui_customresolution 34;exec coop_mod/cfg/menu_video_customreschange.cfg;seta ui_videotest \"seta userFov 112.98;seta r_mode -1;set r_customHeight 1800;set r_customwidth 4320\"" 34
option "5120x1440"		"seta ui_customresolution 35;exec coop_mod/cfg/menu_video_customreschange.cfg;seta ui_videotest \"seta userFov 138.89;seta r_mode -1;set r_customHeight 1440;set r_customwidth 5120\"" 35
option "5120x2160"		"seta ui_customresolution 36;exec coop_mod/cfg/menu_video_customreschange.cfg;seta ui_videotest \"seta userFov 112.33;seta r_mode -1;set r_customHeight 2160;set r_customwidth 5120\"" 36
option "5120x2880"		"seta ui_customresolution 37;exec coop_mod/cfg/menu_video_customreschange.cfg;seta ui_videotest \"seta userFov 96.42;seta r_mode -1;set r_customHeight 2880;set r_customwidth 5120\"" 37
option "5760x2400"		"seta ui_customresolution 38;exec coop_mod/cfg/menu_video_customreschange.cfg;seta ui_videotest \"seta userFov 112.98;seta r_mode -1;set r_customHeight 2400;set r_customwidth 5760\"" 38
option "6880x2880"		"seta ui_customresolution 39;exec coop_mod/cfg/menu_video_customreschange.cfg;seta ui_videotest \"seta userFov 112.74;seta r_mode -1;set r_customHeight 2880;set r_customwidth 6880\"" 39
option "7680x3200"		"seta ui_customresolution 40;exec coop_mod/cfg/menu_video_customreschange.cfg;seta ui_videotest \"seta userFov 112.98;seta r_mode -1;set r_customHeight 3200;set r_customwidth 7680\"" 40
option "7680x4320"		"seta ui_customresolution 41;exec coop_mod/cfg/menu_video_customreschange.cfg;seta ui_videotest \"seta userFov 96.42;seta r_mode -1;set r_customHeight 4320;set r_customwidth 7680\"" 41
option "8640x3600"		"seta ui_customresolution 42;exec coop_mod/cfg/menu_video_customreschange.cfg;seta ui_videotest \"seta userFov 112.98;seta r_mode -1;set r_customHeight 3600;set r_customwidth 8640\"" 42
option "10240x4320"		"seta ui_customresolution 43;exec coop_mod/cfg/menu_video_customreschange.cfg;seta ui_videotest \"seta userFov 112.98;seta r_mode -1;set r_customHeight 4320;set r_customwidth 10240\"" 43

//Thanks to fov calculator
//https://www.wsgf.org/fovcalc.php
    
    font serpentinemedium-12
    hovercommand "globalwidgetcommand tooltip_video title \"$$c#164$$\""
    hoverexitcommand "globalwidgetcommand tooltip_video title \"\""
	
	//hovercommand "seta r_mode -1;seta ui_testRes \"exec coop_mod/cfg/testres.cfg\""
	//hoverexitcommand ""
    
    clicksound sound/misc/menu/click.wav
}

resource
Button
{
	stuffcommand "exec coop_mod/cfg/testres.cfg\n"
	
	title	"Test"
	name 	"videoCostumResTest"
	rect 	 310 122 70 36
	font serpentinemedium-10
	
	fgcolor			0.937 0.643 0.129 1.000
	bgcolor			0 1 1 0.5
	hoverbgcolor	0 1 1 0.7
	hoverfgcolor	1.000 1.000 1.000 1.000
	
	borderstyle "3D_BORDER"
    verticaljustify top
	hovercommand "exec coop_mod/cfg/menu_video_testreshover.cfg"
	hoverexitcommand "exec coop_mod/cfg/menu_video_testreshexit.cfg"
	cvarvisibility cg_gametype -1 ==
}

resource
Button
{
	stuffcommand "pushmenu okDialog;globalwidgetcommand OkDialogTitle title $$c#148$$"
	
	title	"Test"
	name 	"videoCostumResTest2"
	rect 	 310 122 70 36
	font serpentinemedium-10
	
	fgcolor			0.937 0.643 0.129 1.000
	bgcolor			0.5 0.5 0.5 0.5
	borderstyle "NONE"
    verticaljustify top
	hovercommand "globalwidgetcommand tooltip_video title $$c#147$$"
	hoverexitcommand "globalwidgetcommand tooltip_video title \"\""
	cvarvisibility cg_gametype -1 !=
}

resource 
Label
{
	//used as bg for the actual real resolution
    name	"Default"
	rect 382 122 222 36
	bgcolor 0.122 0.157 0.251 1.000
	borderstyle "3D_BORDER"
}
	
resource
SwitchBox
{
    name "Default"
	rect 382 122 170 36
    fgcolor 1 1 1 1
    bgcolor 0.000 0.000 0.000 0
    borderstyle "NONE"
    bordercolor 0.122 0.157 0.251 1.000
	verticaljustify top
    
    linkcvar "r_mode"
	option "320 x 240" "" 0
	option "400 x 300" "" 1
	option "512 x 380" "" 2
	option "640 x 480" "" 3
	option "800 x 600" "" 4
	option "960 x 720" "" 5	
	option "1024 x 768" "" 6
	option "1152 x 864" "" 7
	option "1280 x 1024" "" 8
	option "1600 x 1200" "" 9	
	option "2048 x 1536" "" 10
	option "856 x 480" "" 11
    
    font serpentinemedium-12	
	cvarvisibility "r_mode" -1 !=
}

resource 
Label
{
    name	"Default"
    rect 382 122 70 36
    fgcolor 1 1 1 1
    bgcolor 0.122 0.157 0.251 0
    borderstyle "NONE"
    font serpentinemedium-12
    horizontaljustify right
	verticaljustify top
	linkcvar "r_customwidth"
	cvarvisibility "r_mode" -1 ==
}

resource 
Label
{
	title "X"
    name	"Default"
    rect 454 122 26 36
    fgcolor 1 1 1 1
    bgcolor 0.122 0.157 0.251 0
    borderstyle "NONE"
    font serpentinemedium-12
    horizontaljustify center
	verticaljustify top
	cvarvisibility "r_mode" -1 ==
}

resource 
Label
{
    name	"Default"
    rect 482 122 70 36
    fgcolor 1 1 1 1
    bgcolor 0.122 0.157 0.251 0
    borderstyle "NONE"
    font serpentinemedium-12
    horizontaljustify left
	verticaljustify top
	linkcvar "r_customheight"
	cvarvisibility "r_mode" -1 ==
}

resource 
Label
{
	//used to cover the switchbox of the actual resolution, to prevent clicking on it
    name	"Default"
	rect 382 122 170 36
	bgcolor 0 0 0 0	
    hovercommand "globalwidgetcommand tooltip_video title \"$$c#034$$\""
    hoverexitcommand "globalwidgetcommand tooltip_video title \"\""
}

resource
CheckBox
{
	title "$$FullScreen$$"
	name "Default"
	rect 312 162 120 34
	fgcolor 1.00 1.00 1.00 1.00
	bgcolor 0.50 0.50 0.50 0.00

	shadercolor             0.953 0.667 0.271 1.000
	hovershadercolor        0.953 0.667 0.271 1.000
	armedshadercolor        0.953 0.667 0.271 1.000
	selectedshadercolor     0.953 0.667 0.271 1.000

	borderstyle "NONE"
	linkcvar "r_fullscreen"
	horizontaljustify left
	checked_shader "textures/menu/checkbox_checked"
	unchecked_shader "textures/menu/checkbox_unchecked"
	hovershader menu/generic/button-hover
	armedshader menu/generic/button-press
	font serpentinemedium-10
	hovercommand "globalwidgetcommand tooltip_video title \"$$SetFullScreen$$\""
	hoverexitcommand "globalwidgetcommand tooltip_video title \"\""

	clicksound sound/misc/menu/click.wav
}


resource
Button
{
	stuffcommand "exec coop_mod/cfg/highsettings.cfg"
	
	title	"$$c#161$$"
	name 	"Default"
	rect 	 430 160 174 36
	font serpentinemedium-10
	fgcolor			1 1 1 1
	bgcolor			0.502 0.000 0.502 1.000
	hoverbgcolor	0.6 0.2 0.6 1
	hoverfgcolor	0.000 0.000 0.000 1.000
	borderstyle "3D_BORDER"
    verticaljustify top
	
	hovercommand "globalwidgetcommand tooltip_video title \"$$c#162$$\""
	hoverexitcommand "globalwidgetcommand tooltip_video title \"\""
}

///////////////////////////////////////////////////////////////// VIDEO SETTINGS userfov
///////////////////////////////////////////////////////////////// VIDEO SETTINGS userfov
///////////////////////////////////////////////////////////////// VIDEO SETTINGS userfov
///////////////////////////////////////////////////////////////// VIDEO SETTINGS userfov
resource
Label
{
    title "$$c#131$$"
    name "Default"
    rect 36 160 108 36
    fgcolor 1.00 1.00 1.00 1.00
    bgcolor 0.122 0.157 0.251 1.000
    borderstyle "3D_BORDER"
    font serpentinemedium-10
    horizontaljustify right
	verticaljustify top
	hovercommand "globalwidgetcommand videoCurrFov bgcolor 0 1 0.5 0.5"
	hoverexitcommand "globalwidgetcommand videoCurrFov bgcolor 0.00 0.00 0.00 0.85"
}

resource
Field
{
    name "videoCurrFov"
	rect 146 160 80 36
	fgcolor 1.00 1.00 1.00 1.00
	bgcolor 0.000 0.000 0.000 0.000
	borderstyle	"OUTLINE_BORDER"
	bordercolor	0.125 0.157 0.251 1.000
	horizontaljustify left
	verticaljustify top
	borderstyle	    "NONE"
	font serpentinemedium-12
    clicksound sound/misc/menu/click.wav
	linkcvar "userfov"
	maxcharacters 5
	//stuffcommand    "ui_setrangecvar userfov $e$ 0.0 160.0;ui_verifycvarrange 0 userfov\n"
}

resource
Button
{
	stuffcommand "transitionmenu userfov\n"
	
	title	"$$c#132$$"
	name 	"Default"
	rect 	 228 160 80 36
	font serpentinemedium-10
	fgcolor			0.937 0.643 0.129 1.000
	bgcolor			0.125 0.157 0.251 1.000
	hoverbgcolor	0.278 0.365 0.510 1.000
	hoverfgcolor	1.000 1.000 1.000 1.000
	borderstyle "3D_BORDER"
    verticaljustify top
}

///////////////////////////////////////////////////////////////// VIDEO SETTINGS Texture filter
///////////////////////////////////////////////////////////////// VIDEO SETTINGS Texture filter
///////////////////////////////////////////////////////////////// VIDEO SETTINGS Texture filter
///////////////////////////////////////////////////////////////// VIDEO SETTINGS Texture filter
resource 
Label
{
    title "$$TextureFilter$$"
    name	"Default"
    rect 36 198 140 36
    fgcolor 1.00 1.00 1.00 1.00
    bgcolor 0.122 0.157 0.251 1.000
    borderstyle "3D_BORDER"
    font serpentinemedium-10
    
    horizontaljustify right
    hovercommand "globalwidgetcommand tooltip_video title \"$$SetTextureFilter$$\""
    hoverexitcommand "globalwidgetcommand tooltip_video title \"\""
	verticaljustify top
}

resource
SwitchBox
{
    name "Default"
    rect 178 198 130 36
    fgcolor 0.953 0.667 0.271 1.000
    bgcolor 0.000 0.000 0.000 0.750
    borderstyle "OUTLINE_BORDER"
    bordercolor 0.122 0.157 0.251 1.000
    
    linkcvar "r_texturemode"
    
    option "$$Bilinear$$"   "set r_texturemode gl_linear_mipmap_nearest" gl_linear_mipmap_nearest
    option "$$Trilinear$$"  "set r_texturemode gl_linear_mipmap_linear" gl_linear_mipmap_linear

    font serpentinemedium-10
    hovercommand "globalwidgetcommand tooltip_video title \"$$SetTextureFilter$$\""
    hoverexitcommand "globalwidgetcommand tooltip_video title \"\""
    
    clicksound sound/misc/menu/click.wav
}

///////////////////////////////////////////////////////////////// VIDEO SETTINGS  texture detail
///////////////////////////////////////////////////////////////// VIDEO SETTINGS  texture detail
///////////////////////////////////////////////////////////////// VIDEO SETTINGS  texture detail
///////////////////////////////////////////////////////////////// VIDEO SETTINGS  texture detail
resource 
Label
{
    title "$$TextureQuality$$"
    name	"Default"
    rect 332 198 140 36 
    fgcolor 1.00 1.00 1.00 1.00
    bgcolor 0.122 0.157 0.251 1.000
    borderstyle "3D_BORDER"
    font serpentinemedium-10
    horizontaljustify right
    hovercommand "globalwidgetcommand tooltip_video title \"$$SetTextureDetail$$\""
    hoverexitcommand "globalwidgetcommand tooltip_video title \"\""
	verticaljustify top
}

resource
SwitchBox
{
    name "Default"
    rect 474 198 130 36
    fgcolor 0.953 0.667 0.271 1.000
    bgcolor 0.000 0.000 0.000 0.750
    borderstyle "OUTLINE_BORDER"
    bordercolor 0.122 0.157 0.251 1.000
    
    linkcvar "r_picmip"
    
    option "$$Low$$"        "set r_picmip 2;exec coop_mod/cfg/menu_video_customreschange.cfg" 2
    option "$$Medium$$"     "set r_picmip 1;exec coop_mod/cfg/menu_video_customreschange.cfg" 1
    option "$$High$$"       "set r_picmip 0;exec coop_mod/cfg/menu_video_customreschange.cfg" 0

    font serpentinemedium-10
    
    hovercommand "globalwidgetcommand tooltip_video title \"$$SetTextureDetail$$\""
    hoverexitcommand "globalwidgetcommand tooltip_video title \"\""
    
    clicksound sound/misc/menu/click.wav
}

///////////////////////////////////////////////////////////////// VIDEO SETTINGS  renderer method r_primitives
///////////////////////////////////////////////////////////////// VIDEO SETTINGS  renderer method r_primitives
///////////////////////////////////////////////////////////////// VIDEO SETTINGS  renderer method r_primitives
///////////////////////////////////////////////////////////////// VIDEO SETTINGS  renderer method r_primitives
resource 
Label
{
    title "Render-Method:"
	name "renderMethodTitle"
	rect 36 236 140 36
	fgcolor 1.000 1.000 1.000 1.000
	bgcolor 0.122 0.157 0.251 1.000
	font serpentinemedium-10
	borderstyle "3D_BORDER"	
	horizontaljustify right
	verticaljustify top
}
resource
SwitchBox
{
    name "Default"
    rect 178 236 130 36
    fgcolor 0.953 0.667 0.271 1.000
    bgcolor 0.000 0.000 0.000 0.750
    borderstyle "OUTLINE_BORDER"
    bordercolor 0.122 0.157 0.251 1.000
    
    linkcvar		"r_primitives"

    option "Auto - Vertex"		"set r_primitives 0" 0
    option "Tristrips"			"set r_primitives 1" 1
    option "Triangles"			"set r_primitives 2" 2
    option "Multiple Ext."		"set r_primitives 3" 3
    
    font serpentinemedium-10
    hovercommand "globalwidgetcommand tooltip_video title $$c#151$$"
    hoverexitcommand "globalwidgetcommand tooltip_video title \"\""
    
    clicksound sound/misc/menu/click.wav
}

///////////////////////////////////////////////////////////////// VIDEO SETTINGS  color depth
///////////////////////////////////////////////////////////////// VIDEO SETTINGS  color depth
///////////////////////////////////////////////////////////////// VIDEO SETTINGS  color depth
///////////////////////////////////////////////////////////////// VIDEO SETTINGS  color depth
resource 
Label
{
    title "$$ColorDepth$$"
    name "Default"
    rect 332 236 140 36
    fgcolor 1.00 1.00 1.00 1.00
    bgcolor 0.122 0.157 0.251 1.000
    borderstyle "3D_BORDER"
    font serpentinemedium-10
    horizontaljustify right
    hovercommand "globalwidgetcommand tooltip_video title \"$$SetColorDepth$$\""
    hoverexitcommand "globalwidgetcommand tooltip_video title \"\""
	verticaljustify top
}

resource
SwitchBox
{
    name "Default"
    rect 474 236 130 36
    fgcolor 0.953 0.667 0.271 1.000
    bgcolor 0.000 0.000 0.000 0.750
    borderstyle "OUTLINE_BORDER"
    bordercolor 0.122 0.157 0.251 1.000
    
    linkcvar "r_texturebits"
    
    option "$$Default$$"    "set r_texturebits 0;exec coop_mod/cfg/menu_video_customreschange.cfg"   0
    option "$$16Bit$$"      "set r_texturebits 16;exec coop_mod/cfg/menu_video_customreschange.cfg" 16
    option "$$32Bit$$"      "set r_texturebits 32;exec coop_mod/cfg/menu_video_customreschange.cfg" 32
    
    font serpentinemedium-10
    hovercommand "globalwidgetcommand tooltip_video title \"$$SetColorDepth$$\""
    hoverexitcommand "globalwidgetcommand tooltip_video title \"\""
    
    clicksound sound/misc/menu/click.wav
}