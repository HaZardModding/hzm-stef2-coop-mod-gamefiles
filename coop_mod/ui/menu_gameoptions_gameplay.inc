
resource
CheckBox
{
    title "$$AlwaysRun$$"
    name "Default"
    
    //rect 362 107 232 16
    rect 362 231 232 16
    fgcolor 1.00 1.00 1.00 1.00
    bgcolor 0.50 0.50 0.50 0.00
    
    shadercolor             0.953 0.667 0.271 1.000
    hovershadercolor        0.953 0.667 0.271 1.000
    armedshadercolor        0.953 0.667 0.271 1.000
    selectedshadercolor     0.953 0.667 0.271 1.000
    
    borderstyle "NONE"
    
    linkcvar "cl_run"
    
    checked_shader "textures/menu/checkbox_checked"
    unchecked_shader "textures/menu/checkbox_unchecked"

    hovershader menu/generic/button-hover
    armedshader menu/generic/button-press
    
    horizontaljustify left
    font serpentinemedium-10
    
    hovercommand "globalwidgetcommand tooltip_gameopt title \"$$EnableAlwaysRun$$\""
    hoverexitcommand "globalwidgetcommand tooltip_gameopt title \"\""
    
    clicksound sound/misc/menu/click.wav
}

resource
CheckBox
{
    title "$$ViewKick$$"
    name "Default"
    
    //rect 362 127 232 16
    rect 362 251 232 16
    fgcolor 1.00 1.00 1.00 1.00
    bgcolor 0.50 0.50 0.50 0.00
    
    shadercolor             0.953 0.667 0.271 1.000
    hovershadercolor        0.953 0.667 0.271 1.000
    armedshadercolor        0.953 0.667 0.271 1.000
    selectedshadercolor     0.953 0.667 0.271 1.000
    
    borderstyle "NONE"
    
    linkcvar "cg_viewkick"
    
    checked_shader "textures/menu/checkbox_checked"
    unchecked_shader "textures/menu/checkbox_unchecked"

    hovershader menu/generic/button-hover
    armedshader menu/generic/button-press
    
    horizontaljustify left
    font serpentinemedium-10
    
    hovercommand "globalwidgetcommand tooltip_gameopt title \"$$EnableViewKick$$\""
    hoverexitcommand "globalwidgetcommand tooltip_gameopt title \"\""
    
    clicksound sound/misc/menu/click.wav
}


resource
CheckBox
{
    title "$$ViewBob$$"
    name "Default"
    
    //rect 362 147 232 16
    rect 362 271 232 16
    fgcolor 1.00 1.00 1.00 1.00
    bgcolor 0.50 0.50 0.50 0.00
    
    shadercolor             0.953 0.667 0.271 1.000
    hovershadercolor        0.953 0.667 0.271 1.000
    armedshadercolor        0.953 0.667 0.271 1.000
    selectedshadercolor     0.953 0.667 0.271 1.000
    
    borderstyle "NONE"
    
    linkcvar "cg_viewBob"
    
    checked_shader "textures/menu/checkbox_checked"
    unchecked_shader "textures/menu/checkbox_unchecked"

    hovershader menu/generic/button-hover
    armedshader menu/generic/button-press
    
    horizontaljustify left
    font serpentinemedium-10
    
    hovercommand "globalwidgetcommand tooltip_gameopt title \"$$EnableViewBob$$\""
    hoverexitcommand "globalwidgetcommand tooltip_gameopt title \"\""
    
    clicksound sound/misc/menu/click.wav
}

resource
CheckBox
{
    title "$$c#044$$"
    name "Default"
    
    //rect 362 147 232 16
    rect 362 291 232 16
    fgcolor 1.00 1.00 1.00 1.00
    bgcolor 0.50 0.50 0.50 0.00
    
    shadercolor             0.953 0.667 0.271 1.000
    hovershadercolor        0.953 0.667 0.271 1.000
    armedshadercolor        0.953 0.667 0.271 1.000
    selectedshadercolor     0.953 0.667 0.271 1.000
    
    borderstyle "NONE"
    
    linkcvar "ui_showPlayerName"
    
    checked_shader "textures/menu/checkbox_checked"
    unchecked_shader "textures/menu/checkbox_unchecked"

    hovershader menu/generic/button-hover
    armedshader menu/generic/button-press
    
    horizontaljustify left
    font serpentinemedium-10
    
    hovercommand "globalwidgetcommand tooltip_gameopt title \"$$EnableViewBob$$\""
    hoverexitcommand "globalwidgetcommand tooltip_gameopt title \"\""
    
    clicksound sound/misc/menu/click.wav
}



resource
Label
{
    title "$$DialogText$$"
    name  "Default"
   // rect 362 167 120 16
    rect 362 311 120 16
    
    fgcolor 1.00 1.00 1.00 1.00
    bgcolor 0.122 0.157 0.251 1.000
    borderstyle "3D_BORDER"
    
    font serpentinemedium-10
    horizontaljustify right
    
    hovercommand "globalwidgetcommand tooltip_gameopt title \"$$SetDialogTextMode$$\""
    hoverexitcommand "globalwidgetcommand tooltip_gameopt title \"\""
}

//Dialog Text SwitchBox
resource
SwitchBox
{
    name "Default"
    //rect 482 167 104 16
    rect 482 311 104 16
    fgcolor 0.953 0.667 0.271 1.000
    bgcolor 0.000 0.000 0.000 0.750
    borderstyle "OUTLINE_BORDER"
    bordercolor 0.122 0.157 0.251 1.000
    
    linkcvar "ui_dialogdisplaymode"

    option "$$Off$$"        "set ui_dialogdisplaymode 0" 0
    option "$$Normal$$"     "set ui_dialogdisplaymode 1" 1
    option "$$Always$$"     "set ui_dialogdisplaymode 2" 2
    
    font serpentinemedium-10
    hovercommand "globalwidgetcommand tooltip_gameopt title \"$$SetDialogTextMode$$\""
    hoverexitcommand "globalwidgetcommand tooltip_gameopt title \"\""
    
    clicksound sound/misc/menu/click.wav
}

//Dialog Text Pulldown Menu
resource
PulldownMenuContainer
{
    name "Default"
    //rect 586 167 16 16
    rect 586 311 16 16
    fgcolor                 0.953 0.667 0.271 1.000
    bgcolor                 1.000 1.000 1.000 0.000
    shadercolor             0.953 0.667 0.271 1.000
    hovershadercolor        0.953 0.667 0.271 1.000
    armedshadercolor        0.953 0.667 0.271 1.000
    selectedshadercolor     0.953 0.667 0.271 1.000
    
    font serpentinemedium-10
    
    borderstyle "NONE"
    menushader "MENU" "textures/menu/pulldownarrow"
    selmenushader "MENU" "textures/menu/pulldownarrow_sel"

    addpopup "MENU" "$$Off$$"       command "set ui_dialogdisplaymode 0"
    addpopup "MENU" "$$Normal$$"    command "set ui_dialogdisplaymode 1"
    addpopup "MENU" "$$Always$$"    command "set ui_dialogdisplaymode 2"
    popup_width "MENU" 120
    
    font serpentinemedium-10
    
    hovercommand "globalwidgetcommand tooltip_gameopt title \"$$SetDialogTextMode$$\""
    hoverexitcommand "globalwidgetcommand tooltip_gameopt title \"\""
    
    clicksound sound/misc/menu/click.wav
}

resource
Label
{
    title "$$RadarView$$"
    name  "Default"
    //rect 362 187 120 16
    rect 362 331 120 16
    
    fgcolor 1.00 1.00 1.00 1.00
    bgcolor 0.122 0.157 0.251 1.000
    borderstyle "3D_BORDER"
    
    font serpentinemedium-10
    horizontaljustify right
    
    hovercommand "globalwidgetcommand tooltip_gameopt title \"$$SetRadarViewMode$$\""
    hoverexitcommand "globalwidgetcommand tooltip_gameopt title \"\""
}

//Radar View SwitchBox
resource
SwitchBox
{
    name "Default"
    //rect 482 187 104 16
    rect 482 331 104 16
    fgcolor 0.953 0.667 0.271 1.000
    bgcolor 0.000 0.000 0.000 0.750
    borderstyle "OUTLINE_BORDER"
    bordercolor 0.122 0.157 0.251 1.000
    
    linkcvar "ui_radarviewmode"

    option "$$TopDown$$"        "set ui_radarviewmode 2" 2
    option "$$Tilt$$"           "set ui_radarviewmode 1" 1
    option "$$TiltLocked$$"     "set ui_radarviewmode 3" 3
    option "$$FreeLook$$"       "set ui_radarviewmode 0" 0
    
    font serpentinemedium-10
    hovercommand "globalwidgetcommand tooltip_gameopt title \"$$SetRadarViewMode$$\""
    hoverexitcommand "globalwidgetcommand tooltip_gameopt title \"\""
    
    clicksound sound/misc/menu/click.wav
}

//Dialog Text Pulldown Menu
resource
PulldownMenuContainer
{
    name "Default"
    //rect 586 187 16 16
    rect 586 331 16 16
    fgcolor                 0.953 0.667 0.271 1.000
    bgcolor                 1.000 1.000 1.000 0.000
    shadercolor             0.953 0.667 0.271 1.000
    hovershadercolor        0.953 0.667 0.271 1.000
    armedshadercolor        0.953 0.667 0.271 1.000
    selectedshadercolor     0.953 0.667 0.271 1.000
    
    font serpentinemedium-10
    
    borderstyle "NONE"
    menushader "MENU" "textures/menu/pulldownarrow"
    selmenushader "MENU" "textures/menu/pulldownarrow_sel"

    addpopup "MENU" "$$TopDown$$"           command "set ui_radarviewmode 2"
    addpopup "MENU" "$$Tilt$$"              command "set ui_radarviewmode 1"
    addpopup "MENU" "$$TiltLocked$$"        command "set ui_radarviewmode 3"
    addpopup "MENU" "$$FreeLook$$"          command "set ui_radarviewmode 0"
    
    popup_width "MENU" 120
    
    font serpentinemedium-10
    hovercommand "globalwidgetcommand tooltip_gameopt title \"$$SetRadarViewMode$$\""
    hoverexitcommand "globalwidgetcommand tooltip_gameopt title \"\""
    
    clicksound sound/misc/menu/click.wav
}

end.