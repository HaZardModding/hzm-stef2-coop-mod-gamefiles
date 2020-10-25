//[b607] chrissstrahl - removed the data rate option, it is pointless
//[b607] chrissstrahl - move setup assistant here
resource
widget
{
	rect 362 105 272 22
	fgcolor 1.00 1.00 0.00 1.00
	bgcolor 0.00 0.00 0.00 0.00
	borderstyle "none"
	
	shader menu/main/credits
}

resource
button
{
	title "$$c#059$$"
	name "ConfigureNetwork"
	rect 365 107 240 16
	fgcolor 1 1 1 0.7
	bgcolor 1.00 1.00 1.00 0.00
	borderstyle "none"

	font serpentinemedium-10
	horizontaljustify center
	verticaljustify center

	hovershader menu/generic/button-hover
	pressedshader menu/generic/button-press
	clicksound sound/misc/menu/click.wav
 
	stuffcommand "pushmenu coop_settings\n"
}

resource
CheckBox
{
    title "$$LowBandwidth$$"
    name  "Default"
    //rect 362 251 232 16
    rect 362 127 232 16

    fgcolor 1.00 1.00 1.00 1.00
    bgcolor 0.50 0.50 0.50 0.00
    
    shadercolor             0.953 0.667 0.271 1.000
    hovershadercolor        0.953 0.667 0.271 1.000
    armedshadercolor        0.953 0.667 0.271 1.000
    selectedshadercolor     0.953 0.667 0.271 1.000
    
    borderstyle "NONE"

    checked_shader "textures/menu/checkbox_checked"
    unchecked_shader "textures/menu/checkbox_unchecked"

    hovershader menu/generic/button-hover
    armedshader menu/generic/button-press
    
    linkcvar "mp_lowBandwidth"
    
    font serpentinemedium-10
    horizontaljustify left
    
    hovercommand "globalwidgetcommand tooltip_gameopt title \"$$SetLowBandwidth$$\""
    hoverexitcommand "globalwidgetcommand tooltip_gameopt title \"\""
    
    clicksound sound/misc/menu/click.wav
    
}

resource
CheckBox
{
    title "$$Taunts$$"
    name "Default"
    //rect 362 271 200 16
    rect 362 147 200 16
    fgcolor 1.00 1.00 1.00 1.00
    bgcolor 0.00 0.00 0.00 0.00
    
    shadercolor             0.953 0.667 0.271 1.000
    hovershadercolor        0.953 0.667 0.271 1.000
    armedshadercolor        0.953 0.667 0.271 1.000
    selectedshadercolor     0.953 0.667 0.271 1.000
    
    borderstyle "NONE"
    linkcvar "s_playTaunts"
    
    checked_shader "textures/menu/checkbox_checked"
    unchecked_shader "textures/menu/checkbox_unchecked"
    
    hovershader menu/generic/button-hover
    armedshader menu/generic/button-press
    
    font serpentinemedium-10
    horizontaljustify left

    hovercommand        "globalwidgetcommand tooltip_gameopt title \"$$EnableTaunts$$\""
    hoverexitcommand    "globalwidgetcommand tooltip_gameopt title \"\""}
    
    clicksound sound/misc/menu/click.wav
}
end.