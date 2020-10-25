////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////Functions/////Functions
////////////////////////////////////////////////////////////////////////////////
//[b607] chrissstrahl - new
resource
Button
{
	title "!block"
	name "coop_comFuncblock"
	rect 2 62 252 24
	borderstyle "INDENT_BORDER"
	stuffcommand "!block\ntogglemenu coop_communicator"
	font serpentinemedium-12
	verticaljustify top
	clicksound sound/environment/computer/lcars_yes.wav
	fgcolor 0.99 0.80 0.20 1.00
	bgcolor 0.22 0.25 0.35 0.9
	hoverbgcolor 1 1 1 0.4
	hoverfgcolor 1 1 1 1
	cvarvisibility "coop_comL" "11"
}
resource
Button
{
	title "!stuck"
	name "coop_comFuncstuck"
	rect 2 88 252 24
	borderstyle "INDENT_BORDER"
	stuffcommand "!stuck\ntogglemenu coop_communicator"
	font serpentinemedium-12
	verticaljustify top
	clicksound sound/environment/computer/lcars_yes.wav
	fgcolor 0.99 0.80 0.20 1.00
	bgcolor 0.22 0.25 0.35 0.9
	hoverbgcolor 1 1 1 0.4
	hoverfgcolor 1 1 1 1
	cvarvisibility "coop_comL" "11"
}
resource
Button
{
	title "!drop"
	name "coop_comFuncdrop"
	rect 2 114 252 24
	borderstyle "INDENT_BORDER"
	stuffcommand "!drop\ntogglemenu coop_communicator"
	font serpentinemedium-12
	verticaljustify top
	clicksound sound/environment/computer/lcars_yes.wav
	fgcolor 0.99 0.80 0.20 1.00
	bgcolor 0.22 0.25 0.35 0.9
	hoverbgcolor 1 1 1 0.4
	hoverfgcolor 1 1 1 1
	cvarvisibility "coop_comL" "11"
}
resource
Button
{
	title "!kill"
	name "coop_comFunckill"
	rect 2 140 252 24
	borderstyle "INDENT_BORDER"
	stuffcommand "kill\ntogglemenu coop_communicator"
	font serpentinemedium-12
	verticaljustify top
	clicksound sound/environment/computer/lcars_yes.wav
	fgcolor 0.99 0.80 0.20 1.00
	bgcolor 0.22 0.25 0.35 0.9
	hoverbgcolor 1 1 1 0.4
	hoverfgcolor 1 1 1 1
	cvarvisibility "coop_comL" "11"
}
resource
Button
{
	title "reconnect"
	name "coop_comFuncreconnect"
	rect 2 166 252 24
	borderstyle "INDENT_BORDER"
	stuffcommand "reconnect\ntogglemenu coop_communicator"
	font serpentinemedium-12
	verticaljustify top
	clicksound sound/environment/computer/lcars_yes.wav
	fgcolor 0.99 0.80 0.20 1.00
	bgcolor 0.22 0.25 0.35 0.9
	hoverbgcolor 1 1 1 0.4
	hoverfgcolor 1 1 1 1
	cvarvisibility "coop_comL" "11"
}

// resource
// Button
// {
	// title "xx"
	// name "coop_comFunc???"
	// rect 2 192 252 24
	// borderstyle "INDENT_BORDER"
	// stuffcommand "!"
	// font serpentinemedium-12
	// verticaljustify top
	// clicksound sound/environment/computer/lcars_yes.wav
	// fgcolor 0.99 0.80 0.20 1.00
	// bgcolor 0.22 0.25 0.35 0.9
	// hoverbgcolor 1 1 1 0.4
	// hoverfgcolor 1 1 1 1
	// cvarvisibility "coop_comL" "11"
// }
// resource
// Button
// {
	// title ""
	// name "coop_comFunc???"
	// rect 2 218 252 24
	// borderstyle "INDENT_BORDER"
	// stuffcommand "!"
	// font serpentinemedium-12
	// verticaljustify top
	// clicksound sound/environment/computer/lcars_yes.wav
	// fgcolor 0.99 0.80 0.20 1.00
	// bgcolor 0.22 0.25 0.35 0.9
	// hoverbgcolor 1 1 1 0.4
	// hoverfgcolor 1 1 1 1
	// cvarvisibility "coop_comL" "11"
// }
// resource
// Button
// {
	// title ""
	// name "coop_comFunc???"
	// rect 2 244 252 24
	// borderstyle "INDENT_BORDER"
	// stuffcommand "!"
	// font serpentinemedium-12
	// verticaljustify top
	// clicksound sound/environment/computer/lcars_yes.wav
	// fgcolor 0.99 0.80 0.20 1.00
	// bgcolor 0.22 0.25 0.35 0.9
	// hoverbgcolor 1 1 1 0.4
	// hoverfgcolor 1 1 1 1
	// cvarvisibility "coop_comL" "11"
// }
// resource
// Button
// {
	// title "????"
	// name "coop_comFunc???"
	// rect 2 270 252 24
	// borderstyle "INDENT_BORDER"
	// stuffcommand "!"
	// font serpentinemedium-12
	// verticaljustify top
	// clicksound sound/environment/computer/lcars_yes.wav
	// fgcolor 0.99 0.80 0.20 1.00
	// bgcolor 0.22 0.25 0.35 0.9
	// hoverbgcolor 1 1 1 0.4
	// hoverfgcolor 1 1 1 1
	// cvarvisibility "coop_comL" "11"
// }
// resource
// Button
// {
	// title "$$c#099$$"
	// name "coop_comFunc???"
	// rect 2 296 252 24
	// borderstyle "INDENT_BORDER"
	// stuffcommand "exec coop_mod/cfg/communicator/flushtikis.cfg"
	// font serpentinemedium-12
	// verticaljustify top
	// clicksound sound/environment/computer/lcars_yes.wav
	// fgcolor 0.99 0.80 0.20 1.00
	// bgcolor 0.22 0.25 0.35 0.9
	// hoverbgcolor 1 1 1 0.4
	// hoverfgcolor 1 1 1 1
	// cvarvisibility "coop_comL" "11"
// }
resource
Button
{
	title "$$c#099$$"
	name "coop_comFuncClear"
	rect 2 322 252 24
	borderstyle "INDENT_BORDER"
	stuffcommand "exec coop_mod/cfg/communicator/flushtikis.cfg"
	font serpentinemedium-12
	verticaljustify top
	clicksound sound/environment/computer/lcars_yes.wav
	fgcolor 0.99 0.80 0.20 1.00
	bgcolor 0.22 0.25 0.35 0.9
	hoverbgcolor 1 1 1 0.4
	hoverfgcolor 1 1 1 1
	cvarvisibility "coop_comL" "11"
}

end.