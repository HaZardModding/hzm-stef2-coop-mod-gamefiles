//////////////////////////////////////
//Defiant Hall Pipe 01
//Made/Edited by Explorer
//explorer@exp-ind.com
//
//////////////////////////////////////
//
textures/EntD/wallbase4
{
	qer_editorimage textures/EntD/wallbase4.tga
	{
		map textures/shad_fx/shadefx01.tga
		rgbGen identity
		tcGen environment 
	}
	{
		map textures/EntD/wallbase4.tga
		blendfunc gl_src_color gl_src_color
		rgbGen identity
	}
	{
		map $lightmap 
		blendfunc filter
		tcGen lightmap 
	}
}
