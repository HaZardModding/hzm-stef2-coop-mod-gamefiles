//=========================================================================================
//=========================================================================================
//===============================================================================screenshot
//=========================================================================================
resource
Label
{
	cvarvisibility coop_ui_vt 5 >
	
	name "coopShot"
	rect	72 250 160 100
	fgcolor 1.0 1.0 1.0 1.000
	bgcolor 0 0 0 0
	
	horizontaljustify left
	verticaljustify center
	shader sysimg/2d/default-map-screen.tga
}
resource 
Label
{
	cvarvisibility coop_ui_vt 5 >
	
	title ""
	name "coopName"
	rect	34 354 238 80
	fgcolor 1.0 1.0 1.0 1.000
	bgcolor 1 1 0 0
	
	horizontaljustify center
	verticaljustify top
	font serpentinemedium-12
}

//=========================================================================================
//=========================================================================================
//======================================================================COOP TYPE SELECTION
//=========================================================================================
resource
SwitchBox
{
	disable
	name "Default"
	//rect 50 200 219 36
	rect 34 200 219 36
	fgcolor 0.937 0.643 0.129 1.000
	bgcolor 0 0 0 0.850
	borderstyle	"OUTLINE_BORDER"
	bordercolor	0.278 0.365 0.510 1.000
	linkcvar "coop_ui_vt"
	font serpentinemedium-10
	
	horizontaljustify center
	verticaljustify top

//show the select coop map here text
	option "$$c#034$$" "set coop_ui_vt 6;set coop_ui_sm -1;\n" -1
	option "$$c#034$$" "set coop_ui_vt 6;set coop_ui_sm -1;\n" 0
	option "$$c#034$$" "set coop_ui_vt 6;set coop_ui_sm -1;\n" 1
	option "$$c#034$$" "set coop_ui_vt 6;set coop_ui_sm -1;\n" 2
	option "$$c#034$$" "set coop_ui_vt 6;set coop_ui_sm -1;\n" 3
	option "$$c#034$$" "set coop_ui_vt 6;set coop_ui_sm -1;\n" 4
	option "$$c#034$$" "set coop_ui_vt 6;set coop_ui_sm -1;\n" 5
	
//secret and traing
	option "$$c#035$$" "set coop_ui_vt 6;set coop_ui_sm -1;\n" 6
//missions
    option "$$c#036$$"  "set coop_ui_vt 7;set coop_ui_smn $$mission-m1$$;set coop_ui_sm 1;\n"   7
//community
	option "$$c#037$$" "set coop_ui_vt 13;set coop_ui_smn Custom_Maps;set coop_ui_sm 13;\n" 13
//gbs mod
	option "$$c#038$$" "set coop_ui_vt 14;set coop_ui_smn Custom_Maps;set coop_ui_sm 14;\n" 14
//rotec mod
	option "$$c#039$$" "set coop_ui_vt 15;set coop_ui_smn Custom_Maps;set coop_ui_sm 15;\n" 15
//aftermath mod
	option "$$c#040$$" "set coop_ui_vt 16;set coop_ui_smn Custom_Maps;set coop_ui_sm 16;\n" 16
//test and example
	option "$$c#041$$" "set coop_ui_vt 20;set coop_ui_smn Test_Maps;set coop_ui_sm 13;\n" 20
	 
	hovercommand "globalwidgetcommand tooltip_coop_startserver title \"Select Level Type\""
	hoverexitcommand "globalwidgetcommand tooltip_coop_startserver title \"\""

    clicksound sound/misc/menu/click.wav
}
resource
PulldownMenuContainer
{
	disable
	title "$$list$$"
	name "coopGpoSkillSelect"
	rect 254 200 20 36
    fgcolor 				0.953 0.667 0.271 1.000
    bgcolor                 1.000 1.000 1.000 0.000
    shadercolor             0.953 0.667 0.271 1.000
    hovershadercolor        0.953 0.667 0.271 1.000
    armedshadercolor        0.953 0.667 0.271 1.000
    selectedshadercolor     0.953 0.667 0.271 1.000
	//font serpentinelight-10
	font serpentinemedium-10
	
	
	
	menushader "pulldown" "textures/menu/pulldownarrow"
	selmenushader "pulldown" "textures/menu/pulldownarrow_sel"
	
	addpopup "pulldown"  "$$c#035$$"	command "set coop_ui_vt 6;set coop_ui_sm -1;\n" 6
    addpopup "pulldown"  "$$c#036$$"	command "set coop_ui_vt 7;set coop_ui_smn $$mission-m1$$;set coop_ui_sm 1;\n"   7
	addpopup "pulldown"  "$$c#037$$"	command "set coop_ui_vt 13;set coop_ui_smn Custom_Maps;set coop_ui_sm 13;\n" 13
	addpopup "pulldown"  "$$c#038$$"	command "set coop_ui_vt 14;set coop_ui_smn Custom_Maps;set coop_ui_sm 14;\n" 14
	addpopup "pulldown"  "$$c#039$$"	command "set coop_ui_vt 15;set coop_ui_smn Custom_Maps;set coop_ui_sm 15;\n" 15
	addpopup "pulldown"  "$$c#040$$"	command "set coop_ui_vt 16;set coop_ui_smn Custom_Maps;set coop_ui_sm 16;\n" 16
	addpopup "pulldown"  "$$c#041$$"	command "set coop_ui_vt 20;set coop_ui_smn Test_Maps;set coop_ui_sm 13;\n" 20
	
	hovercommand "globalwidgetcommand tooltip_callvote title \"$$c#049$$\""
    hoverexitcommand "globalwidgetcommand tooltip_callvote title \"\""
	
	popup_width "pulldown" 240
	popup_bgcolor "pulldown" 0 0 0 0.6
	highlight_bgcolor "pulldown" 0 0 1 0.6
    clicksound sound/misc/menu/click.wav
}


end.