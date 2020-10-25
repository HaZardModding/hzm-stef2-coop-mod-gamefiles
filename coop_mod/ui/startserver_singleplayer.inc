///////////////////////////////////////////////////////////////////////////////MISSION SELECTION CAMPAIGN MAPS
///////////////////////////////////////////////////////////////////////////////MISSION SELECTION CAMPAIGN MAPS
///////////////////////////////////////////////////////////////////////////////MISSION SELECTION CAMPAIGN MAPS
///////////////////////////////////////////////////////////////////////////////MISSION SELECTION CAMPAIGN MAPS

resource 
Label
{
	cvarvisibility coop_ui_vt 7 ==
	
	title ""
	name "singleplayerCampaignLevelsTitle"
	rect		274 89 330 24
	fgcolor 0.500 1.000 0.000 0.800
	bgcolor 0.12 0.15 0.25 1.00
	
	borderstyle "3D_BORDER"
	
	horizontaljustify left
	verticaljustify top
	font 	serpentinemedium-10
	
	hovercommand "globalwidgetcommand tooltip_coop_startserver title \"\""
    hoverexitcommand "globalwidgetcommand tooltip_coop_startserver title \"\""
}

// resource 
// Label
// {
	// cvarvisibility coop_ui_vt 7 ==	
	// title ""
	// name "switchMissionFakeIcon"
	// rect	586 89 18 18
	// fgcolor 0.500 1.000 0.000 0.800
	// bgcolor 0 0 0 0
	
	// borderstyle "NONE"
	
	// shader "textures/menu/pulldownarrow_sel"
	// shadercolor	0.953 0.667 0.271 1.000
// }

resource
SwitchBox
{
	cvarvisibility coop_ui_vt 7 ==
    name "Defaultswitchmission"
    rect 274 88 330 24
    fgcolor 0.500 1.000 0.000 0.800
    bgcolor 0 0 0 0
    borderstyle "None"
    bordercolor 0 0 0 0
    
    linkcvar "coop_ui_sm"
	
    option "$$mission-m1$$"		"set coop_ui_sm 1" 1
    option "$$mission-m2$$"		"set coop_ui_sm 2" 2
    option "$$mission-m3$$"		"set coop_ui_sm 3" 3
    option "$$mission-m4$$"		"set coop_ui_sm 4" 4
    option "$$mission-m5$$"		"set coop_ui_sm 5" 5
    option "$$mission-m6$$"		"set coop_ui_sm 6" 6
    option "$$mission-m7$$"		"set coop_ui_sm 7" 7
    option "$$mission-m8$$"		"set coop_ui_sm 8" 8
    option "$$mission-m9$$"		"set coop_ui_sm 9" 9
    option "$$mission-m10$$"	"set coop_ui_sm 10" 10
    option "$$mission-m11$$"	"set coop_ui_sm 11" 11
    option "$$M12End$$"			"set coop_ui_sm 12" 12
    
	horizontaljustify left
	verticaljustify top
	
    hovercommand "globalwidgetcommand tooltip_video title \"$$SelectLevel$$\""
    hoverexitcommand "globalwidgetcommand tooltip_video title \"\""
    
    clicksound sound/misc/menu/click.wav
}

resource
SwitchBox
{
	linkcvar "coop_ui_sm"
	
    option "Next"		"set coop_ui_sm 1" 1
    option "Next"		"set coop_ui_sm 2" 2
    option "Next"		"set coop_ui_sm 3" 3
    option "Next"		"set coop_ui_sm 4" 4
    option "Next"		"set coop_ui_sm 5" 5
    option "Next"		"set coop_ui_sm 6" 6
    option "Next"		"set coop_ui_sm 7" 7
    option "Next"		"set coop_ui_sm 8" 8
    option "Next"		"set coop_ui_sm 9" 9
    option "Next"	"set coop_ui_sm 10" 10
    option "Next"	"set coop_ui_sm 11" 11
    option "Next"	"set coop_ui_sm 12" 12
	
	name 	"switchMissionNextButtonSwitcher"
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
	stuffcommand ""
    verticaljustify top
	hovercommand "globalwidgetcommand coop_settings_tooltip title \"Show next Singleplayer Mission\""
	hoverexitcommand "globalwidgetcommand coop_settings_tooltip title \"\""
	
	cvarvisibility coop_ui_vt 7 ==
}
//////////////////////////////////////////////////////////////////////////////////////// MISSION 1 BORG
//////////////////////////////////////////////////////////////////////////////////////// MISSION 1 BORG
//////////////////////////////////////////////////////////////////////////////////////// MISSION 1 BORG
//////////////////////////////////////////////////////////////////////////////////////// MISSION 1 BORG

resource
Button
{
	cvarvisibility coop_ui_sm 1 ==
	title "Prolog"
	name 	"mision1Level0"
	rect	275 114 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap m0-intro\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/mapshots/m0-intro.tga;globalwidgetcommand coop_startserverName title \"Ritual Entertainment\""
    hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_sm 1 ==
	title "$$BorgSphereLevel1aDesc$$"
	name 	"mision1Level1"
	rect	275 135 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top
	
	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap m1l1a-borg_sphere\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/mapshots/m1l1a-borg_sphere.tga;globalwidgetcommand coop_startserverName title \"Ritual Entertainment\""
    hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_sm 1 ==
	title "$$BorgSphereLevel1bDesc$$"
	name 	"mision1Level2"
	rect	275 156 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top
	
	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap m1l1b-borg_sphere\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/mapshots/m1l1b-borg_sphere.tga;globalwidgetcommand coop_startserverName title \"Ritual Entertainment\""
    hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_sm 1 ==
	title "$$BorgSphereLevel1cDesc$$"
	name 	"mision1Level3"
	rect	275 177 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top
	
	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap m1l1c-borg_sphere\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/mapshots/m1l1c-borg_sphere.tga;globalwidgetcommand coop_startserverName title \"Ritual Entertainment\""
    hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_sm 1 ==
	title "$$BorgSphereLevel2aDesc$$"
	name 	"mision1Level4"
	rect	275 198 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top
	
	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap m1l2a-borg_sphere\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/mapshots/m1l2a-borg_sphere.tga;globalwidgetcommand coop_startserverName title \"Ritual Entertainment\""
	hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_sm 1 ==
	title "$$BorgSphereLevel2bDesc$$"
	name 	"mision1Level5"
	rect	275 219 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top
	
	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap m1l2b-borg_sphere\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/mapshots/m1l2b-borg_sphere.tga;globalwidgetcommand coop_startserverName title \"Ritual Entertainment\""
    hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_sm 1 ==
	title "$$BorgSphereLevel2cDesc$$"
	name 	"mision1Level6"
	rect	275 240 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top
	
	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap m1l2c-borg_sphere\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/mapshots/m1l2c-borg_sphere.tga;globalwidgetcommand coop_startserverName title \"Ritual Entertainment\""
    hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_sm 1 ==
	title "$$BorgBossLevelDesc$$"
	name 	"mision1Level7"
	rect	275 261 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top
	
	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap m1l3-borg_boss\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/mapshots/m1l3-borg_boss.tga;globalwidgetcommand coop_startserverName title \"Ritual Entertainment\""
    hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}

//////////////////////////////////////////////////////////////////////////////////////// MISSION 2 STARFLEET
//////////////////////////////////////////////////////////////////////////////////////// MISSION 2 STARFLEET
//////////////////////////////////////////////////////////////////////////////////////// MISSION 2 STARFLEET
//////////////////////////////////////////////////////////////////////////////////////// MISSION 2 STARFLEET
resource
Button
{
	cvarvisibility coop_ui_sm 2 ==
	title "$$StarfleetAcademyLevel1Desc$$"
	name 	"mision2Level0"
	rect	275 114 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap m2l0-sfa\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/mapshots/m2l0-sfa.tga;globalwidgetcommand coop_startserverName title \"Ritual Entertainment\""
    hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_sm 2 ==
	title "$$StarfleetAcademyLevel2Desc$$"
	name 	"mision2Level1"
	rect	275 135 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top
	
	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap m2l1-sfa\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/mapshots/m2l1-sfa.tga;globalwidgetcommand coop_startserverName title \"Ritual Entertainment\""
    hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_sm 2 ==
	title "$$StarfleetAcademyLevel3Desc$$"
	name 	"mision2Level2"
	rect	275 156 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top
	
	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap m2l2-sfa\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/mapshots/m2l2-sfa.tga;globalwidgetcommand coop_startserverName title \"Ritual Entertainment\""
    hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}

//////////////////////////////////////////////////////////////////////////////////////// MISSION 3 USS DALLAS
//////////////////////////////////////////////////////////////////////////////////////// MISSION 3 USS DALLAS
//////////////////////////////////////////////////////////////////////////////////////// MISSION 3 USS DALLAS
//////////////////////////////////////////////////////////////////////////////////////// MISSION 3 USS DALLAS
resource
Button
{
	cvarvisibility coop_ui_sm 3 ==
	title "$$IGM$$"
	name 	"mision3Level0"
	rect	275 114 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap ent-deck8$igm=1?tr=0?h=0?ts=0?r=0?hm=0?m5unlocked=0\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/mapshots/ent-deck8.tga;globalwidgetcommand coop_startserverName title \"Ritual Entertainment\""
    hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_sm 3 ==
	title "$$DallasLevel1aDesc$$"
	name 	"mision3Level1"
	rect	275 135 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap m3l1a-forever\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/mapshots/m3l1a-forever.tga;globalwidgetcommand coop_startserverName title \"Ritual Entertainment\""
    hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_sm 3 ==
	title "$$DallasLevel1bDesc$$"
	name 	"mision3Level2"
	rect	275 156 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top
	
	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap m3l1b-forever\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/mapshots/m3l1b-forever.tga;globalwidgetcommand coop_startserverName title \"Ritual Entertainment\""
    hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_sm 3 ==
	title "$$DallasLevel2Desc$$"
	name 	"mision3Level3"
	rect	275 177 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top
	
	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap m3l2-forever\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/mapshots/m3l2-forever.tga;globalwidgetcommand coop_startserverName title \"Ritual Entertainment\""
    hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}

//////////////////////////////////////////////////////////////////////////////////////// MISSION 4 ATRAXIAN STATION
//////////////////////////////////////////////////////////////////////////////////////// MISSION 4 ATRAXIAN STATION
//////////////////////////////////////////////////////////////////////////////////////// MISSION 4 ATRAXIAN STATION
//////////////////////////////////////////////////////////////////////////////////////// MISSION 4 ATRAXIAN STATION
resource
Button
{
	cvarvisibility coop_ui_sm 4 ==
	title "$$IGM$$"
	name 	"mision4Level0"
	rect	275 114 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap ent-deck1_bridge$igm=2?tr=0?h=0?ts=0?r=0?hm=0?m5unlocked=0\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/mapshots/ent-deck1_bridge.tga;globalwidgetcommand coop_startserverName title \"Ritual Entertainment\""
    hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_sm 4 ==
	title "$$AttrexianStationLevel1aDesc$$"
	name 	"mision4Level1"
	rect	275 135 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap m4l1a-attrexian_station\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/mapshots/m4l1a-attrexian_station.tga;globalwidgetcommand coop_startserverName title \"Ritual Entertainment\""
    hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_sm 4 ==
	title "$$AttrexianStationLevel1bDesc$$"
	name 	"mision4Level2"
	rect	275 156 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top
	
	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap m4l1b-attrexian_station\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/mapshots/m4l1b-attrexian_station.tga;globalwidgetcommand coop_startserverName title \"Ritual Entertainment\""
    hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_sm 4 ==
	title "$$AttrexianStationLevel2bDesc$$"
	name 	"mision4Level3"
	rect	275 177 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top
	
	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap m4l2b-attrexian_station\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/mapshots/m4l2b-attrexian_station.tga;globalwidgetcommand coop_startserverName title \"Ritual Entertainment\""
    hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}

//////////////////////////////////////////////////////////////////////////////////////// MISSION 5 IDRYLL RUINS 1
//////////////////////////////////////////////////////////////////////////////////////// MISSION 5 IDRYLL RUINS 1
//////////////////////////////////////////////////////////////////////////////////////// MISSION 5 IDRYLL RUINS 1
//////////////////////////////////////////////////////////////////////////////////////// MISSION 5 IDRYLL RUINS 1
resource
Button
{
	cvarvisibility coop_ui_sm 5 ==
	title "$$IGM$$"
	name 	"mision5Level0"
	rect	275 114 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap ent-deck8$igm=3?tr=0?h=0?ts=0?r=0?hm=0?m5unlocked=0\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/mapshots/ent-deck8.tga;globalwidgetcommand coop_startserverName title \"Ritual Entertainment\""
    hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_sm 5 ==
	title "$$DrullRuinsLevel1aDesc$$"
	name 	"mision5Level1"
	rect	275 135 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap m5l1a-drull_ruins1\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/mapshots/m5l1a-drull_ruins1.tga;globalwidgetcommand coop_startserverName title \"Ritual Entertainment\""
    hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_sm 5 ==
	title "$$DrullRuinsLevel1bDesc$$"
	name 	"mision5Level2"
	rect	275 156 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top
	
	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap m5l1b-drull_ruins1\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/mapshots/m5l1b-drull_ruins1.tga;globalwidgetcommand coop_startserverName title \"Ritual Entertainment\""
    hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_sm 5 ==
	title "$$DrullRuinsLevel2aDesc$$"
	name 	"mision5Level3"
	rect	275 177 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top
	
	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap m5l2a-drull_ruins1\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/mapshots/m5l2a-drull_ruins1.tga;globalwidgetcommand coop_startserverName title \"Ritual Entertainment\""
    hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_sm 5 ==
	title "$$DrullRuinsLevel2bDesc$$"
	name 	"mision5Level4"
	rect	275 198 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top
	
	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap m5l2b-drull_ruins1\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/mapshots/m5l2b-drull_ruins1.tga;globalwidgetcommand coop_startserverName title \"Ritual Entertainment\""
    hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_sm 5 ==
	title "$$DrullRuinsLevel2cDesc$$"
	name 	"mision5Level5"
	rect	275 219 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top
	
	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap m5l2c-drull_ruins1\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/mapshots/m5l2c-drull_ruins1.tga;globalwidgetcommand coop_startserverName title \"Ritual Entertainment\""
	hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
//////////////////////////////////////////////////////////////////////////////////////// MISSION 6 ENTERPRISE ATTACK
//////////////////////////////////////////////////////////////////////////////////////// MISSION 6 ENTERPRISE ATTACK
//////////////////////////////////////////////////////////////////////////////////////// MISSION 6 ENTERPRISE ATTACK
//////////////////////////////////////////////////////////////////////////////////////// MISSION 6 ENTERPRISE ATTACK
resource
Button
{
	cvarvisibility coop_ui_sm 6 ==
	title "$$IGM$$"
	name 	"mision6Level0"
	rect	275 114 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap ent-deck1_bridge$igm=4?tr=0?h=0?ts=0?r=0?m5unlocked=0\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/mapshots/ent-deck1_bridge.tga;globalwidgetcommand coop_startserverName title \"Ritual Entertainment\""
    hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_sm 6 ==
	title "$$M6l0$$"
	name 	"mision6Level1"
	rect	275 135 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap m6l0-attack\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/mapshots/m6l0-attack.tga;globalwidgetcommand coop_startserverName title \"Ritual Entertainment\""
    hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_sm 6 ==
	title "$$M6Deck8_red$$"
	name 	"mision6Level2"
	rect	275 156 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top
	
	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap m6-deck8_redalert\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/mapshots/m6-deck8_redalert.tga;globalwidgetcommand coop_startserverName title \"Ritual Entertainment\""
    hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_sm 6 ==
	title "$$M6Deck16$$"
	name 	"mision6Level3"
	rect	275 177 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top
	
	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap m6-deck16_engineering\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/mapshots/m6-deck16_engineering.tga;globalwidgetcommand coop_startserverName title \"Ritual Entertainment\""
    hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_sm 6 ==
	title "$$M6Deck1Bridge_red$$"
	name 	"mision6Level4"
	rect	275 198 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top
	
	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap m6-deck1_bridge_redalert\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/mapshots/m6-deck1_bridge_redalert.tga;globalwidgetcommand coop_startserverName title \"Ritual Entertainment\""
    hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_sm 6 ==
	title "$$M6Ext$$"
	name 	"mision6Level5"
	rect	275 219 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top
	
	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap m6-exterior\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/mapshots/m6-exterior.tga;globalwidgetcommand coop_startserverName title \"Ritual Entertainment\""
	hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}

//////////////////////////////////////////////////////////////////////////////////////// MISSION 7 Attrexian COLONY
//////////////////////////////////////////////////////////////////////////////////////// MISSION 7 Attrexian COLONY
//////////////////////////////////////////////////////////////////////////////////////// MISSION 7 Attrexian COLONY
//////////////////////////////////////////////////////////////////////////////////////// MISSION 7 Attrexian COLONY
resource
Button
{
	cvarvisibility coop_ui_sm 7 ==
	title "$$AttrexianColonyLevel1aDesc$$"
	name 	"mision7Level0"
	rect	275 114 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap m7l1a-attrexian_colony\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/mapshots/m7l1a-attrexian_colony.tga;globalwidgetcommand coop_startserverName title \"Ritual Entertainment\""
    hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_sm 7 ==
	title "$$AttrexianColonyLevel1bDesc$$"
	name 	"mision7Level1"
	rect	275 135 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top
	
	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap m7l1b-attrexian_colony\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/mapshots/m7l1b-attrexian_colony.tga;globalwidgetcommand coop_startserverName title \"Ritual Entertainment\""
    hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_sm 7 ==
	title "$$AttrexianColonyLevel2aDesc$$"
	name 	"mision7Level2"
	rect	275 156 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top
	
	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap m7l2a-attrexian_colony\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/mapshots/m7l2a-attrexian_colony.tga;globalwidgetcommand coop_startserverName title \"Ritual Entertainment\""
    hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_sm 7 ==
	title "$$AttrexianColonyLevel2bDesc$$"
	name 	"mision7Level3"
	rect	275 177 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top
	
	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap m7l2b-attrexian_colony\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/mapshots/m7l2b-attrexian_colony.tga;globalwidgetcommand coop_startserverName title \"Ritual Entertainment\""
    hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_sm 7 ==
	title "$$AttrexianColonyLevel2cDesc$$"
	name 	"mision7Level4"
	rect	275 198 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top
	
	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap m7l2c-attrexian_colony\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/mapshots/m7l2c-attrexian_colony.tga;globalwidgetcommand coop_startserverName title \"Ritual Entertainment\""
	hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}

//////////////////////////////////////////////////////////////////////////////////////// MISSION 8 IDRYLL RUINS 2
//////////////////////////////////////////////////////////////////////////////////////// MISSION 8 IDRYLL RUINS 2
//////////////////////////////////////////////////////////////////////////////////////// MISSION 8 IDRYLL RUINS 2
//////////////////////////////////////////////////////////////////////////////////////// MISSION 8 IDRYLL RUINS 2
resource
Button
{
	cvarvisibility coop_ui_sm 8 ==
	title "$$DrullRuins2Level1aDesc$$"
	name 	"mision8Level0"
	rect	275 114 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap m8l1a-drull_ruins2\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/mapshots/m8l1a-drull_ruins2.tga;globalwidgetcommand coop_startserverName title \"Ritual Entertainment\""
    hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_sm 8 ==
	title "$$DrullRuins2Level1bDesc$$"
	name 	"mision8Level1"
	rect	275 135 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top
	
	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap m8l1b-drull_ruins2\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/mapshots/m8l1b-drull_ruins2.tga;globalwidgetcommand coop_startserverName title \"Ritual Entertainment\""
    hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_sm 8 ==
	title "$$DrullRuins2Level2aDesc$$"
	name 	"mision8Level2"
	rect	275 156 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top
	
	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap m8l2a-drull_ruins2\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/mapshots/m8l2a-drull_ruins2.tga;globalwidgetcommand coop_startserverName title \"Ritual Entertainment\""
    hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_sm 8 ==
	title "$$DrullRuins2Level2bDesc$$"
	name 	"mision8Level3"
	rect	275 177 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top
	
	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap m8l2b-drull_ruins2\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/mapshots/m8l2b-drull_ruins2.tga;globalwidgetcommand coop_startserverName title \"Ritual Entertainment\""
    hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}

//////////////////////////////////////////////////////////////////////////////////////// MISSION 9 KLINGON STARBASE
//////////////////////////////////////////////////////////////////////////////////////// MISSION 9 KLINGON STARBASE
//////////////////////////////////////////////////////////////////////////////////////// MISSION 9 KLINGON STARBASE
//////////////////////////////////////////////////////////////////////////////////////// MISSION 9 KLINGON STARBASE
resource
Button
{
	cvarvisibility coop_ui_sm 9 ==
	title "$$IGM$$"
	name 	"mision9Level0"
	rect	275 114 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap ent-deck8$igm=6?tr=0?h=0?ts=0?r=0?hm=0?m5unlocked=0\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/mapshots/ent-deck8.tga;globalwidgetcommand coop_startserverName title \"Ritual Entertainment\""
    hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_sm 9 ==
	title "$$KlingonBaseLevel1aDesc$$"
	name 	"mision9Level1"
	rect	275 135 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap m9l1a-klingon_base\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/mapshots/m9l1a-klingon_base.tga;globalwidgetcommand coop_startserverName title \"Ritual Entertainment\""
    hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_sm 9 ==
	title "$$KlingonBaseLevel1bDesc$$"
	name 	"mision9Level2"
	rect	275 156 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top
	
	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap m9l1b-klingon_base\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/mapshots/m9l1b-klingon_base.tga;globalwidgetcommand coop_startserverName title \"Ritual Entertainment\""
    hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_sm 9 ==
	title "$$KlingonBaseLevel2Desc$$"
	name 	"mision9Level3"
	rect	275 177 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top
	
	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap m9l2-klingon_base\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/mapshots/m9l2-klingon_base.tga;globalwidgetcommand coop_startserverName title \"Ritual Entertainment\""
    hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}

//////////////////////////////////////////////////////////////////////////////////////// MISSION 10 ROMULAN INSTALLATION
//////////////////////////////////////////////////////////////////////////////////////// MISSION 10 ROMULAN INSTALLATION
//////////////////////////////////////////////////////////////////////////////////////// MISSION 10 ROMULAN INSTALLATION
//////////////////////////////////////////////////////////////////////////////////////// MISSION 10 ROMULAN INSTALLATION
resource
Button
{
	cvarvisibility coop_ui_sm 10 ==
	title "$$IGM$$"
	name 	"mision10Level0"
	rect	275 114 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap ent-deck1_bridge$igm=7?tr=0?h=0?ts=0?r=0?m5unlocked=0\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/mapshots/ent-deck1_bridge.tga;globalwidgetcommand coop_startserverName title \"Ritual Entertainment\""
    hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_sm 10 ==
	title "$$RomulanInstallation1Desc$$"
	name 	"mision10Level1"
	rect	275 135 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap m10l1-romulan_installation\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/mapshots/m10l1-romulan_installation.tga;globalwidgetcommand coop_startserverName title \"Ritual Entertainment\""
    hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_sm 10 ==
	title "$$RomulanInstallation2aDesc$$"
	name 	"mision10Level2"
	rect	275 156 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top
	
	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap m10l2a-romulan_installation\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/mapshots/m10l2a-romulan_installation.tga;globalwidgetcommand coop_startserverName title \"Ritual Entertainment\""
    hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_sm 10 ==
	title "$$RomulanInstallation2bDesc$$"
	name 	"mision10Level3"
	rect	275 177 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top
	
	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap m10l2b-romulan_installation\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/mapshots/m10l2b-romulan_installation.tga;globalwidgetcommand coop_startserverName title \"Ritual Entertainment\""
    hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}

//////////////////////////////////////////////////////////////////////////////////////// MISSION 11 IDRYLL RUINS 3
//////////////////////////////////////////////////////////////////////////////////////// MISSION 11 IDRYLL RUINS 3
//////////////////////////////////////////////////////////////////////////////////////// MISSION 11 IDRYLL RUINS 3
//////////////////////////////////////////////////////////////////////////////////////// MISSION 11 IDRYLL RUINS 3
resource
Button
{
	cvarvisibility coop_ui_sm 11 ==
	title "$$IGM$$"
	name 	"mision11Level0"
	rect	275 114 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap ent-deck8$igm=8?tr=0?h=0?ts=0?r=0?hm=0?m5unlocked=0\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/mapshots/ent-deck8.tga;globalwidgetcommand coop_startserverName title \"Ritual Entertainment\""
    hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_sm 11 ==
	title "$$DrullRuins3Level1aDesc$$"
	name 	"mision11Level1"
	rect	275 135 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap m11l1a-drull_ruins3\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/mapshots/m11l1a-drull_ruins3.tga;globalwidgetcommand coop_startserverName title \"Ritual Entertainment\""
    hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_sm 11 ==
	title "$$DrullRuins3Level1bDesc$$"
	name 	"mision11Level2"
	rect	275 156 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top
	
	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap m11l2a-drull_ruins3\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/mapshots/m11l2a-drull_ruins3.tga;globalwidgetcommand coop_startserverName title \"Ritual Entertainment\""
    hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_sm 11 ==
	title "$$DrullRuins3BossLevel3aDesc$$"
	name 	"mision11Level3"
	rect	275 177 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top
	
	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap m11l3a-drull_ruins3_boss\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/mapshots/m11l3a-drull_ruins3_boss.tga;globalwidgetcommand coop_startserverName title \"Ritual Entertainment\""
    hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}
resource
Button
{
	cvarvisibility coop_ui_sm 11 ==
	title "$$DrullRuins3BossLevel3bDesc$$"
	name 	"mision11Level4"
	rect	275 198 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top
	
	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap m11l3b-drull_ruins3_boss\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/mapshots/m11l3b-drull_ruins3_boss.tga;globalwidgetcommand coop_startserverName title \"Ritual Entertainment\""
    hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}

//////////////////////////////////////////////////////////////////////////////////////// MISSION 12 END CREDITS
//////////////////////////////////////////////////////////////////////////////////////// MISSION 12 END CREDITS
//////////////////////////////////////////////////////////////////////////////////////// MISSION 12 END CREDITS
//////////////////////////////////////////////////////////////////////////////////////// MISSION 12 END CREDITS
resource
Button
{
	cvarvisibility coop_ui_sm 12 ==
	title "$$M12End$$"
	name 	"mision12Level0"
	rect	275 114 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	horizontaljustify left
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set ui_startmap m12-end\n"
	hovercommand "globalwidgetcommand coop_startserverShot shader sysimg/mapshots/m12-end.tga;globalwidgetcommand coop_startserverName title \"Ritual Entertainment\""
    hoverexitcommand "globalwidgetcommand coop_startserverShot shader sysimg/2d/default-map-screen.tga;globalwidgetcommand coop_startserverName title \"\""
}


end.

