////////////////////////////////////////////////////////////////////////////////
//TRANSPORT BUTTONS - PAGE 1
////////////////////////////////////////////////////////////////////////////////
resource
Label
{
	title "Select a Player you wish to Transport to."
	rect 12 25 364 25
	font serpentinelight-12
	verticaljustify top
	horizontaljustify left
	fgcolor 1 1 1 1
	bgcolor 1 0 0 0
	cvarvisibility "coop_comT" "2"
}

resource
Button
{
	title "Transport to random Player"
	rect 12 55 320 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/lcars_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	cvarvisibility "coop_comT" "2"
	stuffcommand "!transport;togglemenu coop_com"
	shader textures/xxx/coopLcars020.tga
	hovershader textures/xxx/coopLcars016.tga
}

resource
Button
{
	title "!transport 0"
	name "coop_comTran0"
	rect 12 85 320 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/lcars_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	cvarvisibility "coop_comL" "20"
	stuffcommand "!transport 0;togglemenu coop_com"
	shader textures/xxx/coopLcars014.tga
	hovershader textures/xxx/coopLcars016.tga
}

resource
Button
{
	title "!transport 1"
	name "coop_comTran1"
	rect 12 105 320 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/lcars_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	cvarvisibility "coop_comL" "20"
	stuffcommand "!transport 1;togglemenu coop_com"
	shader textures/xxx/coopLcars024.tga
	hovershader textures/xxx/coopLcars016.tga
}

resource
Button
{
	title "!transport 2"
	name "coop_comTran2"
	rect 12 125 320 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/lcars_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	cvarvisibility "coop_comL" "20"
	stuffcommand "!transport 2;togglemenu coop_com"
	shader textures/xxx/coopLcars014.tga
	hovershader textures/xxx/coopLcars016.tga
}

resource
Button
{
	title "!transport 3"
	name "coop_comTran3"
	rect 12 145 320 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/lcars_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	cvarvisibility "coop_comL" "20"
	stuffcommand "!transport 3;togglemenu coop_com"
	shader textures/xxx/coopLcars024.tga
	hovershader textures/xxx/coopLcars016.tga
}
resource
Button
{
	title "!transport 4"
	name "coop_comTran4"
	rect 12 165 320 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/lcars_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	cvarvisibility "coop_comL" "20"
	stuffcommand "!transport 4;togglemenu coop_com"
	shader textures/xxx/coopLcars014.tga
	hovershader textures/xxx/coopLcars016.tga
}
resource
Button
{
	title "!transport 5"
	name "coop_comTran5"
	rect 12 185 320 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/lcars_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	cvarvisibility "coop_comL" "20"
	stuffcommand "!transport 5;togglemenu coop_com"
	shader textures/xxx/coopLcars024.tga
	hovershader textures/xxx/coopLcars016.tga
}
////////////////////////////////////////////////////////////////////////////////
//TRANSPORT BUTTONS - PAGE 2
////////////////////////////////////////////////////////////////////////////////
resource
Button
{
	title "!transport 6"
	name "coop_comTran6"
	rect 12 85 320 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/lcars_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	cvarvisibility "coop_comL" "21"
	stuffcommand "!transport 6;togglemenu coop_com"
	shader textures/xxx/coopLcars014.tga
	hovershader textures/xxx/coopLcars016.tga
}
resource
Button
{
	title "!transport 7"
	name "coop_comTran7"
	rect 12 105 320 18
	borderstyle "NONE"
	font serpentinemedium-10
	verticaljustify top
	clicksound sound/environment/computer/lcars_yes.wav
	fgcolor 0 0 0 1
	bgcolor 0 0 0 0
	cvarvisibility "coop_comL" "21"
	stuffcommand "!transport 7;togglemenu coop_com"
	shader textures/xxx/coopLcars024.tga
	hovershader textures/xxx/coopLcars016.tga
}

////////////////////////////////////////////////////////////////////////////////
//TRANSPORT SCROLL
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
	
	cvarvisibility "coop_comL" "21"
	stuffcommand "set coop_comL 20"
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
	
	cvarvisibility "coop_comL" "20"
	stuffcommand "set coop_comL 21"
}
end.