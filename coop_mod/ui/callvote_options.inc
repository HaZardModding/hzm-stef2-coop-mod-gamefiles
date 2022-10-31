/////////////////////////////////////////////////////////////////////////Coop Gameplay Option
/////////////////////////////////////////////////////////////////////////Coop Gameplay Option
/////////////////////////////////////////////////////////////////////////Coop Gameplay Option
/////////////////////////////////////////////////////////////////////////Coop Gameplay Option
resource 
Label
{
	cvarvisibility coop_ui_vt 5 ==
	
	title "$$c#020$$" //[b607]
	name "coopGpoTitle" //[b607]
	rect		274 89 330 24
	fgcolor 0.0 1.0 1.0 1.000
	bgcolor 0.12 0.15 0.25 1.00
	
	borderstyle "3D_BORDER"
	
	horizontaljustify left
	verticaljustify top
	font 	serpentinemedium-10
}
resource
Label
{
	title "$$c#021$$"
	name "coopGpoSkillLabel" //[b607]
	rect	280 116 210 20
	fgcolor 1 1 1 1
	bgcolor 0 0 1 0
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	horizontaljustify right
	cvarvisibility coop_ui_vt 5 ==
}
resource
Label
{
	title ""
	name "coopGpoSkill" //[b607]
	rect	490 116 90 20
	fgcolor 0.0 1.0 1.0 1.000
	bgcolor 0.50 0.50 0.50 0
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	horizontaljustify right
	cvarvisibility coop_ui_vt 5 ==
}
resource
PulldownMenuContainer
{
	title "$$list$$"
	name "coopGpoSkillSelect" //[b607]
	rect 580 116 16 20
    fgcolor 				0.953 0.667 0.271 1.000
    bgcolor                 1.000 1.000 1.000 0.000
    shadercolor             0.953 0.667 0.271 1.000
    hovershadercolor        0.953 0.667 0.271 1.000
    armedshadercolor        0.953 0.667 0.271 1.000
    selectedshadercolor     0.953 0.667 0.271 1.000
	font serpentinelight-10
	
	menushader "MENU" "textures/menu/pulldownarrow"
	selmenushader "MENU" "textures/menu/pulldownarrow_sel"

	addpopup "MENU" "$$Easy$$"		command "callvote coop_skill 0\n"
	addpopup "MENU" "$$Normal$$"	command "callvote coop_skill 1\n"
	addpopup "MENU" "$$Hard$$"		command "callvote coop_skill 2\n"
	addpopup "MENU" "$$VeryHard$$"	command "callvote coop_skill 3\n"
	
	hovercommand "globalwidgetcommand tooltip_callvote title \"$$SetEasySkillLevel$$\""
    hoverexitcommand "globalwidgetcommand tooltip_callvote title \"\""
	
	popup_width "MENU" 310
    clicksound sound/misc/menu/click.wav
	cvarvisibility coop_ui_vt 5 ==
}

resource
Label
{
	title "$$c#022$$" //[b607]
	name "coopGpoAwLabel"
	rect	280 138 210 20
	fgcolor 1 1 1 1
	bgcolor 0 0 1 0
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	horizontaljustify right
	cvarvisibility coop_ui_vt 5 ==
}
resource
Label
{
	name "coopGpoAw" //[b607]
	rect	490 138 90 20
	fgcolor 0.0 1.0 1.0 1.000
	bgcolor 0.50 0.50 0.50 0
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	horizontaljustify right
	cvarvisibility coop_ui_vt 5 ==
}
resource
PulldownMenuContainer
{
	title "$$list$$"
	name "coopGpoAwSelect" //[b607]
	rect 580 138 16 20
    fgcolor 				0.953 0.667 0.271 1.000
    bgcolor                 1.000 1.000 1.000 0.000
    shadercolor             0.953 0.667 0.271 1.000
    hovershadercolor        0.953 0.667 0.271 1.000
    armedshadercolor        0.953 0.667 0.271 1.000
    selectedshadercolor     0.953 0.667 0.271 1.000
	font serpentinelight-10
	
	menushader "MENU" "textures/menu/pulldownarrow"
	selmenushader "MENU" "textures/menu/pulldownarrow_sel"

	addpopup "MENU" "Awards Off"		command "callvote coop_awards 0\n"
	addpopup "MENU" "Awards On"			command "callvote coop_awards 1\n"
	
	hovercommand "globalwidgetcommand tooltip_callvote title \"$$c#023$$\""
    hoverexitcommand "globalwidgetcommand tooltip_callvote title \"\""
	
	popup_width "MENU" 310
    clicksound sound/misc/menu/click.wav
	cvarvisibility coop_ui_vt 5 ==
}

resource
Label
{
	title "$$c#024$$"
	name "coopGpoMvSpdLabel" //[b607]
	rect	280 160 210 20
	fgcolor 1 1 1 1
	bgcolor 0 0 1 0
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	horizontaljustify right
	cvarvisibility coop_ui_vt 5 ==
}
resource
Label
{
	title ""
	name "coopGpoMvSpd" //[b607]
	rect	490 160 90 20
	fgcolor 0.0 1.0 1.0 1.000
	bgcolor 0.50 0.50 0.50 0
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	horizontaljustify right
	cvarvisibility coop_ui_vt 5 ==
}
resource
PulldownMenuContainer
{
	title "$$list$$"
	name "coopGpoMvSpdSelect" //[b607]
	rect 580 160 16 20
    fgcolor 				0.953 0.667 0.271 1.000
    bgcolor                 1.000 1.000 1.000 0.000
    shadercolor             0.953 0.667 0.271 1.000
    hovershadercolor        0.953 0.667 0.271 1.000
    armedshadercolor        0.953 0.667 0.271 1.000
    selectedshadercolor     0.953 0.667 0.271 1.000
	font serpentinelight-10
	
	menushader "MENU" "textures/menu/pulldownarrow"
	selmenushader "MENU" "textures/menu/pulldownarrow_sel"

	addpopup "MENU" "200"						command "callvote coop_maxspeed 200\n"
	addpopup "MENU" "250"						command "callvote coop_maxspeed 250\n"
	addpopup "MENU" "275"						command "callvote coop_maxspeed 275\n"
	addpopup "MENU" "$$c#043$$"	command "callvote coop_maxspeed 300\n"
	addpopup "MENU" "325"						command "callvote coop_maxspeed 325\n"
	addpopup "MENU" "350"						command "callvote coop_maxspeed 350\n"
	addpopup "MENU" "375"						command "callvote coop_maxspeed 375\n"
	addpopup "MENU" "$$c#045$$"		command "callvote coop_maxspeed 400\n"
	addpopup "MENU" "425"						command "callvote coop_maxspeed 425\n"
	addpopup "MENU" "450"						command "callvote coop_maxspeed 450\n"
	
	hovercommand "globalwidgetcommand tooltip_callvote title \"$$c#025$$\""
    hoverexitcommand "globalwidgetcommand tooltip_callvote title \"\""
	
	popup_width "MENU" 310
    clicksound sound/misc/menu/click.wav
	cvarvisibility coop_ui_vt 5 ==
}

resource
Label
{
	title "$$c#026$$"
	name "coopGpoFFLabel" //[b607]
	rect	280 182 210 20
	fgcolor 1 1 1 1
	bgcolor 0 0 1 0
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	horizontaljustify right
	cvarvisibility coop_ui_vt 5 ==
}
resource
Label
{
	title ""
	name "coopGpoFF" //[b607]
	rect	490 182 90 20
	fgcolor 0.0 1.0 1.0 1.000
	bgcolor 0.50 0.50 0.50 0
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	horizontaljustify right
	cvarvisibility coop_ui_vt 5 ==
}
resource
PulldownMenuContainer
{
	title "$$list$$"
	name "coopGpoFFSelect" //[b607]
	rect 580 182 16 20
    fgcolor 				0.953 0.667 0.271 1.000
    bgcolor                 1.000 1.000 1.000 0.000
    shadercolor             0.953 0.667 0.271 1.000
    hovershadercolor        0.953 0.667 0.271 1.000
    armedshadercolor        0.953 0.667 0.271 1.000
    selectedshadercolor     0.953 0.667 0.271 1.000
	font serpentinelight-10
	
	menushader "MENU" "textures/menu/pulldownarrow"
	selmenushader "MENU" "textures/menu/pulldownarrow_sel"

	addpopup "MENU" "0.00 - Off"	command "callvote coop_ff 0\n"
	addpopup "MENU" "0.25 - 25%"	command "callvote coop_ff 0.25\n"
	addpopup "MENU" "0.50 - 50%"	command "callvote coop_ff 0.5\n"
	addpopup "MENU" "0.75 - 75%"	command "callvote coop_ff 0.75\n"
	addpopup "MENU" "1.00 - 100%"	command "callvote coop_ff 1\n"
	addpopup "MENU" "1.25 - 125%"	command "callvote coop_ff 1.25\n"
	addpopup "MENU" "1.50 - 150%"	command "callvote coop_ff 1.50\n"
	
	hovercommand "globalwidgetcommand tooltip_callvote title \"$$c#027$$\""
    hoverexitcommand "globalwidgetcommand tooltip_callvote title \"\""
	
	popup_width "MENU" 310
    clicksound sound/misc/menu/click.wav
	cvarvisibility coop_ui_vt 5 ==
}

resource
Label
{
	title "$$c#028$$"
	name "coopGpoRspwtLabel" //[b607]
	rect	280 204 210 20
	fgcolor 1 1 1 1
	bgcolor 0 0 1 0
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	horizontaljustify right
	cvarvisibility coop_ui_vt 5 ==
}
resource
Label
{
	title ""
	name "coopGpoRspwt" //[b607]
	rect	490 204 90 20
	fgcolor 0.0 1.0 1.0 1.000
	bgcolor 0.50 0.50 0.50 0
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	horizontaljustify right
	cvarvisibility coop_ui_vt 5 ==
}
resource
PulldownMenuContainer
{
	title "$$list$$"
	name "coopGpoRspwtSelect" //[b607]
	rect 580 204 16 20
    fgcolor 				0.953 0.667 0.271 1.000
    bgcolor                 1.000 1.000 1.000 0.000
    shadercolor             0.953 0.667 0.271 1.000
    hovershadercolor        0.953 0.667 0.271 1.000
    armedshadercolor        0.953 0.667 0.271 1.000
    selectedshadercolor     0.953 0.667 0.271 1.000
	font serpentinelight-10
	
	menushader "MENU" "textures/menu/pulldownarrow"
	selmenushader "MENU" "textures/menu/pulldownarrow_sel"

	addpopup "MENU" "0 - Off"	command "callvote coop_respawntime 0\n"
	addpopup "MENU" "5 sec"		command "callvote coop_respawntime 5\n"
	addpopup "MENU" "10 sec"	command "callvote coop_respawntime 10\n"
	addpopup "MENU" "15 sec"	command "callvote coop_respawntime 15\n"
	addpopup "MENU" "20 sec"	command "callvote coop_respawntime 20\n"
	addpopup "MENU" "25 sec"	command "callvote coop_respawntime 25\n"
	addpopup "MENU" "30 sec"	command "callvote coop_respawntime 30\n"
	addpopup "MENU" "40 sec"	command "callvote coop_respawntime 40\n"
	addpopup "MENU" "50 sec"	command "callvote coop_respawntime 50\n"
	addpopup "MENU" "60 sec"	command "callvote coop_respawntime 60\n"
	
	hovercommand "globalwidgetcommand tooltip_callvote title \"$$c#029$$\""
    hoverexitcommand "globalwidgetcommand tooltip_callvote title \"\""
	
	popup_width "MENU" 310
    clicksound sound/misc/menu/click.wav
	cvarvisibility coop_ui_vt 5 ==
}
resource
Label
{
	title "$$c#030$$"
	name "coopGpoLmsLabel" //[b607]
	rect	280 226 210 20
	fgcolor 1 1 1 1
	bgcolor 0 0 1 0
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	horizontaljustify right
	cvarvisibility coop_ui_vt 5 ==
}
resource
Label
{
	title ""
	name "coopGpoLms" //[b607]
	rect	490 226 90 20
	fgcolor 0.0 1.0 1.0 1.000
	bgcolor 0.50 0.50 0.50 0
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	horizontaljustify right
	cvarvisibility coop_ui_vt 5 ==
}
resource
PulldownMenuContainer
{
	title "$$list$$"
	name "coopGpoLmsSelect" //[b607]
	rect 580 226 16 20
    fgcolor 				0.953 0.667 0.271 1.000
    bgcolor                 1.000 1.000 1.000 0.000
    shadercolor             0.953 0.667 0.271 1.000
    hovershadercolor        0.953 0.667 0.271 1.000
    armedshadercolor        0.953 0.667 0.271 1.000
    selectedshadercolor     0.953 0.667 0.271 1.000
	font serpentinelight-10
	
	menushader "MENU" "textures/menu/pulldownarrow"
	selmenushader "MENU" "textures/menu/pulldownarrow_sel"

	addpopup "MENU" "0 - Off"	command "callvote coop_lms 0\n"
	addpopup "MENU" "1 - Live"	command "callvote coop_lms 1\n"
	addpopup "MENU" "2 - Lives"	command "callvote coop_lms 2\n"
	addpopup "MENU" "3 - Lives"	command "callvote coop_lms 3\n"
	addpopup "MENU" "4 - Lives"	command "callvote coop_lms 4\n"
	addpopup "MENU" "5 - Lives"	command "callvote coop_lms 5\n"
	addpopup "MENU" "6 - Lives"	command "callvote coop_lms 6\n"
	addpopup "MENU" "7 - Lives"	command "callvote coop_lms 7\n"
	addpopup "MENU" "8 - Lives"	command "callvote coop_lms 8\n"
	addpopup "MENU" "9 - Lives"	command "callvote coop_lms 9\n"
	addpopup "MENU" "10 - Lives"	command "callvote coop_lms 10\n"
	
	hovercommand "globalwidgetcommand tooltip_callvote title \"$$c#031$$\""
    hoverexitcommand "globalwidgetcommand tooltip_callvote title \"\""
	
	popup_width "MENU" 310
    clicksound sound/misc/menu/click.wav
	cvarvisibility coop_ui_vt 5 ==
}

//[b60011] chrissstrahl - challenge selection option
resource
Label
{
	title "$$c#032$$"
	name "coopGpoChLabel"
	rect	280 248 210 20
	fgcolor 1 1 1 1
	bgcolor 0 0 1 0
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	horizontaljustify right
	cvarvisibility coop_ui_vt 5 ==
}
resource
Label
{
	title ""
	name "coopGpoCh"
	rect	490 248 90 20
	fgcolor 0.0 1.0 1.0 1.000
	bgcolor 0.50 0.50 0.50 0
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	horizontaljustify right
	cvarvisibility coop_ui_vt 5 ==
}
resource
PulldownMenuContainer
{
	title "$$list$$"
	name "coopGpoChSelect"
	rect 580 248 16 20
    fgcolor 				0.953 0.667 0.271 1.000
    bgcolor                 1.000 1.000 1.000 0.000
    shadercolor             0.953 0.667 0.271 1.000
    hovershadercolor        0.953 0.667 0.271 1.000
    armedshadercolor        0.953 0.667 0.271 1.000
    selectedshadercolor     0.953 0.667 0.271 1.000
	font serpentinelight-10
	
	menushader "MENU" "textures/menu/pulldownarrow"
	selmenushader "MENU" "textures/menu/pulldownarrow_sel"

	addpopup "MENU" "$$None$$"				command "callvote coop_challenge 0\n"
	addpopup "MENU" "Stick Together"		command "callvote coop_challenge 1\n"
	//addpopup "MENU" "Halo"				command "callvote coop_challenge 2\n"
	//addpopup "MENU" "Collision"			command "callvote coop_challenge 3\n"
	
	hovercommand "globalwidgetcommand tooltip_callvote title \"$$c#033$$\""
    hoverexitcommand "globalwidgetcommand tooltip_callvote title \"\""
	
	popup_width "MENU" 310
    clicksound sound/misc/menu/click.wav
	cvarvisibility coop_ui_vt 5 ==
}

// new dead bodies option [b607]
resource
Label
{
	title "$$c#114$$"
	name "coopGpoDbLabel"
	rect	280 270 210 20
	fgcolor 1 1 1 1
	bgcolor 0 0 1 0
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	horizontaljustify right
	cvarvisibility coop_ui_vt 5 ==
}
resource
Label
{
	title ""
	name "coopGpoDb"
	rect	490 270 90 20
	fgcolor 0.0 1.0 1.0 1.000
	bgcolor 0.50 0.50 0.50 0
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	horizontaljustify right
	cvarvisibility coop_ui_vt 5 ==
}
resource
PulldownMenuContainer
{
	title "$$list$$"
	name "coopGpoDbSelect"
	rect 580 270 16 20
    fgcolor 				0.953 0.667 0.271 1.000
    bgcolor                 1.000 1.000 1.000 0.000
    shadercolor             0.953 0.667 0.271 1.000
    hovershadercolor        0.953 0.667 0.271 1.000
    armedshadercolor        0.953 0.667 0.271 1.000
    selectedshadercolor     0.953 0.667 0.271 1.000
	font serpentinelight-10
	
	menushader "MENU" "textures/menu/pulldownarrow"
	selmenushader "MENU" "textures/menu/pulldownarrow_sel"

	addpopup "MENU" "$$Off$$"	command "callvote coop_deadbodies 0\n"
	addpopup "MENU" "5"		command "callvote coop_deadbodies 5\n"
	addpopup "MENU" "10"	command "callvote coop_deadbodies 10\n"
	addpopup "MENU" "15"	command "callvote coop_deadbodies 15\n"
	addpopup "MENU" "20"	command "callvote coop_deadbodies 20\n"
	addpopup "MENU" "25"	command "callvote coop_deadbodies 25\n"
	//addpopup "MENU" "30"	command "callvote coop_deadbodies 30\n"
	
	hovercommand "globalwidgetcommand tooltip_callvote title \"$$c#114$$\""
    hoverexitcommand "globalwidgetcommand tooltip_callvote title \"\""
	
	popup_width "MENU" 310
    clicksound sound/misc/menu/click.wav
	cvarvisibility coop_ui_vt 5 ==
}
//end of new dead bodies option [b607]

// new statis time option [b607]
resource
Label
{
	title "$$c#115$$"
	name "coopGpoStLabel"
	rect	280 292 210 20
	fgcolor 1 1 1 1
	bgcolor 0 0 1 0
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	horizontaljustify right
	cvarvisibility coop_ui_vt 5 ==
}
resource
Label
{
	title ""
	name "coopGpoSt"
	rect	490 292 90 20
	fgcolor 0.0 1.0 1.0 1.000
	bgcolor 0.50 0.50 0.50 0
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	horizontaljustify right
	cvarvisibility coop_ui_vt 5 ==
}
resource
PulldownMenuContainer
{
	title "$$list$$"
	name "coopGpoStSelect"
	rect 580 292 16 20
    fgcolor 				0.953 0.667 0.271 1.000
    bgcolor                 1.000 1.000 1.000 0.000
    shadercolor             0.953 0.667 0.271 1.000
    hovershadercolor        0.953 0.667 0.271 1.000
    armedshadercolor        0.953 0.667 0.271 1.000
    selectedshadercolor     0.953 0.667 0.271 1.000
	font serpentinelight-10
	
	menushader "MENU" "textures/menu/pulldownarrow"
	selmenushader "MENU" "textures/menu/pulldownarrow_sel"

	addpopup "MENU" "$$Default$$"	command "callvote coop_stasistime 7\n"
	addpopup "MENU" "10"	command "callvote coop_stasistime 10\n"
	addpopup "MENU" "15"	command "callvote coop_stasistime 15\n"
	addpopup "MENU" "20"	command "callvote coop_stasistime 20\n"
	addpopup "MENU" "25"	command "callvote coop_stasistime 25\n"
	addpopup "MENU" "30"	command "callvote coop_stasistime 30\n"
	
	hovercommand "globalwidgetcommand tooltip_callvote title \"$$c#115$$\""
    hoverexitcommand "globalwidgetcommand tooltip_callvote title \"\""
	
	popup_width "MENU" 310
    clicksound sound/misc/menu/click.wav
	cvarvisibility coop_ui_vt 5 ==
}
//end of new statis time option [b607]

// new airaccellerate option [b607]
resource
Label
{
	title "$$c#116$$"
	name "coopGpoAaLabel"
	rect	280 314 210 20
	fgcolor 1 1 1 1
	bgcolor 0 0 1 0
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	horizontaljustify right
	cvarvisibility coop_ui_vt 5 ==
}
resource
Label
{
	title ""
	name "coopGpoAa"
	rect	490 314 90 20
	fgcolor 0.0 1.0 1.0 1.000
	bgcolor 0.50 0.50 0.50 0
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	horizontaljustify right
	cvarvisibility coop_ui_vt 5 ==
}
resource
PulldownMenuContainer
{
	title "$$list$$"
	name "coopGpoAaSelect"
	rect 580 314 16 20
    fgcolor 				0.953 0.667 0.271 1.000
    bgcolor                 1.000 1.000 1.000 0.000
    shadercolor             0.953 0.667 0.271 1.000
    hovershadercolor        0.953 0.667 0.271 1.000
    armedshadercolor        0.953 0.667 0.271 1.000
    selectedshadercolor     0.953 0.667 0.271 1.000
	font serpentinelight-10
	
	menushader "MENU" "textures/menu/pulldownarrow"
	selmenushader "MENU" "textures/menu/pulldownarrow_sel"

	addpopup "MENU" "0"	command "callvote coop_airaccelerate 0\n"
	addpopup "MENU" "1"	command "callvote coop_airaccelerate 1\n"
	addpopup "MENU" "$$Default$$"	command "callvote coop_airaccelerate 2\n"
	addpopup "MENU" "3"	command "callvote coop_airaccelerate 3\n"
	addpopup "MENU" "4"	command "callvote coop_airaccelerate 4\n"
	
	hovercommand "globalwidgetcommand tooltip_callvote title \"$$c#116$$\""
    hoverexitcommand "globalwidgetcommand tooltip_callvote title \"\""
	
	popup_width "MENU" 310
    clicksound sound/misc/menu/click.wav
	cvarvisibility coop_ui_vt 5 ==
}
//end of new airaccellerate option [b607]

end.
