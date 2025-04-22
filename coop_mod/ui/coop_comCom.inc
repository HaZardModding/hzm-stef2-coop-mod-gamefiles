////////////////////////////////////////////////////////////////////////////////
//COMMUNICATOR BUTTONS -  O R D E R S
////////////////////////////////////////////////////////////////////////////////
resource
Button
{
	title "$$c#067$$" //FOLLOW ME
	rect 12 30 320 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	cvarvisibility "coop_comL" "0"

	hovercommand "globalwidgetcommand coop_comTooltip title \"Communicate to Team\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	stuffcommand "!follow;say =\/\\= : Follow me! : =\/\\= : Folgen Sie mir!\ntogglemenu coop_com"
	shader textures/coop_mod/lcars/coopLcars012.tga
	hovershader textures/coop_mod/lcars/coopLcars016.tga
}

resource
Button
{
	title "$$c#066$$" //Cover me
	rect 12 50 320 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	cvarvisibility "coop_comL" "0"

	hovercommand "globalwidgetcommand coop_comTooltip title \"Communicate to Team\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	stuffcommand "say =\/\\= : Cover me! : =\/\\= : Geben Sie mir Deckung!\ntogglemenu coop_com"
	shader textures/coop_mod/lcars/coopLcars014.tga
	hovershader textures/coop_mod/lcars/coopLcars016.tga
}

resource
Button
{
	title "$$c#068$$" //take cover
	rect 12 70 320 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	cvarvisibility "coop_comL" "0"

	hovercommand "globalwidgetcommand coop_comTooltip title \"Communicate to Team\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	stuffcommand "say =\/\\= : Take cover! : =\/\\= : In Deckung!\ntogglemenu coop_com"
	shader textures/coop_mod/lcars/coopLcars012.tga
	hovershader textures/coop_mod/lcars/coopLcars016.tga
}

resource
Button
{
	title "$$c#065$$" //fall back
	rect 12 90 320 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	cvarvisibility "coop_comL" "0"
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Communicate to Team\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	stuffcommand "say =\/\\= : Fallback! : =\/\\= : Rueckzug!\ntogglemenu coop_com"
	shader textures/coop_mod/lcars/coopLcars014.tga
	hovershader textures/coop_mod/lcars/coopLcars016.tga
}

resource
Button
{
	title "$$c#070$$" //lead the way
	rect 12 110 320 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	cvarvisibility "coop_comL" "0"
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Communicate to Team\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	stuffcommand "say =\/\\= : Lead the way! : =\/\\= : Gehen Sie voran!\ntogglemenu coop_com"
	shader textures/coop_mod/lcars/coopLcars012.tga
	hovershader textures/coop_mod/lcars/coopLcars016.tga
}

resource
Button
{
	title "$$c#073$$" //take next objective
	rect 12 130 320 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	cvarvisibility "coop_comL" "0"
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Communicate to Team\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	stuffcommand "say =\/\\= : Take next Objective! : =\/\\= : Naechstes Ziel uebernehmen!\ntogglemenu coop_communicato"
	shader textures/coop_mod/lcars/coopLcars014.tga
	hovershader textures/coop_mod/lcars/coopLcars016.tga
}

resource
Button
{
	title "$$c#071$$" //meet with me
	rect 12 150 320 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	cvarvisibility "coop_comL" "0"
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Communicate to Team\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	stuffcommand "say =\/\\= : Meet with me! : =\/\\= : Stossen Sie zu mir!\ntogglemenu coop_com"
	shader textures/coop_mod/lcars/coopLcars012.tga
	hovershader textures/coop_mod/lcars/coopLcars016.tga
}

resource
Button
{
	title "$$c#072$$" //hold this position
	rect 12 170 320 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	cvarvisibility "coop_comL" "0"
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Communicate to Team\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	stuffcommand "say =\/\\= : Hold this position! : =\/\\= : Halten Sie diese Position!\ntogglemenu coop_com"
	shader textures/coop_mod/lcars/coopLcars014.tga
	hovershader textures/coop_mod/lcars/coopLcars016.tga
}

resource
Button
{
	title "$$c#085$$" //I need backup
	rect 12 190 320 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	cvarvisibility "coop_comL" "0"
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Communicate to Team\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	stuffcommand "say =\/\\= : I need backup!: =\/\\= : Ich brauche Unterstuetzung!\ntogglemenu coop_com"
	shader textures/coop_mod/lcars/coopLcars012.tga
	hovershader textures/coop_mod/lcars/coopLcars016.tga
}

////////////////////////////////////////////////////////////////////////////////
//COMMUNICATOR BUTTONS -  O R D E R S
////////////////////////////////////////////////////////////////////////////////
resource
Button
{
	title "$$c#076$$" //positive
	rect 12 30 320 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	cvarvisibility "coop_comL" "1"

	hovercommand "globalwidgetcommand coop_comTooltip title \"Communicate to Team\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	stuffcommand "say =\/\\= : Positive... : =\/\\= : Positiv...\ntogglemenu coop_com"
	shader textures/coop_mod/lcars/coopLcars012.tga
	hovershader textures/coop_mod/lcars/coopLcars016.tga
}

resource
Button
{
	title "$$c#074$$" //negative
	rect 12 50 320 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	cvarvisibility "coop_comL" "1"

	hovercommand "globalwidgetcommand coop_comTooltip title \"Communicate to Team\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	stuffcommand "say =\/\\= : Negative... : =\/\\= : Negativ...\ntogglemenu coop_com"
	shader textures/coop_mod/lcars/coopLcars014.tga
	hovershader textures/coop_mod/lcars/coopLcars016.tga
}

resource
Button
{
	title "$$c#078$$" //following you
	rect 12 70 320 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	cvarvisibility "coop_comL" "1"

	hovercommand "globalwidgetcommand coop_comTooltip title \"Communicate to Team\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	stuffcommand "say =\/\\= : Following you... : =\/\\= : Ich folge Ihnen...\ntogglemenu coop_com"
	shader textures/coop_mod/lcars/coopLcars012.tga
	hovershader textures/coop_mod/lcars/coopLcars016.tga
}

resource
Button
{
	title "$$c#077$$" //covering you
	rect 12 90 320 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	cvarvisibility "coop_comL" "1"
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Communicate to Team\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	stuffcommand "say =\/\\= : Covering you... : =\/\\= : Ich gebe Deckung...\ntogglemenu coop_com"
	shader textures/coop_mod/lcars/coopLcars014.tga
	hovershader textures/coop_mod/lcars/coopLcars016.tga
}

resource
Button
{
	title "$$c#079$$" //retreating (taking cover)
	rect 12 110 320 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	cvarvisibility "coop_comL" "1"
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Communicate to Team\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	stuffcommand "say =\/\\= : I am retreating... : =\/\\= : Ich ziehe mich zurueck...\ntogglemenu coop_com"
	shader textures/coop_mod/lcars/coopLcars012.tga
	hovershader textures/coop_mod/lcars/coopLcars016.tga
}

resource
Button
{
	title "$$c#081$$" //leading the way
	rect 12 130 320 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	cvarvisibility "coop_comL" "1"
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Communicate to Team\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	stuffcommand "say =\/\\= : Leading the way... : =\/\\= : Ich gehe voran...\ntogglemenu coop_com"
	shader textures/coop_mod/lcars/coopLcars014.tga
	hovershader textures/coop_mod/lcars/coopLcars016.tga
}

resource
Button
{
	title "$$c#082$$" //taking next objective
	rect 12 150 320 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	cvarvisibility "coop_comL" "1"
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Communicate to Team\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	stuffcommand "say =\/\\= : I take the next Objective... : =\/\\= : Ich erledige naechstes Missionsziel...\ntogglemenu coop_com"
	shader textures/coop_mod/lcars/coopLcars012.tga
	hovershader textures/coop_mod/lcars/coopLcars016.tga
}

resource
Button
{
	title "$$c#086$$" //I am waiting here
	rect 12 170 320 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	cvarvisibility "coop_comL" "1"
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Communicate to Team\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	stuffcommand "say =\/\\= : I am waiting here: =\/\\= : Ich warte hier\n togglemenu coop_com"
	shader textures/coop_mod/lcars/coopLcars014.tga
	hovershader textures/coop_mod/lcars/coopLcars016.tga
}

resource
Button
{
	title "$$c#090$$" //
	rect 12 190 320 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	cvarvisibility "coop_comL" "1"
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Communicate to Team\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	stuffcommand "say =\/\\= : I need a Medic! : =\/\\= : Ich brauche ein Doctor!\ntogglemenu coop_com"
	shader textures/coop_mod/lcars/coopLcars012.tga
	hovershader textures/coop_mod/lcars/coopLcars016.tga
}

resource
Button
{
	title "$$c#089$$" //
	rect 12 210 320 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	cvarvisibility "coop_comL" "1"
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Communicate to Team\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	stuffcommand "say =\/\\= : I need a Technican! : =\/\\= : Ich brauche ein Techniker!\ntogglemenu coop_com"
	shader textures/coop_mod/lcars/coopLcars014.tga
	hovershader textures/coop_mod/lcars/coopLcars016.tga
}

////////////////////////////////////////////////////////////////////////////////
//COMMUNICATOR SCROLL
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
	
	cvarvisibility "coop_comL" "1"
	stuffcommand "set coop_comL 0"
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
	
	cvarvisibility "coop_comL" "0"
	stuffcommand "set coop_comL 1"
}
end.