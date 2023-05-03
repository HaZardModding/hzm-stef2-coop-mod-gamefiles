////////////////////////////////////////////////////////////////////////////////
//COMMUNICATOR BUTTONS
////////////////////////////////////////////////////////////////////////////////
resource
Button
{
	title "$$c#067$$" //FOLLOW ME
	rect 12 30 320 16
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	cvarvisibility "coop_comL" "0"
	stuffcommand "!follow;say some text"
	shader textures/xxx/coopLcars012.tga
}

resource
Button
{
	title "$$c#066$$" //Take Cover
	rect 12 50 320 16
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	cvarvisibility "coop_comL" "0"
	stuffcommand ""
	shader textures/xxx/coopLcars014.tga
}

resource
Button
{
	title "$$c#068$$" //take cover
	rect 12 70 320 16
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	cvarvisibility "coop_comL" "0"
	stuffcommand ""
	shader textures/xxx/coopLcars012.tga
}

resource
Button
{
	title "$$c#066$$" //Take Cover
	rect 12 90 320 16
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/holo_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	cvarvisibility "coop_comL" "0"
	stuffcommand ""
	shader textures/xxx/coopLcars014.tga
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
	
	cvarvisibility "coop_comL" "0"
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
	
	cvarvisibility "coop_comL" "0"
	stuffcommand ""
}
end.