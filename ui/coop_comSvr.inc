////////////////////////////////////////////////////////////////////////////////
//RCON LABEL AND PASSWORD
////////////////////////////////////////////////////////////////////////////////
resource
Label
{
	title "Server Remote Console Password:"
	rect 12 30 360 20
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	fgcolor 1 1 1 1
	bgcolor 1 0 0 0
	cvarvisibility "coop_comL" "30"
}

resource
Field
{
	linkcvar "rconPassword"
	maxcharacters   64
	rect 12 50 360 24
	fgcolor .7 .9 .8 1
	bgcolor 0.22 0.25 0.35 0.5
	borderstyle "INDENT_BORDER"
	//borderwidth "4"
	bordercolor 0 0 0 1
	horizontaljustify left
	verticaljustify top
	cvarvisibility "coop_comL" "30"
}

////////////////////////////////////////////////////////////////////////////////
//RCON BUTTONS
////////////////////////////////////////////////////////////////////////////////

resource
Button
{
	title "Restart Level"
	rect 12 90 128 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	shader textures/xxx/coopLcars023.tga
	hovershader textures/xxx/coopLcars017.tga
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Restarts the current Map\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	cvarvisibility "coop_comL" "30"
	stuffcommand "rcon restart"
}

resource
Button
{
	title "Status"
	rect 200 90 128 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	shader textures/xxx/coopLcars015.tga
	hovershader textures/xxx/coopLcars017.tga
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Prints server status into Console\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	cvarvisibility "coop_comL" "30"
	stuffcommand "rcon status"
}

resource
Button
{
	title "Console Commands List"
	rect 12 130 320 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/lcars_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	cvarvisibility "coop_comL" "30"
	stuffcommand "set coop_comL 31"
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Shows a list of console commands\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""
	
	shader textures/xxx/coopLcars012.tga
	hovershader textures/xxx/coopLcars016.tga
}

resource
Button
{
	title "United Server CFG Collection"
	rect 12 150 320 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/lcars_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	cvarvisibility "coop_comL" "30"
	stuffcommand "set coop_comL 32"
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Shows a list of console commands\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""
	
	shader textures/xxx/coopLcars012.tga
	hovershader textures/xxx/coopLcars016.tga
}

////////////////////////////////////////////////////////////////////////////////
//RCON CONSOLE COMMANDS LIST
////////////////////////////////////////////////////////////////////////////////
resource
Label
{
	title "rcon ^5sv_maxSpeed 350 ^6- Standard: 300"
	rect 12 30 360 20
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	horizontaljustify left
	fgcolor 1 1 1 1
	bgcolor 1 1 1 0.2
	hoverbgcolor 1 1 1 0.4
	cvarvisibility "coop_comL" "31"
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Sets the Maximum Movement Speed\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""
}

resource
Label
{
	title "rcon ^5sv_gravity 400 ^6- Standard: 800"
	rect 12 55 360 20
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	horizontaljustify left
	fgcolor 1 1 1 1
	bgcolor 1 1 1 0.2
	hoverbgcolor 1 1 1 0.4
	cvarvisibility "coop_comL" "31"
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Sets the Gravity\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""
}

resource
Label
{
	title "rcon ^5mp_damageMultiplier 1.5 ^6- Standard: 1"
	rect 12 80 360 20
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	horizontaljustify left
	fgcolor 1 1 1 1
	bgcolor 1 1 1 0.2
	hoverbgcolor 1 1 1 0.4
	cvarvisibility "coop_comL" "31"
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Sets the Multiplier for Damage\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""
}

resource
Label
{
	title "rcon ^5mp_timeLimit 10 ^6- Standard: 20"
	rect 12 105 360 20
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	horizontaljustify left
	fgcolor 1 1 1 1
	bgcolor 1 1 1 0.2
	hoverbgcolor 1 1 1 0.4
	cvarvisibility "coop_comL" "31"
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Sets Timeout for each Match\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""
}

resource
Label
{
	title "rcon ^5mp_pointLimit 20 ^6- Standard: 0"
	rect 12 130 360 20
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	horizontaljustify left
	fgcolor 1 1 1 1
	bgcolor 1 1 1 0.2
	hoverbgcolor 1 1 1 0.4
	cvarvisibility "coop_comL" "31"
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Sets Point Limit to win Match\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""
}

resource
Button
{
	title "$$Back$$"
	rect 12 202 128 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/lcars_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	shader textures/xxx/coopLcars013.tga
	hovershader textures/xxx/coopLcars017.tga
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"$$Back$$\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	cvarvisibility "coop_comL" "31"
	stuffcommand "set coop_comL 30"
}

////////////////////////////////////////////////////////////////////////////////
//CFG EXEC COMMAND PAGE - HZM SERVER CFG MOD
////////////////////////////////////////////////////////////////////////////////
resource
Button
{
	title "Sniper Only"
	rect 12 30 128 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	shader textures/xxx/coopLcars023.tga
	hovershader textures/xxx/coopLcars017.tga
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Sets Snipers Only\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	cvarvisibility "coop_comL" "32"
	stuffcommand "rcon exec sniper;popmenu coop_com"
}

resource
Button
{
	title "All Weapons"
	rect 200 30 128 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	shader textures/xxx/coopLcars023.tga
	hovershader textures/xxx/coopLcars017.tga
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Restores all Weapons\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	cvarvisibility "coop_comL" "32"
	stuffcommand "rcon exec allweapons;popmenu coop_com"
}

resource
Button
{
	title "Action Hero"
	rect 12 50 128 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	shader textures/xxx/coopLcars023.tga
	hovershader textures/xxx/coopLcars017.tga
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Sets Actionhero\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	cvarvisibility "coop_comL" "32"
	stuffcommand "rcon exec actionhero;popmenu coop_com"
}

resource
Button
{
	title "Reset Hero"
	rect 200 50 128 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	shader textures/xxx/coopLcars023.tga
	hovershader textures/xxx/coopLcars017.tga
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Resets Actionhero\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	cvarvisibility "coop_comL" "32"
	stuffcommand "rcon exec resetactionhero;popmenu coop_com"
}

resource
Button
{
	title "Ellimination"
	rect 12 70 128 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	shader textures/xxx/coopLcars023.tga
	hovershader textures/xxx/coopLcars017.tga
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Sets Gametype Elimination\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	cvarvisibility "coop_comL" "32"
	stuffcommand "rcon exec elimination;popmenu coop_com"
}

resource
Button
{
	title "Reset Ellim."
	rect 200 70 128 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	shader textures/xxx/coopLcars023.tga
	hovershader textures/xxx/coopLcars017.tga
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Resets Gametype Elimination\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	cvarvisibility "coop_comL" "32"
	stuffcommand "rcon exec resetelimination;popmenu coop_com"
}

resource
Button
{
	title "Controlpoints"
	rect 12 90 128 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	shader textures/xxx/coopLcars023.tga
	hovershader textures/xxx/coopLcars017.tga
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Sets Gametype Controlpoints\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	cvarvisibility "coop_comL" "32"
	stuffcommand "rcon exec controlpoints;popmenu coop_com"
}

resource
Button
{
	title "Reset Controlp."
	rect 200 90 128 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	shader textures/xxx/coopLcars023.tga
	hovershader textures/xxx/coopLcars017.tga
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Resets Gametype Controlpoints\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	cvarvisibility "coop_comL" "32"
	stuffcommand "rcon exec resetcontrolpoints;popmenu coop_com"
}

resource
Button
{
	title "Holomatch"
	rect 12 110 128 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	shader textures/xxx/coopLcars023.tga
	hovershader textures/xxx/coopLcars017.tga
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Sets Gametype Holomatch/Deathmatch\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	cvarvisibility "coop_comL" "32"
	stuffcommand "rcon exec holomatch;popmenu coop_com"
}

resource
Button
{
	title "TDM"
	rect 200 110 128 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	shader textures/xxx/coopLcars023.tga
	hovershader textures/xxx/coopLcars017.tga
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Sets Gametype Team Deathmatch\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	cvarvisibility "coop_comL" "32"
	stuffcommand "rcon exec teamdeathmatch;popmenu coop_com"
}

resource
Button
{
	title "CTF"
	rect 12 130 128 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	shader textures/xxx/coopLcars023.tga
	hovershader textures/xxx/coopLcars017.tga
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Sets Gametype Capture the Flag\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	cvarvisibility "coop_comL" "32"
	stuffcommand "rcon exec capturetheflag;popmenu coop_com"
}

resource
Button
{
	title "One Flag"
	rect 200 130 128 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	shader textures/xxx/coopLcars023.tga
	hovershader textures/xxx/coopLcars017.tga
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Sets Gametype One Flag\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	cvarvisibility "coop_comL" "32"
	stuffcommand "rcon exec oneflag;popmenu coop_com"
}

resource
Button
{
	title "Specialties"
	rect 12 150 128 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	shader textures/xxx/coopLcars023.tga
	hovershader textures/xxx/coopLcars017.tga
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Sets Gametype Specialties\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	cvarvisibility "coop_comL" "32"
	stuffcommand "rcon exec specialties;popmenu coop_com"
}

resource
Button
{
	title "Reset Special."
	rect 200 150 128 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	shader textures/xxx/coopLcars023.tga
	hovershader textures/xxx/coopLcars017.tga
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Resets Gametype Specialties\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	cvarvisibility "coop_comL" "32"
	stuffcommand "rcon exec resetspecialties;popmenu coop_com"
}

resource
Button
{
	title "Low Gravity"
	rect 12 170 128 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	shader textures/xxx/coopLcars023.tga
	hovershader textures/xxx/coopLcars017.tga
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Sets Low Gravity\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	cvarvisibility "coop_comL" "32"
	stuffcommand "rcon exec lowgravity;popmenu coop_com"
}

resource
Button
{
	title "Reset Gravity"
	rect 200 170 128 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	shader textures/xxx/coopLcars023.tga
	hovershader textures/xxx/coopLcars017.tga
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Resets Gravity\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	cvarvisibility "coop_comL" "32"
	stuffcommand "rcon exec resetgravity;popmenu coop_com"
}

resource
Button
{
	title "$$Back$$"
	rect 12 202 128 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/lcars_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	shader textures/xxx/coopLcars013.tga
	hovershader textures/xxx/coopLcars017.tga
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"$$Back$$\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	cvarvisibility "coop_comL" "32"
	stuffcommand "set coop_comL 30"
}

resource
Button
{
	title "Info / Details"
	rect 200 202 128 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	shader textures/xxx/coopLcars013.tga
	hovershader textures/xxx/coopLcars017.tga
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"How these commands work...\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	cvarvisibility "coop_comL" "32"
	stuffcommand "set coop_comL 33"
}

////////////////////////////////////////////////////////////////////////////////
//CFG EXEC COMMAND PAGE - HZM SERVER CFG MOD - DESCRIPTION
////////////////////////////////////////////////////////////////////////////////
resource
Label
{
	title "Executes 'UNITED SERVER CONFIGS' CFG Files\nA collection of CFG Files the Server needs to have\nCheck Coop Mod /_tools_/ folder.\nThis does not work on a listen Server...\n\nThe Remote Server needs to have unitedServerCfgs.pk3 installed."
	rect 12 30 360 120
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	fgcolor 1 1 1 1
	bgcolor 1 0 0 0
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""
	
	cvarvisibility "coop_comL" "33"
}

resource
Button
{
	title "$$Back$$"
	rect 12 202 128 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/lcars_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	shader textures/xxx/coopLcars013.tga
	hovershader textures/xxx/coopLcars017.tga
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"$$Back$$\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	cvarvisibility "coop_comL" "33"
	stuffcommand "set coop_comL 32"
}

////////////////////////////////////////////////////////////////////////////////
//COMMAND SCROLL
////////////////////////////////////////////////////////////////////////////////
resource
Button
{
	//PREVIOUS
	rect 18 230 24 40
	borderstyle "NONE"
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	hovercommand "globalwidgetcommand coop_comTooltip title \"Previous Page...\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""
	
	cvarvisibility "coop_comL" "31"
	stuffcommand "set coop_comL 30"
}

resource
Button
{
	//PREVIOUS
	rect 18 230 24 40
	borderstyle "NONE"
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	hovercommand "globalwidgetcommand coop_comTooltip title \"Previous Page...\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""
	
	cvarvisibility "coop_comL" "32"
	stuffcommand "set coop_comL 31"
}

resource
Button
{
	//NEXT
	rect 44 230 24 40
	borderstyle "NONE"
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	hovercommand "globalwidgetcommand coop_comTooltip title \"Next Page...\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""
	
	cvarvisibility "coop_comL" "30"
	stuffcommand "set coop_comL 31"
}

resource
Button
{
	//NEXT
	rect 44 230 24 40
	borderstyle "NONE"
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	hovercommand "globalwidgetcommand coop_comTooltip title \"Next Page...\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""
	
	cvarvisibility "coop_comL" "31"
	stuffcommand "set coop_comL 32"
}

end.