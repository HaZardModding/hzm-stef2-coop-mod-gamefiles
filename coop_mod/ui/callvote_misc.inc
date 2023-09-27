////////////////////////////////////////////////////////////// Current map options
////////////////////////////////////////////////////////////// Current map options
////////////////////////////////////////////////////////////// Current map options
////////////////////////////////////////////////////////////// Current map options

resource 
Label
{
	cvarvisibility coop_ui_vt 4 ==
	
	title "$$c#008$$"
	name "coopOptionsCurrentMapTitle"
	rect		274 89 330 24
	fgcolor 0 1 1 1
	bgcolor 0.12 0.15 0.25 1.00
	
	borderstyle "3D_BORDER"
	
	horizontaljustify left
	verticaljustify top
	font 	serpentinemedium-10
	
	hovercommand "globalwidgetcommand tooltip_callvote title \"$$c#008$$\""
    hoverexitcommand "globalwidgetcommand tooltip_callvote title \"\""
}


//[b607] chrissstrahl changed so it can be used on all coop/misc voting options
//this is the background for the maps to vote, we are gonna use only one background
//this saves us alot of work, we will also not adjust its length to each vote option
//we rather want it to be suitable for up to 13 maps, no this is not a good luck charm
//this is just the number of maps that fit in there nicley
resource 
Label
{
	//[b607] chrissstrahl changed so it can be used on all coop/misc voting options
	cvarvisibility coop_ui_vt 4 >=
		
	name "coopMapsListBg"
	rect	274 113 330 275
	fgcolor 1.0 1.0 1.0 1.000
	bgcolor 0 0 0 0.60
	
	borderstyle "BORDER_OUTLINE"
	borderwidth 1
	bordercolor 0.12 0.15 0.25 1.00
	
	horizontaljustify left
	verticaljustify center
	font 	serpentinemedium-10
}

// resource 
// Label
// {
	// cvarvisibility coop_ui_vt 4 ==
		
	// name "coopOptionsCurrentMapBg"
	// rect	274 113 330 85
	// fgcolor 1.0 1.0 1.0 1.000
	// bgcolor 0 0 0 0.60
	
	// borderstyle "BORDER_OUTLINE"
	// borderwidth 1
	// bordercolor 0.12 0.15 0.25 1.00
	
	// horizontaljustify left
	// verticaljustify center
	// font 	serpentinemedium-10
// }

//restart
resource
Button
{
	cvarvisibility coop_ui_vt 4 ==
	title "$$c#012$$"
	name 	"restart_map"
	rect	275 114 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	verticaljustify top
	verticaljustify top

	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote restart\n"
	hovercommand "globalwidgetcommand tooltip_callvote title \"$$c#013$$\""
    hoverexitcommand "globalwidgetcommand tooltip_callvote title \"\""
}
//skip cinematic
resource
Button
{
	cvarvisibility coop_ui_vt 4 ==
	title "$$c#018$$"
	name 	"skip_cinematic"
	rect	275 136 328 20
	font serpentinemedium-10
	fgcolor 		1.000 1.000 1.000 0.800
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	verticaljustify top
	verticaljustify top
	
	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote skipcinematic\n"
    hovercommand "globalwidgetcommand tooltip_callvote title \"$$c#019$$\""
    hoverexitcommand "globalwidgetcommand tooltip_callvote title \"\""
}

////////////////////////////////////////////////////////////// COOPMAP OPTIONS
////////////////////////////////////////////////////////////// COOPMAP OPTIONS
//next map
resource
Button
{
	cvarvisibility coop_ui_vt 4 ==
	title "$$c#014$$"
	name 	"next_map"
	rect	441 168 162 20
	
	font serpentinemedium-10
	fgcolor 		0.000 1.000 1.000 1.000
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	verticaljustify top
	verticaljustify top
	
	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote coop_next\n"
    hovercommand "globalwidgetcommand tooltip_callvote title \"$$c#015$$\""
    hoverexitcommand "globalwidgetcommand tooltip_callvote title \"\""
}
//prevoiuse map
resource
Button
{
	cvarvisibility coop_ui_vt 4 ==
	title "$$c#016$$"
	name 	"previous_map"
	rect	275 168 162 20
	
	font serpentinemedium-10
	fgcolor 		0.000 1.000 1.000 1.000
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	verticaljustify top
	verticaljustify top
	
	clicksound sound/misc/menu/click.wav
 
	stuffcommand "callvote coop_prev\n"
    hovercommand "globalwidgetcommand tooltip_callvote title \"$$c#017$$\""
    hoverexitcommand "globalwidgetcommand tooltip_callvote title \"\""
}

//coop gameplay Options
resource
Button
{
	cvarvisibility coop_ui_vt 4 ==
	title "$$c#020$$"
	name 	"coopOptionsGameplayBtn"
	rect	275 190 328 20
	font serpentinemedium-10
	fgcolor 		0.000 1.000 1.000 1.000
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	verticaljustify top
	verticaljustify top
	
	clicksound sound/misc/menu/click.wav
 
	stuffcommand "seta coop_ui_vt 5;set coop_ui_sm 0\n"
    hovercommand "globalwidgetcommand tooltip_callvote title \"$$c#009$$\""
    hoverexitcommand "globalwidgetcommand tooltip_callvote title \"\""
}

//coop Training and Secret Maps
resource
Button
{
	cvarvisibility coop_ui_vt 4 ==
	title "$$c#035$$"
	name 	"coopOptionsLvlTrainingBtn"
	rect	275 222 328 20
	font serpentinemedium-10
	fgcolor 		0.953 0.667 0.271 1.000
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	verticaljustify top
	verticaljustify top
	
	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set coop_ui_vt 6;set coop_ui_sm -1"
    hovercommand "globalwidgetcommand tooltip_callvote title \"$$c#112$$\""
    hoverexitcommand "globalwidgetcommand tooltip_callvote title \"\""
}
//coop Singleplayer Campaign
resource
Button
{
	cvarvisibility coop_ui_vt 4 ==
	title "$$c#036$$"
	name 	"coopOptionsLvlCampaignBtn"
	rect	275 244 328 20
	font serpentinemedium-10
	fgcolor 		0.953 0.667 0.271 1.000
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	verticaljustify top
	verticaljustify top
	
	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set coop_ui_vt 7;set coop_ui_smn $$mission-m1$$;set coop_ui_sm 1"
    hovercommand "globalwidgetcommand tooltip_callvote title \"$$c#112$$\""
    hoverexitcommand "globalwidgetcommand tooltip_callvote title \"\""
}
//coop custom maps
resource
Button
{
	cvarvisibility coop_ui_vt 4 ==
	title "$$c#037$$"
	name 	"coopOptionsLvlCommunityBtn"
	rect	275 266 328 20
	font serpentinemedium-10
	fgcolor 		0.953 0.667 0.271 1.000
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	verticaljustify top
	verticaljustify top
	
	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set coop_ui_vt 13;set coop_ui_smn Custom_Maps;set coop_ui_sm 13"
    hovercommand "globalwidgetcommand tooltip_callvote title \"$$c#112$$\""
    hoverexitcommand "globalwidgetcommand tooltip_callvote title \"\""
}
//coop a gate two birds mod
resource
Button
{
	cvarvisibility coop_ui_vt 4 ==
	title "$$c#038$$"
	name 	"coopOptionsLvlGbsBtn"
	rect	275 288 328 20
	font serpentinemedium-10
	fgcolor 		0.953 0.667 0.271 1.000
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	verticaljustify top
	verticaljustify top
	
	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set coop_ui_vt 14;set coop_ui_smn Custom_Maps;set coop_ui_sm 14"
    hovercommand "globalwidgetcommand tooltip_callvote title \"$$c#112$$\""
    hoverexitcommand "globalwidgetcommand tooltip_callvote title \"\""
}
//coop return of the emptry crow
resource
Button
{
	cvarvisibility coop_ui_vt 4 ==
	title "$$c#039$$"
	name 	"coopOptionsLvlRotecBtn"
	rect	275 310 328 20
	font serpentinemedium-10
	fgcolor 		0.953 0.667 0.271 1.000
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	verticaljustify top
	verticaljustify top
	
	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set coop_ui_vt 15;set coop_ui_smn Custom_Maps;set coop_ui_sm 15"
    hovercommand "globalwidgetcommand tooltip_callvote title \"$$c#112$$\""
    hoverexitcommand "globalwidgetcommand tooltip_callvote title \"\""
}
//coop Aftermath Mod
resource
Button
{
	cvarvisibility coop_ui_vt 4 ==
	title "$$c#040$$"
	name 	"coopOptionsLvlAftermathBtn"
	rect	275 332 328 20
	font serpentinemedium-10
	fgcolor 		0.953 0.667 0.271 1.000
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	verticaljustify top
	verticaljustify top
	
	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set coop_ui_vt 16;set coop_ui_smn Custom_Maps;set coop_ui_sm 16"
    hovercommand "globalwidgetcommand tooltip_callvote title \"$$c#112$$\""
    hoverexitcommand "globalwidgetcommand tooltip_callvote title \"\""
}
//coop Example and test maps
resource
Button
{
	cvarvisibility coop_ui_vt 4 ==
	title "$$c#041$$"
	name 	"coopOptionsLvlTestBtn"
	rect	275 354 328 20
	font serpentinemedium-10
	fgcolor 		0.953 0.667 0.271 1.000
	bgcolor 		0.12 0.15 0.25 0.7
	hoverbgcolor 	0.22 0.25 0.35 1.0
	
	verticaljustify top
	verticaljustify top
	
	clicksound sound/misc/menu/click.wav
 
	stuffcommand "set coop_ui_vt 20;set coop_ui_smn Test_Maps;set coop_ui_sm 13"
    hovercommand "globalwidgetcommand tooltip_callvote title \"$$c#112$$\""
    hoverexitcommand "globalwidgetcommand tooltip_callvote title \"\""
}

end.