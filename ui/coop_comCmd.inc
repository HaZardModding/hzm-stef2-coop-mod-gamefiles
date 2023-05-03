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
	stuffcommand "!follow\n"
}

resource
Button
{
	title "!stuck"
	rect 170 30 128 16
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	shader textures/xxx/coopLcars019.tga
	
	hovercommand "globalwidgetcommand coop_comTooltip title \"Moves you to Spawn location\""
	hoverexitcommand "globalwidgetcommand coop_comTooltip title \"\""

	cvarvisibility "coop_comL" "10"
	stuffcommand "!stuck\n"
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