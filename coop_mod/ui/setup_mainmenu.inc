////////////////////////////
// This fires up the setup menu if required
////////////////////////////
resource
Label
{
	cvarvisibility coop_ver 608 !=
	title "$$c#001$$"
	name "coopVersionCheckerTitle"
	rect 120 90 400 40
	//fgcolor 0 0.8 0.9 1.00
	fgcolor 1 1 1 1.00
	bgcolor 1.00 0 0 0.40
	font serpentinemedium-24
	horizontaljustify center
	verticaljustify top
	borderstyle "none"
}
resource
widget
{
	cvarvisibility coop_ver 608 !=
	name "coopVersionCheckerImage"
	rect 230 140 40 52
	bgcolor 0 1 0 0.40
	horizontaljustify center
	verticaljustify top
	borderstyle "none"
	//shader textures/menu/clouds
}
resource
widget
{
	cvarvisibility coop_ver 608 !=
	name "coopVersionCheckerImage1"
	rect 230 142 20 20
	bgcolor 0 1 0 0
	shader textures/menu/arrow_left
}
resource
widget
{
	cvarvisibility coop_ver 608 !=
	name "coopVersionCheckerImage2"
	rect 230 170 20 20
	bgcolor 0 1 0 0
	shader textures/menu/arrow_left
}
resource
Label
{
	cvarvisibility coop_ver 608 !=
	title "$$c#002$$"
	name "coopVersionCheckerShadow"
	rect 272 142 250 52
	fgcolor 0 0 0 1
	bgcolor 0 1 0 0
	font serpentinemedium-14
	horizontaljustify center
	verticaljustify top
	borderstyle "none"
}
resource
Label
{
	cvarvisibility coop_ver 608 !=
	title "$$c#002$$"
	name "coopVersionChecker"
	rect 270 140 250 52
	fgcolor 1 1 1 1
	bgcolor 0 1 0 0.40
	font serpentinemedium-14
	horizontaljustify center
	verticaljustify top
	borderstyle "none"
}
resource
Label
{
	cvarvisibility coop_ver 608 !=
	title "$$c#003$$"
	name "coopVersionCheckerButtonShadow"
	rect 122 142 100 52
	fgcolor 0 0 0 1
	bgcolor 1.00 0 0 0
	font serpentinemedium-14
	horizontaljustify center
	verticaljustify top
	borderstyle "none"
}
resource
Button
{
	cvarvisibility coop_ver 608 !=
	title "$$c#003$$"
	name "coopVersionCheckerButton"
	rect 120 140 100 52
	//fgcolor 0.12 0.15 0.25 1.00
	//bgcolor 0.00 1.00 1.00 0.40
	//fgcolor 0.4 0.5 0.7 1.00
	bgcolor 1.00 0 0 0.40
	hoverfgcolor 1 0 0 1
	hoverbgcolor 0 0 0 0.70
	hoverbordercolor 1 1 1 1
	borderstyle "BORDER_OUTLINE"

	//font serpentinemedium-12
	font serpentinemedium-14
	horizontaljustify center
	verticaljustify top
	hovercommand "globalwidgetcommand tooltip_main title \"$$c#007$$\""
	hoverexitcommand "globalwidgetcommand tooltip_main title \"\""
	stuffcommand "pushmenu coop_setup\n"

	ordernumber 12

	hoversound sound/misc/menu/hover.wav
	clicksound sound/misc/menu/click.wav
}
////////////////////////

end.

