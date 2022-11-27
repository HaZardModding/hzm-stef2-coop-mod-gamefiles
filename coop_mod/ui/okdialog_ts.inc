//[b60011] chrissstrahl
resource
Button
{
	title "$$c#006$$"
	rect 228 360 183 60
	fgcolor 0.00 1.00 1.00 1.00
	bgcolor 1.00 1.00 1.00 0.50
	stuffcommand "g_gametype 1;dedicated 0;map blackbox$getmap=1"
	font serpentinemedium-10
	clicksound sound/misc/menu/click.wav
    verticaljustify top
    horizontaljustify center
	textshadowcolor 0 0 0 1
	hovertextshadowcolor 0 0 0 1
	
	cvarvisibility cg_gametype -1 ==
}
