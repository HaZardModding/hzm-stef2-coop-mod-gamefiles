////////////////////////////////////////////////////////////////////////////////
//COMMAND TEXT LABELS
////////////////////////////////////////////////////////////////////////////////
resource
Label
{
	title "No DATA retrived from server yet."
	name "coop_comCmdI0"
	rect 6 30 360 166
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	fgcolor 1 1 1 1
	bgcolor 1 0 0 0
	cvarvisibility "coop_comL" "12"
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

	cvarvisibility "coop_comL" "12"
	stuffcommand "set coop_comL 10"
}

resource
Button
{
	title "$$GetList$$"
	rect 200 202 128 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/lcars_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	shader textures/xxx/coopLcars021.tga
	hovershader textures/xxx/coopLcars017.tga
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"$$GetList$$\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	cvarvisibility "coop_comL" "12"
	stuffcommand "globalwidgetcommand coop_comCmdI0 labeltext INFO:^Please^wait^a^moment,^querying^DATA^from^Server^has^a^cooldown!;!info"
}

////////////////////////////////////////////////////////////////////////////////
//COMMAND BUTTONS
////////////////////////////////////////////////////////////////////////////////
resource
Button
{
	title "!info"
	rect 12 30 128 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	shader textures/xxx/coopLcars015.tga
	hovershader textures/xxx/coopLcars017.tga
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Shows you your Info\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	cvarvisibility "coop_comL" "10"
	stuffcommand "!info;set coop_comL 12"
}

resource
Button
{
	title "!follow"
	rect 200 30 128 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	shader textures/xxx/coopLcars013.tga
	hovershader textures/xxx/coopLcars017.tga
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Shows you as green dot on Radar\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	cvarvisibility "coop_comL" "10"
	stuffcommand "!follow"
}
resource
Button
{
	title "!stuck"
	rect 200 50 128 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	shader textures/xxx/coopLcars019.tga
	hovershader textures/xxx/coopLcars017.tga
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Moves you to Spawn location\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	cvarvisibility "coop_comL" "10"
	stuffcommand "!stuck"
}

resource
Button
{
	title "!origin"
	rect 12 50 128 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	shader textures/xxx/coopLcars015.tga
	hovershader textures/xxx/coopLcars017.tga
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Displays your and targeted origin\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	cvarvisibility "coop_comL" "10"
	stuffcommand "!origin"
}

resource
Button
{
	title "!skill"
	rect 12 70 128 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	shader textures/xxx/coopLcars015.tga
	hovershader textures/xxx/coopLcars017.tga
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Prints current Game Difficulty Level\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	cvarvisibility "coop_comL" "10"
	stuffcommand "!skill"
}

resource
Button
{
	title "!drop"
	rect 200 70 128 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	shader textures/xxx/coopLcars019.tga
	hovershader textures/xxx/coopLcars017.tga
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Drops your current weapon if possible\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	cvarvisibility "coop_comL" "10"
	stuffcommand "!drop"
}

resource
Button
{
	title "!kickbots"
	rect 200 97 128 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	shader textures/xxx/coopLcars029.tga
	hovershader textures/xxx/coopLcars017.tga
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Kicks all BOT players\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	cvarvisibility "coop_comL" "10"
	stuffcommand "!kickbots"
}

resource
Button
{
	title "!block"
	rect 12 90 128 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	shader textures/xxx/coopLcars019.tga
	hovershader textures/xxx/coopLcars017.tga
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Use to aim on a Player that is blocking the way\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	cvarvisibility "coop_comL" "10"
	stuffcommand "!block"
}

resource
Button
{
	title "!login"
	rect 12 110 128 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	shader textures/xxx/coopLcars021.tga
	hovershader textures/xxx/coopLcars017.tga
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Login in to the Server\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	cvarvisibility "coop_comL" "10"
	stuffcommand "!login"
}

resource
Button
{
	title "!logout"
	rect 12 130 128 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	shader textures/xxx/coopLcars021.tga
	hovershader textures/xxx/coopLcars017.tga
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Logs you out\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	cvarvisibility "coop_comL" "10"
	stuffcommand "!logout"
}

resource
Button
{
	title "!kill"
	rect 200 124 128 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	shader textures/xxx/coopLcars019.tga
	hovershader textures/xxx/coopLcars017.tga
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Commit Suicide\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	cvarvisibility "coop_comL" "10"
	stuffcommand "!kill"
}

resource
Button
{
	title "reconnect"
	rect 200 150 128 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	shader textures/xxx/coopLcars023.tga
	hovershader textures/xxx/coopLcars017.tga
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Reconnects you to Server\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	cvarvisibility "coop_comL" "10"
	stuffcommand "reconnect"
}

resource
Button
{
	title "3rd Person"
	rect 12 150 128 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	shader textures/xxx/coopLcars015.tga
	hovershader textures/xxx/coopLcars017.tga
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	cvarvisibility "coop_comL" "10"
	stuffcommand "toggle cg_3rd_person"
}

resource
Button
{
	title "$$c#097$$"
	rect 12 190 320 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/lcars_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	cvarvisibility "coop_comL" "10"
	stuffcommand "set coop_comL 11"
	shader textures/xxx/coopLcars020.tga
	hovershader textures/xxx/coopLcars016.tga
}
////////////////////////////////////////////////////////////////////////////////
//COMMAND BUTTONS -  A D M I N
////////////////////////////////////////////////////////////////////////////////
resource
Button
{
	title "!noclip"
	rect 12 30 128 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	shader textures/xxx/coopLcars019.tga
	hovershader textures/xxx/coopLcars017.tga
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Turns no clipping on/off\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	cvarvisibility "coop_comL" "11"
	stuffcommand "!noclip"
}

resource
Button
{
	title "!showspawn"
	rect 12 50 128 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	shader textures/xxx/coopLcars015.tga
	hovershader textures/xxx/coopLcars017.tga
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Shows playerspawnspots\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	cvarvisibility "coop_comL" "11"
	stuffcommand "!showspawn"
}

resource
Button
{
	title "!testspawn"
	rect 12 70 128 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	shader textures/xxx/coopLcars019.tga
	hovershader textures/xxx/coopLcars017.tga
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Moves you to playerspawnspots for testing\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	cvarvisibility "coop_comL" "11"
	stuffcommand "!testspawn"
}

resource
Button
{
	title "!targetnames"
	rect 12 90 128 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	shader textures/xxx/coopLcars015.tga
	hovershader textures/xxx/coopLcars017.tga
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Shows targeted entity Targetnames\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	cvarvisibility "coop_comL" "11"
	stuffcommand "!targetnames"
}

resource
Button
{
	title "!levelend"
	rect 200 30 128 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	shader textures/xxx/coopLcars023.tga
	hovershader textures/xxx/coopLcars017.tga
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Runs the level end script function\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	cvarvisibility "coop_comL" "11"
	stuffcommand "!levelend"
}

resource
Button
{
	title "!reboot"
	rect 200 70 128 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	shader textures/xxx/coopLcars023.tga
	hovershader textures/xxx/coopLcars017.tga
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Reboots the Server right now\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	cvarvisibility "coop_comL" "11"
	stuffcommand "!reboot"
}

resource
Label
{
	title "Admin Options - Require Login on the Server!\n^3 !thread starts fuc, with you as activator..."
	rect 6 140 360 64
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	fgcolor 1 1 1 0.60
	bgcolor 1 0 0 0
	cvarvisibility "coop_comL" "11"
}

resource
Button
{
	title "$$Back$$"
	rect 12 190 320 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/lcars_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	cvarvisibility "coop_comL" "11"
	stuffcommand "set coop_comL 10"
	shader textures/xxx/coopLcars012.tga
	hovershader textures/xxx/coopLcars016.tga
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
	
	cvarvisibility "coop_comL" "11"
	stuffcommand "set coop_comL 10"
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
	
	cvarvisibility "coop_comL" "12"
	stuffcommand "set coop_comL 11"
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
	
	cvarvisibility "coop_comL" "10"
	stuffcommand "set coop_comL 11"
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
	
	cvarvisibility "coop_comL" "11"
	stuffcommand "set coop_comL 12"
}

end.