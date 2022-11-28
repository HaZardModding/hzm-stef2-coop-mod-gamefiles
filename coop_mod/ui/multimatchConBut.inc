
//[b60011] chrissstrahl - coop server quick connect
resource
Button
{
	title			"$$c#155$$"
	name			"coop_qConBttn1"
	rect 54 155 152 21
	bgcolor 0.000 1.000 1.000 1.000
	fgcolor 0.125 0.157 0.251 1.000
	borderstyle "3D_BORDER"
	
	font serpentinemedium-10
	horizontaljustify center
	verticaljustify top
	
	hovershader menu/generic/button-hover
	armedshader menu/generic/button-press
	stuffcommand "connect coop.hazardmodding.com\n"
	
	ordernumber 5
	
	hovercommand "globalwidgetcommand tooltip_multimatch title $$c#152$$"
	hoverexitcommand "globalwidgetcommand tooltip_multimatch title \"\""
	
    clicksound sound/misc/menu/click.wav
}

//[b60011] chrissstrahl - coop server quick connect
resource
Button
{
	title			"$$c#154$$"
	name			"coop_qConBttn2"
	rect 208 155 162 21
	bgcolor 0.000 1.000 1.000 1.000
	fgcolor 0.125 0.157 0.251 1.000 
	borderstyle "3D_BORDER"
	
	font serpentinemedium-10
	horizontaljustify center
	verticaljustify top
	
	hovershader menu/generic/button-hover
	armedshader menu/generic/button-press
	stuffcommand "connect coop.hazardmodding.com:29255\n"
	
	ordernumber 5
	
	hovercommand "globalwidgetcommand tooltip_multimatch title $$c#153$$"
	hoverexitcommand "globalwidgetcommand tooltip_multimatch title \"\""
	
    clicksound sound/misc/menu/click.wav
}

end.