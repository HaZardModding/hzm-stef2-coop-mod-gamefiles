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
	rect 200 94 128 18
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
	title "!kill"
	rect 200 118 128 18
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
	rect 200 143 128 18
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
	title "reboot Server"
	rect 200 170 128 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	shader textures/xxx/coopLcars023.tga
	hovershader textures/xxx/coopLcars017.tga
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Requests Server Reboot\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	cvarvisibility "coop_comL" "10"
	stuffcommand "callvote coop_quit"
}

resource
Button
{
	title "3rd Person"
	rect 12 110 128 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	shader textures/xxx/coopLcars015.tga
	hovershader textures/xxx/coopLcars017.tga
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Toggles 3rd Person viewmode\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	cvarvisibility "coop_comL" "10"
	stuffcommand "toggle cg_3rd_person"
}

resource
Button
{
	title "!notransport"
	rect 12 130 128 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	shader textures/xxx/coopLcars015.tga
	hovershader textures/xxx/coopLcars017.tga
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Activates a Transport Inhibitor\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	cvarvisibility "coop_comL" "10"
	stuffcommand "!notransport"
}

resource
Button
{
	title "!transferlive"
	rect 12 150 128 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	shader textures/xxx/coopLcars019.tga
	hovershader textures/xxx/coopLcars017.tga
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Transfers one of your lives to a dead player\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	cvarvisibility "coop_comL" "10"
	stuffcommand "!transferlive"
}

resource
Button
{
	title "!ability"
	rect 12 170 128 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	shader textures/xxx/coopLcars015.tga
	hovershader textures/xxx/coopLcars017.tga
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Activate Coop Class Special ability\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	cvarvisibility "coop_comL" "10"
	stuffcommand "!ability"
}

resource
Button
{
	title "$$c#097$$"
	rect 12 202 320 18
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
	stuffcommand "!levelend;popmenu coop_com"
}


resource
Button
{
	title "!reboot"
	rect 200 50 128 18
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
	stuffcommand "!reboot;popmenu coop_com"
}

resource
Button
{
	title "!flushtikis"
	rect 200 90 128 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	shader textures/xxx/coopLcars019.tga
	hovershader textures/xxx/coopLcars017.tga
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Clears server Models cache right now\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	cvarvisibility "coop_comL" "11"
	stuffcommand "!flushtikis"
}

resource
Label
{
	title "Admin Options - Require Login on the Server!\n^3 !thread starts fuc, with you as activator..."
	rect 6 155 360 64
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
	title "!login"
	rect 12 130 128 18
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

	cvarvisibility "coop_comL" "11"
	stuffcommand "!login;seta coop_comL 19"
}

resource
Button
{
	title "!logout"
	rect 200 130 128 18
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

	cvarvisibility "coop_comL" "11"
	stuffcommand "!logout"
}

resource
Button
{
	title "$$Back$$"
	rect 12 202 320 18
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
//CODEPANNEL LOGIN - ADMIN !LOGIN
////////////////////////////////////////////////////////////////////////////////
resource
Button
{
	title "1"
	rect 12 30 32 32
	borderstyle "NONE"
	font serpentinemedium-14
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	shader textures/xxx/coopLcars021.tga
	hovershader textures/xxx/coopLcars017.tga
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Enter Number\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	cvarvisibility "coop_comL" "19"
	stuffcommand "coopinput 1"
}

resource
Button
{
	title "2"
	rect 54 30 32 32
	borderstyle "NONE"
	font serpentinemedium-14
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	shader textures/xxx/coopLcars021.tga
	hovershader textures/xxx/coopLcars017.tga
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Enter Number\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	cvarvisibility "coop_comL" "19"
	stuffcommand "coopinput 2"
}

resource
Button
{
	title "3"
	rect 96 30 32 32
	borderstyle "NONE"
	font serpentinemedium-14
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	shader textures/xxx/coopLcars021.tga
	hovershader textures/xxx/coopLcars017.tga
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Enter Number\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	cvarvisibility "coop_comL" "19"
	stuffcommand "coopinput 3"
}

resource
Button
{
	title "4"
	rect 138 30 32 32
	borderstyle "NONE"
	font serpentinemedium-14
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	shader textures/xxx/coopLcars021.tga
	hovershader textures/xxx/coopLcars017.tga
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Enter Number\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	cvarvisibility "coop_comL" "19"
	stuffcommand "coopinput 4"
}

resource
Button
{
	title "5"
	rect 180 30 32 32
	borderstyle "NONE"
	font serpentinemedium-14
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	shader textures/xxx/coopLcars021.tga
	hovershader textures/xxx/coopLcars017.tga
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Enter Number\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	cvarvisibility "coop_comL" "19"
	stuffcommand "coopinput 5"
}

resource
Button
{
	title "6"
	rect 12 72 32 32
	borderstyle "NONE"
	font serpentinemedium-14
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	shader textures/xxx/coopLcars021.tga
	hovershader textures/xxx/coopLcars017.tga
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Enter Number\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	cvarvisibility "coop_comL" "19"
	stuffcommand "coopinput 6"
}

resource
Button
{
	title "7"
	rect 54 72 32 32
	borderstyle "NONE"
	font serpentinemedium-14
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	shader textures/xxx/coopLcars021.tga
	hovershader textures/xxx/coopLcars017.tga
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Enter Number\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	cvarvisibility "coop_comL" "19"
	stuffcommand "coopinput 7"
}

resource
Button
{
	title "8"
	rect 96 72 32 32
	borderstyle "NONE"
	font serpentinemedium-14
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	shader textures/xxx/coopLcars021.tga
	hovershader textures/xxx/coopLcars017.tga
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Enter Number\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	cvarvisibility "coop_comL" "19"
	stuffcommand "coopinput 8"
}

resource
Button
{
	title "9"
	rect 138 72 32 32
	borderstyle "NONE"
	font serpentinemedium-14
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	shader textures/xxx/coopLcars021.tga
	hovershader textures/xxx/coopLcars017.tga
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Enter Number\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	cvarvisibility "coop_comL" "19"
	stuffcommand "coopinput 9"
}

resource
Button
{
	title "0"
	rect 180 72 32 32
	borderstyle "NONE"
	font serpentinemedium-14
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	shader textures/xxx/coopLcars021.tga
	hovershader textures/xxx/coopLcars017.tga
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Enter Number\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	cvarvisibility "coop_comL" "19"
	stuffcommand "coopinput 0"
}

resource
Button
{
	title "Reset"
	rect 222 30 128 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	shader textures/xxx/coopLcars021.tga
	hovershader textures/xxx/coopLcars017.tga
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Reset\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	cvarvisibility "coop_comL" "19"
	stuffcommand "coopinput clear"
}

resource
Button
{
	title "$$Back$$"
	rect 222 72 128 18
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

	cvarvisibility "coop_comL" "19"
	stuffcommand "set coop_comL 11"
}

resource
Label
{
	name "coop_comCmdLoginCode"
	rect 12 114 360 32
	borderstyle "NONE"
	font serpentinemedium-14
	verticaljustify top
	fgcolor 1 1 1 1
	bgcolor 1 0 0 0
	cvarvisibility "coop_comL" "19"
}

resource
Label
{
	name "coop_comCmdLoginMsg"
	rect 12 148 360 64
	borderstyle "NONE"
	font serpentinemedium-14
	verticaljustify top
	fgcolor 1 1 1 1
	bgcolor 0 1 0 0
	cvarvisibility "coop_comL" "19"
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