////////////////////////////////////////////////////////////////////////////////
//COMMAND BUTTONS
////////////////////////////////////////////////////////////////////////////////
resource
Button
{
	title "!follow"
	rect 12 30 128 16
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	shader textures/xxx/coopLcars017.tga
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Shows you as green dot on Radar\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	cvarvisibility "coop_comL" "10"
	stuffcommand "!follow"
}
resource
Button
{
	title "!stuck"
	rect 200 30 128 16
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	shader textures/xxx/coopLcars023.tga
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Moves you to Spawn location\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	cvarvisibility "coop_comL" "10"
	stuffcommand "!stuck"
}

resource
Button
{
	title "!drop"
	rect 12 60 128 16
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	shader textures/xxx/coopLcars023.tga
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Drops your current weapon if possible\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	cvarvisibility "coop_comL" "10"
	stuffcommand "!drop"
}
resource
Button
{
	title "!info"
	rect 200 60 128 16
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	shader textures/xxx/coopLcars015.tga
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Shows you your Info\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	cvarvisibility "coop_comL" "10"
	stuffcommand "!info"
}

resource
Button
{
	title "!kickbots"
	rect 12 90 128 16
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	shader textures/xxx/coopLcars019.tga
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Kicks all BOT players\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	cvarvisibility "coop_comL" "10"
	stuffcommand "!kickbots"
}
resource
Button
{
	title "!kill"
	rect 200 90 128 16
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	shader textures/xxx/coopLcars023.tga
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Commit Suicide\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	cvarvisibility "coop_comL" "10"
	stuffcommand "!kill"
}

resource
Button
{
	title "?"
	rect 12 120 128 16
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	shader textures/xxx/coopLcars019.tga
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	cvarvisibility "coop_comL" "10"
	stuffcommand ""
}
resource
Button
{
	title "?"
	rect 200 120 128 16
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	shader textures/xxx/coopLcars023.tga
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	cvarvisibility "coop_comL" "10"
	stuffcommand ""
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
	stuffcommand ""
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
	
	cvarvisibility "coop_comL" "1"
	stuffcommand ""
}
end.