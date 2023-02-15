//Co-Op Related, remove the missionobjectives hud before showing the loading hud
showcommand	"ui_removehud coop_objectives;\n"

resource
Label
{
name "timerhudBg"
rect 0 0 192 56 //48
fgcolor 1.00 1.00 1.00 1.00
bgcolor 0.50 0.50 0.50 0.00
borderstyle "NONE"
shader textures/menu/timer
}
resource
Label
{
name "timerhudBar"
rect 20 18 153 20 //20 18 153 19
fgcolor 1.00 1.00 1.00 1.00
bgcolor 0.50 0.50 0.50 0.00
borderstyle "NONE"
statbar_shader textures/menu/timer_bar
playerstat generic
statbar horizontal 0 100
}
end.